#pragma once
class Player1
{
private:
	enum State {
		Right,
		Left,
		Up,
		Down
	};
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	int ic ;
	int fc ;
	int i;
	State state;
public:
	int Get_X();
	int Get_Y();
	int Get_W();
	int Get_H();
    void Move();
	void Draw();
	int Player1_Image[12];


	Player1(int x,int y,int w,int h);
	Player1();
	~Player1();
};

