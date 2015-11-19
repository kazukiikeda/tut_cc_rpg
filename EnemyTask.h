//EnemyTask.h
#pragma once

#include <DxLib.h>
#include "NPCTask.h"
#include "CollisionObject.h"
#include <vector>

class EnemyTask : public NPCTask
{
private:
public:
	EnemyTask(int X, int id, int Object_num, int movepattern);
	bool Init();
	virtual GAMETASK_CODE Update();
	virtual GAMETASK_CODE Draw();
	virtual bool Exit();
};