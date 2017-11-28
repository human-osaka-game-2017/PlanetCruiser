#ifndef ASTEROID_H
#define ASTEROID_H

#include"ObjBase.h"

class Asteroid :public ObjBase {
public:
	struct AsteroidIniData {
		float speed = 0.0f;
		float tu = 0.0f;
		float tv = 0.0f;
		float magnifying = 1.0f;
	};

	Asteroid(float x, float y, const AsteroidIniData& astData);
	virtual ~Asteroid();

	virtual void Update();
	virtual void Draw();

private:
	AsteroidIniData m_AsteroidData;
};
#endif