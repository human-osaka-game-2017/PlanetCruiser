#ifndef ENDLESSSYSTEM_H
#define ENDLESSSYSTEM_H

#include"ObjBase.h"

class Pattern;
class PatternManager;

class EndlessSystem :public ObjBase {
public:
	EndlessSystem();
	virtual ~EndlessSystem();

	virtual void Update();
	virtual void Draw();

	static const float kScrollSpeed;
	static const int kMaxScrollY;

private:
	Pattern* m_pCurrentPattern = nullptr;
	Pattern* m_pNextPattern = nullptr;

	PatternManager* m_pPatternManager = nullptr;
};
#endif