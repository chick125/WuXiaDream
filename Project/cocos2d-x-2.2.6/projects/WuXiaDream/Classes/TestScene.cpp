//
//  TestScene.cpp
//  WuXiaDream
//
//  Created by 何金 北京 on 15/3/26.
//
//

#include "TestScene.h"
#include "DataLoader.h"
CCScene* TestScene::scene()
{
    CCScene *scene=CCScene::create();
    TestScene *layer=TestScene::create();
    scene->addChild(layer);
    return scene;
}
bool TestScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    CCArray* testArray=DataLoader::getLoader()->parseStringArray("Test.plist", "NB");
    CCString *testString=(CCString*)testArray->objectAtIndex(2);

    CCLabelTTF* pLabel = CCLabelTTF::create(testString->getCString(), "Arial", 100);
    
//    // position the label on the center of the screen
//    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - pLabel->getContentSize().height));
    pLabel->cocos2d::CCNode::setPosition(1000, 500);
    
    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    return true;
}