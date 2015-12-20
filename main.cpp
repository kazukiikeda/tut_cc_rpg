#include <DxLib.h>
#include "IScene.h"
#include "KeyDownChecker.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int i = 0;
	//画面モードをウィンドウに変更
	ChangeWindowMode(true);

	//描画先を裏画面に変更
	SetDrawScreen(DX_SCREEN_BACK);

	int PosX = 0;
	
	//Dxライブラリの初期化
	if (DxLib_Init() == -1)
		return -1;
	//各設定
	SetGraphMode(1280, 720, 32); //ウィンドウサイズ
	SetTransColor(255,0,255); //画像の透過色設定
	SetFontSize(32); //フォントサイズ設定
	SetBackgroundColor(0, 0, 0);
	//シーンを取得、初期化する
	std::fstream ifs;
	std::string str;
	ifs.open("Data/StartPoint.txt");
	getline(ifs,str);
	std::stringstream stream(str);
	std::string dumy;
	std::vector<std::string> buffer;
	int j = 0;
	while (getline(stream, dumy, ',')){
		if (j == 0)
			buffer.push_back(dumy);
		if (j == 1)
			buffer.push_back(dumy);
		j++;
	}
	ifs.close();
	std::vector<std::shared_ptr<IScene>> ExecScene;
	if (buffer.at(1) == "EPILOG")
		ExecScene.push_back(CreateEpilogueScene());
	else if (buffer.at(1) == "END")
		ExecScene.push_back(CreateEndcreditsScene());
	else if (buffer.at(1) == "TITLE")
		ExecScene.push_back(CreateTitleScene());
	else
		ExecScene.push_back(CreateMapScene(std::stoi(buffer.at(0)), buffer.at(1)));
	ExecScene[i]->Init();

	//キー入力チェッククラスを作成
	KeyDownChecker* Checker = KeyDownChecker::GetInstance();

	//ゲームループ
	while (!ProcessMessage())
	{
		//画面初期化
		ClearDrawScreen();

		//キー入力
		Checker->CheckKeyState();

		//シーンを実行する
		if (!ExecScene[i]->Exec())
		{
			//画面初期化
			ClearDrawScreen();
			DrawString(1000, 650, "Now loading", GetColor(255, 255, 255));
			ScreenFlip();
			ExecScene[i]->Exit();
			
			//次のシーンを取得
			if (ExecScene[i]->Next() == KEEP){
				ExecScene[i] = ExecScene[i]->GetNextScene();
			}
			else if (ExecScene[i]->Next() == NEW){
				ExecScene.push_back(ExecScene[i]->GetNextScene());
				i++;
			}
			else if (ExecScene[i]->Next() == BACK){
				ExecScene.pop_back();
				i--;
			}			
			ExecScene[i]->Init();
		}
		//裏画面情報を表画面に転送
		ScreenFlip();
	}

	//シーンの終了処理
	ExecScene[i]->Exit();

	//Dxライブラリの終了処理
	DxLib_End();

	return 0;
}
