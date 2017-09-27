#include "Application.h"

US_CV_FRAMEWORK

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	pApplication application = Application::getInstance();
	application->run(hInstance, "Hello World", 60);
}