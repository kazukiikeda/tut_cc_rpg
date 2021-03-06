//TitleScene.h
#pragma once

#include "IScene.h"
#include <vector>

class TitleScene : public IScene
{
private:
	int GraphHandle[400];
	std::vector<std::string> text;
public:
	bool Init();
	bool Exec();
	NextScene Next();
	bool Exit();
	std::shared_ptr<IScene> GetNextScene();
};