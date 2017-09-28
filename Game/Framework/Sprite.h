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
	Sprite(LPCSTR filePath, int totalFrames = 1, int cols = 1);
	~Sprite();
	
	void release();

	void renderSelf() override;
	//void render(pViewport viewport);

	void setPosition(float x, float y, float z = 1) override;
	void setPosition(Vec3 vector) override;
	void setPosition(Vec2 position) override;
	void setPositionX(float x) override;
	void setPositionY(float y) override;

	void setScale(Vec2 scale) override;
	void setScale(float scale) override;
	void setScaleX(float sx) override;
	void setScaleY(float sy) override;

	void setRotate(float degree) override;

	void setOrigin(Vec2 origin) override;

	void setZIndex(float z) override;

	RECT getBounding() const;

	void setFrameRect(RECT rect);
	void setFrameRect(float top, float right, float bottom, float left);
	void setFrameRect(float x, float y, int width, int height);
	RECT getFrameRect() const;

	void nextFrame();
	void setIndex(int index);

	int getFrameWidth() const;

	int getFrameHeight() const;

	int getTextureWidth() const;

	int getTextureHeight() const;

	void drawBounding(bool draw);

	void setOpacity(float opacity);
	float getOpacity() const;

	void setColor(D3DXCOLOR color);
	D3DXCOLOR getColor() const;
private:
	Texture _texture;
	float _opacity;
	D3DXCOLOR _color;

	RECT _bound;

	int _totalFrames;
	int _columns;
	int _index;
	Vec2 _currentFrame;

	RECT _frameRect;
	int _frameWidth;
	int _frameHeight;
	int _textureWidth;
	int _textureHeight;

	void setFrameRect();
	void setCurrentFrame();
	void updateBounding();

	Vec2 rotatePointAroundOrigin(Vec2 point, float angle, Vec2 origin) const;

	LPDIRECT3DSURFACE9	_surface;
	bool				_isDrawBounding;
};

NS_CV_FRAMEWORK_END
#endif //__SPRITE_H__
