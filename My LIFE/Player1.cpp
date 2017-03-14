#include "Player1.h"
#include"DxLib.h"


Player1::Player1(int x,int y,int w,int h)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;

	ic = 0;
	fc = 0;
	i = 0;  
	state = Player1::State::Down;
}

Player1::Player1()
{
	ic = 0;
	fc = 0;
	i = 0;
	state = Player1::State::Down;
}

Player1::~Player1()
{
}

int Player1::Get_X()
{
	return m_x;
}

int Player1::Get_Y()
{
	return m_y;
}

int Player1::Get_W()
{
	return m_w;
}

int Player1::Get_H()
{
	return m_h;
}

void Player1::Move()
{

	if (CheckHitKey(KEY_INPUT_RIGHT) != 0)
	{
		if (state!= State::Right)
		{
			ic = 6;
		}
		state = Player1::State::Right;
		m_x += 1;
	}

	else if (CheckHitKey(KEY_INPUT_LEFT) != 0)
	{
		if (state != State::Left)
		{
			ic = 3;
		}
		state = Player1::State::Left;
		m_x -= 1;
	}

	else if (CheckHitKey(KEY_INPUT_UP) != 0)
	{
		if (state != State::Up)
		{
			ic = 9;
		}
		state = Player1::State::Up;
    	m_y -= 1;
	}

	else if (CheckHitKey(KEY_INPUT_DOWN) != 0)
	{
		if (state != State::Down)
		{
			ic = 0;
		}
		state = Player1::State::Down;
		m_y += 1;
	}
}

void Player1::Draw()
{
	fc += 1;
	if (fc == 10)
	{
		ic += 1;

		fc = 0;
	}
	switch (state)
	{
	case Player1::Right:
		if (ic == 8)
		{
			ic = 6;
		}
		break;
	case Player1::Left:
		if (ic == 5)
		{
			ic = 3;
		}
	break;
	case Player1::Up:
		if (ic == 11)
		{
			ic = 9;
		}
	break;
	case Player1::Down:
		if (ic == 2)
		{
			ic = 0;
		}
		break;
	default:
		break;
	}

	int x = Get_X() - (Get_W() / 2);
	int y = Get_Y() - (Get_H() / 2);

	DrawGraph(x, y, Player1_Image[ic], TRUE);

}
