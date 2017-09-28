#include "HelloWorldScene.h"
#include "Framework/Director.h"



HelloWorldScene::HelloWorldScene()
{
}


HelloWorldScene::~HelloWorldScene()
{
}

void HelloWorldScene::init ( )
{
	_testSprite = new FrameWork::Sprite("test.png");
	_testSprite->setPosition(50, 50);
	addChild(_testSprite);
	_currentState = MOVING_RIGHT;

	auto sprite2 = new FrameWork::Sprite("test.png");
	sprite2->setOpacity(0.5f);
	sprite2->setScale(1.3f);
	sprite2->setPosition(0, 0);
	_testSprite->addChild(sprite2, true, true);
}

void HelloWorldScene::update ( )
{
	auto dt = FrameWork::Director::getInstance (  )->getDeltaTime();
	switch ( _currentState )
	{
	case MOVING_DOWN:
		if(_testSprite->getPositionY (  ) > FrameWork::Director::getInstance (  )->getWindowHeight (  ))
		{
			_currentState = MOVING_LEFT;
		}
		break;
	case MOVING_UP:
		if (_testSprite->getPositionY() < 0)
		{
			_currentState = MOVING_RIGHT;
		}
		break;
	case MOVING_RIGHT:
		if (_testSprite->getPositionX() > FrameWork::Director::getInstance()->getWindowWidth())
		{
			_currentState = MOVING_DOWN;
		}
		break;
	case MOVING_LEFT:
		if (_testSprite->getPositionX() <0)
		{
			_currentState = MOVING_UP;
		}
		break;
	}

	switch(_currentState)
	{
	case MOVING_RIGHT:
		_testSprite->setLocalPositionX(_testSprite->getLocalPositionX() + 100 * dt);
		break;
	case MOVING_LEFT:
		_testSprite->setLocalPositionX(_testSprite->getLocalPositionX() - 100 * dt);
		break;
	case MOVING_UP:
		_testSprite->setLocalPositionY(_testSprite->getLocalPositionY() - 100 * dt);
		break;
	case MOVING_DOWN:
		_testSprite->setLocalPositionY(_testSprite->getLocalPositionY() + 100 * dt);
		break;
	}
}
