#include"Asteroid.h"

Asteroid::Asteroid(float x, float y, const AsteroidIniData& astData) :
	ObjBase(D3DXVECTOR2(x, y)),
	m_AsteroidData(astData)
{
}

Asteroid::~Asteroid() {

}

void Asteroid::Update() {

}

void Asteroid::Draw() {

}