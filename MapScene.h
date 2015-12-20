//MapScene.h
#pragma once

#include "IScene.h"
#include "GameTask.h"
#include "vector"
#include "GameTask.h"
class MapScene : public IScene
{
protected:
	bool ExitFlag;
	bool EventFlag;
	std::shared_ptr<GameTask> Root;
	GAMETASK_CODE code;
public:
	MapScene();
	MapScene(std::shared_ptr<GameTask> roottask, std::string Scenename);
	bool Init();
	bool Exec();
	bool Exit();
	virtual NextScene Next();
	virtual std::shared_ptr<IScene> GetNextScene();
};