#include "EnemyTask.h"
#include "KeyDownChecker.h"
#include <vector>

std::shared_ptr<GameTask> CreateEnemyTask(int x, int ID, int movepatern, bool flag, int Object_num)
{
	return std::make_shared<EnemyTask>(x, ID, Object_num, movepatern, flag);
}

void EnemyTask::MoveLeft()
{
	DirType = CHARACTER_DIR_RIGHT;
	x--;

	if (counter % 20 == 1)
		CurrentGraph = (CurrentGraph == 1 ? 3 : 1);
}

void EnemyTask::MoveRight()
{
	DirType = CHARACTER_DIR_DOWN;
	x++;

	if (counter % 20 == 1)
		CurrentGraph = (CurrentGraph == 1 ? 3 : 1);
}

void EnemyTask::MoveUp()
{
	DirType = CHARACTER_DIR_LEFT;
	y--;

	if (counter % 20 == 1)
		CurrentGraph = (CurrentGraph == 1 ? 3 : 1);
}

void EnemyTask::MoveDown()
{
	DirType = CHARACTER_DIR_UP;
	y++;

	if (counter % 20 == 1)
		CurrentGraph = (CurrentGraph == 1 ? 3 : 1);
}

void EnemyTask::Stay()
{
	MoveType = CHARACTER_STAY;
	CurrentGraph = 0;
}

EnemyTask::EnemyTask(int X, int id, int object_num, int movepatern, bool flag) : ObjectTask(x, id, Object_num)
{
	ID = id;
	CollisionObject::id = OBJECT_ENEMY;
	Object_num = object_num;
	x = (float)X * (float)Size_x;//15
	y = (float)7 * (float)Size_y;//12
	r = 20;
	std::vector<std::vector<std::vector<int>>> Movepatern = {
		{ { 120, 260 }, { 128, 128 }, { 3, 1 } } ,
		{ {}, {}, {} }
	};
	
		for (int i = 0; i < Movepatern[movepatern][0].size(); i++)
		{
			MoveProcess Process;
			Process.StartCount = Movepatern[movepatern][0][i];
			Process.ProcessCount = Movepatern[movepatern][1][i];
			Process.Direction = (CHARACTER_DIRECTION_TYPE)Movepatern[movepatern][2][i];
			MoveList.push_back(Process);
		}
}

bool EnemyTask::Init()
{
	int tmp[16];
	switch (ID){
	case 0:
		LoadDivGraph("Data/Character/Enemy.bmp", 16, 4, 4, Size_x, Size_y, tmp);
		r = 20;
		break;
	case 1:
		LoadDivGraph("Data/Character/char_skeleton.png", 16, 4, 4, Size_x, Size_y, tmp);
		r = 20;
		break;
	}
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			GraphHandle[y][x] = tmp[4 * y + x];

	MoveType = CHARACTER_STAY;
	DirType = CHARACTER_DIR_UP;

	counter = 0;
	CurrentGraph = 0;
	CurrentMove = 0;

	return true;
}

GAMETASK_CODE EnemyTask::Update()
{
	if (KeyDownChecker::GetKeyDownState(KEY_INPUT_RIGHT))
		//DirType = CHARACTER_DIR_RIGHT;
		mapDir = 1;
	else if (KeyDownChecker::GetKeyDownState(KEY_INPUT_LEFT))
		//DirType = CHARACTER_DIR_LEFT;
		mapDir = 2;
	
	if (KeyDownChecker::GetKeyState(KEY_INPUT_LEFT) || KeyDownChecker::GetKeyState(KEY_INPUT_RIGHT))
		switch (mapDir)
	{
		case 2:
			x=x+2;
			break;
		case 1:
			x=x-2;
			break;
	}
	if (MoveList[CurrentMove].StartCount <= counter)
	{
		//終了処理
		if (MoveList[CurrentMove].ProcessCount + MoveList[CurrentMove].StartCount == counter)
		{
			CurrentMove++;
			if (CurrentMove == MoveList.size())
			{
				CurrentMove = 0;
				counter = -1;	//最後なのでカウンタを-1に戻す
			}
		}
		else
		{
			//移動操作
			switch (MoveList[CurrentMove].Direction)
			{
				case CHARACTER_DIR_LEFT:
					MoveLeft();
					break;
				case CHARACTER_DIR_RIGHT:
					MoveRight();
					break;
				case CHARACTER_DIR_UP:
					MoveUp();
					break;
				case CHARACTER_DIR_DOWN:
					MoveDown();
					break;

			}
		}
	}
	else	//プロセス時以外は待機
		Stay();
	counter++;
	
	return TASK_SUCCEEDED;
}

GAMETASK_CODE EnemyTask::Draw()
{
	DrawGraphF(x, y, GraphHandle[DirType][CurrentGraph], true);
	return TASK_SUCCEEDED;
}

bool EnemyTask::Exit()
{
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			DeleteGraph(GraphHandle[x][y]);

	return true;
}
