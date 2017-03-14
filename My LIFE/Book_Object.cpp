#include "Book_Object.h"
#include"DxLib.h"


Book_Object::Book_Object(int x,int y,int w,int h)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;

	is_hit = false;

}

Book_Object::Book_Object()
{
	is_hit = false;
}

Book_Object::~Book_Object()
{
}


int Book_Object::Get_X()
{
	return m_x;
}

int Book_Object::Get_Y()
{
	return m_y;
}

int Book_Object::Get_W()
{
	return m_w;
}

int Book_Object::Get_H()
{
	return m_h;
}

void Book_Object::Load()
{
	book_image = LoadGraph("res/book_object2.png");

	book_image2 = LoadGraph("res/book_open.png");
}

bool Book_Object::Is_Hit(bool t)
{
	is_hit = t;
	return true;
}

void Book_Object::Draw()
{
	int x = Get_X() - (Get_W() / 2);
	int y = Get_Y() - (Get_H() / 2);
	
	if (is_hit)
		DrawGraph(x, y - 2, book_image2, TRUE);
	else
		DrawGraph(x, y, book_image, TRUE);




}
