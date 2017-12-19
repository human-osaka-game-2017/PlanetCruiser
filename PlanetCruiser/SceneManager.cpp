#include"SceneManager.h"
#include"SceneFactory.h"
#include"TitleScene.h"
#include"Score.h"
#include<Lib.h>

SceneManager::SceneManager() :
	m_pScene(new TitleScene)
{
	Lib::GetInstance().LoadWaveFile("Sound\\start.wav");
}

SceneManager::~SceneManager() {
	delete m_pScene;
	Lib::GetInstance().CancelSound("Sound\\start.wav");
}

void SceneManager::Run() {
	SCENE_ID nextSceneId = m_pScene->Update();
	m_pScene->Draw();

	if (m_CurrentSceneId != nextSceneId) {
		delete m_pScene;
		Score::GetInstance().SetCurrentScene(nextSceneId);
		m_pScene = SceneFactory::GetInstance().Create(nextSceneId);
		m_CurrentSceneId = nextSceneId;
	}
}