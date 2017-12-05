#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

class SceneBase;

class SceneManager {
public:
	SceneManager();
	~SceneManager();

	enum SCENE_ID {
		MAIN,
		RESULT
	};

	void Run();

	SCENE_ID GetCurrentScene_ID() {
		return m_CurrentSceneId;
	}

private:
	SCENE_ID m_CurrentSceneId = MAIN;
	SceneBase* m_pScene;
};
#endif