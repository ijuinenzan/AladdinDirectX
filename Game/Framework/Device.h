#ifndef __DEVICE_H__
#define __DEVICE_H__

#include "Definitions.h"
#include "IWindow.h"

NS_CV_FRAMEWORK
NS_CV_FRAMEWORK_BEGIN

class Device
{
public:
	void release() const;
	void clearScreen() const;
	void present() const;
	void init(pWindow window);

	LPDIRECT3DDEVICE9 getDevice() const;
	LPDIRECT3DSURFACE9 getSurface() const;

	Device();
private:
	LPDIRECT3D9 _pD3d;
	LPDIRECT3DDEVICE9 _pDevice;
	LPDIRECT3DSURFACE9 _surface;
};

typedef Device* pDevice;

NS_CV_FRAMEWORK_END

#endif //__DEVICE_H__
