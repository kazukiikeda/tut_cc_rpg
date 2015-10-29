//TitleScene.cpp
#include "TitleScene.h"
#include "KeyDownChecker.h"

std::shared_ptr<IScene> CreateTitleScene()
{
	return std::make_shared<TitleScene>();
}

bool TitleScene::Init()
{
	OutputDebugString("TitleScene::Init()\n");

	return true;
}

bool TitleScene::Exec()
{
	OutputDebugString("TitleScene::Exec()\n");
	int Cr = GetColor(0, 0, 0);
	DrawString(500, 500, "TitleScene", Cr);
	if (KeyDownChecker::GetKeyDownState(KEY_INPUT_Z))
		return false;

	return true;
}

bool TitleScene::Exit()
{
	OutputDebugString("TitleScene::Exit()\n");
	return true;
}

std::shared_ptr<IScene> TitleScene::GetNextScene()
{
	return CreateMapScene(START, 0);
}