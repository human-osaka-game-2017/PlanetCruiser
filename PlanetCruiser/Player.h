#ifndef PLAYER_H
#define PLAYER_H

#include"ObjBase.h"

class Player :public ObjBase {
public:
	Player();
	virtual ~Player();

	virtual void Update();
	virtual void Draw();

private:
	float m_Speed = 0.3f;
	bool m_IsRight = true;

	const float kAcceleration = 0.2f; //‰Á‘¬“x
	const int kWidth =	72;
	const int kHeight = 110;
};
#endif