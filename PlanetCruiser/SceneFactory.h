#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

#include"SceneManager.h"

class SceneBase;

class SceneFactory {
public:
	static SceneFactory& GetInstance() {
		if (m_pInstance == nullptr) {
			m_pInstance = new SceneFactory;
		}
		return *m_pInstance;
	}

	SceneBase* Create(SceneManager::SCENE_ID scene_id);

private:
	static SceneFactory* m_pInstance;
	SceneFactory();
	~SceneFactory();

	SceneFactory(const SceneFactory&);
	void operator = (const SceneFactory&);
};


#endif
