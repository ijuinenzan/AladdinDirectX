#ifndef __DIRECTOR_H__
#define __DIRECTOR_H__

#include "Definitions.h"
#include "IWindow.h"
#include "Device.h"

NS_CV_FRAMEWORK
NS_CV_FRAMEWORK_BEGIN

class Scene;

class Director
{
public:
	void init(pWindow window, Scene* startScene);
	void release() const;
	void stopGame();
	void mainLoop(float delta);

	pDevice getDevice() const;
	LPD3DXSPRITE getSpriteHandler() const;

	static Director* getInstance();

	bool isGameRunning() const;

	int getWindowWidth() const;
	int getWindowHeight() const;

	Scene* getRunningScene() const;

	float getDeltaTime() const;

	float getCurrentTime() const;
private:
	static Director* _instance;

	pDevice _device;
	LPD3DXSPRITE _spriteHandler;
	bool _isGameRunning;
	int _windowWidth;
	int _windowHeight;
	float _interval;
	float _currentTime;

	Scene* _runningScene;

	void render() const;
};

typedef Director* pDirector;

NS_CV_FRAMEWORK_END

#endif //__DIRECTOR_H__