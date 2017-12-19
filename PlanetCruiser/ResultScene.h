#ifndef RESULTSCENE_H
#define RESULTSCENE_H

#include"SceneBase.h"
#include<vector>

class ObjectBase;

class ResultScene :public SceneBase {
public:
	ResultScene();
	virtual ~ResultScene();

	virtual SceneManager::SCENE_ID Update();
	virtual void Draw();

private:
	std::vector<ObjectBase*> m_PtrObjects;
	std::string m_SoundName;
};
#endif