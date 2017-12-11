#include"ResultScene.h"
#include<Lib.h>
#include"ResultBackground.h"
#include"PushSpaceKey.h"
#include"Score.h"
#include"MassageManager.h"

ResultScene::ResultScene() {
	Lib::GetInstance().LoadPictureFile("Assets\\GameOver.png", ResultBackground::kPicWidth, ResultBackground::kPicHeight);
	Lib::GetInstance().LoadPictureFile("Assets\\rPushSpaceKey.png", PushSpaceKey::kPicWidth, PushSpaceKey::kPicHeight);
	Lib::GetInstance().LoadPictureFile("Assets\\fonts.png", Score::kPicWidth, Score::kPicHeight);

	ResultBackground* pResultBackGround = new ResultBackground();
	PushSpaceKey* pPushSpaceKey = new PushSpaceKey(false);

	m_PtrObjects.push_back(pResultBackGround);
	m_PtrObjects.push_back(pPushSpaceKey);
}

ResultScene::~ResultScene() {
	Lib::GetInstance().CancelTexture("Assets\\GameOver.png");
	Lib::GetInstance().CancelTexture("Assets\\rPushSpaceKey.png");
	Lib::GetInstance().CancelTexture("Assets\\fonts.png");

	for (auto itr = m_PtrObjects.begin(); itr != m_PtrObjects.end(); itr++)
	{
		delete *itr;
	}
}

SceneManager::SCENE_ID ResultScene::Update() {
	SceneManager::SCENE_ID nextScene = SceneManager::SCENE_ID::RESULT;

	for (auto itr = m_PtrObjects.begin(); itr != m_PtrObjects.end(); itr++)
	{
		(*itr)->Update();
	}

	if (MassageManager::GetInstance().GetPushSpaceKeyFlg() == true) {
		MassageManager::GetInstance().SetPushSpaceKeyFlg(false);
		nextScene = SceneManager::SCENE_ID::MAIN;
	}

	Score::GetInstance().Update();

	return nextScene;
}

void ResultScene::Draw() {
	Lib::GetInstance().SetRenderState2D();

	Lib::GetInstance().StartDraw(0x00, 0x00, 0x00);

	for (auto itr = m_PtrObjects.begin(); itr != m_PtrObjects.end(); itr++)
	{
		(*itr)->Draw();
	}

	Score::GetInstance().Draw();

	Lib::GetInstance().EndDraw();
}