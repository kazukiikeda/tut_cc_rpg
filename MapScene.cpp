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
	int scx = Posx;
		
	manager->EntryTask(CreateMapTask(100, 15, (int (*)[])tmpMap, scx));
	manager->EntryTask(CreateObjectTask(Posx + 10, 0, 1));
	manager->EntryTask(CreateObjectTask(Posx + 20, 0, 2));
	//manager->EntryTask(CreateEnemyTask(x, ID, movepatern, flag, 3));

	manager->EntryTask(CreateEnemyTask(5, 0, 0, 1, 3));
	manager->EntryTask(CreateEnemyTask(30, 1, 0, 1, 3));

	manager->EntryTask(CreatePlayerTask());
	
	std::shared_ptr<MapScene> Scene = std::make_shared<MapScene>(manager);

	return Scene;
}

MapScene::MapScene(std::shared_ptr<GameTask> roottask)
{
	Root = roottask;
}

bool MapScene::Init()
{
	OutputDebugString("MapScene::Init()\n");

	ExitFlag = false;

	Root->Init();
	return true;
}

bool MapScene::Exec()
{
	bool flag = true;
	
	code = Root->Update();
	if (code == TASK_NEXTSCENE)
		num = Root->getnum();
	if (KeyDownChecker::GetKeyDownState(KEY_INPUT_Z))
		return false;
	if (KeyDownChecker::GetKeyDownState(KEY_INPUT_UP)&& code == TASK_NEXTSCENE)
	return false;

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

bool MapScene::Exit()
{
	Root->Exit();
	return true;
}

std::shared_ptr<IScene> MapScene::GetNextScene()
{
	if (num == 1)
		return CreateMapScene(MAP, -5);
	if (num == 2)
		return CreateMapScene(MAP, 5);
}