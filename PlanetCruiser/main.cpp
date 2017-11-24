#include<Windows.h>
#include<tchar.h>
#include<stdio.h>
#include"Common.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg)
	{
	case WM_KEYDOWN:        // キーが押されたとき
		if (wp == VK_ESCAPE)
		{
			DestroyWindow(hWnd);
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wp, lp);

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;

	WNDCLASSEX Wndclass;
	Wndclass.cbSize = sizeof(WNDCLASSEX);
	Wndclass.style = CS_HREDRAW | CS_VREDRAW;
	Wndclass.lpfnWndProc = WndProc;
	Wndclass.cbClsExtra = 0;
	Wndclass.cbWndExtra = 0;
	Wndclass.hInstance = hInstance;
	Wndclass.hIcon = NULL;
	Wndclass.hCursor = NULL;
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	Wndclass.lpszMenuName = NULL;
	Wndclass.lpszClassName = TEXT("WINDOW");
	Wndclass.hIconSm = NULL;

	//Windowの登録
	RegisterClassEx(&Wndclass);

	//Windowの生成
	hWnd = CreateWindow(
		TEXT("WINDOW"),								//ウィンドウのクラス名
		"PlanetCruiser", 							//ウィンドウのタイトル
		WS_VISIBLE | WS_OVERLAPPEDWINDOW,				//ウィンドウスタイル
		CW_USEDEFAULT,						// ウィンドウの横方向の位置x
		CW_USEDEFAULT,						// ウィンドウの縦方向の位置y
		WINDOW_WIDTH,							// Width（幅）
		WINDOW_HEIGHT,							// Height（高さ）
		NULL,
		NULL,
		hInstance,							// アプリケーションインスタンスのハンドル
		NULL
	);
	SetProcessDPIAware();					//お守り

	//resize
	RECT rw, rc;
	GetWindowRect(hWnd, &rw);
	GetClientRect(hWnd, &rc);

	int new_width = (rw.right - rw.left) - (rc.right - rc.left) + WINDOW_WIDTH;
	int new_height = (rw.bottom - rw.top) - (rc.bottom - rc.top) + WINDOW_HEIGHT;

	SetWindowPos(hWnd, NULL, 0, 0, new_width, new_height, SWP_NOMOVE | SWP_NOZORDER);

	ShowWindow(hWnd, SW_SHOW);
	ShowCursor(false);


	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	DWORD prevtime = timeGetTime();
	DWORD currenttime;

	timeBeginPeriod(1);

	while (msg.message != WM_QUIT) {

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != false) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {

			currenttime = timeGetTime();

			if (currenttime - prevtime >= 1000 / 60) {
			}
		}
	}
	timeEndPeriod(1);

	return (int)msg.wParam;
}