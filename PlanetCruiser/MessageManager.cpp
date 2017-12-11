#include"MessageManager.h"

MessageManager* MessageManager::m_pInstance = nullptr;

MessageManager::MessageManager()
{
}

MessageManager::~MessageManager()
{
	delete m_pInstance;
}
