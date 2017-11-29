#ifndef PATTERN_H
#define PATTERN_H

#include<vector>

class Asteroid;

class Pattern{
public:
	Pattern(const std::vector<Asteroid*>& asteroids);
	~Pattern();

	void Update();
	void Draw();

	void PullDown();

private:
	std::vector<Asteroid*> m_Asteroids;
};
#endif