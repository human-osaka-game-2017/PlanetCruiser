#ifndef ENDLESSSYSTEM_H
#define ENDLESSSYSTEM_H

#include<ObjectBase.h>

class Pattern;
class PatternManager;

class EndlessSystem :public ObjectBase {
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

	float m_ScrollAcceleration = 0;
	int m_ScrollFrCnt = 0;

	//easyタグを読み込んだ回数
	int m_EasyCnt = 0;
	//easyタグを読み込むべき回数
	int m_EasyNum = 0;

	void CreatePattern();
};
#endif