//
//  Main.cpp
//  test
//
//  Created by 浦田 祐輝 on 2013/11/18.
//
//

#include "Main.h"

USING_NS_CC;

CCScene* Main::scene(){
    CCScene* scene = CCScene::create();
    CCLayer* layer = Main::create();
    scene->addChild(layer);
    return scene;
}

bool Main::init(){
    if(!CCLayer::init()){
        return false;
    }
    const char* listName = "HelloWorldTexture.plist";
    const char* atlasName = "HelloWorldTexture.png";
    const char* spriteName = "HelloWorld128.png";
    
//    this->batching(listName, atlasName, spriteName);
//    this->offscreenRendering(listName, atlasName, spriteName);
    this->offScreenRenderingAndBatching(listName, atlasName, spriteName);

    return true;
}

void Main::batching(const char* listName, const char* atlasName, const char* spriteName){
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

    CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    cache->addSpriteFramesWithFile(listName, atlasName);
    
    CCTexture2D* texture2D = CCTextureCache::sharedTextureCache()->addImage(spriteName);
    CCSpriteBatchNode* batchNode = CCSpriteBatchNode::createWithTexture(texture2D);
    this->addChild(batchNode, 0);

    for(int i = 0; i < 10; i++){
        CCSprite* sprite = CCSprite::createWithTexture(batchNode->getTexture());
        sprite->setPosition(ccp( rand() % (int)visibleSize.width, rand() % (int)visibleSize.height ));
        this->addChild(sprite);
    }
    
}

void Main::offscreenRendering(const char* listName, const char* atlasName, const char* spriteName){
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    cache->addSpriteFramesWithFile(listName, atlasName);
    
    CCSprite* sprite = CCSprite::createWithSpriteFrameName(spriteName);
    
    CCRenderTexture* renderTexture = CCRenderTexture::create(visibleSize.width, visibleSize.height);
    renderTexture->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    this->addChild(renderTexture);
    
    renderTexture->beginWithClear(0, 0, 1, 1);
    for(int i= 0; i < 10000; i++){
        sprite->setPosition(ccp( rand() % (int)visibleSize.width, rand() % (int)visibleSize.height ));
        sprite->visit();
    }
    renderTexture->end();
}

void Main::offScreenRenderingAndBatching(const char* listName, const char* atlasName, const char* spriteName){
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    cache->addSpriteFramesWithFile(listName, atlasName);
    
    CCTexture2D* texture2D = CCTextureCache::sharedTextureCache()->addImage(atlasName);
    CCSpriteBatchNode* batchNode = CCSpriteBatchNode::createWithTexture(texture2D);
    this->addChild(batchNode, 0);
    
    //render
    CCRenderTexture* renderTexture = CCRenderTexture::create(visibleSize.width, visibleSize.height);
    renderTexture->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    this->addChild(renderTexture);
    
    //オフスクリーンレンダリング
    renderTexture->beginWithClear(0, 0, 1, 1);
    for(int i=0; i < 150000; i++){
        CCSprite* sprite = CCSprite::createWithSpriteFrameName(spriteName);
        sprite->setPosition(ccp( rand() % (int)visibleSize.width, rand() % (int)visibleSize.height ));
        sprite->visit();
    }
    renderTexture->end();
}
