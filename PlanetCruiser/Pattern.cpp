#include"Pattern.h"
#include"Asteroid.h"

Pattern::Pattern(const std::vector<Asteroid*>& asteroids){
	for (auto itr = asteroids.begin(); itr != asteroids.end(); ++itr) {
		Asteroid* pAst = new Asteroid((*itr)->GetAsteroidData());
		m_Asteroids.push_back(pAst);
	}
}

Pattern::~Pattern() {
	for (auto itr = m_Asteroids.begin(); itr != m_Asteroids.end(); ++itr) {
		delete *itr;
	}
}

void Pattern::Update() {
	for (auto itr = m_Asteroids.begin(); itr != m_Asteroids.end(); itr++)
	{
		(*itr)->Update();
	}
}

void Pattern::Draw() {
	for (auto itr = m_Asteroids.begin(); itr != m_Asteroids.end(); itr++)
	{
		(*itr)->Draw();
	}
}

void Pattern::PullDown() {
	for (auto itr = m_Asteroids.begin(); itr != m_Asteroids.end(); itr++)
	{
		(*itr)->PullDown();
	}
}