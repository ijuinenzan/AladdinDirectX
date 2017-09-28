#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "Definitions.h"
#include "Node.h"
#include "Texture.h"

NS_CV_FRAMEWORK
NS_CV_FRAMEWORK_BEGIN

class Sprite: public Node
{
public:
	Sprite(LPCSTR filePath, int zIndex = 0);
	~Sprite();
	
	void releaseSelf() override;

	void setFrameRect(RECT rect);
	void setFrameRect(float top, float right, float bottom, float left);
	void setFrameRect(float x, float y, int width, int height);
	RECT getFrameRect() const;

	int getTextureWidth() const;

	int getTextureHeight() const;

	void setOpacity(float opacity);
	float getOpacity() const;

	void setColor(D3DXCOLOR color);
	D3DXCOLOR getColor() const;
private:
	Texture _texture;
	float _opacity;
	D3DXCOLOR _color;

	RECT _frameRect;

	int _textureWidth;
	int _textureHeight;

	void setFrameRect();

	void renderSelf() override;
	void renderSelf(pViewport viewport) override;
};

typedef Sprite* pSprite;

NS_CV_FRAMEWORK_END
#endif //__SPRITE_H__
