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

	void WriteCsv();
	void SetCurrentScene(SceneManager::SCENE_ID scene) {
		m_CurrentScene = scene;
	}

	static const int kPicWidth = 1024;
	static const int kPicHeight = 1024;

private:
	static Score* m_pInstance;
	Score();
	virtual ~Score();

	unsigned int m_Score = 0;
	unsigned int m_FrCnt = 0;
	SceneManager::SCENE_ID m_CurrentScene = SceneManager::SCENE_ID::MAIN;
	
	void MainSceneUpdate();
	void MainSceneDraw();
	void ResultSceneUpdate();
	void ResultSceneDraw();

	static const int kWidth = 24;
	static const int kHeight = 32;
	const int kMaxNumberOfDigits = 7;
};
#endif