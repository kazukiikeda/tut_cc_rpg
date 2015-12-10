#include "NPCTask.h"
#include "KeyDownChecker.h"
#include <vector>

std::shared_ptr<GameTask> CreateNPCTask(int x, int y, int ID, int movepattern,  int Object_num)
{
	return std::make_shared<NPCTask>(x, y, ID, Object_num, movepattern);
}

void NPCTask::MoveLeft()
{
	DirType = CHARACTER_DIR_RIGHT;
	x--;

	if (counter % 20 == 1)
		CurrentGraph = (CurrentGraph == 1 ? 3 : 1);
}

void NPCTask::MoveRight()
{
	DirType = CHARACTER_DIR_DOWN;
	x++;

	if (counter % 20 == 1)
		CurrentGraph = (CurrentGraph == 1 ? 3 : 1);
}

void NPCTask::MoveUp()
{
	DirType = CHARACTER_DIR_LEFT;
	y--;

	if (counter % 20 == 1)
		CurrentGraph = (CurrentGraph == 1 ? 3 : 1);
}

void NPCTask::MoveDown()
{
	DirType = CHARACTER_DIR_UP;
	y++;

	if (counter % 20 == 1)
		CurrentGraph = (CurrentGraph == 1 ? 3 : 1);
}

void NPCTask::Stay()
{
	CurrentGraph = 0;
}

NPCTask::NPCTask(int X, int Y, int id, int object_num, int movepattern) : PlayerTask(X, Y)
{
	
	CollisionObject::id = OBJECT_NPC;
	Object_num = object_num;
	x = (float)X * (float)Size_x;
	y = (float)Y * (float)Size_y;
	r = 16;
	ID = id;
	std::vector<std::vector<std::vector<int>>> Movepattern = {
		{ {0}, {0}, {0} },
		{ { 50, 100 }, { 30, 30 }, { 3, 1 } },
		{ { 120, 260 }, { 128, 128 }, { 3, 1} }
	};

	for (int i = 0; i < Movepattern[movepattern][0].size(); i++)
	{
		MoveProcess Process;
		Process.StartCount = Movepattern[movepattern][0][i];
		Process.ProcessCount = Movepattern[movepattern][1][i];
		Process.Direction = (CHARACTER_DIRECTION_TYPE)Movepattern[movepattern][2][i];
		MoveList.push_back(Process);
	}
	CurrentMove = 0;
	
}

bool NPCTask::Init()
{
	int tmp[16];
	switch (ID){
	case 0:
		LoadDivGraph("Data/Character/NPC1.bmp", 16, 4, 4, Size_x, Size_y, tmp);
		break;
	case 1:
		LoadDivGraph("Data/Character/char_skeleton.bmp", 16, 4, 4, Size_x, Size_y, tmp);
		break;
	}
	for (int x = 0; x < 4; x++)
	for (int y = 0; y < 4; y++)
		GraphHandle[y][x] = tmp[4 * y + x];
	return true;
}

GAMETASK_CODE NPCTask::Update()
{
	if (KeyDownChecker::GetKeyDownState(KEY_INPUT_RIGHT))
		mapDir = CHARACTER_DIR_RIGHT;
	else if (KeyDownChecker::GetKeyDownState(KEY_INPUT_LEFT))
		mapDir = CHARACTER_DIR_LEFT;

	if (KeyDownChecker::GetKeyState(KEY_INPUT_LEFT) || KeyDownChecker::GetKeyState(KEY_INPUT_RIGHT))
		switch (mapDir)
	{
		case CHARACTER_DIR_LEFT:
			x = x + speed;
			break;
		case CHARACTER_DIR_RIGHT:
			x = x - speed;
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

GAMETASK_CODE NPCTask::Draw()
{
		DrawGraphF(x, y, GraphHandle[DirType][CurrentGraph], true);
	return TASK_SUCCEEDED;
}

bool NPCTask::Exit()
{
	for (int x = 0; x < 4; x++)
	for (int y = 0; y < 4; y++)
		DeleteGraph(GraphHandle[x][y]);
	return true;
}