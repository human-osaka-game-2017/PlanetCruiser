#include"Player.h"
#include"Common.h"
#include<Lib.h>
#include<SquareCollider.h>
#include<ColliderManager.h>

Player::Player():
	ObjectBase(D3DXVECTOR2(WINDOW_WIDTH/2.0f,700.0f))
{
	SquareCollider::Size size{ kCollideWidth,kCollideHeight };
	m_pCollider = new SquareCollider(std::string("Player"), m_Pos, std::bind(&Player::Collision, this), size);
	ColliderManager::GetInstance().Register(m_pCollider);
}

Player::~Player() {
	ColliderManager::GetInstance().Cancel(m_pCollider);
	delete m_pCollider;
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

	m_pCollider->SetPos(m_Pos);
}

void Player::Draw() {
	Lib::GetInstance().Draw(m_Pos, "Assets\\integ.png", (float)kWidth, (float)kHeight);
}

void Player::Collision() {
	
	OutputDebugString("fuck you");
}