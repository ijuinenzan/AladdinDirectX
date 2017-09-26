#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Definitions.h"
#include "Window.h"

NS_CV_FRAMEWORK
NS_CV_FRAMEWORK_BEGIN

class Application
{
public:
	static Application* getInstance();

	void run(HINSTANCE hInstance, LPCSTR applicationName);

	~Application();
private:
	static Application* _instance;
	Application();

	pWindow _window;
};

typedef Application* pApplication;

NS_CV_FRAMEWORK_END

#endif __APPLICATION_H__