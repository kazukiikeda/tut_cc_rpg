//TitleScene.cpp
#include "TitleScene.h"
#include "KeyDownChecker.h"
#include <fstream>

std::shared_ptr<IScene> CreateTitleScene()
{
	return std::make_shared<TitleScene>();
}

bool TitleScene::Init()
{
	std::ifstream ifs;
	ifs.open("Data/Title/TitleInfo.txt");
	std::string str;
	while (getline(ifs, str))
	{
		text.push_back(str);
	}
	ifs.close();
	int Sizex, Sizey, Gr;
	Gr = LoadGraph(text.at(0).c_str());
	GetGraphSize(Gr, &Sizex, &Sizey);
	LoadDivGraph(text.at(0).c_str(), (Sizex * Sizey) / (32 * 32), Sizex / 32, Sizey / 32, 32, 32, GraphHandle);

	return true;
}

bool TitleScene::Exec()
{
	for (int x = 0; x < 40; x++)
	for (int y = 0; y < 23; y++)
	{
		DrawGraph(32 * x, 32 * y, GraphHandle[std::stoi(text.at(1))], true);
	}
	int Cr = GetColor(255, 255, 255);
	SetFontSize(std::stoi(text.at(3))); //フォントサイズ設定
	DrawString((1280 - text.at(2).length() * std::stoi(text.at(3))/2) / 2, std::stoi(text.at(4)), text.at(2).c_str(), Cr);
	SetFontSize(std::stoi(text.at(6))); //フォントサイズ設定
	DrawString((1280 - text.at(5).length() * std::stoi(text.at(6))/2) / 2, std::stoi(text.at(7)), text.at(5).c_str(), Cr);
	if (KeyDownChecker::GetKeyDownState(KEY_INPUT_Q))
		return false;

	return true;
}
NextScene TitleScene::Next(){
	SetFontSize(32); //フォントサイズ設定
	return KEEP;
}
bool TitleScene::Exit()
{
	return true;
}

std::shared_ptr<IScene> TitleScene::GetNextScene()
{
	return CreateMapScene(19, "HOUSE");
}