#pragma once
class Player
{
private:
	enum State 
	{
		Right,
		Left,
		Up,
		Down
	};

	State state;

	double m_x,m_y;
	int m_w,m_h;

	float m_move;

	int m_player_image[12];

	int image_count;
	int flame_count;

	bool m_life;

private:
	void Move();
	void Draw();

public:
	Player();
	~Player();
	void All();


};

