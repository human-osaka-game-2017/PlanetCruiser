#ifndef PLAYER_H
#define PLAYER_H

#include<ObjectBase.h>

class SquareCollider;

class Player :public ObjectBase {
public:
	Player();
	virtual ~Player();

	virtual void Update();
	virtual void Draw();

private:
	SquareCollider* m_pCollider;
	float m_Speed = 0.15f;
	bool m_IsRight = true;

	void Collision();

	const float kAcceleration = 0.07f; //‰Á‘¬“x
	const int kWidth =	72;
	const int kHeight = 110;
	const int kCollideWidth = 72;
	const int kCollideHeight = 110;
};
#endif