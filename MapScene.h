//MapScene.h
#pragma once

#include "IScene.h"
#include "GameTask.h"

class MapScene : public IScene
{
protected:
	bool ExitFlag;
	std::shared_ptr<GameTask> Root;
	GAMETASK_CODE code;
	bool TalkFlag;

public:
	MapScene(std::shared_ptr<GameTask> roottask);
	bool Init();
	bool Exec();
	bool Exit();
	virtual std::shared_ptr<IScene> GetNextScene();
};