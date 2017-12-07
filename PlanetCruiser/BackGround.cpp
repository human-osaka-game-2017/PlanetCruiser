#include"Background.h"
#include"Common.h"
#include"EndlessSystem.h"
#include<Lib.h>
#include"MassageManager.h"

Background::Background() :
	ObjectBase(D3DXVECTOR2(kPicWidth/2, 0.0f))
{

}

Background::~Background() {

}

void Background::Update() {
	if (MassageManager::GetInstance().GetPlayerState() == Player::ALLIVE) {
		if (m_Pos.y >= kPicHeight) {
			m_Pos = D3DXVECTOR3(kPicWidth / 2, 0.0f, 0.0f);
		}

		m_Pos.y += EndlessSystem::kScrollSpeed + MassageManager::GetInstance().GetScrollAcceleration();
	}
}

void Background::Draw() {
	using Utility::CUSTOMVERTEX;

	CUSTOMVERTEX vertex1[]{
		{ (float)-kWidth / 2, 0.0f ,0.5f, 1.0f, 0xffffffff, 0.0f, 0.0f },
		{ (float)kWidth / 2, 0.0f ,0.5f, 1.0f, 0xffffffff, 1.0f, 0.0f },
		{ (float)kWidth / 2, (float)kHeight ,0.5f, 1.0f, 0xffffffff, 1.0f, 1.0f },
		{ (float)-kWidth / 2, (float)kHeight ,0.5f, 1.0f, 0xffffffff, 0.0f, 1.0f }
	};

	CUSTOMVERTEX vertex2[]{
		{ (float)-kWidth / 2, (float)-kHeight ,0.5f, 1.0f, 0xffffffff, 0.0f, 0.0f },
		{ (float)kWidth / 2, (float)-kHeight ,0.5f, 1.0f, 0xffffffff, 1.0f, 0.0f },
		{ (float)kWidth / 2, 0.0f ,0.5f, 1.0f, 0xffffffff, 1.0f, 1.0f },
		{ (float)-kWidth / 2, 0.0f ,0.5f, 1.0f, 0xffffffff, 0.0f, 1.0f }
	};

	CUSTOMVERTEX drawVertex1[4];
	CUSTOMVERTEX drawVertex2[4];
	for (int i = 0; i < 4; i++) {
		drawVertex1[i] = vertex1[i];
		drawVertex1[i].x += m_Pos.x;
		drawVertex1[i].y += m_Pos.y;
		drawVertex2[i] = vertex2[i];
		drawVertex2[i].x += m_Pos.x;
		drawVertex2[i].y += m_Pos.y;
	}

	Lib::GetInstance().Draw(drawVertex1, "Assets\\Background.png");
	Lib::GetInstance().Draw(drawVertex2, "Assets\\Background.png");
}