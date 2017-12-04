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

	m_pFont = new Font("HIT!!");
}

Player::~Player() {
	ColliderManager::GetInstance().Cancel(m_pCollider);
	delete m_pCollider;
	delete m_pFont;
}

void Player::Update() {
	m_WasCllided = false;
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

	if (m_WasCllided) {
		RECT rect = { 20,10,100,50 };
		m_pFont->DrawInDisplay(rect);
	}
}

void Player::Collision() {
	
	m_WasCllided = true;
}