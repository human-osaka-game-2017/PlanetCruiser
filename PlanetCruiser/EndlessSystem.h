#ifndef ENDLESSSYSTEM_H
#define ENDLESSSYSTEM_H

#include"ObjBase.h"

class Pattern;
class PatternFactory;

class EndlessSystem :public ObjBase {
public:
	EndlessSystem();
	virtual ~EndlessSystem();

	virtual void Update();
	virtual void Draw();

private:
	Pattern* m_pCurrentPattern;
	Pattern* m_pNextPattern;
	PatternFactory* m_pPatternFactory;

	const float kScrollSpeed = 0.3f;
	const int kMaxScrollY = 1280;
};
#endif