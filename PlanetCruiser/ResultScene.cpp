#include"ResultScene.h"
#include<Lib.h>
#include"ResultBackground.h"
#include"Score.h"

ResultScene::ResultScene() {
	Lib::GetInstance().LoadPictureFile("Assets\\GameOver.png", ResultBackground::kPicWidth, ResultBackground::kPicHeight);

	ResultBackground* pResultBackGround = new ResultBackground();

	m_PtrObjects.push_back(pResultBackGround);
}

ResultScene::~ResultScene() {

}

SceneManager::SCENE_ID ResultScene::Update() {
	SceneManager::SCENE_ID nextScene = SceneManager::SCENE_ID::RESULT;

	for (auto itr = m_PtrObjects.begin(); itr != m_PtrObjects.end(); itr++)
	{
		(*itr)->Update();
	}

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