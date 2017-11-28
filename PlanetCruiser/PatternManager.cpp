#include"PatternManager.h"

PatternManager::PatternManager() {

}

PatternManager::~PatternManager() {

}

const std::vector<Asteroid*> PatternManager::GetPatternInfo(PATTERN_KIND kind) {
	return m_pPatterns[0];
}