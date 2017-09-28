#include "Sprite.h"

US_CV_FRAMEWORK

Sprite::Sprite(LPCSTR filePath, int totalFrames, int cols)
{
	_origin = Vec2(0.5f, 0.5f);
	_scale = Vec2(1.0f, 1.0f);
	_zIndex = 1;
	_rotate = 0.0f;

	auto result = _texture.loadFromFile(filePath);
	if(result != D3D_OK)
	{
		throw exception("Cannot create texture");
	}

	_totalFrames = totalFrames;
	_columns = cols;
	_textureWidth = _texture.getWidth();
	_textureHeight = _texture.getHeight();
	_frameWidth = _textureWidth / cols;
	_frameHeight = _textureHeight * cols / totalFrames;

	_index = 0;
	_currentFrame = Vec2(0.0f, 0.0f);

	setIndex(0);
	updateBounding();

	_isDrawBounding = false;
	_surface = NULL;

	Director::getInstance()->getDevice()->getDevice()->CreateOffscreenPlainSurface(
		Director::getInstance()->getWindowWidth(),
		Director::getInstance()->getWindowHeight(),
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&_surface,
		NULL);
}


Sprite::~Sprite()
{
}

void Sprite::release ( )
{
	_texture.release();
}

void Sprite::renderSelf ( )
{
	_texture.render(
		&_frameRect,
		Vec2(int(_position.x), int(_position.y)),
		_scale,
		_rotate,
		_origin,
		_zIndex
	);
}

//void Sprite::render ( pViewport viewport )
//{
//	_texture.render(
//		&_frameRect,
//		*viewport,
//		_position,
//		_scale,
//		_rotate,
//		_origin,
//		_zIndex
//	);
//
//	if (_surface == nullptr || _isDrawBounding == false)
//	{
//		return;
//	}
//
//	RECT r;
//	r.top = WINDOW_HEIGHT - _bound.top;
//	r.left = _bound.left;
//	r.bottom = WINDOW_HEIGHT - _bound.bottom;
//	r.right = _bound.right;
//
//	Director::getInstance()->getDevice()->getDevice()->ColorFill(_surface, NULL, CV_COLOR_KEY);
//	Director::getInstance()->getDevice()->getDevice()->StretchRect(
//		_surface,
//		NULL,
//		Director::getInstance()->getDevice()->getSurface(),
//		&r,
//		D3DTEXF_NONE
//	);
//}

void Sprite::setPosition ( float x, float y, float z )
{
	Node::setPosition(x, y, z);
	updateBounding();
}

void Sprite::setPosition ( Vec3 vector )
{
	Node::setPosition(vector);
	updateBounding();
}

void Sprite::setPosition ( Vec2 position )
{
	Node::setPosition(position);
	updateBounding();
}

void Sprite::setPositionX ( float x )
{
	Node::setPositionX(x);
	updateBounding();
}

void Sprite::setPositionY ( float y )
{
	Node::setPositionY(y);
	updateBounding();
}

void Sprite::setScale ( Vec2 scale )
{
	Node::setScale(scale);
	updateBounding();
}

void Sprite::setScale ( float scale )
{
	Node::setScale(scale);
	updateBounding();
}

void Sprite::setScaleX ( float sx )
{
	Node::setScaleX(sx);
	updateBounding();
}

void Sprite::setScaleY ( float sy )
{
	Node::setScaleY(sy);
	updateBounding();
}

void Sprite::setRotate ( float degree )
{
	Node::setRotate(degree);
	updateBounding();
}

void Sprite::setOrigin ( Vec2 origin )
{
	Node::setOrigin(origin);
	updateBounding();
}

void Sprite::setZIndex ( float z )
{
	Node::setZIndex(z);
}

RECT Sprite::getBounding ( ) const
{
	return _bound;
}

void Sprite::setFrameRect ( RECT rect )
{
	_frameRect = rect;

	_frameWidth = abs(_frameRect.left - _frameRect.right);
	_frameHeight = abs(_frameRect.top - _frameRect.bottom);

	updateBounding();
}

void Sprite::setFrameRect ( float top, float right, float bottom, float left )
{
	_frameRect.top = top;
	_frameRect.right = right;
	_frameRect.left = left;
	_frameRect.bottom = bottom;

	_frameWidth = abs(_frameRect.left - _frameRect.right);
	_frameHeight = abs(_frameRect.top - _frameRect.bottom);

	updateBounding();
}

void Sprite::setFrameRect ( float x, float y, int width, int height )
{
	_frameRect.top = y;
	_frameRect.right = x + width;
	_frameRect.left = x;
	_frameRect.bottom = y + height;

	_frameWidth = width;
	_frameHeight = height;

	updateBounding();
}

RECT Sprite::getFrameRect ( ) const
{
	return _frameRect;
}

void Sprite::nextFrame ( )
{
	setIndex(_index + 1);
}

void Sprite::setIndex ( int index )
{
	_index = index;
	setCurrentFrame();
}

int Sprite::getFrameWidth ( ) const
{
	return _frameWidth * abs(_scale.x);
}

int Sprite::getFrameHeight ( ) const
{
	return _frameHeight * abs(_scale.y);
}

int Sprite::getTextureWidth ( ) const
{
	return _textureWidth*abs(_scale.x);
}

int Sprite::getTextureHeight ( ) const
{
	return _textureHeight*abs(_scale.y);
}

void Sprite::drawBounding ( bool draw )
{
	_isDrawBounding = draw;
}

void Sprite::setOpacity ( float opacity )
{
	_opacity = opacity;
	_texture.setColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, _opacity));
}

float Sprite::getOpacity ( ) const
{
	return _opacity;
}

void Sprite::setColor ( D3DXCOLOR color )
{
	_color = color;
	_texture.setColor(color);
}

D3DXCOLOR Sprite::getColor ( ) const
{
	return _color;
}

void Sprite::setFrameRect ( )
{
	this->_frameRect.left = long ( _currentFrame . x ) * _frameWidth;
	this->_frameRect.right = _frameRect.left + _frameWidth;
	this->_frameRect.top = long ( _currentFrame . y ) * _frameHeight;
	this->_frameRect.bottom = _frameRect.top + _frameHeight;
}

void Sprite::setCurrentFrame ( )
{
	_currentFrame.x = _index % _columns;
	_currentFrame.y = _index / _columns;

	setFrameRect();
}

void Sprite::updateBounding ( )
{
	float scaleW = _frameWidth * abs(_scale.x);
	float scaleH = _frameHeight * abs(_scale.y);

	this->_bound.left = _position.x - scaleW * _origin.x;
	this->_bound.bottom = _position.y - scaleH * _origin.y;
	this->_bound.right = _bound.left + scaleW;
	this->_bound.top = _bound.bottom + scaleH;

	// 4 diem cua hcn
	Vec2 p1 = Vec2(_bound.left, _bound.top);
	Vec2 p2 = Vec2(_bound.right, _bound.top);
	Vec2 p3 = Vec2(_bound.right, _bound.bottom);
	Vec2 p4 = Vec2(_bound.left, _bound.bottom);
	_anchorPoint = Vec2(_bound.left + scaleW * _origin.x, _bound.bottom + scaleH * _origin.y);

	//rotate 4 diem
	p1 = rotatePointAroundOrigin(p1, _rotate, _anchorPoint);
	p2 = rotatePointAroundOrigin(p2, _rotate, _anchorPoint);
	p3 = rotatePointAroundOrigin(p3, _rotate, _anchorPoint);
	p4 = rotatePointAroundOrigin(p4, _rotate, _anchorPoint);

	_bound.left = min(min(p1.x, p2.x), min(p3.x, p4.x));
	_bound.top = max(max(p1.y, p2.y), max(p3.y, p4.y));
	_bound.right = max(max(p1.x, p2.x), max(p3.x, p4.x));
	_bound.bottom = min(min(p1.y, p2.y), min(p3.y, p4.y));
}

Vec2 Sprite::rotatePointAroundOrigin ( Vec2 point, float angle, Vec2 origin ) const
{
	// nhan ma tran xoay
	/*
	x' = x.cos(t) - y.sin(t)
	y' = x.sin(t) + y.cos(t)
	t la goc quay theo radian
	*/

	Vec2 newPoint;
	//lech 90 do nen tru lai
	float rad = -angle * (M_PI / 180);

	float _sin = sin(rad);
	float _cos = cos(rad);

	//doi diem ve goc
	point -= origin;

	//xoay
	newPoint.x = point.x * _cos - point.y * _sin;
	newPoint.y = point.x * _sin + point.y * _cos;

	//doi ve cho cu
	newPoint += origin;

	return newPoint;

}
