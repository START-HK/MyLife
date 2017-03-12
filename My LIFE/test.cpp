#include"DxLib.h"
#include"Cat.h"
#include"Player1.h"

#define Window_X 1280
#define Window_Y 720



int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR ipCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); //ウィンドモードの変更（TRUEの場合はウィンドウモード　FALSE場合はフルスクリーンモード）
	SetGraphMode(Window_X, Window_Y, 32); //ウィンドウのサイズ変更

	//DXライブラリの初期化
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

	DxLib_End(); //DXライブラリの終了

	return 0;
}