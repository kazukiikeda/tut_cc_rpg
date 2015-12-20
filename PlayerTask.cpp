#include "PlayerTask.h"
#include "KeyDownChecker.h"

std::shared_ptr<GameTask> CreatePlayerTask(int x, int y)
{
	return std::make_shared<PlayerTask>(x, y);
}

PlayerTask::PlayerTask(int X, int Y)
{
	r = 16;
	id = OBJECT_PLAYER;
	jFlag = false;
	x = (float)X * (float)Size_x;
	y = (float)Y * (float)Size_y;
	DirType = CHARACTER_DIR_UP;
	CurrentGraph = 0;
	counter = 0;
}

bool PlayerTask::Init()
{
	int tmp[16];
	LoadDivGraph("Data/player.bmp", 16, 4, 4, Size_x, Size_y, tmp);
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			GraphHandle[y][x] = tmp[4 * y + x];

	return true;
}

GAMETASK_CODE PlayerTask::Update()
{
	//ƒLƒƒƒ‰•ûŒü‚ðÝ’è
	if (KeyDownChecker::GetKeyDownState(KEY_INPUT_LEFT))
	{
		DirType = CHARACTER_DIR_LEFT;
	}
	
	else if (KeyDownChecker::GetKeyDownState(KEY_INPUT_RIGHT))
	{
		DirType = CHARACTER_DIR_RIGHT;
	}
	
	if (jFlag){
		y_temp = y;
		y += (y - y_prev) + 1;
		y_prev = y_temp;
		if (y == 336 )
			jFlag = false;
	}
	if (KeyDownChecker::GetKeyDownState(KEY_INPUT_UP) && jFlag == false){
		jFlag = true;
		y_prev = y;
		y = y - 20;
	}
	//ƒLƒƒƒ‰ˆÚ“®
	if (KeyDownChecker::GetKeyState(KEY_INPUT_LEFT)	 ||KeyDownChecker::GetKeyState(KEY_INPUT_RIGHT))
	{
		counter++;
		if (counter % 20 == 1){
			CurrentGraph = (CurrentGraph == 1 ? 3 : 1);
		}
		//‰æ–ÊŠO”»’è
		if (x < 0)
			x++;
		else if (x > 600)
			x--;
	}
	else
	{
		counter = 0;
		CurrentGraph = 0;
	}
	return TASK_SUCCEEDED;
}

GAMETASK_CODE PlayerTask::Draw()
{
	DrawGraphF(x, y, GraphHandle[DirType][CurrentGraph], true);

	return TASK_SUCCEEDED;
}

bool PlayerTask::Exit()
{
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			 DeleteGraph(GraphHandle[x][y]);

	return true;
}