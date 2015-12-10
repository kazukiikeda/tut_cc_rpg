#include "EnemyTask.h"
#include "KeyDownChecker.h"
#include <vector>

std::shared_ptr<GameTask> CreateEnemyTask(int x, int y, int ID, int movepattern, int Object_num)
{
	return std::make_shared<EnemyTask>(x, y, ID, Object_num, movepattern);
}
EnemyTask::EnemyTask(int X, int Y, int id, int object_num, int movepattern) : NPCTask(x, y, id, Object_num, movepattern)
{
	CollisionObject::id = OBJECT_ENEMY;
	r = 16;
	x = (float)X * (float)Size_x;
	y = (float)Y * (float)Size_y;
	Object_num = object_num;
	Flag = true;
}

bool EnemyTask::Init()
{
	if (Flag){
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
	}
	return true;
}

GAMETASK_CODE EnemyTask::Draw()
{
	if (Flag){
		DrawGraphF(x, y, GraphHandle[DirType][CurrentGraph], true);
	}
	return TASK_SUCCEEDED;
}
bool EnemyTask::Exit()
{
	if (Flag){
		for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			DeleteGraph(GraphHandle[x][y]);
	}
	return true;
}
void EnemyTask::dead(){
	Flag = false;
	x = 0;
	y = 0;
	r = 0;
}