//MapScene.cpp
#include "MapScene.h"
#include "KeyDownChecker.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

std::shared_ptr<IScene> CreateMapScene(int PosX, std::string SceneName)
{
	//マップ情報
	std::ifstream ifs;
	std::string str;
	std::string Handlead;
	int back;
	int width;
	int grand;
	int wall;
	std::string LeftWall;
	int LeftNextX;
	std::string RightWall;
	int RightNextX;
	ifs.open("Data/" + SceneName + "/MapInfo.txt");
	int j = 0;
	while (getline(ifs, str)){
		if (j == 0)
			Handlead = str;
		if (j == 1)
			back = std::stoi(str);
		if (j == 2)
			grand = std::stoi(str);
		if (j == 3)
			width = std::stoi(str);
		if (j == 4)
			wall = std::stoi(str);
		if (j == 5)
			LeftWall = str;
		if (j == 6)
			LeftNextX = std::stoi(str);
		if (j == 7)
			RightWall = str;
		if (j == 8)
			RightNextX = std::stoi(str);
		j++;
	}
	ifs.close();
	//マップ情報
	int tmpMap[100][15];
	for (int i = 0; i < width; i++){
		for (int j = 0; j < 12; j++){
			tmpMap[i][j] = back;
		}
		tmpMap[i][12] = grand;
	}
	//ルートマネージャーを作成
	std::shared_ptr<GameTaskManager> manager = CreateCollisionCheck();
	int Object_num = 0;
	//タスクを登録
	manager->EntryTask(CreateMapTask(width, 15, (int (*)[])tmpMap, PosX, Handlead));
	
	std::ifstream ofs;
	ofs.open("Data/" + SceneName + "/ObjectList.txt");
	while (getline(ofs, str)){
		std::stringstream stream(str);
		std::string dumy;
		std::vector<std::string> buf;
		while (getline(stream, dumy, ',')){
			buf.push_back(dumy);
			}
		manager->EntryTask(CreateObjectTask(PosX + std::stoi(buf.at(0)), std::stoi(buf.at(1)), buf.at(2), Object_num, buf.at(3), std::stoi(buf.at(4)), buf.at(5)));
		Object_num++;
	}
	ofs.close();
	std::ifstream efs;
	efs.open("Data/" + SceneName + "/EnemyList.txt");
	while (getline(efs, str)){
		std::stringstream stream(str);
		std::string dumy;
		std::vector<std::string> buf;
		while (getline(stream, dumy, ',')){
			buf.push_back(dumy);
		}
		manager->EntryTask(CreateEnemyTask(PosX + std::stoi(buf.at(0)), std::stoi(buf.at(1)), buf.at(2), buf.at(3), Object_num));
		Object_num++;
	}
	efs.close();
	std::ifstream nfs;
	nfs.open("Data/" + SceneName + "/NPCList.txt");
	while (getline(nfs, str)){
		std::stringstream stream(str);
		std::string dumy;
		std::vector<std::string> buf;
		while (getline(stream, dumy, ',')){
			buf.push_back(dumy);
		}
		manager->EntryTask(CreateNPCTask(PosX + std::stoi(buf.at(0)), std::stoi(buf.at(1)), buf.at(2), buf.at(3), buf.at(4), Object_num));
		Object_num++;
	}
	nfs.close();
		for (int i = 0; i < 12; i++)
			manager->EntryTask(CreateWallTask(PosX, i, wall, LeftWall, LeftNextX, Handlead, Object_num));
		Object_num++;
		for (int i = 0; i < 12; i++)
			manager->EntryTask(CreateWallTask(PosX + width - 1, i, wall, RightWall, RightNextX, Handlead, Object_num));

		manager->EntryTask(CreatePlayerTask(20, 7));
	
	std::shared_ptr<MapScene> Scene = std::make_shared<MapScene>(manager, SceneName);
	
	return Scene;
}
MapScene::MapScene(){}
MapScene::MapScene(std::shared_ptr<GameTask> roottask, std::string Scenename)
{
	Root = roottask;
	scene = Scenename;
	EventFlag = false;
}

bool MapScene::Init()
{
		ExitFlag = false;
		Root->Init();		
	return true;
}

bool MapScene::Exec()
{
	bool flag = true;
	if (EventFlag){
		return false;
	}
		code = Root->Update();		

		if (code == TASK_NEXTSCENE || code == TASK_BATTLESCENE || code == TASK_TALK || code == TASK_STOP){
			num = Root->getnum();
			ID = Root->getID();
			nextscene = Root->getNext();
			nextPosX = Root->getNextX();
		}
		if (code == TASK_BATTLESCENE){	
			Root->checker();
			return false;
		}
		if (code == TASK_STOP){
			if (nextscene == "STOP"){
				Root->stop(Root->checker());
			}
			else
				return false;
		}

		if (KeyDownChecker::GetKeyDownState(KEY_INPUT_Q) && code == TASK_NEXTSCENE){
			if (Root->getText() != "NULL"){
				Root->checker();
				std::shared_ptr<GameTask> root = CreateTextTask(Root->getText(), Root, scene);
				root->Init();
				root->Update();
				root->Draw();
				root->Exit();
			}
			return false;
		}
		if (KeyDownChecker::GetKeyDownState(KEY_INPUT_Q) && code == TASK_TALK){
			Root->checker();
			std::shared_ptr<GameTask> root = CreateTextTask(Root->getText(), Root, scene);	
			root->Init();			
			root->Update();			
			root->Draw();			
			root->Exit();
		}
		code = Root->Draw();
		if (code)
		{
			switch (code)
			{
			case TASK_NEXTSCENE:
				flag = false;
				break;
			}
		}
	return flag;
}
NextScene MapScene::Next(){	
	if (nextscene == "BATTLE")
		return NEW;
	return KEEP;
}
bool MapScene::Exit()
{
		Root->Exit();
	return true;
}
std::shared_ptr<IScene> MapScene::GetNextScene()
{
	if (EventFlag){
		EventFlag = false;
		return CreateEventScene(ID);
	}
	if (nextscene == "BATTLE"){
		std::ifstream ifs;

		ifs.open("Data/EVENT/" + ID + "/BOSS.txt");
		if (ifs.fail() != true)
			EventFlag = true;
		ifs.close();
		return CreateBattleScene(ID);
	}
	else
		return CreateMapScene(nextPosX, nextscene);
}