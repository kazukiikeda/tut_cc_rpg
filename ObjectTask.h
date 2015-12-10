// Object.h
#pragma once

#include <DxLib.h>
#include "MapTask.h"
#include "CollisionObject.h"
#include <vector>
class ObjectTask : public MapTask, public CollisionObject
{
protected:
	int GraphHandle[400];
	int ID;
	int PosY;
	CHARACTER_DIRECTION_TYPE DirType;
	 std::vector<std::vector<std::vector<int>>> ObjectHandle;
	 int dirType;
public:
	ObjectTask();
	ObjectTask(int x, int y, int id, int object_num);
	virtual bool Init();
	virtual GAMETASK_CODE Draw();
	bool Exit();
	void setDirType(int i);
	void changeDirType();
};