#ifndef NEWRECORD_H
#define NEWRECORD_H

#include<ObjectBase.h>

class NewRecord :public ObjectBase{
public:
	NewRecord();
	virtual ~NewRecord();

	virtual void Update();
	virtual void Draw();

	static const int kPicWidth = 150;
	static const int kPicHeight = 40;
};
#endif