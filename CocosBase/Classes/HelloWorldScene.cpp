// 2バイト文字対応
#pragma execution_character_set("utf-8")

#include "HelloWorldScene.h"
#include "Game3DDemoScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    /**  you can create scene with following comment code instead of using csb file.
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    **/
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
//    auto rootNode = CSLoader::createNode("MainScene.csb");
//    addChild(rootNode);

    auto mainScene = CSLoader::getInstance()->createNode("MainScene.csb");
//    auto mainScene = CSLoader::getInstance()->createNode("Game3DDemoScene.csb");
    this->addChild(mainScene);
    

    // ボタンノードを取得
    auto button_3d = mainScene->getChildByName<ui::Button*>("Button_3D");
    
    // タッチイベント追加
    button_3d->addTouchEventListener([this](Ref* sender, ui::Widget::TouchEventType type) {
        
        // タッチ中
        if (type == ui::Widget::TouchEventType::BEGAN) {
            dynamic_cast<ui::Button*>(sender)->setTitleText("押されている");
        }
        
        // タッチが終わった後に実行
        if (type == ui::Widget::TouchEventType::ENDED || type == ui::Widget::TouchEventType::CANCELED) {
            dynamic_cast<ui::Button*>(sender)->setTitleText("サンプル");
            Director::getInstance()->replaceScene(TransitionFade::create(1.0f, Game3DDemo::createScene(), Color3B::WHITE));
        }
    });


    return true;
}
