#include"MainScene.h"
#include<Lib.h>
#include"Player.h"
#include"Background.h"
#include"EndlessSystem.h"
#include"Score.h"
#include<ColliderManager.h>
#include"Score.h"
#include"MessageManager.h"
#include"ScoreUp.h"
#include"ItemManager.h"

MainScene::MainScene() {
	Lib::GetInstance().LoadPictureFile("Assets\\integ.png", kPicWidth, kPicHeight);
	Lib::GetInstance().LoadPictureFile("Assets\\Background.png", Background::kPicWidth, Background::kPicHeight);
	Lib::GetInstance().LoadPictureFile("Assets\\fonts.png", Score::kPicWidth, Score::kPicHeight);
	Lib::GetInstance().LoadPictureFile("Assets\\Crush.png", Player::kCrushPicWidth, Player::kCrushPicHeight);
	Lib::GetInstance().LoadPictureFile("Assets\\ScoreUp.png", ScoreUp::kWidth, ScoreUp::kHeight);

	ObjectBase* player = new Player;
	ObjectBase* background = new Background;
	ObjectBase* endlessSystem = new EndlessSystem;
	ObjectBase* itemManager = new ItemManager;

	m_Objects.push_back(background);
	m_Objects.push_back(endlessSystem);
	m_Objects.push_back(itemManager);
	m_Objects.push_back(player);
}

MainScene::~MainScene() {
	Lib::GetInstance().CancelTexture("Assets\\integ.png");
	Lib::GetInstance().CancelTexture("Assets\\Background.png");
	Lib::GetInstance().CancelTexture("Assets\\Crush.png");
	Lib::GetInstance().CancelTexture("Assets\\ScoreUp.png");
	Lib::GetInstance().CancelTexture("Assets\\fonts.png");

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

	ColliderManager::GetInstance().Update();

	Score::GetInstance().Update();

	if (MessageManager::GetInstance().GetPlayerState() == Player::STATE::DEAD) {
		nextScene = SceneManager::SCENE_ID::RESULT;
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

	Score::GetInstance().Draw();

	Lib::GetInstance().EndDraw();
}