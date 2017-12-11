#include "NewRecord.h"
#include<Lib.h>
#include"Score.h"

NewRecord::NewRecord():
	ObjectBase(D3DXVECTOR2(100.0f,600.0f))
{
}

NewRecord::~NewRecord(){
}

void NewRecord::Update() {

}

void NewRecord::Draw() {
	Lib::GetInstance().Draw(m_Pos, "Assets\\NewRecord.png", kPicWidth, kPicHeight);
}