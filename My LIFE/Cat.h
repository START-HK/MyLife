#pragma once
class Cat
{
private:
	int m_x;
	int m_y;
public:
	int Get_X();
	int Get_Y();
	void Move();

	Cat(int x,int y);
	Cat();
	~Cat();
};

