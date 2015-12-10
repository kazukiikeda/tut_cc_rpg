#include <DxLib.h>
#include "IScene.h"
#include "KeyDownChecker.h"
#include "vector"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int i = 0;
	//画面モードをウィンドウに変更
	ChangeWindowMode(true);

	//描画先を裏画面に変更
	SetDrawScreen(DX_SCREEN_BACK);

	BeforScene BEFOR = START;
	int PosX = 0;
	
	//Dxライブラリの初期化
	if (DxLib_Init() == -1)
		return -1;
	//各設定
	SetGraphMode(1280, 720, 32); //ウィンドウサイズ
	SetTransColor(255,0,255); //画像の透過色設定
	SetFontSize(32); //フォントサイズ設定

	//シーンを取得、初期化する
	std::vector<std::shared_ptr<IScene>> ExecScene{ CreateMapScene(BEFOR, PosX)};
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
				//battleシーンから戻ってきた時の処理関数が必要(敵キャラを消す)
				
				ExecScene.pop_back();
				i--;
				ExecScene[i]->callback();
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
