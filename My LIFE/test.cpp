#include"DxLib.h"
#include"Cat.h"
#include"Player1.h"

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

	SetDrawScreen(DX_SCREEN_BACK);

	Player1 player(Window_X / 2, Window_Y / 2);

	player.Player1_Image[12];
	LoadDivGraph("res/monster.png", 12, 3, 4, 64, 64, player.Player1_Image);

	while (ProcessMessage() != -1)
	{
		ClearDrawScreen();


		player.Move();

		player.Draw();

		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)
			break;


		ScreenFlip();
		
	}

	DxLib_End(); //DX���C�u�����̏I��

	return 0;
}