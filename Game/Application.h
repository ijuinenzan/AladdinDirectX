#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Framework/Definitions.h"
#include "Framework/Window.h"
#include "Framework/Director.h"

NS_CV_FRAMEWORK
NS_CV_FRAMEWORK_BEGIN

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

	pWindow _window;
};

typedef Application* pApplication;

NS_CV_FRAMEWORK_END

#endif __APPLICATION_H__