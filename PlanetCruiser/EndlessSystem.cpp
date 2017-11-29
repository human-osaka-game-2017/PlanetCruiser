#include"EndlessSystem.h"
#include"PatternManager.h"
#include"PatternFactory.h"
#include"PatternManager.h"
#include"Pattern.h"
#include<Utility.h>

const float EndlessSystem::kScrollSpeed = 0.3f;

EndlessSystem::EndlessSystem() :
	ObjBase(D3DXVECTOR2(0.0,0.0))
{
	m_pPatternManager = new PatternManager;
	m_pPatternFactory = new PatternFactory;

	const std::vector<Asteroid*>& tmpCurrent = m_pPatternManager->GetPatternInfo(PatternManager::PATTERN_0);
	m_pCurrentPattern = m_pPatternFactory->Create(tmpCurrent);

	const std::vector<Asteroid*>& tmpNext = m_pPatternManager->GetPatternInfo((PatternManager::PATTERN_KIND)Utility::Random(0, PatternManager::MAX));
	m_pNextPattern = m_pPatternFactory->Create(tmpNext);
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
		const std::vector<Asteroid*>& tmpNext = m_pPatternManager->GetPatternInfo((PatternManager::PATTERN_KIND)Utility::Random(0, PatternManager::MAX));
		m_pNextPattern = m_pPatternFactory->Create(tmpNext);
		m_Pos.y = 0.0f;
	}

	m_pCurrentPattern->Update();
}

void EndlessSystem::Draw() {
	m_pCurrentPattern->Draw();
}