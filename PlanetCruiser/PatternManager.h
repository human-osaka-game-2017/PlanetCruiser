#ifndef PATTERNMANAGER_H
#define PATTERNMANAGER_H

#include<vector>
#include<map>
#include"Asteroid.h"

class PatternManager {
public:
	enum PATTERN_KIND {
		PATTERN_0,
		PATTERN_1,
		MAX
	};

	const std::vector<Asteroid*>& GetPatternInfo(PATTERN_KIND kind);

	PatternManager();
	~PatternManager();

private:
	std::map<PATTERN_KIND,std::vector<Asteroid*>> m_pPatterns;

	//fileName ó·Åj".\\Assets\\test.ini
	std::vector<Asteroid*>* LoadIniFile(const char* fileName, std::vector<Asteroid*>* asteroids);

	struct UV {
		float tu, tv;
	};

	std::map<std::string, UV> m_UVData;
	void InitUVData();
};
#endif