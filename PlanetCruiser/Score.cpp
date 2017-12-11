#include"Score.h"
#include"Common.h"
#include<Lib.h>
#include"MessageManager.h"
#include<fstream>

Score* Score::m_pInstance = nullptr;

Score::Score() :
	ObjectBase(D3DXVECTOR2(WINDOW_WIDTH - (kWidth), WINDOW_HEIGHT - (kHeight)))
{
	std::ifstream ifs("Stage\\highScore.txt");
	ifs >> m_HighScore;
}

Score::~Score() {
	delete m_pInstance;
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
	if (MessageManager::GetInstance().GetPlayerState() == Player::ALIVE) {
		m_FrCnt++;
		if (m_FrCnt == 30) {
			m_Score += m_AdditionalScore;
			m_FrCnt = 0;
		}
	}

	if (m_ScoreThresholdCnt == m_Score / 1000) {
		m_ScoreThresholdCnt++;
		m_AdditionalScore += 10;
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

			Lib::GetInstance().TrimingVertex(vertex, (float)108 * spacingCnt, (float)144 * 4, (float)108, (float)144, (float)kPicWidth, (float)kPicHeight);

			Lib::GetInstance().Draw(vertex, "Assets\\fonts.png");
		}
	}
}

void Score::ResultSceneUpdate() {

}

void Score::ResultSceneDraw() {

	//前回のスコア表示
	D3DXVECTOR2 pos(440,400);

	for (int i = 0; i < kMaxNumberOfDigits; ++i) {

		pos.x -= kWidth + 2.0f;

		int NumPower = 1;

		for (int j = 0; j < i; ++j) {
			NumPower *= 10;
		}

		int num = (m_Score / (NumPower)) % 10;

		if (num == 0) {
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

			Lib::GetInstance().TrimingVertex(vertex, (float)108 * spacingCnt, (float)144 * 4, (float)108, (float)144, (float)kPicWidth, (float)kPicHeight);

			Lib::GetInstance().Draw(vertex, "Assets\\fonts.png");
		}
	}

	//ハイスコア表示
	pos = D3DXVECTOR2(440, 600);

	for (int i = 0; i < kMaxNumberOfDigits; ++i) {

		pos.x -= kWidth + 2.0f;

		int NumPower = 1;

		for (int j = 0; j < i; ++j) {
			NumPower *= 10;
		}

		int num = (m_HighScore / (NumPower)) % 10;

		if (num == 0) {
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

			Lib::GetInstance().TrimingVertex(vertex, (float)108 * spacingCnt, (float)144 * 4, (float)108, (float)144, (float)kPicWidth, (float)kPicHeight);

			Lib::GetInstance().Draw(vertex, "Assets\\fonts.png");
		}
	}
}

void Score::WriteScore() {
	std::ofstream outputfile("Stage\\highScore.txt");
	outputfile << m_Score;
	outputfile.close();
}

void Score::CompareCurrentScoreWithHighScore() {
	if (m_HighScore < m_Score) {
		WriteScore();
		m_HighScore = m_Score;
		isNewRecord = true;
	}
}