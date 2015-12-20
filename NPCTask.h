#pragma once

#include <DxLib.h>
#include "PlayerTask.h"
#include <vector>

typedef struct{
	int StartCount;
	int ProcessCount;
	CHARACTER_DIRECTION_TYPE Direction;
}MoveProcess;

class NPCTask : public PlayerTask
{
private:
	const int Size_x = 32;
	const int Size_y = 48;
	int GraphHandle[4][4];
	int CurrentMove;
protected:
	std::vector<MoveProcess> MoveList;
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void Stay();

public:
	NPCTask(int X, int Y, std::string id, int Object_num, std::string movepattern);
	NPCTask(int X, int Y, std::string id, int Object_num, std::string movepattern, std::string text);
	virtual bool Init();
	virtual GAMETASK_CODE Update();
	virtual GAMETASK_CODE Draw();
	virtual bool Exit();
	virtual void stop(int i);
};