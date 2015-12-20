#pragma once
#include "IScene.h"
#include <vector>

class EndcreditsScene : public IScene
{
private:
	std::shared_ptr<GameTask> root;
	std::vector<std::string> talk;
	int PosX;
	int PosY;
	int cnt;
public:
	EndcreditsScene();
	bool Init();
	bool Exec();
	NextScene Next();
	bool Exit();
	std::shared_ptr<IScene> GetNextScene();
};