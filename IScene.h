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
	int befornum;
	bool Flag;
	int ID;
public:
	virtual bool Init() = 0;
	virtual bool Exec() = 0;
	virtual NextScene Next() = 0;
	virtual bool Exit() = 0;
	virtual std::shared_ptr<IScene> GetNextScene() = 0;
	bool talkflag = false;
};

std::shared_ptr<IScene> CreateMapScene(BeforScene BEFOR, int Posx);
std::shared_ptr<IScene> CreateTitleScene();
std::shared_ptr<IScene> CreateBattleScene(int Object_num);