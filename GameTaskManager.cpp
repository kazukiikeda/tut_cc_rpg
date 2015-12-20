//GameTaskManager.cpp
#include "GameTask.h"

bool GameTaskManager::Init()
{
	bool flag = true;
	for (auto it : TaskList)
		flag &= it->Init();

	return flag;
}

GAMETASK_CODE GameTaskManager::Update()
{
	GAMETASK_CODE ReturnCode = TASK_SUCCEEDED;

	//Update‚ğÀs‚·‚é
	std::list<std::shared_ptr<GameTask>>::iterator it;
	for (it = TaskList.begin(); it != TaskList.end();)
	{
		GAMETASK_CODE code = (*it)->Update();
		
		it++;
	}
	
	return ReturnCode;
}

GAMETASK_CODE GameTaskManager::Draw()
{
	GAMETASK_CODE ReturnCode = TASK_SUCCEEDED;

	//Draw‚ğÀs‚·‚é
	std::list<std::shared_ptr<GameTask>>::iterator it;
	for (it = TaskList.begin(); it != TaskList.end();)
	{
		GAMETASK_CODE code = (*it)->Draw();

		it++;
	}

	return ReturnCode;
}

bool GameTaskManager::Exit()
{
	bool flag = true;
	for (auto it : TaskList)
		flag &= it->Exit();

	return flag;
}

void GameTaskManager::EntryTask(std::shared_ptr<GameTask> task)
{
	TaskList.push_back(task);
}

int GameTaskManager::getnum(){
	return num;
}
std::string GameTaskManager::getID(){
	return ID;
}
std::string GameTaskManager::getNext(){
	return next;
}
std::string GameTaskManager::getText(){
	return text;
}
int GameTaskManager::getNextX(){
	return nextPosX;
}
void GameTaskManager::stop(int i){
	std::list<std::shared_ptr<GameTask>>::iterator it;
	for (it = TaskList.begin(); it != TaskList.end();)
	{
		(*it)->stop(i);
		it++;
	}
}