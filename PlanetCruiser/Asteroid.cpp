#include"Asteroid.h"
#include"EndlessSystem.h"
#include<Lib.h>
#include<SquareCollider.h>
#include<ColliderManager.h>
#include"MassageManager.h"

Asteroid::Asteroid(const AsteroidIniData& astData) :
	ObjectBase(D3DXVECTOR3(astData.x, astData.y, 0.0f)),
	m_AsteroidData(astData)
{
	m_Pos.y -= EndlessSystem::kMaxScrollY;

	D3DXVECTOR3 collidePos = m_Pos;

	SquareCollider::Size size{ m_AsteroidData.collidedWidth,m_AsteroidData.collidedHeight };

	//ó·äOèàóù
	if (size.width == 104) {
		collidePos.y -= 4.0f;
	}

	m_pCollider = new SquareCollider(std::string("Asteroid"), collidePos, std::bind(&Asteroid::Collision, this), size);
	ColliderManager::GetInstance().Register(m_pCollider);
}

Asteroid::~Asteroid() {
	ColliderManager::GetInstance().Cancel(m_pCollider);
	delete m_pCollider;
}

void Asteroid::Update() {
	if (m_Pos.y < kSwitchPoint) {
		m_Pos.y += EndlessSystem::kScrollSpeed + MassageManager::GetInstance().GetScrollAcceleration();
	}
	else {
		m_Pos.y += m_AsteroidData.speed + MassageManager::GetInstance().GetScrollAcceleration();
	}

	D3DXVECTOR3 collidePos = m_Pos;

	//ó·äOèàóù
	if (m_AsteroidData.collidedWidth == 104) {
		collidePos.y -= 4.0f;
	}

	m_pCollider->SetPos(collidePos);
}

void Asteroid::Draw() {
	if (m_Pos.y > kSwitchPoint) {
		Lib::GetInstance().Draw(m_Pos, "Assets\\integ.png", m_AsteroidData.width, m_AsteroidData.height, m_AsteroidData.tlTu, m_AsteroidData.tlTv);
	}
}

void Asteroid::PullDown() {
	m_Pos.y += EndlessSystem::kMaxScrollY;
}

void Asteroid::Collision() {

}