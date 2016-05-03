#include "Game3DDemoScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* Game3DDemo::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Game3DDemo::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Game3DDemo::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    // 画面サイズ取得
    auto screen = Director::getInstance()->getWinSize();


    // 背景用カメラ
    auto camBg = Camera::create(); // defaultと同じ設定のカメラを生成
    camBg ->setCameraFlag(CameraFlag::USER2);
    addChild(camBg );


    // 3D Camera
    int cx, cy, cz;
    int lx, ly, lz;
    cx = 0;
    cy = 30;
    cz = 150;
    lx = 0;
    ly = cy;
    lz = 0;
    auto cam3d = Camera::createPerspective(30, (GLfloat)screen.width / screen.height, 10, 1000);
    cam3d->setCameraFlag(CameraFlag::USER8);
    cam3d->setPosition3D(Vec3(cx, cy, cz));
    cam3d->lookAt(Vec3(lx, ly, lz));
    addChild(cam3d);


    //background
    auto bg = Sprite3D::create("background.c3t");
    bg->setTexture("background002.png");
    bg->setRotation3D(Vec3(0,0,270));
    bg->setPosition3D(Vec3(0, cy, 0));
    bg->setScale(37.f);
    bg->setGlobalZOrder(10.0f);


    // Cat
    auto model = Sprite3D::create("cat7_Anime_walk.c3t");
    model->setTexture("cat6_UV_temp.png");
    model->setScale(1.f);
    model->setPosition3D(Vec3(0, 0, 0));
    model->setGlobalZOrder(10.0f);
    // Animetion
    model->setRotation3D(Vec3(0,90,0));
    // the animation is contained in the .c3b file
    auto animation = Animation3D::create("cat7_Anime_walk.c3t");
    // creates the Action with Animation object
    auto animate = Animate3D::create(animation);
    // runs the animation
    model->runAction(RepeatForever::create(animate));
    
    
    this->addChild(bg);
    this->addChild(model);

    // カメラの割り当て
    bg ->setCameraMask((unsigned short)CameraFlag::USER8);
    model ->setCameraMask((unsigned short)CameraFlag::USER8);

    return true;
}
