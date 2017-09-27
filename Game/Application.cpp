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

void Application::run ( HINSTANCE hInstance, LPCSTR applicationName, int fps)
{
	_window = new Window(hInstance, applicationName, WINDOW_WIDTH, WINDOW_HEIGHT, false);
	_window->initWindow();

	setAnimationInterval(1.0 / fps);

	auto director = Director::getInstance();
	director->init(_window);

	//main message loop
	_LARGE_INTEGER last;
	_LARGE_INTEGER now;

	QueryPerformanceCounter(&last);

	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);

	LONGLONG interval = 0LL;
	LONG waitMS = 0L;

	while(director->isGameRunning (  ))
	{
		QueryPerformanceCounter(&now);
		interval = now.QuadPart - last.QuadPart;
		if (interval >= _animationInterval.QuadPart)
		{
			last.QuadPart = now.QuadPart;
			director->mainLoop();
		}
		else
		{
			// The precision of timer on Windows is set to highest (1ms) by 'timeBeginPeriod' from above code,
			// but it's still not precise enough. For example, if the precision of timer is 1ms,
			// Sleep(3) may make a sleep of 2ms or 4ms. Therefore, we subtract 1ms here to make Sleep time shorter.
			// If 'waitMS' is equal or less than 1ms, don't sleep and run into next loop to
			// boost CPU to next frame accurately.
			waitMS = (_animationInterval.QuadPart - interval) * 1000LL / freq.QuadPart - 1L;
			if (waitMS > 1L)
				Sleep(waitMS);
		}
	}
	Director::getInstance()->release();
}

void Application::setAnimationInterval ( float interval )
{
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	_animationInterval.QuadPart = LONGLONG ( interval * freq . QuadPart );
}

Application::Application()
{
}


Application::~Application()
{
	delete _instance;
	_instance = NULL;
}
