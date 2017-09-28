#include "Director.h"
#include "Sprite.h"

US_CV_FRAMEWORK

pDirector Director::_instance = NULL;

Sprite *sprite;

void Director::init ( pWindow window )
{
	_device = new Device();
	_device->init(window);

	D3DXCreateSprite(_device->getDevice(), &_spriteHandler);

	_isGameRunning = true;

	_windowWidth = window->getWidth();
	_windowHeight = window->getHeight();

	sprite = new Sprite("test.png");
	sprite->setScale(0.5);
}

void Director::release ( ) const
{
	sprite->release();
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
		{
			stopGame();
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
#pragma endregion

	render();
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

int Director::getWindowWidth ( ) const
{
	return _windowWidth;
}

int Director::getWindowHeight ( ) const
{
	return _windowHeight;
}

void Director::render ( )
{
	auto device = Director::getInstance()->getDevice (  );
	device->getDevice()->BeginScene();
	device->clearScreen();
	// main game's logic

	sprite->render();

	device->getDevice()->EndScene();

	device->present();
}
