#include"MainScene.h"
#include<Lib.h>
#include"Player.h"
#include"Background.h"

MainScene::MainScene() {
	Lib::GetInstance().LoadPictureFile("Assets\\integ.png", ObjBase::kPicWidth, ObjBase::kPicHeight);
	Lib::GetInstance().LoadPictureFile("Assets\\Background.png", Background::kPicWidth, Background::kPicHeight);

	ObjBase* player = new Player;
	ObjBase* background = new Background;

	m_Objects.push_back(background);
	m_Objects.push_back(player);
}

MainScene::~MainScene() {
	for (auto itr = m_Objects.begin(); itr != m_Objects.end(); itr++)
	{
		delete *itr;
	}
}

SceneManager::SCENE_ID MainScene::Update() {
	SceneManager::SCENE_ID nextScene = SceneManager::SCENE_ID::MAIN;

	for (auto itr = m_Objects.begin(); itr != m_Objects.end(); itr++)
	{
		(*itr)->Update();
	}

	return nextScene;
}

void MainScene::Draw() {
	Lib::GetInstance().SetRenderState2D();

	Lib::GetInstance().StartDraw(0x00,0x00,0x00);

	for (auto itr = m_Objects.begin(); itr != m_Objects.end(); itr++)
	{
		(*itr)->Draw();
	}

	Lib::GetInstance().EndDraw();
}