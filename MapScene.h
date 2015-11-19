//MapScene.h
#pragma once

#include "IScene.h"
#include "GameTask.h"
#include "vector"

class MapScene : public IScene
{
protected:
	bool ExitFlag;
	std::shared_ptr<GameTask> Root;
	GAMETASK_CODE code;
	int PosX;
	std::shared_ptr<GameTaskManager> task;
public:
	MapScene(std::shared_ptr<GameTask> roottask, int x);
	bool Init();
	bool Exec();
	NextScene Next();
	bool Exit();
	virtual std::shared_ptr<IScene> GetNextScene();
};