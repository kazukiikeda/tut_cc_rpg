#include "EnemyTask.h"
#include "KeyDownChecker.h"
#include <vector>

std::shared_ptr<GameTask> CreateEnemyTask(int x, int ID, int movepattern, int Object_num)
{
	return std::make_shared<EnemyTask>(x, ID, Object_num, movepattern);
}
EnemyTask::EnemyTask(int X, int id, int object_num, int movepattern) : NPCTask(x, id, Object_num, movepattern)
{
	
	CollisionObject::id = OBJECT_ENEMY;
	r = 16;
	x = (float)X * (float)Size_x;//15
	y = (float)7 * (float)Size_y;//12
	r = 16;
	Flag = true;
}

bool EnemyTask::Init()
{
	int tmp[16];
	switch (ID){
	case 0:
		LoadDivGraph("Data/Character/Enemy.bmp", 16, 4, 4, Size_x, Size_y, tmp);
		break;
	case 1:
		LoadDivGraph("Data/Character/char_skeleton.bmp", 16, 4, 4, Size_x, Size_y, tmp);
		break;
	}
	for (int x = 0; x < 4; x++)
	for (int y = 0; y < 4; y++)
		GraphHandle[y][x] = tmp[4 * y + x];
	/*
	if (Flag == false){
		x = 0;
		y = 0;
		r = 0;
		Posx = 0;
	}*/
	return true;
}
GAMETASK_CODE EnemyTask::Update()
{
	if (KeyDownChecker::GetKeyDownState(KEY_INPUT_RIGHT))
		mapDir = 1;
	else if (KeyDownChecker::GetKeyDownState(KEY_INPUT_LEFT))
		mapDir = 2;

	if (KeyDownChecker::GetKeyState(KEY_INPUT_LEFT) || KeyDownChecker::GetKeyState(KEY_INPUT_RIGHT))
		switch (mapDir)
	{
		case 2:
			x = x + 4;
			break;
		case 1:
			x = x - 4;
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