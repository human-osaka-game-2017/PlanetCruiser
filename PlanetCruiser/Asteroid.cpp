#include"Asteroid.h"
#include"EndlessSystem.h"
#include<Lib.h>

Asteroid::Asteroid(const AsteroidIniData& astData) :
	ObjBase(D3DXVECTOR2(astData.x, astData.y)),
	m_AsteroidData(astData)
{
	m_Pos.y -= EndlessSystem::kMaxScrollY;
}

Asteroid::~Asteroid() {

}

void Asteroid::Update() {
	if (m_Pos.y < kSwitchPoint) {
		m_Pos.y += EndlessSystem::kScrollSpeed;
	}
	else {
		m_Pos.y += m_AsteroidData.speed;
	}
}

void Asteroid::Draw() {
	if (m_Pos.y > kSwitchPoint) {
		Lib::GetInstance().Draw(m_Pos, "Assets\\integ.png", m_AsteroidData.width, m_AsteroidData.height, m_AsteroidData.tlTu, m_AsteroidData.tlTv);
	}
}

void Asteroid::PullDown() {
	m_Pos.y += EndlessSystem::kMaxScrollY;
}