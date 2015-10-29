// Object.h
#pragma once

#include <DxLib.h>
#include "GameTask.h"
#include "CollisionObject.h"
#include <vector>
class ObjectTask : public GameTask, public CollisionObject
{
private:
	CHARACTER_DIRECTION_TYPE DirType;
protected:
	int GraphHandle[400];
	int ID;
	int Posx;
	 std::vector<std::vector<std::vector<int>>> ObjectHandle;
public:
	ObjectTask(int x, int id, int object_num);
	virtual bool Init();
	virtual GAMETASK_CODE Update();
	virtual GAMETASK_CODE Draw();
	bool Exit();
	virtual int getnum();
};