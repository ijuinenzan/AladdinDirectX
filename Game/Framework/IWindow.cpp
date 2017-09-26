#include "IWindow.h"

US_CV_FRAMEWORK

bool IWindow::isFullScreen ( ) const
{
	return _isFullScreen;
}

int IWindow::getWidth ( ) const
{
	return _width;
}

int IWindow::getHeight ( ) const
{
	return _height;
}

int IWindow::getFrameRate ( ) const
{
	return _fps;
}

HWND IWindow::getWindow ( ) const
{
	return _hWnd;
}

HINSTANCE IWindow::getInstance ( ) const
{
	return _hInstance;
}
