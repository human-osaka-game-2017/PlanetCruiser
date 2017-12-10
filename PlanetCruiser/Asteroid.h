#ifndef ASTEROID_H
#define ASTEROID_H

#include<ObjectBase.h>
class SquareCollider;

class Asteroid :public ObjectBase {
public:
	struct AsteroidIniData {
		float x = 0.0f;
		float y = 0.0f;
		float speed = 0.0f;
		float tlTu = 0.0f;
		float tlTv = 0.0f;
		float width = 0.0f;
		float height = 0.0f;
		float collidedWidth = 0.0f;
		float collidedHeight = 0.0f;
		float magnifying = 1.0f;
	};

	Asteroid(const AsteroidIniData& astData);
	virtual ~Asteroid();

	virtual void Update();
	virtual void Draw();

	void PullDown();
	const AsteroidIniData& GetAsteroidData() {
		return m_AsteroidData;
	}

private:
	AsteroidIniData m_AsteroidData;
	SquareCollider* m_pCollider;

	void Collision();

	const int kSwitchPoint = -100;
};
#endif