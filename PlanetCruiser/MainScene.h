#ifndef MAINSCENE_H
#define MAINSCENE_H

#include<vector>
#include"SceneBase.h"

class ObjectBase;

class MainScene :public SceneBase {
public:
	MainScene();
	virtual ~MainScene();

	virtual SceneManager::SCENE_ID Update();
	virtual void Draw();
private:
	std::vector<ObjectBase*> m_Objects;

	const int kPicWidth = 512;
	const int kPicHeight = 512;
};
#endif