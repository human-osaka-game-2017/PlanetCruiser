#ifndef PLAYER_H
#define PLAYER_H

#include"ObjBase.h"

class Player :public ObjBase {
public:
	Player();
	virtual ~Player();

	virtual void Update();
	virtual void Draw();

	static const int kPicWidth =	72;
	static const int kPicHeight =	110;

private:
	const int kWidth = 72;
	const int kHeight = 110;
};

#endif