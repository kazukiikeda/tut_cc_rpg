//MapTask.h
#pragma once

#include <DxLib.h>
#include <string>
#include "GameTask.h"
enum MAP_DIRECTION{
	LEFT,
	RIGHT,
};
class MapTask : public GameTask
{
private:
	int Map[100][15];
	int GraphHandle[400];
protected:
	int PosX;
	CHARACTER_DIRECTION_TYPE mapDir;
	const int speed = 4;
	int width;
	int handle;
public:
	MapTask();
	MapTask(int num_x, int num_y, int(*map)[], int befor, std::string id);
	virtual bool Init();
	virtual GAMETASK_CODE Update();
	virtual GAMETASK_CODE Draw();
	bool Exit();
	int getnum();
	std::string getID();
	std::string getNext();
	std::string getText();
	int getNextX();
	virtual int checker(){ return 0; };
	virtual void stop(int i);
};