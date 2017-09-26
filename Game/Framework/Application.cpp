#include "Application.h"

US_CV_FRAMEWORK

pApplication Application::_instance = NULL;

Application* Application::getInstance ( )
{
	if(_instance == NULL)
	{
		_instance = new Application();

	}

	return _instance;
}

void Application::run ( HINSTANCE hInstance, LPCSTR applicationName)
{
	_window = new Window(hInstance, applicationName, WINDOW_WIDTH, WINDOW_HEIGHT, 60, false);
	_window->initWindow();
}

Application::Application()
{
}


Application::~Application()
{
	delete _instance;
	_instance = NULL;
}
