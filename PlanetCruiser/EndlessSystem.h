#ifndef ENDLESSSYSTEM_H
#define ENDLESSSYSTEM_H

#include"ObjBase.h"

class Pattern;

class EndlessSystem :public ObjBase {
public:
	EndlessSystem();
	virtual ~EndlessSystem();

	virtual void Update();
	virtual void Draw();

private:
	Pattern* m_pCurrentPattern;
	Pattern* m_pNextPattern;
};
#endif