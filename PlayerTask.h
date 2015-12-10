//PlayerTask.h
#pragma once

#include <DxLib.h>
#include "ObjectTask.h"

class PlayerTask : public ObjectTask
{
private:
	const int Size_x = 48;
	const int Size_y = 64;
	int GraphHandle[4][3];
protected:
	//CHARACTER_DIRECTION_TYPE DirType;
	int counter;
	int CurrentGraph;
	bool jFlag;
	float y_temp = 0;
	float y_prev = 0;
public:
	PlayerTask(int x, int y);
	bool Init();
	GAMETASK_CODE Update();
	GAMETASK_CODE Draw();
	bool Exit();
};