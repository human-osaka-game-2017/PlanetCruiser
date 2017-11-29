#include"EndlessSystem.h"
#include"PatternManager.h"
#include"PatternFactory.h"
#include<Utility.h>

const float EndlessSystem::kScrollSpeed = 0.3f;

EndlessSystem::EndlessSystem() :
	ObjBase(D3DXVECTOR2(0.0,0.0))
{
	m_pPatternFactory = new PatternFactory;
	m_pCurrentPattern = m_pPatternFactory->Create(PatternManager::PATTERN_0);
	m_pNextPattern = m_pPatternFactory->Create((PatternManager::PATTERN_KIND)Utility::Random(0, PatternManager::MAX));
}

EndlessSystem::~EndlessSystem() {
	delete m_pPatternFactory;
	delete m_pCurrentPattern;
	delete m_pNextPattern;
}

void EndlessSystem::Update() {
	m_Pos.y += kScrollSpeed;

	if (m_Pos.y > kMaxScrollY) {
		delete m_pCurrentPattern;
		m_pCurrentPattern = m_pNextPattern;
		m_pNextPattern = m_pPatternFactory->Create((PatternManager::PATTERN_KIND)Utility::Random(0, PatternManager::MAX));
		m_Pos.y = 0.0f;
	}
}

void EndlessSystem::Draw() {

}