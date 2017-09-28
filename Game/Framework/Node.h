#ifndef __NODE_H__
#define __NODE_H__

#include "Definitions.h"

NS_CV_FRAMEWORK
NS_CV_FRAMEWORK_BEGIN

class Node
{
public:
	Node();
	~Node();

	virtual Vec2 getPosition();
	virtual float getPositionX();
	virtual float getPositionY();

	virtual void setPosition(Vec3 vector);
	virtual void setPosition(float x, float y, float z);
	virtual void setPosition(Vec2 position);
	virtual void setPosition(float x, float y);
	virtual void setPositionX(float x);
	virtual void setPositionY(float y);

	virtual Vec2 getScale();
	virtual void setScale(Vec2 scale);
	virtual void setScale(float scale);
	virtual void setScaleX(float sx);
	virtual void setScaleY(float sy);

	virtual float getRotate();
	virtual void setRotate(float degree);

	virtual Vec2 getOrigin();
	virtual void setOrigin(Vec2 origin);

	virtual void setZIndex(float z);
	virtual float getZIndex();

	virtual Vec2 getAnchorPoint();

	virtual void renderSelf();
	virtual void render();

	virtual void addChild(Node* node);

	virtual Node* getParent() const;
	virtual vector<Node*> getChildren() const;
protected:
	Vec2 _position;
	Vec2 _scale;
	float _rotate;
	Vec2 _origin;
	Vec2 _anchorPoint;
	float _zIndex;

	vector<Node*> _children;
	Node* _parent;
};

typedef Node* pNode;

NS_CV_FRAMEWORK_END

#endif //__NODE_H__