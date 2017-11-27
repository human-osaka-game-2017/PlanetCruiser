#ifndef Background_H
#define Background_H

#include"ObjBase.h"

class Background :public ObjBase {
public:
	Background();
	virtual ~Background();

	virtual void Update();
	virtual void Draw();

	static const int kPicWidth = 500;
	static const int kPicHeight = 1778;

private:
	int m_FrCnt = 0;

	static const float kScrollSpeed;
};
#endif