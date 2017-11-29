#ifndef ASTEROID_H
#define ASTEROID_H

#include"ObjBase.h"

class Asteroid :public ObjBase {
public:
	struct AsteroidIniData {
		float x = 0.0f;
		float y = 0.0f;
		float speed = 0.0f;
		float tlTu = 0.0f;
		float tlTv = 0.0f;
		float width = 0.0f;
		float height = 0.0f;
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
	const int kSwitchPoint = -100;
};
#endif