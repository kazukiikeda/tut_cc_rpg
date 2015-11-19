//PlayerTask.h
#pragma once

#include <DxLib.h>
#include "GameTask.h"
#include "CollisionObject.h"

class PlayerTask : public GameTask, public CollisionObject
{
private:
	const int Size_x = 48;//32
	const int Size_y = 64;//32
	int counter;
	int CurrentGraph;
	int GraphHandle[4][3];
	CHARACTER_MOVE_TYPE MoveType;
	CHARACTER_DIRECTION_TYPE DirType;
	bool jFlag;
	float y_temp = 0;
	float y_prev = 0;
public:
	PlayerTask(int x, int y);
	bool Init();
	GAMETASK_CODE Update();
	GAMETASK_CODE Draw();
	bool Exit();
	virtual int getnum();
	virtual int getX();
};