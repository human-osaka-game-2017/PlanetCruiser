#ifndef OBJBASE_H
#define OBJBASE_H

#include<d3dx9.h>

class ObjBase {
public:
	ObjBase(const D3DXVECTOR2& pos):
		m_Pos(pos){};
	virtual ~ObjBase() {};

	virtual void Update() = 0;
	virtual void Draw() = 0;

	static const int kPicWidth = 512;
	static const int kPicHeight = 512;

protected:
	D3DXVECTOR2 m_Pos;
};
#endif