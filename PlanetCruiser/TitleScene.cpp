#include "TitleScene.h"
#include<Lib.h>
#include"MassageManager.h"
#include"TitleBackground.h"
#include"PushSpaceKey.h"

TitleScene::TitleScene(){
	Lib::GetInstance().LoadPictureFile("Assets\\Title.png", TitleBackground::kPicWidth, TitleBackground::kPicHeight);
	Lib::GetInstance().LoadPictureFile("Assets\\sPushSpaceKey.png", PushSpaceKey::kPicWidth, PushSpaceKey::kPicHeight);

	TitleBackground* pTitleBackground = new TitleBackground();
	PushSpaceKey* pPushSpaceKey = new PushSpaceKey(true);

	m_PtrObjects.push_back(pTitleBackground);
	m_PtrObjects.push_back(pPushSpaceKey);
}


TitleScene::~TitleScene(){
	Lib::GetInstance().CancelTexture("Assets\\Title.png");
	Lib::GetInstance().CancelTexture("Assets\\sPushSpaceKey.png");

	for (auto itr = m_PtrObjects.begin(); itr != m_PtrObjects.end(); itr++)
	{
		delete *itr;
	}
}

SceneManager::SCENE_ID TitleScene::Update() {
	SceneManager::SCENE_ID nextScene = SceneManager::SCENE_ID::TITLE;

	for (auto itr = m_PtrObjects.begin(); itr != m_PtrObjects.end(); itr++)
	{
		(*itr)->Update();
	}

	if (MassageManager::GetInstance().GetPushSpaceKeyFlg() == true) {
		MassageManager::GetInstance().SetPushSpaceKeyFlg(false);
		nextScene = SceneManager::SCENE_ID::MAIN;
	}

	return nextScene;
}

void TitleScene::Draw() {
	Lib::GetInstance().SetRenderState2D();

	Lib::GetInstance().StartDraw(0x00, 0x00, 0x00);

	for (auto itr = m_PtrObjects.begin(); itr != m_PtrObjects.end(); itr++)
	{
		(*itr)->Draw();
	}

	Lib::GetInstance().EndDraw();
}