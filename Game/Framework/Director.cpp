#include "Director.h"

US_CV_FRAMEWORK

pDirector Director::_instance = NULL;

void Director::init ( pWindow window )
{
	_device = new Device();
	_device->init(window);

	D3DXCreateSprite(_device->getDevice(), &_spriteHandler);

	_isGameRunning = true;
}

void Director::release ( ) const
{
	_device->release();
	delete _device;

	_spriteHandler->Release();

	delete _instance;
	_instance = NULL;
}

void Director::stopGame ( )
{
	_isGameRunning = false;
}

void Director::mainLoop ( )
{
	MSG msg;

#pragma region Translate Message
	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
			stopGame();
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
#pragma endregion

}

pDevice Director::getDevice ( ) const
{
	return _device;
}

LPD3DXSPRITE Director::getSpriteHandler ( ) const
{
	return _spriteHandler;
}

Director* Director::getInstance ( )
{
	if(_instance == NULL)
	{
		_instance = new Director;
	}

	return _instance;
}

bool Director::isGameRunning ( ) const
{
	return _isGameRunning;
}
