#include"SceneManager.h"
#include"SceneFactory.h"
#include"MainScene.h"
#include"Score.h"

SceneManager::SceneManager() :
	m_pScene(new MainScene)
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
		m_pScene = SceneFactory::GetInstance().Create(nextSceneId);
		Score::GetInstance().SetCurrentScene(nextSceneId);
	}
}