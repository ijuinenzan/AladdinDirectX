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

	pDevice getDevice() const;
	LPD3DXSPRITE getSpriteHandler() const;

	static Director* getInstance();

	bool isGameRunning() const;
private:
	static Director* _instance;

	pDevice _device;
	LPD3DXSPRITE _spriteHandler;
	bool _isGameRunning;
};

typedef Director* pDirector;

NS_CV_FRAMEWORK_END

#endif //__DIRECTOR_H__