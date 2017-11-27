#ifndef PLAYER_H
#define PLAYER_H

#include"ObjBase.h"

class Player :public ObjBase {
public:
	Player();
	virtual ~Player();

	virtual void Update();
	virtual void Draw();

	static const int kPicWidth =	128;
	static const int kPicHeight =	256;

private:
	float m_Speed = 0.3f;
	bool m_IsRight = true;

	const float kAcceleration = 0.2f;
	const int kWidth =	128;
	const int kHeight = 256;
};
#endif