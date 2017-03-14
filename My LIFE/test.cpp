#include"DxLib.h"
#include"Cat.h"
#include"Player1.h"
#include"Book_Object.h"
#include"Console_Window.h"
#include<stdio.h>

#define Window_X 1280
#define Window_Y 720
#define Chara_Size_W 64
#define Chara_Size_H 32

bool Is_Hit(int x_1, int y_1, int w_1, int h_1, int x_2, int y_2, int w_2, int h_2);

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

	Console_Window::Create();

	Player1 player(Window_X / 2, Window_Y / 2, Chara_Size_W, Chara_Size_H);
	Book_Object book(Window_X / 2, Window_Y / 2, Chara_Size_W, Chara_Size_H);

	book.Load();

	player.Player1_Image[12];
	LoadDivGraph("res/monster.png", 12, 3, 4, 64, 64, player.Player1_Image);

	bool open_or_close = false;

	while (ProcessMessage() != -1)
	{
		ClearDrawScreen();

		book.Draw();

		player.Move();
		player.Draw();

		bool is_hit = Is_Hit(book.Get_X(), book.Get_Y(), book.Get_W(), book.Get_H(), player.Get_X(), player.Get_Y(), player.Get_W(), player.Get_H());
		

		if (is_hit)
		{
			if (CheckHitKey(KEY_INPUT_SPACE) != 0)
			{
				DrawFormatString(0, 0, GetColor(255, 255, 255), "こんばんは");
				open_or_close = !open_or_close;
			}
			else
			{
				DrawFormatString(0, 0, GetColor(255, 255, 255), "おはよう");

			}

		}

		book.Is_Hit(open_or_close);

		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)
			break;


		ScreenFlip();
		
	}

	Console_Window::Close();

	DxLib_End(); //DXライブラリの終了

	return 0;
}


bool Is_Hit(int x_1, int y_1, int w_1, int h_1, int x_2, int y_2, int w_2, int h_2)
{
	bool is_hit = false;

	if (((x_1 >= x_2 && x_1 <= x_2 + w_2) ||
		(x_2 >= x_1 && x_2 <= x_1 + w_1)) &&
		((y_1 >= y_2 && y_1 <= y_2 + h_2) ||
		(y_2 >= y_1 && y_2 <= y_1 + h_1)))
	{
		is_hit = true;

	}
	return is_hit;
}