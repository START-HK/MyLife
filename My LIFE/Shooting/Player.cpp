#include "Player.h"
#include"DxLib.h"
#include"../InputManager.h"
#include"define.h"

#define Ok_Window(x) MessageBox(NULL, x, NULL, MB_OK);
#define Player_Speed 3
#define Left_Image_Min 3
#define Left_Image_Max 5
#define Right_Image_Min 6
#define Right_Image_Max 8
#define Up_Image_Min 9
#define Up_Image_Max 11
#define Down_Image_Min 0
#define Down_Image_Max 2

Player::Player()
{
	state = Player::State::Down;

	m_x = 180;
	m_y = 400;
	m_w = 64;
	m_h = 64;

	int error = LoadDivGraph("Shooting/Image/monster.png", 12, 3, 4, 64, 64, m_player_image);
	if (error == -1)
	{
		Ok_Window("error");
	}

	m_move = 1.0f; //Šî–{ˆÚ“®—Ê

	image_count = 0;
	flame_count = 0;

	m_life = true;

}


Player::~Player()
{
}

void Player::Move()
{
	InputManager::Key left = InputManager::Instance().GetKeyOf(KEY_INPUT_LEFT);
	InputManager::Key right = InputManager::Instance().GetKeyOf(KEY_INPUT_RIGHT);
	InputManager::Key up = InputManager::Instance().GetKeyOf(KEY_INPUT_UP);
	InputManager::Key down = InputManager::Instance().GetKeyOf(KEY_INPUT_DOWN);

	if (left._state == InputManager::State::Press || right._state==InputManager::State::Press)
	{
		if (up._state == InputManager::State::Press || down._state == InputManager::State::Press)
		{
			m_move = 0.71f;
		}
		else { m_move = 1.0f; }
	}
	else if (up._state == InputManager::State::Press || down._state == InputManager::State::Press)
	{
		m_move = 1.0f;
	}


	if (left._state == InputManager::State::Press)
	{
		if (state != State::Left)
		{
			image_count = 3;
		}
		state = Player::State::Left;
		m_x -= (int)Player_Speed*m_move;
	}
	 if (right._state == InputManager::State::Press)
	{
		if (state != State::Right)
		{
			image_count = 6;
		}
		state = Player::State::Right;
		m_x += (int)Player_Speed*m_move;
	}
	 if (up._state == InputManager::State::Press)
	{
		if (state != State::Up)
		{
			image_count = 9;
		}
		state = Player::State::Up;
		m_y -= (int)Player_Speed*m_move;
	}
	 if (down._state == InputManager::State::Press)
	{
		if (state != State::Down)
		{
			image_count = 0;
		}
		state = Player::State::Down;
		m_y += (int)Player_Speed*m_move;
	}


	 if (m_x > Action_Range_X - Margin - m_w / 2)
	{
		 m_x = Action_Range_X - Margin - m_w / 2;
	}
	else if (m_x < Margin + m_w / 2)
	{
		m_x = Margin + m_w / 2;
	}

	 if (m_y > Action_Range_Y - m_h / 2 - Margin)
	{
		m_y = Action_Range_Y - m_h / 2 - Margin;
	}
	else if (m_y < Margin + m_h / 2)
	{
		m_y = Margin + m_h / 2;
	}

}

void Player::Draw()
{
	if (m_life)
	{

		flame_count += 1;
		if (flame_count == 10)
		{
			image_count += 1;
			flame_count = 0;
		}

		switch (state)
		{
		case Player::Left:
			if (image_count == Left_Image_Max)
			{
				image_count = Left_Image_Min;
			}
			break;
		case Player::Right:
			if (image_count == Right_Image_Max)
			{
				image_count = Right_Image_Min;
			}
			break;
		case Player::Up:
			if (image_count == Up_Image_Max)
			{
				image_count = Up_Image_Min;
			}
			break;
		case Player::Down:
			if (image_count == Down_Image_Max)
			{
				image_count = Down_Image_Min;
			}
			break;
		default:
			break;
		}

		DrawGraph(m_x - m_w / 2, m_y - m_h / 2, m_player_image[image_count], TRUE);

	}
}

void Player::All()
{
	Move();
	Draw();
}