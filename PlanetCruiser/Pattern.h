#ifndef PATTERN_H
#define PATTERN_H

#include<vector>

class Asteroid;

class Pattern{
public:
	Pattern(std::vector<Asteroid*> pAsteroids);
	~Pattern();

	void Update();
	void Draw();

private:
	std::vector<Asteroid*> m_pAsteroids;
};
#endif