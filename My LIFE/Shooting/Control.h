#pragma once
#include"Player.h"
#include"Back_Ground.h"

class Control
{
private:
	Player* m_player;
	Back_Ground*m_back_ground;

public:
	Control();
	~Control();
	void All();
};

