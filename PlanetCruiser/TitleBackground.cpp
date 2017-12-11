#include "TitleBackground.h"
#include"Common.h"
#include<Lib.h>

TitleBackground::TitleBackground():
	ObjectBase(D3DXVECTOR2(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2))
{
}

TitleBackground::~TitleBackground()
{
}

void TitleBackground::Update() {
}

void TitleBackground::Draw() {
	Lib::GetInstance().Draw(m_Pos, "Assets\\Title.png", (float)kPicWidth, (float)kPicHeight);
}