#ifndef PATTERNFACTORY_H
#define PATTERNFACTORY_H

#include"PatternManager.h"

class Pattern;

class PatternFactory {
public:
	PatternFactory();
	~PatternFactory();

	Pattern* Create(PatternManager::PATTERN_KIND);
};
#endif