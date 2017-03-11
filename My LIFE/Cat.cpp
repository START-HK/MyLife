#include "Cat.h"

#include"DxLib.h"

Cat::Cat(int x, int y)
{
	m_x = x;
	m_y = y;

}

Cat::Cat()
{

}

Cat::~Cat()
{

}

int Cat::Get_X()
{
	return m_x;
}

int Cat::Get_Y()
{
	return m_y;
}

void Cat::Move()
{
	if (CheckHitKey(KEY_INPUT_RIGHT) != 0)
		m_x += 1;

	if (CheckHitKey(KEY_INPUT_LEFT) != 0)
		m_x -= 1;

	if (CheckHitKey(KEY_INPUT_UP) != 0)
		m_y -= 1;

	if (CheckHitKey(KEY_INPUT_DOWN) != 0)
		m_y += 1;
}