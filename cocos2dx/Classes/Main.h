//
//  Main.cpp
//  test
//
//  Created by 浦田 祐輝 on 2013/11/18.
//
//

#ifndef __test__NoMove__
#define __test__NoMove__

#include "cocos2d.h"

class Main : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(Main);
private:
    void batching(const char* listName, const char* atlasName, const char* spriteName);
    void offscreenRendering(const char* listName, const char* atlasName, const char* spriteName);
    void offScreenRenderingAndBatching(const char* listName, const char* atlasName, const char* spriteName);
};

#endif /* defined(__test__NoMove__) */
