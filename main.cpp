#include <DxLib.h>
#include "IScene.h"
#include "KeyDownChecker.h"
#include "vector"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int i = 0;
	//��ʃ��[�h���E�B���h�E�ɕύX
	ChangeWindowMode(true);

	//�`���𗠉�ʂɕύX
	SetDrawScreen(DX_SCREEN_BACK);

	BeforScene BEFOR = START;
	int PosX = 0;
	
	//Dx���C�u�����̏�����
	if (DxLib_Init() == -1)
		return -1;
	//�e�ݒ�
	SetGraphMode(1280, 720, 32); //�E�B���h�E�T�C�Y
	SetTransColor(255,0,255); //�摜�̓��ߐF�ݒ�
	SetFontSize(32); //�t�H���g�T�C�Y�ݒ�

	//�V�[�����擾�A����������
	std::vector<std::shared_ptr<IScene>> ExecScene{ CreateMapScene(BEFOR, PosX)};
	ExecScene[i]->Init();

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
		if (!ExecScene[i]->Exec())
		{
			ExecScene[i]->Exit();
			
			//���̃V�[�����擾
			if (ExecScene[i]->Next() == KEEP){
				ExecScene[i] = ExecScene[i]->GetNextScene();
			}
			else if (ExecScene[i]->Next() == NEW){
				ExecScene.push_back(ExecScene[i]->GetNextScene());
				i++;
			}
			else if (ExecScene[i]->Next() == BACK){
				//battle�V�[������߂��Ă������̏����֐����K�v(�G�L����������)
				
				ExecScene.pop_back();
				i--;
				ExecScene[i]->callback();
			}
			
			ExecScene[i]->Init();
		}

		//����ʏ���\��ʂɓ]��
		ScreenFlip();
	}

	//�V�[���̏I������
	ExecScene[i]->Exit();

	//Dx���C�u�����̏I������
	DxLib_End();

	return 0;
}
