#include"Asteroid.h"

Asteroid::Asteroid(const AsteroidIniData& astData) :
	ObjBase(D3DXVECTOR2(astData.x, astData.y)),
	m_AsteroidData(astData)
{
}

Asteroid::~Asteroid() {

}

void Asteroid::Update() {

}

void Asteroid::Draw() {

}