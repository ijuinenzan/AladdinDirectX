#include "Viewport.h"

US_CV_FRAMEWORK

Viewport::Viewport ( )
{
}

Viewport::Viewport ( float x, float y )
{
	_worldPosition.x = x;
	_worldPosition.y = y;
}

Viewport::Viewport ( float x, float y, float width, float height )
{
	_worldPosition.x = x;
	_worldPosition.y = y;
	_width = width;
	_height = height;
}

Viewport::~Viewport ( )
{
}

void Viewport::setPositionWorld ( Vec2 position )
{
	_worldPosition = position;
}

Vec2 Viewport::getPositionWorld ( ) const
{
	return _worldPosition;
}

float Viewport::getWidth ( ) const
{
	return _width;
}

float Viewport::getHeight ( ) const
{
	return _height;
}

Vec3 Viewport::getPositionInViewport ( Vec3* position ) const
{
	D3DXMATRIX mt;
	D3DXVECTOR4 posViewport;

	D3DXMatrixIdentity(&mt);
	mt._22 = -1.0f;
	mt._41 = (-1) * _worldPosition.x;
	mt._42 = _worldPosition.y;

	D3DXVec3Transform(&posViewport, position, &mt);

	return Vec3(posViewport.x, posViewport.y, posViewport.z);
}

bool Viewport::isContains ( const RECT& rect ) const
{
	if (rect.right < _worldPosition.x)
		return false;
	if (rect.bottom > _worldPosition.y)
		return false;
	if (rect.left > _worldPosition.x + _width)
		return false;
	if (rect.top < _worldPosition.y - _height)
		return false;
	return true;
}

RECT Viewport::getBounding ( ) const
{
	RECT rect;

	rect.left = _worldPosition.x;
	rect.top = _worldPosition.y;
	rect.bottom = rect.top - _height;
	rect.right = rect.left + _width;

	return rect;
}
