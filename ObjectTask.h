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
	int PosY;
	CHARACTER_DIRECTION_TYPE DirType;
	 std::vector<std::vector<std::string>> objectHandle;
	 std::vector<std::string> col;
	 int dirType;
	 int adjY;
	 std::string buf;
public:
	ObjectTask();
	ObjectTask(int x, int y, std::string id, int object_num, std::string nextscene, int nextPosX, std::string textad);
	virtual bool Init();
	virtual GAMETASK_CODE Draw();
	bool Exit();
	void setDirType(int i);
	void changeDirType();
};