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

	void DeadPlayer() {
		m_PlayerIsDead = true;
	}

	bool GetPlayerDeadFlg() {
		return m_PlayerIsDead;
	}

private:
	static MassageManager* m_pInstance;
	MassageManager();
	~MassageManager();

	bool m_PlayerIsDead = false;
};
#endif