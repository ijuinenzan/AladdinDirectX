#ifndef __NODE_H__
#define __NODE_H__

#include "Definitions.h"
#include "Viewport.h"

NS_CV_FRAMEWORK
NS_CV_FRAMEWORK_BEGIN

class Node
{
public:
	Node();
	~Node();

	virtual void release();

	virtual Vec2 getPosition();
	virtual float getPositionX();
	virtual float getPositionY();

	virtual Vec2 getLocalPostion();
	virtual float getLocalPositionX();
	virtual float getLocalPositionY();

	virtual void setPosition(Vec3 vector);
	virtual void setPosition(float x, float y, float z);
	virtual void setPosition(Vec2 position);
	virtual void setPosition(float x, float y);
	virtual void setPositionX(float x);
	virtual void setPositionY(float y);

	virtual void setLocalPosition(Vec3 vector);
	virtual void setLocalPosition(float x, float y, float z);
	virtual void setLocalPosition(Vec2 position);
	virtual void setLocalPosition(float x, float y);
	virtual void setLocalPositionX(float x);
	virtual void setLocalPositionY(float y);

	virtual Vec2 getScale();
	virtual Vec2 getLocalScale();

	virtual void setScale(Vec2 scale);
	virtual void setScale(float scale);
	virtual void setScaleX(float sx);
	virtual void setScaleY(float sy);

	virtual void setLocalScale(Vec2 scale);
	virtual void setLocalScale(float scale);
	virtual void setLocalScaleX(float sx);
	virtual void setLocalScaleY(float sy);

	virtual float getRotate();
	virtual void setRotate(float degree);

	virtual Vec2 getOrigin();
	virtual void setOrigin(Vec2 origin);

	virtual void setZIndex(float z);
	virtual float getZIndex();

	virtual void render();
	virtual void render(pViewport viewport);

	virtual void addChild(Node* node, bool willUpdatePosition = false, bool willUpdateScale = false);

	virtual Node* getParent() const;
	virtual vector<Node*> getChildren() const;

	//virtual void update();
protected:
	Vec2 _position;
	Vec2 _scale;
	float _rotate;
	Vec2 _origin;
	float _zIndex;

	Vec2 _localPosition;
	Vec2 _localScale;

	vector<Node*> _children;
	Node* _parent;

	void updateChildPosition(Vec2 delta);
	void updateChildScale(Vec2 delta);

	virtual void renderSelf();
	virtual void renderSelf(pViewport viewport);
	virtual void releaseSelf();
};

typedef Node* pNode;

NS_CV_FRAMEWORK_END

#endif //__NODE_H__