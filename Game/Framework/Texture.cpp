#include "Texture.h"

US_CV_FRAMEWORK

Texture::Texture()
{
	_backColor = CV_WHITE;
	_texture = NULL;
}

Texture::~Texture()
{
}

void Texture::release()
{
	_texture->Release();
	_texture = NULL;
}

HRESULT Texture::loadFromFile(LPCSTR filePath, D3DXCOLOR backColor, D3DXCOLOR colorKey)
{
	auto result = D3DXGetImageInfoFromFile(filePath, &_imageInfo);

	if (result != D3D_OK)
	{
		return result;
	}

	auto device = Director::getInstance()->getDevice()->getDevice (  );
	Director::getInstance (  )->getSpriteHandler (  )->GetDevice(&device);

	result = D3DXCreateTextureFromFileEx(
		device,
		filePath,
		_imageInfo.Width,
		_imageInfo.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		colorKey,
		&_imageInfo,
		NULL,
		&_texture
	);

	_backColor = backColor;

	return result;
}

void Texture::render(const RECT* rect, const Vec3* center, const Vec3* position) const
{
	Director::getInstance (  )->getSpriteHandler (  )->Draw(
		_texture,
		rect,
		center,
		position,
		_backColor
	);
}

void Texture::render(RECT* sourceRect, Vec2 position, Vec2 scale, float rotate, Vec2 origin, float zIndex) const
{
	D3DXMATRIX matTransformed;
	D3DXMATRIX matOld;

	auto spriteHandler = Director::getInstance()->getSpriteHandler();

	Vec3 center = Vec3(abs(sourceRect->right - sourceRect->left) * origin.x, abs(sourceRect->top - sourceRect->bottom) * (1 - origin.y), zIndex);

	spriteHandler->GetTransform(&matOld);

	D3DXMatrixTransformation2D(
		&matTransformed,
		&position,
		0.0f,
		&scale,
		&position,
		D3DXToRadian(rotate),
		0
	);

	D3DXMATRIX matFinal = matTransformed * matOld;

	spriteHandler->SetTransform(&matFinal);

	spriteHandler->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_DONOTSAVESTATE);

	spriteHandler->Draw(
		this->_texture,
		sourceRect,
		&center,
		&Vec3(position.x, position.y, zIndex),
		_backColor);

	spriteHandler->SetTransform(&matOld);

	spriteHandler->End();
}

void Texture::render(RECT* sourceRect, Viewport viewport, Vec2 position, Vec2 scale, float rotate, Vec2 origin, float zIndex) const
{
	Vec3 viewportPosition = viewport.getPositionInViewport(&Vec3(position.x, position.y, zIndex));

	render(sourceRect, Vec2(int(viewportPosition.x), int(viewportPosition.y)), scale, rotate, origin, zIndex);
}

void Texture::setColor(D3DXCOLOR backColor)
{
	_backColor = backColor;
}

D3DXCOLOR Texture::getColor() const
{
	return _backColor;
}

int Texture::getWidth() const
{
	return _imageInfo.Width;
}

int Texture::getHeight() const
{
	return _imageInfo.Height;
}
