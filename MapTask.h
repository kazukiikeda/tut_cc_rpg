//MapTask.h
#pragma once

#include <DxLib.h>
#include "GameTask.h"

class MapTask : public GameTask
{
private:
	CHARACTER_DIRECTION_TYPE DirType;
protected:
	int Map[100][15];
	int GraphHandle[400];
public:
	MapTask(int num_x, int num_y, int(*map)[], int befor);
	virtual bool Init();
	virtual GAMETASK_CODE Update();
	virtual GAMETASK_CODE Draw();
	bool Exit();
	virtual int getnum();
	virtual int getX();
};