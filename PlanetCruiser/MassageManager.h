#ifndef MASSAGEMANAGER_H
#define MASSAGEMANAGER_H

#include"Player.h"

class MassageManager{
public:
	static MassageManager& GetInstance() {
		if (m_pInstance == nullptr) {
			m_pInstance = new MassageManager;
		}
		return *m_pInstance;
	}

	void SetPlayerState(Player::STATE state) {
		m_PlayerState = state;
	}

	Player::STATE GetPlayerState() {
		return m_PlayerState;
	}

	bool GetPushSpaceKeyFlg() {
		return m_IsPushingSpaceKey;
	}

	void SetPushSpaceKeyFlg(bool pushSpaceKeyFlg) {
		m_IsPushingSpaceKey = pushSpaceKeyFlg;
	}

private:
	static MassageManager* m_pInstance;
	MassageManager();
	~MassageManager();

	Player::STATE m_PlayerState = Player::ALLIVE;
	bool m_IsPushingSpaceKey = false;
};
#endif