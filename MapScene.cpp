//MapScene.cpp
#include "MapScene.h"
#include "KeyDownChecker.h"

#define grand 3

std::shared_ptr<IScene> CreateMapScene(BeforScene BEFOR, int PosX)
{
	//マップ情報
	int tmpMap[100][15] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand }, 
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, grand },
	};
	//ルートマネージャーを作成
	std::shared_ptr<GameTaskManager> manager = CreateCollisionCheck();

	SetBackgroundColor(255, 255, 255);
	
	//タスクを登録
	manager->EntryTask(CreateMapTask(100, 15, (int (*)[])tmpMap, PosX));

	manager->EntryTask(CreateObjectTask(PosX + 10, 11, 0, 1));
	manager->EntryTask(CreateObjectTask(PosX + 20, 11, 0, 2));

	manager->EntryTask(CreateEnemyTask(PosX + 5, 7, 0, 2, 3));
	manager->EntryTask(CreateEnemyTask(PosX + 30, 7, 1, 2, 4));
	
	manager->EntryTask(CreateNPCTask(PosX + 9, 7, 0, 1, 1));
	
		manager->EntryTask(CreatePlayerTask(11, 5));
	
	std::shared_ptr<MapScene> Scene = std::make_shared<MapScene>(manager, PosX);
	
	return Scene;
}

MapScene::MapScene(std::shared_ptr<GameTask> roottask, int x)
{
	PosX = x;
	Root = roottask;
	
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
	
		code = Root->Update();

		if (code == TASK_NEXTSCENE || code == TASK_BATTLESCENE){
			num = Root->getnum();
		}
		if (code == TASK_BATTLESCENE){	
			Root->checker();
			return false;
		}
		if (KeyDownChecker::GetKeyDownState(KEY_INPUT_A) && code == TASK_NEXTSCENE){
			return false;
		}
		if (KeyDownChecker::GetKeyDownState(KEY_INPUT_Q) && code == TASK_TALK){
			Root->checker();
			std::shared_ptr<GameTask> root = CreateTextTask(num, Root);
			
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
	switch (num){
	case 3:
	case 4:
		return NEW;
	}
	return KEEP;
}
bool MapScene::Exit()
{
		Root->Exit();
	return true;
}
void MapScene::callback(){
	OutputDebugString("帰ってきーたよ\n");
}
std::shared_ptr<IScene> MapScene::GetNextScene()
{
	switch (num){
	case 0:
		return  CreateTitleScene();
	case 1:
		return CreateMapScene(MAP, -5);
	case 2:
		return CreateMapScene(MAP, 5);
	case 3:
	case 4:
		return CreateBattleScene(num);
	}
		return CreateTitleScene();

}