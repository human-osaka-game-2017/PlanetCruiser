#include"Player.h"
#include"Common.h"
#include<Lib.h>
#include<SquareCollider.h>
#include<ColliderManager.h>
#include"MessageManager.h"

Player::Player():
	ObjectBase(D3DXVECTOR2(WINDOW_WIDTH/2.0f,700.0f))
{
	SquareCollider::Size upSize{ kUpCollideWidth,kUpCollideHeight };
	m_UpCollidePos = m_Pos - D3DXVECTOR3(0.0f, 24.0f,0.0f);
	m_pUpCollider = new SquareCollider(std::string("Player"), m_UpCollidePos, std::bind(&Player::UpCollision, this), upSize);
	ColliderManager::GetInstance().Register(m_pUpCollider);
	
	SquareCollider::Size downSize{ kDownCollideWidth,kDownCollideHeight };
	m_DownCollidePos = m_Pos + D3DXVECTOR3(0.0f, 26.0f, 0.0f);
	m_pDownCollider = new SquareCollider(std::string("Player"), m_DownCollidePos, std::bind(&Player::DownCollision, this), downSize);
	ColliderManager::GetInstance().Register(m_pDownCollider);

	MessageManager::GetInstance().SetPlayerState(ALIVE);
}

Player::~Player() {
	ColliderManager::GetInstance().Cancel(m_pUpCollider);
	delete m_pUpCollider;
	ColliderManager::GetInstance().Cancel(m_pDownCollider);
	delete m_pDownCollider;
}

void Player::Update() {
	if (m_CurrentState == ALIVE) {
		m_WasCllided = false;
		if (Utility::PUSH == Lib::GetInstance().GetKeyState(Utility::SPACE)) {
			m_IsRight = !m_IsRight;
			Lib::GetInstance().StopSound("Sound\\avoid.wav");
			Lib::GetInstance().PlayBackSound("Sound\\avoid.wav", false);
		}

		if (m_IsRight) {
			m_Speed += kAcceleration;
		}
		else {
			m_Speed -= kAcceleration;
		}

		m_Pos.x += m_Speed;
		m_UpCollidePos.x += m_Speed;
		m_DownCollidePos.x+= m_Speed;

		m_pUpCollider->SetPos(m_UpCollidePos);
		m_pDownCollider->SetPos(m_DownCollidePos);

		//‰æ–Ê’[‚Æ‚Ì”»’è
		if ((m_Pos.x - kWidth / 2) < -12 || (m_Pos.x + kWidth / 2) > WINDOW_WIDTH + 12) {
			m_CurrentState = CLUSH;
			Lib::GetInstance().PlayBackSound("Sound\\crush.wav", false);
			MessageManager::GetInstance().SetPlayerState(m_CurrentState);
		}
	}
	else if (m_CurrentState == CLUSH) {
		++m_AnimFrCnt;
		if (m_AnimFrCnt == 2) {
			m_AnimFrCnt = 0;
			++m_CurrentAnimNo;
		}

		if (40 <= m_CurrentAnimNo) {
			m_CurrentState = DEAD;
			MessageManager::GetInstance().SetPlayerState(m_CurrentState);
		}
	}
}

void Player::Draw() {
	if (m_CurrentState == ALIVE) {
		Lib::GetInstance().Draw(m_Pos, "Assets\\integ.png", (float)kWidth, (float)kHeight);
	}
	else if (m_CurrentState == CLUSH) {
		Lib::GetInstance().Draw(m_Pos, "Assets\\Crush.png", (float)kClushWidth, (float)kClushHeight, kClushWidth*m_CurrentAnimNo);
	}
}

void Player::Collision() {
	if (m_CurrentState == ALIVE) {
		m_CurrentState = CLUSH;
		Lib::GetInstance().PlayBackSound("Sound\\crush.wav", false);
		MessageManager::GetInstance().SetPlayerState(m_CurrentState);
	}
}

void Player::UpCollision() {
	for (auto itr = m_pUpCollider->GetCollidedClassNames().begin(); itr != m_pUpCollider->GetCollidedClassNames().end(); ++itr) {
		if ((*itr) == "Asteroid") {
			m_WasCllided = true;
		}
	}

	if (m_WasCllided) {
		Collision();
	}
}

void Player::DownCollision() {
	for (auto itr = m_pDownCollider->GetCollidedClassNames().begin(); itr != m_pDownCollider->GetCollidedClassNames().end(); ++itr) {
		if ((*itr) == "Asteroid") {
			m_WasCllided = true;
		}
	}

	if (m_WasCllided) {
		Collision();
	}
}