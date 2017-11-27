#include"Player.h"
#include<Lib.h>

Player::Player():
	ObjBase(D3DXVECTOR2(100.0,100.0))
{

}

Player::~Player() {

}

void Player::Update() {

}

void Player::Draw() {
	Lib::GetInstance().Draw(m_Pos, "Assets/sample2.png", (float)kWidth, (float)kHeight);
}