#include"Player.h"
#include"Common.h"
#include<Lib.h>

Player::Player():
	ObjectBase(D3DXVECTOR2(WINDOW_WIDTH/2.0f,700.0f))
{

}

Player::~Player() {

}

void Player::Update() {
	if (Utility::PUSH == Lib::GetInstance().GetKeyState(Utility::SPACE)) {
		m_IsRight = !m_IsRight;
	}

	if (m_IsRight) {
		m_Speed += kAcceleration;
	}
	else {
		m_Speed -= kAcceleration;
	}

	m_Pos.x += m_Speed;
}

void Player::Draw() {
	Lib::GetInstance().Draw(m_Pos, "Assets\\integ.png", (float)kWidth, (float)kHeight);
}