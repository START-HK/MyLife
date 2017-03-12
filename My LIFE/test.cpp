#include"DxLib.h"
#include"Cat.h"

#define Window_X 1280
#define Window_Y 720



int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR ipCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); //�E�B���h���[�h�̕ύX�iTRUE�̏ꍇ�̓E�B���h�E���[�h�@FALSE�ꍇ�̓t���X�N���[�����[�h�j
	SetGraphMode(Window_X, Window_Y, 32); //�E�B���h�E�̃T�C�Y�ύX

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		return-1; 
	}

	Cat cat(Window_X/2,Window_Y/2);

	int monster_image[12];
	LoadDivGraph("res / monster.png", 12, 4, 3, 64, 64, monster_image);
	
	while (ProcessMessage() != -1)
	{
		ClearDrawScreen();

		cat.Move();

		//LoadGraphScreen(cat.Get_X(), cat.Get_Y(), "res/cat.jpg",TRUE);

		DrawGraph(0, 0, monster_image[2], TRUE);

		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)
			break;


		ScreenFlip();
		
	}

	//DrawPixel(100, 240, GetColor(0, 255, 255)); //�w��Ɉʒu�Ɏw��̐F�œ_��\��

	//WaitKey(); //�����L�[��ł܂őҋ@

	DxLib_End(); //DX���C�u�����̏I��

	return 0;
}