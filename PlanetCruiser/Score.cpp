#include"Score.h"
#include"Common.h"
#include<Lib.h>

Score* Score::m_pInstance = nullptr;

Score::Score() :
	ObjectBase(D3DXVECTOR2(WINDOW_WIDTH - (kWidth), WINDOW_HEIGHT - (kHeight)))
{

}

Score::~Score() {

}

void Score::Update() {
	switch (m_CurrentScene) {
	case SceneManager::SCENE_ID::MAIN:
		MainSceneUpdate();
		break;

	case SceneManager::SCENE_ID::RESULT:
		ResultSceneUpdate();
		break;
	}
}

void Score::Draw() {
	switch (m_CurrentScene) {
	case SceneManager::SCENE_ID::MAIN:
		MainSceneDraw();
		break;

	case SceneManager::SCENE_ID::RESULT:
		ResultSceneDraw();
		break;
	}
}

void Score::MainSceneUpdate() {
	m_FrCnt++;
	if (m_FrCnt == 30) {
		m_Score += 10;
		m_FrCnt = 0;
	}
}

void Score::MainSceneDraw() {

 	D3DXVECTOR2 pos = m_Pos;

	for (int i = 0; i < kMaxNumberOfDigits; ++i) {

		pos.x -= kWidth + 2.0f;

		int NumPower = 1;

		for (int j = 0; j < i; ++j) {
			NumPower *= 10;
		}

		int num = (m_Score / (NumPower)) % 10;

		if (num==0) {
			Lib::GetInstance().Draw(pos, "Assets\\fonts.png", (float)108, (float)144, 0.0f, 144 * 5, 0.0f, 1.0f / 4.5f);
		}
		else {
			int spacingCnt = num - 1;
			Utility::CUSTOMVERTEX vertex[4]{
				{ -kWidth / 2 + pos.x,-kHeight / 2 + pos.y,0.5f,1.0f,0xffffffff,0.0f,0.0f },
				{ kWidth / 2 + pos.x,-kHeight / 2 + pos.y,0.5f,1.0f,0xffffffff,1.0f,0.0f },
				{ kWidth / 2 + pos.x,kHeight / 2 + pos.y,0.5f,1.0f,0xffffffff,1.0f,1.0f },
				{ -kWidth / 2 + pos.x,kHeight / 2 + pos.y,0.5f,1.0f,0xffffffff,0.0f,1.0f }
			};

			Lib::GetInstance().TrimingVertex(vertex, 108 * spacingCnt, 144 * 4, 108, 144, kPicWidth, kPicHeight);

			Lib::GetInstance().Draw(vertex, "Assets\\fonts.png");
		}
	}
}

void Score::ResultSceneUpdate() {

}

void Score::ResultSceneDraw() {

}