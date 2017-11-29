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
		float magnifying = 1.0f;
	};

	Asteroid(const AsteroidIniData& astData);
	virtual ~Asteroid();

	virtual void Update();
	virtual void Draw();

private:
	AsteroidIniData m_AsteroidData;
};
#endif