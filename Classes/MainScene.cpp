#include "MainScene.h"
#include "Player.h"
#include "cocos2d.h"

USING_NS_CC; // макрос использования пространства имён cocos2d::
std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "Ws2_32.lib")

#include "stdio.h"
#include <iostream>
#include <string>
#include <fstream>
#include "AppDelegate.h"

Scene* MainScene::createScene()
{
    // все указатели, которые порождает Cocos - 2dx уже находятся под контролем выделенной памяти. Поэтому они не требуют явного удаления через delete или обертки в интеллектуальный указатель
    auto scene = Scene::create(); // создаем сцену
    auto layer = MainScene::create(); // создаем слой сцены
    scene->addChild(layer); // добавляем слой как ребенка на сцену
    return scene;
}

bool MainScene::init()
{
    if (!Layer::init()) // если мы не можем проинициализировать - просто выходим
    {
        return false;
    }


    //
    cocos2d::Sprite* leftWall = cocos2d::Sprite::create("wall.png");
    cocos2d::Sprite* rightWall = cocos2d::Sprite::create("wall.png");
    cocos2d::Sprite* top = cocos2d::Sprite::create("top.png");
    cocos2d::Sprite* bottom = cocos2d::Sprite::create("top.png");
    cocos2d::Sprite* line = cocos2d::Sprite::create("line.png");
    cocos2d::Sprite* redline = cocos2d::Sprite::create("redline.png");
    cocos2d::Sprite* wheel1 = cocos2d::Sprite::create("wheel.png");
    cocos2d::Sprite* wheel2 = cocos2d::Sprite::create("wheel.png");
    cocos2d::Sprite* wheel3 = cocos2d::Sprite::create("wheel.png");
    cocos2d::Sprite* wheel4 = cocos2d::Sprite::create("wheel.png");


    leftWall->setAnchorPoint(cocos2d::Vec2(0.5, 1));
    leftWall->setPosition(this->getBoundingBox().getMinX(), this->getBoundingBox().getMaxY());
    rightWall->setAnchorPoint(cocos2d::Vec2(0.5, 1));
    rightWall->setPosition(this->getBoundingBox().getMaxX(), this->getBoundingBox().getMaxY());
    top->setAnchorPoint(cocos2d::Vec2(0, 0.5));
    top->setPosition(this->getBoundingBox().getMinX(), this->getBoundingBox().getMaxY());
    bottom->setAnchorPoint(cocos2d::Vec2(0, 0.5));
    bottom->setPosition(this->getBoundingBox().getMinX(), this->getBoundingBox().getMinY());
    wheel1->setPosition(1600, 1000);
    wheel2->setPosition(800, 200);
    wheel3->setPosition(800, 400);
    wheel4->setPosition(200, 800);

    background->setAnchorPoint(Vec2(0, 0));
    background->setPosition(-9999, -9999);
    
    this->addChild(background, 1);
    this->addChild(leftWall, 1);
    this->addChild(rightWall, 1);
    this->addChild(top, 1);
    this->addChild(bottom, 1);
    this->addChild(wheel1, 1);
    this->addChild(wheel2, 1);
    this->addChild(wheel3, 1);
    this->addChild(wheel4, 1);
    // Спрайты стен, колес

    //
    player1 = new Player("hummerBlack.png");
    player2 = new Player("regularPlayer.png");

    player1->playerLines = player1->initLines((cocos2d::Node*)this, *player2, background);
    player2->playerLines = player2->initLines((cocos2d::Node*)this, *player1, background);

    player1->GetSprite()->setPosition(300, 300);
    player2->GetSprite()->setPosition(600, 600);

    this->addChild(player1->GetSprite(), 1);
    this->addChild(player2->GetSprite(), 1);
    // создание игроков
    this->schedule(SEL_SCHEDULE(&MainScene::Update), kUpdateTick);
    return true;
}

void MainScene::Update(float dt) {
    player1->MovementLogic(this, *player2, background);
    player2->MovementLogic(this, *player1, background);
}