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
	SquareCollider* m_pUpCollider;
	SquareCollider* m_pDownCollider;
	D3DXVECTOR3 m_UpCollidePos;
	D3DXVECTOR3 m_DownCollidePos;
	float m_Speed = 0.15f;
	unsigned int m_AnimFrCnt = 0;
	unsigned int m_CurrentAnimNo = 0;
	bool m_IsRight = true;
	bool m_WasCllided = false;
	STATE m_CurrentState = ALLIVE;

	void Collision();
	void UpCollision();
	void DownCollision();

	const float kAcceleration = 0.07f; //‰Á‘¬“x
	const int kWidth =	72;
	const int kHeight = 110;
	const int kClushWidth = 128;
	const int kClushHeight = 128;
	const int kUpCollideWidth = 36;
	const int kUpCollideHeight = 62;
	const int kDownCollideWidth = 64;
	const int kDownCollideHeight = 38;
};
#endif