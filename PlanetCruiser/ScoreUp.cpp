#include "ScoreUp.h"
#include<Lib.h>
#include<SquareCollider.h>
#include"Score.h"
#include<ColliderManager.h>
#include"MessageManager.h"
#include"EndlessSystem.h"
#include"Common.h"

ScoreUp::ScoreUp():
	ObjectBase(D3DXVECTOR2(0,-kHeight/2))
{
	SquareCollider::Size size{ kCollideWidth,kCollideHeight };
	m_pCollider = new SquareCollider("ScoreUp", m_Pos, std::bind(&ScoreUp::Collision, this), size);

	ColliderManager::GetInstance().Register(m_pCollider);

	std::vector<SquareCollider> colliders;

	ColliderManager::GetInstance().SearchCollider(&colliders, "Asteroid");

	while (true) {
		for (int i = 0; i < kMaxTryNum; ++i) {
			m_Pos.x = Utility::Random(0, WINDOW_WIDTH);
			bool canCreate = true;
			for (auto itr = colliders.begin(); itr != colliders.end(); ++itr) {
				D3DXVECTOR2 pos = m_Pos;
				D3DXVECTOR2 astPos = (*itr).GetPos();
				if (Utility::JudgeCollisionSquare(pos, kWidth, kHeight, astPos, (*itr).GetSize().width, (*itr).GetSize().height)) {
					canCreate = false;
				}
			}

			if (canCreate) {
				goto BREAK;
			}
		}

		m_Pos.y += 100;
	}

BREAK:;
	
}

ScoreUp::~ScoreUp()
{
	ColliderManager::GetInstance().Cancel(m_pCollider);
	delete m_pCollider;
}

void ScoreUp::Update() {
	m_Pos.y+= EndlessSystem::kScrollSpeed + MessageManager::GetInstance().GetScrollAcceleration();
	m_pCollider->SetPos(m_Pos);
}

void ScoreUp::Draw() {
	Lib::GetInstance().Draw(m_Pos, "Assets\\ScoreUp.png", (float)kWidth, (float)kHeight);
}

void ScoreUp::Collision() {
	for (auto itr = m_pCollider->GetCollidedClassNames().begin(); itr != m_pCollider->GetCollidedClassNames().end(); ++itr) {
		if ((*itr) == std::string("Player")) {
			m_WasTaken = true;
			int additionalPoint = (((Score::GetInstance().GetScore() / 4) / 10) * 10);
			Score::GetInstance().AddScore(additionalPoint);
			break;
		}
	}
}