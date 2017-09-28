#ifndef __VIEWPORT_H__
#define __VIEWPORT_H__

#include "Definitions.h"

NS_CV_FRAMEWORK
NS_CV_FRAMEWORK_BEGIN

class Viewport
{
public:
	Viewport();
	Viewport(float x, float y);
	Viewport(float x, float y, float width, float height);
	~Viewport();

	void setPositionWorld(Vec2 position);
	Vec2 getPositionWorld() const;

	float getWidth() const;
	float getHeight() const;

	Vec3 getPositionInViewport(Vec3* position) const;

	bool isContains(const RECT &rect) const;

	RECT getBounding() const;
private:
	Vec2 _worldPosition;
	float _width;
	float _height;
};

typedef Viewport* pViewport;

NS_CV_FRAMEWORK_END

#endif //__VIEWPORT_H__