#ifndef SCOREUO_H
#define SCOREUO_H

#include <ObjectBase.h>

class SquareCollider;

class ScoreUp :public ObjectBase{
public:
	ScoreUp();
	virtual ~ScoreUp();

	virtual void Update();
	virtual void Draw();

	bool GetTakeFlg() {
		return m_WasTaken;
	}

	static const int kWidth = 70;
	static const int kHeight = 70;

private:
	SquareCollider* m_pCollider;
	bool m_WasTaken = false;
	void Collision();

	const int kCollideWidth = 70;
	const int kCollideHeight = 70;
	const int kMaxTryNum = 10;
};
#endif