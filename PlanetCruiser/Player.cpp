#include"Player.h"
#include"Common.h"
#include<Lib.h>
#include<SquareCollider.h>
#include<ColliderManager.h>
#include"MassageManager.h"

Player::Player():
	ObjectBase(D3DXVECTOR2(WINDOW_WIDTH/2.0f,700.0f))
{
	SquareCollider::Size upSize{ kUpCollideWidth,kUpCollideHeight };
	m_UpCollidePos = m_Pos - D3DXVECTOR3(0.0f, 24.0f,0.0f);
	m_pUpCollider = new SquareCollider(std::string("Player"), m_UpCollidePos, std::bind(&Player::Collision, this), upSize);
	ColliderManager::GetInstance().Register(m_pUpCollider);
	
	SquareCollider::Size downSize{ kDownCollideWidth,kDownCollideHeight };
	m_DownCollidePos = m_Pos + D3DXVECTOR3(0.0f, 26.0f, 0.0f);
	m_pDownCollider = new SquareCollider(std::string("Player"), m_DownCollidePos, std::bind(&Player::Collision, this), downSize);
	ColliderManager::GetInstance().Register(m_pDownCollider);

	MassageManager::GetInstance().SetPlayerState(ALLIVE);

	m_pFont = new Font("HIT!!");
}

Player::~Player() {
	ColliderManager::GetInstance().Cancel(m_pUpCollider);
	delete m_pUpCollider;
	ColliderManager::GetInstance().Cancel(m_pDownCollider);
	delete m_pDownCollider;
	delete m_pFont;
}

void Player::Update() {
	if (m_CurrentState == ALLIVE) {
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
		m_UpCollidePos.x += m_Speed;
		m_DownCollidePos.x+= m_Speed;

		m_pUpCollider->SetPos(m_UpCollidePos);
		m_pDownCollider->SetPos(m_DownCollidePos);

		//‰æ–Ê’[‚Æ‚Ì”»’è
		if ((m_Pos.x - kWidth / 2) < 0 || (m_Pos.x + kWidth / 2) > WINDOW_WIDTH) {
			m_CurrentState = CLUSH;
			MassageManager::GetInstance().SetPlayerState(m_CurrentState);
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
			MassageManager::GetInstance().SetPlayerState(m_CurrentState);
		}
	}
}

void Player::Draw() {
	if (m_CurrentState == ALLIVE) {
		Lib::GetInstance().Draw(m_Pos, "Assets\\integ.png", (float)kWidth, (float)kHeight);
	}
	else if (m_CurrentState == CLUSH) {
		Lib::GetInstance().Draw(m_Pos, "Assets\\Clush.png", (float)kClushWidth, (float)kClushHeight, kClushWidth*m_CurrentAnimNo);
	}

	if (m_WasCllided) {
		RECT rect = { 20,10,100,50 };
		m_pFont->DrawInDisplay(rect);
	}
}

void Player::Collision() {
	m_WasCllided = true;
	if (m_CurrentState == ALLIVE) {
		m_CurrentState = CLUSH;
		MassageManager::GetInstance().SetPlayerState(m_CurrentState);
	}
}