#include "PushSpaceKey.h"
#include<Lib.h>
#include"MassageManager.h"

PushSpaceKey::PushSpaceKey(bool currentSceneIsTitle):
	ObjectBase(D3DXVECTOR2(270,700)),
	m_CurrentSceneIsTitle(currentSceneIsTitle)
{
}

PushSpaceKey::~PushSpaceKey() {

}

void PushSpaceKey::Update() {
	if (Lib::GetInstance().GetKeyState(Utility::KEY_KIND::SPACE) == Utility::BUTTON_STATE::PUSH) {
		MassageManager::GetInstance().SetPushSpaceKeyFlg(true);
	}

	++m_AlphaFrCnt;
	if (m_AlphaFrCnt == kMaxAlphaFrCnt) {
		m_AlphaFrCnt = 0;
	}
}

void PushSpaceKey::Draw() {
	int alpha;

	if (m_AlphaFrCnt < kMaxAlphaFrCnt / 2) {
		alpha = ((float)m_AlphaFrCnt / (float)kMaxAlphaFrCnt) * 255;
	}
	else {
		alpha = ((float)(kMaxAlphaFrCnt - m_AlphaFrCnt) / (float)kMaxAlphaFrCnt) * 255;
	}

	DWORD color = D3DCOLOR_RGBA(255, 255, 255, alpha);

	if (m_CurrentSceneIsTitle) {
		Lib::GetInstance().Draw(m_Pos, "Assets\\sPushSpaceKey.png", (float)kPicWidth, (float)kPicHeight, 0.0f, 0.0f, 0.0f, 1.0f, color);
	}
	else {
		Lib::GetInstance().Draw(m_Pos, "Assets\\rPushSpaceKey.png", (float)kPicWidth, (float)kPicHeight, 0.0f, 0.0f, 0.0f, 1.0f, color);
	}
}