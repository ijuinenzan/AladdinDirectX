#include "Node.h"

US_CV_FRAMEWORK

Node::Node()
{
	_scale = Vec2(1.0f, 1.0f);
	_localScale = Vec2(1.0f, 1.0f);
	_children.clear();
	_parent = NULL;
}


Node::~Node()
{
}

void Node::releaseNode ( )
{
	for(auto node: _children)
	{
		node->releaseNode();
		delete node;
	}
	release();
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

Vec2 Node::getLocalPostion ( )
{
	return _localPosition;
}

float Node::getLocalPositionX ( )
{
	return _localPosition.x;
}

float Node::getLocalPositionY ( )
{
	return _localPosition.y;
}

void Node::setPosition ( Vec3 vector )
{
	auto deltaPosition = Vec2(vector.x, vector.y) - _position;
	_localPosition += deltaPosition;
	_position = Vec2(vector.x, vector.y);
	updateChildPosition(deltaPosition);
}

void Node::setPosition ( float x, float y, float z )
{
	auto deltaPosition = Vec2(x, y) - _position;
	_localPosition += deltaPosition;
	_position = Vec2(x, y);
	updateChildPosition(deltaPosition);
}

void Node::setPosition ( Vec2 position )
{
	auto deltaPosition = Vec2(position.x, position.y) - _position;
	_localPosition += deltaPosition;
	_position = Vec2(position.x, position.y);
	updateChildPosition(deltaPosition);
}

void Node::setPosition ( float x, float y )
{
	auto deltaPosition = Vec2(x, y) - _position;
	_localPosition += deltaPosition;
	_position = Vec2(x, y);
	updateChildPosition(deltaPosition);
}

void Node::setPositionX ( float x )
{
	auto deltaPosition = Vec2(x, _position.y) - _position;
	_localPosition += deltaPosition;
	_position.x = x;
	updateChildPosition(deltaPosition);
}

void Node::setPositionY ( float y )
{
	auto deltaPosition = Vec2(_position.x, y) - _position;
	_localPosition += deltaPosition;
	_position.y = y;
	updateChildPosition(deltaPosition);
}

void Node::setLocalPosition ( Vec3 vector )
{
	auto deltaPosition = Vec2(vector.x, vector.y) - _localPosition;
	_position += deltaPosition;
	_localPosition = Vec2(vector.x, vector.y);
	updateChildPosition(deltaPosition);
}

void Node::setLocalPosition ( float x, float y, float z )
{
	auto deltaPosition = Vec2(x, y) - _localPosition;
	_position += deltaPosition;
	_localPosition = Vec2(x, y);
	updateChildPosition(deltaPosition);
}

void Node::setLocalPosition ( Vec2 position )
{
	auto deltaPosition = Vec2(position.x, position.y) - _localPosition;
	_position += deltaPosition;
	_localPosition = Vec2(position.x, position.y);
	updateChildPosition(deltaPosition);
}

void Node::setLocalPosition ( float x, float y )
{
	auto deltaPosition = Vec2(x, y) - _localPosition;
	_position += deltaPosition;
	_localPosition = Vec2(x, y);
	updateChildPosition(deltaPosition);
}

void Node::setLocalPositionX ( float x )
{
	auto deltaPosition = Vec2(x, _localPosition.y) - _localPosition;
	_position += deltaPosition;
	_localPosition.x = x;
	updateChildPosition(deltaPosition);
}

void Node::setLocalPositionY ( float y )
{
	auto deltaPosition = Vec2(_localPosition.x, y) - _localPosition;
	_position += deltaPosition;
	_localPosition.y = y;
	updateChildPosition(deltaPosition);
}

Vec2 Node::getScale ( )
{
	return _scale;
}

Vec2 Node::getLocalScale ( )
{
	return _localScale;
}

void Node::setScale ( Vec2 scale )
{
	auto deltaScale = Vec2(_localScale.x*scale.x / _scale.x, _localScale.y*scale.y / _scale.y);
	_localScale = deltaScale;
	_scale = Vec2(scale.x, scale.y);
	updateChildScale(deltaScale);
}

void Node::setScale ( float scale )
{
	auto deltaScale = Vec2(_localScale.x*scale / _scale.x, _localScale.y*scale / _scale.y);
	_localScale = deltaScale;
	_scale = Vec2(scale, scale);
	updateChildScale(deltaScale);
}

void Node::setScaleX ( float sx )
{
	auto deltaScale = Vec2(_localScale.x*sx / _scale.x, _localScale.y);
	_localScale = deltaScale;
	_scale.x = sx;
	updateChildScale(deltaScale);
}

void Node::setScaleY ( float sy )
{
	auto deltaScale = Vec2(_localScale.x, _localScale.y*sy / _scale.y);
	_localScale = deltaScale;
	_scale.y = sy;
	updateChildScale(deltaScale);
}

void Node::setLocalScale ( Vec2 scale )
{
	auto deltaScale = Vec2(_scale.x*scale.x / _localScale.x, _scale.y*scale.y / _localScale.y);
	_scale = deltaScale;
	_localScale = Vec2(scale.x, scale.y);
	updateChildScale(deltaScale);
}

void Node::setLocalScale ( float scale )
{
	auto deltaScale = Vec2(_scale.x*scale / _localScale.x, _scale.y*scale / _localScale.y);
	_scale = deltaScale;
	_localScale = Vec2(scale, scale);
	updateChildScale(deltaScale);
}

void Node::setLocalScaleX ( float sx )
{
	auto deltaScale = Vec2(_scale.x*sx / _localScale.x, _scale.y);
	_scale = deltaScale;
	_localScale.x = sx;
	updateChildScale(deltaScale);
}

void Node::setLocalScaleY ( float sy )
{
	auto deltaScale = Vec2(_scale.x,_scale.y*sy / _localScale.y);
	_scale = deltaScale;
	_localScale.x = sy;
	updateChildScale(deltaScale);
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

void Node::render ( )
{

}

void Node::render ( pViewport viewport )
{
}

void Node::release ( )
{

}

void Node::update ( )
{
}

Node* Node::create ( )
{
	Node* node = new Node;
	return node;
}

void Node::renderNode ( )
{
	this->render();
	for(auto node: _children)
	{
		node->renderNode();
	}
}

void Node::renderNode ( pViewport viewport )
{
	this->render(viewport);
	for (auto node : _children)
	{
		node->renderNode(viewport);
	}
}

void Node::addChild ( Node* node, bool willUpdatePosition, bool willUpdateScale )
{
	if(node == this)
	{
		return;
	}

	for(auto child: _children)
	{
		if(child == node)
		{
			return;
		}
	}

	_children.push_back(node);
	node->_parent = this;
	
	if(willUpdatePosition)
	{
		auto oldPosition = node->_position;
		node->_position = node->_localPosition + _position;
		node->updateChildPosition(node->_position - oldPosition);
	}
	else
	{
		node->_localPosition = node->_position - _position;
	}

	if(willUpdateScale)
	{
		auto oldScale = node->_scale;
		node->_scale = Vec2(node->_localScale.x / _scale.x, node->_localScale.y / _scale.y);
		node->updateChildScale(Vec2(node->_scale.x/oldScale.x, node->_scale.y/oldScale.y));
	}
	else
	{
		node->_localScale = Vec2(node->_scale.x * _scale.x, node->_scale.y * _scale.y);
	}
}

Node* Node::getParent ( ) const
{
	return _parent;
}

vector<Node*> Node::getChildren ( ) const
{
	return _children;
}

void Node::updateNode ( )
{
	this->update();
	for(auto node: _children)
	{
		node->updateNode();
	}
}

void Node::updateChildPosition ( Vec2 delta )
{
	for(auto node: _children)
	{
		node->_position += delta;
		node->updateChildPosition(delta);
	}
}

void Node::updateChildScale ( Vec2 delta )
{
	for(auto node: _children)
	{
		node->_scale.x *= delta.x;
		node->_scale.y *= delta.y;
		node->updateChildScale(delta);
	}
}
