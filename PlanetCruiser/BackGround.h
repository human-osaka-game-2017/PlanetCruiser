#ifndef BACKGROUND_H
#define BACKGROUND_H

#include<ObjectBase.h>

class Background :public ObjectBase {
public:
	Background();
	virtual ~Background();

	virtual void Update();
	virtual void Draw();

	static const int kPicWidth = 550;
	static const int kPicHeight = 1024;

private:
	int m_FrCnt = 0;

	const int kWidth = 550;
	const int kHeight = 1024;
	const int kScrollSpeed = 1;
};
#endif