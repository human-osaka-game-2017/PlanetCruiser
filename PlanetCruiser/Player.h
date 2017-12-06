#ifndef PLAYER_H
#define PLAYER_H

#include<ObjectBase.h>
#include<Font.h>

class SquareCollider;

class Player :public ObjectBase {
public:
	Player();
	virtual ~Player();

	enum STATE {
		ALLIVE,
		CLUSH,
		DEAD
	};

	virtual void Update();
	virtual void Draw();

	bool GetCollidedFlg() {
		return m_WasCllided;
	}

	static const int kClushPicWidth = 5120;
	static const int kClushPicHeight = 128;

private:
	SquareCollider* m_pCollider;
	Font* m_pFont;
	float m_Speed = 0.15f;
	unsigned int m_AnimFrCnt = 0;
	unsigned int m_CurrentAnimNo = 0;
	bool m_IsRight = true;
	bool m_WasCllided = false;
	STATE m_CurrentState = ALLIVE;

	void Collision();

	const float kAcceleration = 0.07f; //‰Á‘¬“x
	const int kWidth =	72;
	const int kHeight = 110;
	const int kClushWidth = 128;
	const int kClushHeight = 128;
	const int kCollideWidth = 72;
	const int kCollideHeight = 110;
};
#endif