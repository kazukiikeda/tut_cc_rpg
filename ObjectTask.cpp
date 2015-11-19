#include "ObjectTask.h"
#include "KeyDownChecker.h"

std::shared_ptr<GameTask> CreateObjectTask(int x, int ID, int Object_num)
{
	return std::make_shared<ObjectTask>(x, ID, Object_num);
}
ObjectTask::ObjectTask(int x, int id, int object_num)
{
	ID = id;
	Posx = x;
	CollisionObject::id = OBJECT_DOOR;
	Object_num = object_num;
}
bool ObjectTask::Init()
{
	std::vector<std::vector<std::vector<int>>> objectHandle = {
		{ { 2, 20 }, { 235, 227, 305, 297, 289 }, { 357, 349, 306, 298, 290 }, { 235, 227, 307, 299, 291 } }
	};
	r = objectHandle[ID][0][1];
	ObjectHandle = objectHandle;
	LoadDivGraph("Data/Map/ST-Town-E012.png", 400, 8, 50, 32, 32, GraphHandle);
	return true;
}

GAMETASK_CODE ObjectTask::Update()
{
	if (KeyDownChecker::GetKeyDownState(KEY_INPUT_RIGHT))
		DirType = CHARACTER_DIR_RIGHT;
	else if (KeyDownChecker::GetKeyDownState(KEY_INPUT_LEFT))
		DirType = CHARACTER_DIR_LEFT;

	if (KeyDownChecker::GetKeyState(KEY_INPUT_LEFT) || KeyDownChecker::GetKeyState(KEY_INPUT_RIGHT))
		switch (DirType)
	{
		case CHARACTER_DIR_LEFT:
			Scx = Scx + 4;
			break;
		case CHARACTER_DIR_RIGHT:
			Scx = Scx - 4;
			break;
	}
	CollisionObject::x = 32 * (Posx + ObjectHandle[ID][0][0]) + Scx;
	return TASK_SUCCEEDED;
}

GAMETASK_CODE ObjectTask::Draw()
{
	for (int x = 1; x < ObjectHandle[ID].size() ; x++){
		for (int y = 0; y < ObjectHandle[ID][x].size(); y++){
			DrawGraph(32 * (Posx + x) + Scx, 32 * (11 - y), GraphHandle[ObjectHandle[ID][x][y]], true);
		}
	}
	return TASK_SUCCEEDED;
}

bool ObjectTask::Exit()
{
	for (int i = 0; i < 400; i++)
		DeleteGraph(GraphHandle[i]);
	return true;
}
int ObjectTask::getnum(){
	return num;
}
int ObjectTask::getX(){
	return Scx;
}