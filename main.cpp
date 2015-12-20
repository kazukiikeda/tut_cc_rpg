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
	//��ʃ��[�h���E�B���h�E�ɕύX
	ChangeWindowMode(true);

	//�`���𗠉�ʂɕύX
	SetDrawScreen(DX_SCREEN_BACK);

	int PosX = 0;
	
	//Dx���C�u�����̏�����
	if (DxLib_Init() == -1)
		return -1;
	//�e�ݒ�
	SetGraphMode(1280, 720, 32); //�E�B���h�E�T�C�Y
	SetTransColor(255,0,255); //�摜�̓��ߐF�ݒ�
	SetFontSize(32); //�t�H���g�T�C�Y�ݒ�
	SetBackgroundColor(0, 0, 0);
	//�V�[�����擾�A����������
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
			//��ʏ�����
			ClearDrawScreen();
			DrawString(1000, 650, "Now loading", GetColor(255, 255, 255));
			ScreenFlip();
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
				ExecScene.pop_back();
				i--;
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
