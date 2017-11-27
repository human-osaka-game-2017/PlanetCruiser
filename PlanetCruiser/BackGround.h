#ifndef BACKGROUND_H
#define BACKGROUND_H

#include"ObjBase.h"

class BackGround: public ObjBase {
public:
	BackGround();
	~BackGround();

	static const float kScrollSpeed = 0.1f;

};
#endif