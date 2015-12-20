#include "ScrollingTextTask.h"
#include <vector>
#include <string>
#include <fstream>

std::shared_ptr<GameTask> CreateScrollingTextTask(std::string textad)
{
	return std::make_shared<ScrollingTextTask>(textad);
}
ScrollingTextTask::ScrollingTextTask(std::string textad)
{
	std::ifstream ifs;
	ifs.open("Data/TEXT/"+ textad +".txt");
	std::string str;
	while (getline(ifs, str))
	{
		talk.push_back(str);
	}
	ifs.close();
	PosY = (14 + talk.size()) / 2;
	PosX = 1;
	Cr = GetColor(255, 255, 255);
	num = 0;
	Line = 0;
}
bool ScrollingTextTask::Init()
{
	return true;
}

GAMETASK_CODE ScrollingTextTask::Update()
{

	return TASK_SUCCEEDED;
}
GAMETASK_CODE ScrollingTextTask::Draw()
{
	Line = 0;
	if (talk.size() > Line){
		if (num > 13){
			num = 0;
			ClearDrawScreen();
		}
		for (int i = 0; i < num; i++)
		DrawString(PosX * 32, (PosY + i) * 32, talk.at(Line).c_str(), Cr);
			Line++;
	}
	return TASK_SUCCEEDED;
}
bool ScrollingTextTask::Exit()
{
	return true;
}