#ifndef __IWINDOW_H__
#define __IWINDOW_H__

#include "Definitions.h"

NS_CV_FRAMEWORK
NS_CV_FRAMEWORK_BEGIN

class IWindow
{
public:
	virtual void initWindow() = 0;

	virtual bool isFullScreen() const;
	virtual int getWidth() const;
	virtual int getHeight() const;
	virtual HWND getWindow() const;
	virtual HINSTANCE getInstance() const;
protected:
	HINSTANCE _hInstance;
	HWND _hWnd;

	LPCSTR _windowClassName;
	bool _isFullScreen;

	int _width;
	int _height;
};

typedef IWindow* pWindow;

NS_CV_FRAMEWORK_END

#endif //__IWINDOW_H__