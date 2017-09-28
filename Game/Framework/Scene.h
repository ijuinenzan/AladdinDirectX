#ifndef __SCENE_H__
#define __SCENE_H__

#include "Definitions.h"
#include "Node.h"
#include "Sprite.h"

NS_CV_FRAMEWORK
NS_CV_FRAMEWORK_BEGIN

class Scene: public Node
{
public:
	Scene();
	~Scene();

	virtual void init();

	void updateSelf() override;
private:
	pSprite sprite1;
	pSprite sprite2;
};

typedef Scene* pScene;

NS_CV_FRAMEWORK_END

#endif //__SCENE_H__