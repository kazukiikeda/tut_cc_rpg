//MapScene.cpp
#include "MapScene.h"
#include "KeyDownChecker.h"

#define grand 3

std::shared_ptr<IScene> CreateMapScene(BeforScene BEFOR, int Posx)
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
	manager->EntryTask(CreateMapTask(100, 15, (int (*)[])tmpMap, Posx));

	manager->EntryTask(CreateObjectTask(Posx + 10, 0, 1));
	manager->EntryTask(CreateObjectTask(Posx + 20, 0, 2));

	manager->EntryTask(CreateEnemyTask(Posx + 5, 0, 2, 3));
	manager->EntryTask(CreateEnemyTask(Posx + 30, 1, 2, 4));
	//(int x, int ID, int movepattern, int Object_num);

	manager->EntryTask(CreateNPCTask(Posx + 9, 0, 1, 1));
	
		manager->EntryTask(CreatePlayerTask());
	
	std::shared_ptr<MapScene> Scene = std::make_shared<MapScene>(manager, Posx);
	
	return Scene;
}

MapScene::MapScene(std::shared_ptr<GameTask> roottask, int x)
{
	PosX = x;
	Root = roottask;
	//Root->Flag = false;;
	//Flag = true;
	num = 0;
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
		PosX = Root->Scx;
		if (code == TASK_NEXTSCENE || code == TASK_BATTLESCENE){
			num = Root->getnum();
			//ID = Root->getID();
			//Root->setFlag(false);
		}
		if (code == TASK_BATTLESCENE){
			return false;
		}
		if (KeyDownChecker::GetKeyDownState(KEY_INPUT_A) && code == TASK_NEXTSCENE){
			return false;
		}
		if (KeyDownChecker::GetKeyDownState(KEY_INPUT_Q) && code == TASK_TALK){
			std::shared_ptr<GameTask> root = CreateTextTask(num, Root);
			root->Init();
			root->Update();
			root->Draw();
			root->Exit();
		}
		//if (Root->getnum() == befornum)
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
		if (num == 3)
			return NEW;
		if (num == 4)
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
		if (num == 0)
			return  CreateTitleScene();
		if (num == 1)
			return CreateMapScene(MAP, -5);
		if (num == 2)
			return CreateMapScene(MAP, 5);
		if (num == 3)
			return CreateBattleScene(3);
		if (num == 4)
			return CreateBattleScene(4);

}