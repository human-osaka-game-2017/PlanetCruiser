#include "MassageManager.h"

MassageManager* MassageManager::m_pInstance = nullptr;

MassageManager::MassageManager()
{
}

MassageManager::~MassageManager()
{
	delete m_pInstance;
}
