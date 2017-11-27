#ifndef SCENEBASE_H
#define SCENEBASE_H

#include"SceneManager.h"

class SceneBase {
public:
	SceneBase() {};
	virtual ~SceneBase() {};

	virtual SceneManager::SCENE_ID Update() = 0;
	virtual void Draw() = 0;
};
#endif