#ifndef MAINSCENE_H
#define MAINSCENE_H

#include<vector>
#include"SceneBase.h"

class ObjBase;

class MainScene :public SceneBase {
public:
	MainScene();
	virtual ~MainScene();

	virtual SceneManager::SCENE_ID Update();
	virtual void Draw();
private:
	std::vector<ObjBase*> m_Objects;
};
#endif