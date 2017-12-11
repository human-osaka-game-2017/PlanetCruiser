#ifndef TITLEBACKGROUND_H
#define TITLEBACKGROUND_H

#include<ObjectBase.h>

class TitleBackground :public ObjectBase{
public:
	TitleBackground();
	~TitleBackground();

	virtual void Update();
	virtual void Draw();

	static const int kPicWidth = 550;
	static const int kPicHeight = 880;
};
#endif