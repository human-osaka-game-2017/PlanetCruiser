#ifndef PUSHSPACEKEY_H
#define PUSHSPACEKEY_H

#include<ObjectBase.h>

class PushSpaceKey :public ObjectBase{
public:
	PushSpaceKey(bool currentSceneIsTitle);
	virtual ~PushSpaceKey();

	virtual void Update();
	virtual void Draw();

	static const int kPicWidth = 400;
	static const int kPicHeight = 150;
private:
	int m_AlphaFrCnt = 0;

	const int kMaxAlphaFrCnt = 180;

	bool m_CurrentSceneIsTitle;
};
#endif