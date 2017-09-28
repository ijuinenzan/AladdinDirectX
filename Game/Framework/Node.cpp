#include "Node.h"

US_CV_FRAMEWORK

Node::Node()
{
	_scale = Vec2(1.0f, 1.0f);
	_children.clear();
	_parent = NULL;
}


Node::~Node()
{
}

Vec2 Node::getPosition ( )
{
	return _position;
}

float Node::getPositionX ( )
{
	return _position.x;
}

float Node::getPositionY ( )
{
	return _position.y;
}

void Node::setPosition ( Vec3 vector )
{
	_position = Vec2(vector.x, vector.y);
}

void Node::setPosition ( float x, float y, float z )
{
	_position = Vec2(x, y);
}

void Node::setPosition ( Vec2 position )
{
	_position = Vec2(position.x, position.y);
}

void Node::setPosition ( float x, float y )
{
	_position.x = x;
	_position.y = y;
}

void Node::setPositionX ( float x )
{
	_position.x = x;
}

void Node::setPositionY ( float y )
{
	_position.y = y;
}

Vec2 Node::getScale ( )
{
	return _scale;
}

void Node::setScale ( Vec2 scale )
{
	_scale = Vec2(scale.x, scale.y);
}

void Node::setScale ( float scale )
{
	_scale = Vec2(scale, scale);
}

void Node::setScaleX ( float sx )
{
	_scale.x = sx;
}

void Node::setScaleY ( float sy )
{
	_scale.y = sy;
}

float Node::getRotate ( )
{
	return _rotate;
}

void Node::setRotate ( float degree )
{
	_rotate = degree;
}

Vec2 Node::getOrigin ( )
{
	return _origin;
}

void Node::setOrigin ( Vec2 origin )
{
	_origin = origin;
}

void Node::setZIndex ( float z )
{
	_zIndex = z;
}

float Node::getZIndex ( )
{
	return _zIndex;
}

Vec2 Node::getAnchorPoint ( )
{
	return _anchorPoint;
}

void Node::renderSelf ( )
{

}

void Node::render ( )
{
	this->renderSelf();
	for(auto node: _children)
	{
		node->renderSelf();
	}
}

void Node::addChild ( Node* node )
{
	_children.push_back(node);
	node->_parent = this;
}

Node* Node::getParent ( ) const
{
	return _parent;
}

vector<Node*> Node::getChildren ( ) const
{
	return _children;
}
