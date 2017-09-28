#pragma warning(disable: 4244)
#pragma warning(disable: 4715)

#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#define _USE_MATH_DEFINES

#include "../DirectX/Include/d3d9.h"
#include "../DirectX/Include/d3dx9.h"

#include <windows.h>
#include <exception>
#include <math.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

#define WINDOW_WIDTH 512
#define WINDOW_HEIGHT 448
#define SCALE_FACTOR 2.0f

#ifndef SAFE_DELETE

#define SAFE_DELETE(p) \
if(p) \
{\
	delete (p); \
	p = nullptr; \
} \

typedef D3DXVECTOR3 Vec3;
typedef D3DXVECTOR2 Vec2;
#define VECTOR2ZERO Vec2(0.0f, 0.0f)
#define VECTOR2ONE  Vec2(1.0f, 1.0f)

#define CV_WHITE D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f)
#define CV_COLOR_KEY D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f)

#define NS_CV_FRAMEWORK		namespace FrameWork

#define NS_CV_FRAMEWORK_BEGIN	{

#define NS_CV_FRAMEWORK_END	}

#define US_CV_FRAMEWORK		using namespace FrameWork;


#endif // !SAFE_DELETE



#endif //__DEFINITIONS_H__
