#include"MainScene.h"
#include<Lib.h>
#include"Player.h"

MainScene::MainScene() {
	Lib::GetInstance().LoadPictureFile("Assets\\sample2.png", Player::kPicWidth, Player::kPicHeight);

	ObjBase* player = new Player;

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

	return nextScene;
}

void MainScene::Draw() {
	Lib::GetInstance().StartDraw();

	for (auto itr = m_Objects.begin(); itr != m_Objects.end(); itr++)
	{
		(*itr)->Draw();
	}

	Lib::GetInstance().EndDraw();
}