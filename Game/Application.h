#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Framework/Definitions.h"
#include "Framework/Director.h"

class Application
{
public:
	static Application* getInstance();

	void run(HINSTANCE hInstance, LPCSTR applicationName, int fps);

	void setAnimationInterval(float interval);

	~Application();
private:
	static Application* _instance;
	Application();

	LARGE_INTEGER _animationInterval;

	FrameWork::pWindow _window;
};

typedef Application* pApplication;

#endif __APPLICATION_H__