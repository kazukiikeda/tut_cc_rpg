#include <DxLib.h>
#include "IScene.h"
#include "KeyDownChecker.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//画面モードをウィンドウに変更
	ChangeWindowMode(true);

	//描画先を裏画面に変更
	SetDrawScreen(DX_SCREEN_BACK);

	BeforScene BEFOR = START;
	int Posx = 0;
	
	//Dxライブラリの初期化
	if (DxLib_Init() == -1)
		return -1;
	
	SetGraphMode(1280, 720, 32);

	//シーンを取得、初期化する
	std::shared_ptr<IScene> ExecScene = CreateMapScene(BEFOR, Posx);
	ExecScene->Init();

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
		if (!ExecScene->Exec())
		{
			ExecScene->Exit();

			//次のシーンを取得
			ExecScene = ExecScene->GetNextScene();
			ExecScene->Init();
		}/**/

		//裏画面情報を表画面に転送
		ScreenFlip();
	}

	//シーンの終了処理
	ExecScene->Exit();

	//Dxライブラリの終了処理
	DxLib_End();

	return 0;
}
