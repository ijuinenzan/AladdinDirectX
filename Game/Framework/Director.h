#ifndef __DIRECTOR_H__
#define __DIRECTOR_H__

#include "Definitions.h"
#include "IWindow.h"
#include "Device.h"

NS_CV_FRAMEWORK
NS_CV_FRAMEWORK_BEGIN

class Director
{
public:
	void init(pWindow window);
	void release() const;
	void stopGame();
	void mainLoop();
	static Director* getInstance();

	bool isGameRunning() const;
private:
	static Director* _instance;

	pDevice _device;
	bool _isGameRunning;
};

typedef Director* pDirector;

NS_CV_FRAMEWORK_END

#endif //__DIRECTOR_H__