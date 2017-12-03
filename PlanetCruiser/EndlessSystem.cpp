#include"EndlessSystem.h"
#include"PatternManager.h"
#include"Pattern.h"
#include<Utility.h>

const float EndlessSystem::kScrollSpeed = 1.0f;
const int EndlessSystem::kMaxScrollY = 1280;

EndlessSystem::EndlessSystem() :
	ObjectBase(D3DXVECTOR2(0.0,0.0))
{
	m_pPatternManager = new PatternManager;

	const std::vector<Asteroid*>& astroidsCurrent = m_pPatternManager->GetPatternInfo(PatternManager::PATTERN_0);
	m_pCurrentPattern = new Pattern(astroidsCurrent);
	m_pCurrentPattern->PullDown();

	PatternManager::PATTERN_KIND patternKind = (PatternManager::PATTERN_KIND)Utility::Random(0, PatternManager::MAX-1);
	const std::vector<Asteroid*>& asteroidsNext = m_pPatternManager->GetPatternInfo(patternKind);
	m_pNextPattern = new Pattern(asteroidsNext);
}

EndlessSystem::~EndlessSystem() {
	delete m_pCurrentPattern;
	delete m_pNextPattern;
}

void EndlessSystem::Update() {
	m_Pos.y += kScrollSpeed;

	if (m_Pos.y > kMaxScrollY) {
		delete m_pCurrentPattern;
		m_pCurrentPattern = m_pNextPattern;
		PatternManager::PATTERN_KIND patternKind = (PatternManager::PATTERN_KIND)Utility::Random(0, PatternManager::MAX - 1);
		const std::vector<Asteroid*>& asteroidsNext = m_pPatternManager->GetPatternInfo(patternKind);
		m_pNextPattern = new Pattern(asteroidsNext);
		m_Pos.y = 0.0f;
	}

	m_pCurrentPattern->Update();
	m_pNextPattern->Update();
}

void EndlessSystem::Draw() {
	m_pCurrentPattern->Draw();
	m_pNextPattern->Draw();
}