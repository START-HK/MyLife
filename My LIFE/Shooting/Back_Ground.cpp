#include "Back_Ground.h"
#include"define.h"
#include"DxLib.h"


Back_Ground::Back_Ground()
{
	m_graphyc_handle = LoadGraph("Shooting/Image/wall.jpg");
	m_x = m_y = Margin;
}


Back_Ground::~Back_Ground()
{
}

void Back_Ground::Draw()
{
	DrawExtendGraph(m_x, m_y, m_x + Action_Range_X-Margin*2, m_y + Action_Range_Y-Margin*2, m_graphyc_handle, FALSE);
}

void Back_Ground::All()
{
	Draw();
}