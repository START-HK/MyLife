#pragma once
class Book_Object
{
private:
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	int book_image;
	int book_image2;
	bool is_hit;

public:
	Book_Object(int x,int y,int w,int h);
	Book_Object();
	~Book_Object();
	int Get_X();
	int Get_Y();
	int Get_W();
	int Get_H();
	void Draw();
	void Load();
	bool Is_Hit(bool t);
	
};

