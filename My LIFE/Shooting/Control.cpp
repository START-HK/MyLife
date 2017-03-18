#include "Control.h"




Control::Control()
{
	m_player = new Player();
	m_back_ground = new Back_Ground();
}


Control::~Control()
{
	delete m_player;
	delete m_back_ground;
}

void Control::All()
{
	m_back_ground->All();
	m_player->All();
}

