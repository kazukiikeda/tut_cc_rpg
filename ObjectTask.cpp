#include "ObjectTask.h"
#include "KeyDownChecker.h"

std::shared_ptr<GameTask> CreateObjectTask(int x, int y, int ID, int Object_num)
{
	return std::make_shared<ObjectTask>(x, y, ID, Object_num);
}
ObjectTask::ObjectTask(){}
ObjectTask::ObjectTask(int x, int y, int id, int object_num)
{
	ID = id;
	PosX = x * 32;
	PosY = y * 32;
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

GAMETASK_CODE ObjectTask::Draw()
{
	CollisionObject::x = PosX + 32 * ObjectHandle[ID][0][0];
	for (int x = 1; x < ObjectHandle[ID].size() ; x++){
		for (int y = 0; y < ObjectHandle[ID][x].size(); y++){
			DrawGraph(x * 32 + PosX, PosY - 32 * y, GraphHandle[ObjectHandle[ID][x][y]], true);
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

void ObjectTask::setDirType(int i){
	//dirType = i;
	DirType = (CHARACTER_DIRECTION_TYPE)i;
}