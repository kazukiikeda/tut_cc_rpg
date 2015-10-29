#include <DxLib.h>
#include "IScene.h"
#include "KeyDownChecker.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//��ʃ��[�h���E�B���h�E�ɕύX
	ChangeWindowMode(true);

	//�`���𗠉�ʂɕύX
	SetDrawScreen(DX_SCREEN_BACK);

	BeforScene BEFOR = START;
	int Posx = 0;
	
	//Dx���C�u�����̏�����
	if (DxLib_Init() == -1)
		return -1;
	
	SetGraphMode(1280, 720, 32);

	//�V�[�����擾�A����������
	std::shared_ptr<IScene> ExecScene = CreateMapScene(BEFOR, Posx);
	ExecScene->Init();

	//�L�[���̓`�F�b�N�N���X���쐬
	KeyDownChecker* Checker = KeyDownChecker::GetInstance();

	//�Q�[�����[�v
	while (!ProcessMessage())
	{
		//��ʏ�����
		ClearDrawScreen();

		//�L�[����
		Checker->CheckKeyState();

		//�V�[�������s����
		if (!ExecScene->Exec())
		{
			ExecScene->Exit();

			//���̃V�[�����擾
			ExecScene = ExecScene->GetNextScene();
			ExecScene->Init();
		}/**/

		//����ʏ���\��ʂɓ]��
		ScreenFlip();
	}

	//�V�[���̏I������
	ExecScene->Exit();

	//Dx���C�u�����̏I������
	DxLib_End();

	return 0;
}
