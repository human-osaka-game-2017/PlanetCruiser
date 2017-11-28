#ifndef PATTERNMANAGER_H
#define PATTERNMANAGER_H

#include<vector>
#include"Asteroid.h"

class PatternManager {
public:
	enum PATTERN_KIND {
		PATTERN_0,
		PATTERN_1,
		MAX
	};

	const std::vector<Asteroid*> GetPatternInfo(PATTERN_KIND kind);

	PatternManager();
	~PatternManager();

private:
	std::vector<std::vector<Asteroid*>> m_pPatterns;
};
#endif