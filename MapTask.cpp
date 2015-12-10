#include "MapTask.h"
#include "KeyDownChecker.h"

std::shared_ptr<GameTask> CreateMapTask(int num_x, int num_y, int(*map)[], int befor)
{
	return std::make_shared<MapTask>(num_x, num_y, map, befor);
}
MapTask::MapTask(){}
MapTask::MapTask(int num_x, int num_y, int(*map)[], int befor)
{
	PosX = 32 * befor;

	memcpy(Map, map, sizeof(int) * num_x * num_y);
}

bool MapTask::Init()
{
	LoadDivGraph("Data/Map/ST-Town-E012.png", 400, 8, 50, 32, 32, GraphHandle);
	return true;
}
GAMETASK_CODE MapTask::Update()
{
	if (KeyDownChecker::GetKeyDownState(KEY_INPUT_RIGHT))
		mapDir = CHARACTER_DIR_RIGHT;
	else if (KeyDownChecker::GetKeyDownState(KEY_INPUT_LEFT))
		mapDir = CHARACTER_DIR_LEFT;

	if (KeyDownChecker::GetKeyState(KEY_INPUT_LEFT) || KeyDownChecker::GetKeyState(KEY_INPUT_RIGHT))
	switch (mapDir)
	{
	case CHARACTER_DIR_LEFT:
		PosX = PosX + speed;
		break;
	case CHARACTER_DIR_RIGHT:
		PosX = PosX - speed;
		break;
	}
	return TASK_SUCCEEDED;
}

GAMETASK_CODE MapTask::Draw()
{
	for (int x = 0; x < 60; x++)
		for (int y = 0; y < 13; y++)
		{
			DrawGraph(32 * x + PosX , 32 * y, GraphHandle[Map[x][y]], true);
		}

	return TASK_SUCCEEDED;
}

bool MapTask::Exit()
{
	for (int i = 0; i < 400; i++)
		DeleteGraph(GraphHandle[i]);

	return true;
}

int MapTask::getnum(){
	return num;
}