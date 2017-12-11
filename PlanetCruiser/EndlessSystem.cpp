#include"EndlessSystem.h"
#include"PatternManager.h"
#include"Pattern.h"
#include<Lib.h>
#include"MassageManager.h"

const float EndlessSystem::kScrollSpeed = 1.8f;
const int EndlessSystem::kMaxScrollY = 1280;

EndlessSystem::EndlessSystem() :
	ObjectBase(D3DXVECTOR2(0.0,0.0))
{
	m_pPatternManager = new PatternManager;

	const std::vector<Asteroid*>& astroidsCurrent = m_pPatternManager->GetPatternInfo(PatternManager::PATTERN_0);
	m_pCurrentPattern = new Pattern(astroidsCurrent);
	m_pCurrentPattern->PullDown();

	PatternManager::PATTERN_KIND patternKind = (PatternManager::PATTERN_KIND)Utility::Random(1, 6);
	const std::vector<Asteroid*>& asteroidsNext = m_pPatternManager->GetPatternInfo(patternKind);
	m_pNextPattern = new Pattern(asteroidsNext);

	m_EasyCnt = 0;
	int percentage = Utility::Random(0, 100);

	if (percentage <= 20) {
		m_EasyNum = 1;
	}
	else if (percentage <= 70) {
		m_EasyNum = 2;
	}
	else if (percentage <= 100) {
		m_EasyNum = 3;
	}
}

EndlessSystem::~EndlessSystem() {
	delete m_pCurrentPattern;
	delete m_pNextPattern;
	delete m_pPatternManager;
}

void EndlessSystem::Update() {
	if (MassageManager::GetInstance().GetPlayerState() == Player::ALLIVE) {
		++m_ScrollFrCnt;
		if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::W) == Utility::BUTTON_STATE::PUSH) {
			m_ScrollAcceleration += 0.1f;
		}
		if (m_ScrollFrCnt == 60) {
			m_ScrollFrCnt = 0;
			m_ScrollAcceleration += 0.003f;
			MassageManager::GetInstance().SetScrollAcceleration(m_ScrollAcceleration);
		}

		m_Pos.y += kScrollSpeed + m_ScrollAcceleration;

		if (m_Pos.y > kMaxScrollY) {
			CreatePattern();
			m_Pos.y = 0.0f;
		}

		m_pCurrentPattern->Update();
		m_pNextPattern->Update();
	}
}

void EndlessSystem::Draw() {
	m_pCurrentPattern->Draw();
	m_pNextPattern->Draw();
}

void EndlessSystem::CreatePattern() {
	delete m_pCurrentPattern;
	m_pCurrentPattern = m_pNextPattern;

	OutputDebugString("next:");

	if (m_EasyCnt == m_EasyNum) {
		m_EasyCnt = 0;
		int percentage= Utility::Random(0, 100);

		if (percentage <= 20) {
			m_EasyNum = 1;
		}
		else if (percentage <= 70) {
			m_EasyNum = 2;
		}
		else if (percentage <= 100) {
			m_EasyNum = 3;
		}

		PatternManager::PATTERN_KIND patternKind = (PatternManager::PATTERN_KIND)Utility::Random(7, 10);
		const std::vector<Asteroid*>& asteroidsNext = m_pPatternManager->GetPatternInfo(patternKind);
		m_pNextPattern = new Pattern(asteroidsNext);

		std::string nextKind = std::to_string(patternKind);
		OutputDebugString(nextKind.c_str());
	}
	else {
		++m_EasyCnt;
		PatternManager::PATTERN_KIND patternKind = (PatternManager::PATTERN_KIND)Utility::Random(1, 6);
		const std::vector<Asteroid*>& asteroidsNext = m_pPatternManager->GetPatternInfo(patternKind);
		m_pNextPattern = new Pattern(asteroidsNext);

		std::string nextKind = std::to_string(patternKind);
		OutputDebugString(nextKind.c_str());
	}
}