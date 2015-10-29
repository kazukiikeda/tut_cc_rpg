//EnemyTask.h
#pragma once

#include <DxLib.h>
#include "ObjectTask.h"
#include "CollisionObject.h"
#include <vector>

typedef struct{
	int StartCount;
	int ProcessCount;
	CHARACTER_DIRECTION_TYPE Direction;
}MoveProcess;

class EnemyTask : public ObjectTask
{
private:
	const int Size_x = 32;
	const int Size_y = 48;
	int counter;
	int CurrentGraph;
	int GraphHandle[4][4];
	CHARACTER_MOVE_TYPE MoveType;
	CHARACTER_DIRECTION_TYPE DirType;
	int mapDir = 0;

	std::vector<MoveProcess> MoveList;
	int CurrentMove;

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void Stay();

public:
	//EnemyTask(int x, int y, int ProcessNum, int Start[], int Time[], CHARACTER_DIRECTION_TYPE Dir[], int befor);
	EnemyTask(int X, int id, int Object_num, int movepatern, bool flag);
	bool Init();
	GAMETASK_CODE Update();
	GAMETASK_CODE Draw();
	bool Exit();
};