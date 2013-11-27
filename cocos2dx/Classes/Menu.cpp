//
//  Menu.cpp
//  test
//
//  Created by 浦田 祐輝 on 2013/11/18.
//
//

#include "Menu.h"
#include "Main.h"
#include "cocos-ext.h"



using namespace cocos2d::extension;

USING_NS_CC;

CCScene* Menu::scene(){
    CCScene* scene = CCScene::create();
    CCLayer* layer = Menu::create();
    scene->addChild(layer);
    return scene;
}

bool Menu::init(){
    if(!CCLayer::init()){
        return false;
    }

    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

    
    CCMenuItem* nomoveBtn = CCMenuItemImage::create("start_btn.png", "start_btn_high.png", this, menu_selector(Menu::mainMove));
    
    
    CCMenu* topMenu = CCMenu::create(nomoveBtn, NULL);
    topMenu->alignItemsVerticallyWithPadding(5);
    topMenu->setPosition(ccp(visibleSize.width / 2, visibleSize.height * 0.35));
    this->addChild(topMenu);
    
    return true;
}

void Menu::mainMove(){
    CCDirector* director = CCDirector::sharedDirector();
    CCScene* pScene = Main::scene();
    director->replaceScene(CCTransitionFade::create(3.0f, pScene));
}

