#ifndef _GAME3DDEMO_SCENE_H
#define _GAME3DDEMO_SCENE_H

#include "cocos2d.h"

class Game3DDemo : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Game3DDemo);
};
#endif // __GAME3DDEMO_SCENE_H__