#pragma once

#include <DxLib.h>
#include "MapTask.h"
#include <string>
#include <vector>

class ScrollingTextTask : public MapTask
{
private:
	std::vector<std::string> talk;
	int PosY;
	int Cr;
	int num;
	int Line;
public:
	ScrollingTextTask(std::string textad);
	virtual bool Init();
	virtual GAMETASK_CODE Update();
	virtual GAMETASK_CODE Draw();
	bool Exit();
};