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

	static const float kScrollSpeed;

private:
	Pattern* m_pCurrentPattern = nullptr;
	Pattern* m_pNextPattern = nullptr;
	PatternFactory* m_pPatternFactory = nullptr;

	const int kMaxScrollY = 1280;
};
#endif