#ifndef PLAYER_H
#define PLAYER_H

#include<ObjectBase.h>

class Player :public ObjectBase {
public:
	Player();
	virtual ~Player();

	virtual void Update();
	virtual void Draw();

private:
	float m_Speed = 0.15f;
	bool m_IsRight = true;

	const float kAcceleration = 0.07f; //‰Á‘¬“x
	const int kWidth =	72;
	const int kHeight = 110;
};
#endif