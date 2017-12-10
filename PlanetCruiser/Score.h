#ifndef SCORE_H
#define SCORE_H

#include<ObjectBase.h>
#include"SceneManager.h"

class Score :public ObjectBase {
public:
	static Score& GetInstance(){
		if (m_pInstance == nullptr) {
			m_pInstance = new Score;
		}
		return *m_pInstance;
	}

	virtual void Update();
	virtual void Draw();

	void SetCurrentScene(SceneManager::SCENE_ID scene) {
		m_CurrentScene = scene;
	}

	void AddScore(unsigned int val) {
		m_Score += val;
	}

	static const int kPicWidth = 1024;
	static const int kPicHeight = 1024;

private:
	static Score* m_pInstance;
	Score();
	virtual ~Score();

	unsigned int m_Score = 0;
	unsigned int m_AdditionalScore = 10;
	unsigned int m_ScoreThresholdCnt = 1;
	unsigned int m_HighScore = 0;
	unsigned int m_FrCnt = 0;
	SceneManager::SCENE_ID m_CurrentScene = SceneManager::SCENE_ID::MAIN;
	bool isNewRecord = false;
	
	void MainSceneUpdate();
	void MainSceneDraw();
	void ResultSceneUpdate();
	void ResultSceneDraw();
	void WriteScore();
	//high score更新してたらWriteScoreを呼び出し、リセットするところまでやっている
	void CompareCurrentScoreWithHighScore();

	static const int kWidth = 24;
	static const int kHeight = 32;
	const int kMaxNumberOfDigits = 7;
};
#endif