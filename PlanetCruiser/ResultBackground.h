#ifndef RESULTBACKGROUND_H
#define RESULTBACKGROUND_H

#include<ObjectBase.h>

class ResultBackground :public ObjectBase {
public:
	ResultBackground();
	virtual ~ResultBackground();

	virtual void Update();
	virtual void Draw();

	static const int kPicWidth = 550;
	static const int kPicHeight = 880;

private:

};
#endif