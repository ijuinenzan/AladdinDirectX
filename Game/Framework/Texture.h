#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "Framework/Definitions.h"
#include "Framework/Director.h"

NS_CV_FRAMEWORK
NS_CV_FRAMEWORK_BEGIN

class Texture
{
public:
	Texture();
	~Texture();

	void release();

	HRESULT loadFromFile(LPCSTR filePath, D3DXCOLOR backColor = CV_WHITE, D3DXCOLOR colorKey = CV_COLOR_KEY);

	void render(const RECT* rect, const Vec3 *center, const Vec3 *position) const;

	void render(RECT* sourceRect, Vec2 position, Vec2 scale, float rotate, Vec2 origin, float zIndex = 0) const;

	//void render(LPD3DXSPRITE spriteHandler, RECT* sourceRect, Viewport viewport, CV_Vector2 position, CV_Vector2 scale, float rotate, CV_Vector2 origin, float zIndex = 0);

	void setColor(D3DXCOLOR backColor);
	D3DXCOLOR getColor() const;

	int getWidth() const;
	int getHeight() const;

private:
	LPDIRECT3DTEXTURE9 _texture;
	D3DXIMAGE_INFO _imageInfo;

	D3DXCOLOR _backColor;
};

typedef Texture* pTexture;

NS_CV_FRAMEWORK_END

#endif //__TEXTURE_H__