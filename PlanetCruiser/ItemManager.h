#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include <ObjectBase.h>

class ScoreUp;

class ItemManager :public ObjectBase{
public:
	ItemManager();
	virtual ~ItemManager();

	virtual void Update();
	virtual void Draw();

private:
	ScoreUp* m_pScoreUp;
};
#endif