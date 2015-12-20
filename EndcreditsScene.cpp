#include "EndcreditsScene.h"
#include "KeyDownChecker.h"
#include <fstream>
#include <vector>
#include <string>

std::shared_ptr<IScene> CreateEndcreditsScene()
{
	return std::make_shared<EndcreditsScene>();
}
EndcreditsScene::EndcreditsScene(){
	std::ifstream ifs;
	std::string str;
	ifs.open("Data/TEXT/Credits.txt");
	while (getline(ifs, str))
	{
		talk.push_back(str);
	}
	ifs.close();
	PosY = 0;
}
bool EndcreditsScene::Init(){
	return true;
}
bool EndcreditsScene::Exec(){
	int Cr = GetColor(255, 255, 255);
	if (PosY < talk.size() * 32 + 940){
		for (int i = 0; i < talk.size(); i++){
			DrawString((1280 - talk.at(i).length() * 16) / 2, (25 + i) * 32 - PosY, talk.at(i).c_str(), Cr);
		}
		cnt++;
	}
	else{
		SetFontSize(64); //フォントサイズ設定
		DrawString(584, 320, "Fin", Cr);
		if (CheckHitKey(KEY_INPUT_Q)){
			SetFontSize(32);
			return false;
		}
	}
	PosY++;
	return true;
}
NextScene EndcreditsScene::Next(){
	return KEEP;
}
bool EndcreditsScene::Exit(){
	return true;
}
std::shared_ptr<IScene> EndcreditsScene::GetNextScene(){
	return CreateTitleScene();
}