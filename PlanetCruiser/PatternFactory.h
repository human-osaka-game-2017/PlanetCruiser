#ifndef PATTERNFACTORY_H
#define PATTERNFACTORY_H

#include"PatternManager.h"

class Pattern;

class PatternFactory {
public:
	PatternFactory();
	~PatternFactory();

	Pattern* Create(const std::vector<Asteroid*>& asteroids);
};
#endif