#include "Sprite.h"

US_CV_FRAMEWORK

Sprite::Sprite(LPCSTR filePath, int zIndex)
{
	_origin = Vec2(0.5f, 0.5f);
	_scale = Vec2(1.0f, 1.0f);
	_localScale = Vec2(1.0f, 1.0f);
	_zIndex = zIndex;
	_rotate = 0.0f;

	auto result = _texture.loadFromFile(filePath);
	if(result != D3D_OK)
	{
		throw exception("Cannot create texture");
	}

	_textureWidth = _texture.getWidth();
	_textureHeight = _texture.getHeight();

	setFrameRect();
}


Sprite::~Sprite()
{
}

void Sprite::releaseSelf ( )
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

void Sprite::renderSelf ( pViewport viewport )
{
	_texture.render(
		&_frameRect,
		*viewport,
		_position,
		_scale,
		_rotate,
		_origin,
		_zIndex
	);
}

//void Sprite::render ( pViewport viewport )
//{

//}


void Sprite::setFrameRect ( RECT rect )
{
	_frameRect = rect;
}

void Sprite::setFrameRect ( float top, float right, float bottom, float left )
{
	_frameRect.top = top;
	_frameRect.right = right;
	_frameRect.left = left;
	_frameRect.bottom = bottom;
}

void Sprite::setFrameRect ( float x, float y, int width, int height )
{
	_frameRect.top = y;
	_frameRect.right = x + width;
	_frameRect.left = x;
	_frameRect.bottom = y + height;
}

RECT Sprite::getFrameRect ( ) const
{
	return _frameRect;
}

int Sprite::getTextureWidth ( ) const
{
	return _textureWidth*abs(_scale.x);
}

int Sprite::getTextureHeight ( ) const
{
	return _textureHeight*abs(_scale.y);
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
	this->_frameRect.left =  0;
	this->_frameRect.right = _textureWidth;
	this->_frameRect.top = 0;
	this->_frameRect.bottom = _textureHeight;
}
