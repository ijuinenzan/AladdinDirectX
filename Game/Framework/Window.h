#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "Definitions.h"
#include "IWindow.h"

NS_CV_FRAMEWORK
NS_CV_FRAMEWORK_BEGIN

class Window: public IWindow
{
public:
	Window(HINSTANCE hInstance, LPCSTR className, int width, int height, int isFullScreen);

	void initWindow () override;
protected:
	static HRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);
};

NS_CV_FRAMEWORK_END

#endif //__WINDOW_H__