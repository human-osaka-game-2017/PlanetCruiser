#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H

#include"Player.h"

class MessageManager{
public:
	static MessageManager& GetInstance() {
		if (m_pInstance == nullptr) {
			m_pInstance = new MessageManager;
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

	float GetScrollAcceleration() {
		return m_ScrollAcceleration;
	}

	void SetScrollAcceleration(float a) {
		m_ScrollAcceleration = a;
	}

private:
	static MessageManager* m_pInstance;
	MessageManager();
	~MessageManager();

	Player::STATE m_PlayerState = Player::ALIVE;
	bool m_IsPushingSpaceKey = false;
	float m_ScrollAcceleration = 0;
};
#endif