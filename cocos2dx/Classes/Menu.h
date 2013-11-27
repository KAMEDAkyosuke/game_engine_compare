//
//  Menu.h
//  test
//
//  Created by 浦田 祐輝 on 2013/11/18.
//
//

#ifndef __test__Menu__
#define __test__Menu__

#include "cocos2d.h"


class Menu : public cocos2d::CCLayer
{
public:
    static cocos2d::CCScene* scene();
    virtual bool init();
    CREATE_FUNC(Menu);
    void mainMove();
};

#endif /* defined(__test__Menu__) */
