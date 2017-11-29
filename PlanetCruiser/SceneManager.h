#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

class SceneBase;

class SceneManager {
public:
	SceneManager();
	~SceneManager();

	enum SCENE_ID {
		MAIN
	};

	void Run();

private:
	SCENE_ID m_CurrentSceneId = MAIN;
	SceneBase* m_pScene;
};
#endif