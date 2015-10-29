//IScene.h
#pragma once

#include <memory>
#include <DxLib.h>

enum BeforScene{
	START,
	BATTLE,
	MAP,
	HOUSE,
	LEFT,
	RIGHT,
};

class IScene
{
protected:
	int num = 0;
public:
	virtual bool Init() = 0;
	virtual bool Exec() = 0;
	virtual bool Exit() = 0;
	virtual std::shared_ptr<IScene> GetNextScene() = 0;
};

std::shared_ptr<IScene> CreateMapScene(BeforScene BEFOR, int Posx);
std::shared_ptr<IScene> CreateTitleScene();