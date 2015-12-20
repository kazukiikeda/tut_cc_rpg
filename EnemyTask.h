//EnemyTask.h
#pragma once

#include <DxLib.h>
#include "NPCTask.h"
#include <vector>

class EnemyTask : public NPCTask
{
private:
	const int Size_x = 32;
	const int Size_y = 48;
	int GraphHandle[4][4];
	bool Flag;
public:
	EnemyTask(int X, int Y, std::string id, int Object_num, std::string movepattern);
	bool Init();
	virtual GAMETASK_CODE Draw();
	virtual bool Exit();
	void dead();
};