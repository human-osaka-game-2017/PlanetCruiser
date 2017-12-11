#ifndef TITLESCENE_H
#define TITLESCENE_H

#include "SceneBase.h"
#include<vector>

class ObjectBase;

class TitleScene :public SceneBase{
public:
	TitleScene();
	virtual ~TitleScene();

	virtual SceneManager::SCENE_ID Update();
	virtual void Draw();

private:
	std::vector<ObjectBase*> m_PtrObjects;
};
#endif