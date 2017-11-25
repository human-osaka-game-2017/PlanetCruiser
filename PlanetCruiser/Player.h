#ifndef PLAYER_H
#define PLAYER_H

#include"ObjBase.h"

class Player :public ObjBase {
public:
	Player();
	virtual ~Player();

	virtual void Update();
	virtual void Draw();

};

#endif