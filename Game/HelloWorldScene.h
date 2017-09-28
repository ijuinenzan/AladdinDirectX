#pragma once
#include "Framework\Scene.h"

enum State
{
	MOVING_RIGHT,
	MOVING_DOWN,
	MOVING_LEFT,
	MOVING_UP
};

class HelloWorldScene :
	public FrameWork::Scene
{
public:
	HelloWorldScene();
	~HelloWorldScene();
	
	void init() override;
	void update() override;
private:
	State _currentState;
	FrameWork::Sprite* _testSprite;
};

