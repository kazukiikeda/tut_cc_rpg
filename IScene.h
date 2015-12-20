//IScene.h
#pragma once

#include <memory>
#include <DxLib.h>
#include <string>
#include "GameTask.h"

enum NextScene{
	KEEP,
	NEW,
	BACK,
	STOP,
};

class IScene
{
protected:
	int num;
	bool Flag;
	std::string ID;
	int dead;
	std::string nextscene;
	int nextPosX;
	std::string scene;
public:
	virtual bool Init() = 0;
	virtual bool Exec() = 0;
	virtual NextScene Next() = 0;
	virtual bool Exit() = 0;
	virtual std::shared_ptr<IScene> GetNextScene() = 0;
	bool talkflag = false;
};

std::shared_ptr<IScene> CreateMapScene(int PosX, std::string SceneName);
std::shared_ptr<IScene> CreateTitleScene();
std::shared_ptr<IScene> CreateBattleScene(std::string id);
std::shared_ptr<IScene> CreateEventScene(std::string id);
std::shared_ptr<IScene> CreateEpilogueScene();
std::shared_ptr<IScene> CreateEndcreditsScene();