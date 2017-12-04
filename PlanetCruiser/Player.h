#ifndef PLAYER_H
#define PLAYER_H

#include<ObjectBase.h>
#include<Font.h>

class SquareCollider;

class Player :public ObjectBase {
public:
	Player();
	virtual ~Player();

	virtual void Update();
	virtual void Draw();

	bool GetCollidedFlg() {
		return m_WasCllided;
	}

private:
	SquareCollider* m_pCollider;
	Font* m_pFont;
	float m_Speed = 0.15f;
	bool m_IsRight = true;
	bool m_WasCllided = false;

	void Collision();

	const float kAcceleration = 0.07f; //‰Á‘¬“x
	const int kWidth =	72;
	const int kHeight = 110;
	const int kCollideWidth = 72;
	const int kCollideHeight = 110;
};
#endif