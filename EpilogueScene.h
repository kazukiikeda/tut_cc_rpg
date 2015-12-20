#pragma once
#include "IScene.h"
#include <vector>

class EpilogueScene : public IScene
{
private:
	std::vector<std::string> talk;
	int cnt;
public:
	EpilogueScene();
	bool Init();
	bool Exec();
	NextScene Next();
	bool Exit();
	std::shared_ptr<IScene> GetNextScene();
};