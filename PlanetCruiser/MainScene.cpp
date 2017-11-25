#include"MainScene.h"

MainScene::MainScene() {

}

MainScene::~MainScene() {

}

SceneManager::SCENE_ID MainScene::Update() {
	SceneManager::SCENE_ID nextScene = SceneManager::SCENE_ID::MAIN;

	return nextScene;
}

void MainScene::Draw() {

}