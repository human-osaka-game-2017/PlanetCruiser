#include "ItemManager.h"
#include"ScoreUp.h"
#include"EndlessSystem.h"
#include"MessageManager.h"
#include"Common.h"
#include"Player.h"

ItemManager::ItemManager():
	ObjectBase(D3DXVECTOR2(0.0f,0.0f)),
	m_pScoreUp(nullptr)
{
}


ItemManager::~ItemManager() {
	delete m_pScoreUp;
}

void ItemManager::Update() {
	if (MessageManager::GetInstance().GetPlayerState() == Player::ALIVE) {
		if (m_pScoreUp != nullptr) {
			if (m_pScoreUp != nullptr) {
				m_pScoreUp->Update();
			}

			if (m_pScoreUp->GetTakeFlg() || m_pScoreUp->GetPos().y > WINDOW_HEIGHT + m_pScoreUp->kHeight / 2) {
				delete m_pScoreUp;
				m_pScoreUp = nullptr;
			}
		}
		else {
			if (EndlessSystem::kMaxScrollY * 1 < m_Pos.y) {
				m_Pos.y = 0;
				m_pScoreUp = new ScoreUp();
			}
		}

		m_Pos.y += EndlessSystem::kScrollSpeed + MessageManager::GetInstance().GetScrollAcceleration();
	}
}

void ItemManager::Draw() {
	if (m_pScoreUp != nullptr) {
		m_pScoreUp->Draw();
	}
}