#include"SceneManager.h"
#include"SceneFactory.h"
#include"TitleScene.h"
#include"Score.h"

SceneManager::SceneManager() :
	m_pScene(new TitleScene)
{
}

SceneManager::~SceneManager() {
	delete m_pScene;
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