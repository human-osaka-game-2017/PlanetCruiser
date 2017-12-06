#include"ResultBackground.h"
#include"Common.h"
#include<Lib.h>

ResultBackground::ResultBackground():
	ObjectBase(D3DXVECTOR2(WINDOW_WIDTH/2,WINDOW_HEIGHT/2))
{

}

ResultBackground::~ResultBackground() {

}

void ResultBackground::Update() {
}

void ResultBackground::Draw() {
	Lib::GetInstance().Draw(m_Pos, "Assets\\GameOver.png", (float)kPicWidth, (float)kPicHeight);
}