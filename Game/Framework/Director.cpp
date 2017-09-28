#include "Director.h"
#include "Scene.h"

US_CV_FRAMEWORK

pDirector Director::_instance = NULL;

void Director::init ( pWindow window, Scene* startScene )
{
	_device = new Device();
	_device->init(window);

	D3DXCreateSprite(_device->getDevice(), &_spriteHandler);

	_isGameRunning = true;

	_windowWidth = window->getWidth();
	_windowHeight = window->getHeight();

	_runningScene = startScene;
	_runningScene->init();

	_currentTime = 0;
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

void Director::mainLoop(float delta)
{
	_interval = delta;
	_currentTime += delta;
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
	_runningScene->update();
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

Scene* Director::getRunningScene ( ) const
{
	return _runningScene;
}

float Director::getDeltaTime ( ) const
{
	return _interval;
}

float Director::getCurrentTime ( ) const
{
	return _currentTime;
}

void Director::render () const
{
	auto device = Director::getInstance()->getDevice (  );
	device->getDevice()->BeginScene();
	device->clearScreen();
	// main game's logic

	if(_runningScene!= NULL)
	{
		_runningScene->render();
	}

	device->getDevice()->EndScene();

	device->present();
}
