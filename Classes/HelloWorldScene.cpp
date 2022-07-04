#include "HelloWorldScene.h"

USING_NS_CC; // макрос использования пространства имён cocos2d::
std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "Ws2_32.lib")

#include "stdio.h"
#include "winsock2.h"
#include <ws2tcpip.h>
#include <time.h>
#include <iostream>
#include <mutex>
#include <string>
#include <fstream>

Scene* HelloWorld::createScene()
{
    // все указатели, которые порождает Cocos - 2dx уже находятся под контролем выделенной памяти. Поэтому они не требуют явного удаления через delete или обертки в интеллектуальный указатель
    auto scene = Scene::create(); // создаем сцену
    auto layer = HelloWorld::create(); // создаем слой сцены

    scene->addChild(layer); // добавляем слой как ребенка на сцену
    return scene;
}

bool HelloWorld::init()
{
    if (!Layer::init()) // если мы не можем проинициализировать - просто выходим
    {
        return false;
    }
    auto label = Label::createWithSystemFont("Privet", "Consolas", 48); // создаем метку для вывода текста. 
    auto visibleSize = Director::getInstance()->getVisibleSize(); // получаем размеры вида просмотра (то, где будем рисовать)
    auto node = Node::create();
    Vec2 origin = Director::getInstance()->getVisibleOrigin(); // получаем вектор смещения, для рисования на разных координатах


    label->setPosition(100, 100); // рисуем по заданным координатам. По - умолчанию у всех компонентов Cocos - 2dx точка отрисовки находится в середине, не слева сверху!
    player->setPosition(100, 300);
    player->setScale(0.1);
    this->addChild(label, 1);
    this->addChild(player, 1);
    // наконец добавляем метку как ребенка. второй параметр - это z - последовательность
    auto rectNode = DrawNode::create();
    Vec2 rectangle[4];
    rectangle[0] = Vec2(-50, -50);
    rectangle[1] = Vec2(50, -50);
    rectangle[2] = Vec2(50, 50);
    rectangle[3] = Vec2(-50, 50);

    Color4F white(1, 1, 1, 1);
    rectNode->drawPolygon(rectangle, 4, white, 1, white);
    rectNode->setPosition(300, 100);
    this->addChild(rectNode);
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        log("pressed");
        keyMap[keyCode] = true;

        if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_A || keyCode == cocos2d::EventKeyboard::KeyCode::KEY_A) {
            auto rotateLeft = RotateBy::create(1, -180);
            rectNode->runAction(rotateLeft);
        }
        if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_D || keyCode == cocos2d::EventKeyboard::KeyCode::KEY_D) {
            auto rotateRight = RotateBy::create(1, 180);
            rectNode->runAction(rotateRight);
        }
        if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_W || keyCode == cocos2d::EventKeyboard::KeyCode::KEY_W) {
            auto moveForward = MoveBy::create(1, cocos2d::Vec2(80,0));
            rectNode->runAction(moveForward);
        }
        if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_S || keyCode == cocos2d::EventKeyboard::KeyCode::KEY_S) {
            auto moveBackward = MoveBy::create(1, cocos2d::Vec2(-80, 0));
            rectNode->runAction(moveBackward);
        }
        onKeyPressed(keyCode, event);
    };


    listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        log("released");
        keyMap[keyCode] = false;
        onKeyReleased(keyCode, event);
    };


    this->schedule(SEL_SCHEDULE(&HelloWorld::Update), kUpdateTick);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}

void HelloWorld::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event) {
    switch (keyCode) {
    case EventKeyboard::KeyCode::KEY_W:
        pressedW = true;
        break;
    case EventKeyboard::KeyCode::KEY_A:
        pressedA = true;
        break;
    case EventKeyboard::KeyCode::KEY_S:
        pressedS = true;
        break;
    case EventKeyboard::KeyCode::KEY_D:
        pressedD = true;
        break;
    }
}

void HelloWorld::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event) {
    switch (keyCode) {
    case EventKeyboard::KeyCode::KEY_W:
        pressedW = false;
        break;
    case EventKeyboard::KeyCode::KEY_A:
        pressedA = false;
        break;
    case EventKeyboard::KeyCode::KEY_S:
        pressedS = false;
        break;
    case EventKeyboard::KeyCode::KEY_D:
        pressedD = false;
        break;
    }
}

void HelloWorld::Update(float dt) {
    if (pressedW) {
        player->setRotation(-90.0f);
        if (player->getPosition().y < 440 + player_speed) player->setPosition(player->getPosition().x, player->getPosition().y + player_speed);
    }
    if (pressedS) {
        player->setRotation(90.0f);
        if (player->getPosition().y > 50 - player_speed) player->setPosition(player->getPosition().x, player->getPosition().y - player_speed);
    }
    if (pressedA) {
        if (player->getPosition().x > 70 - player_speed) player->setPosition(player->getPosition().x - player_speed, player->getPosition().y);
        player->setRotation(180.0f);
        if (pressedW) player->setRotation(-135.0f);
        if (pressedS) player->setRotation(135.0f);
    }
    if (pressedD) {
        if (player->getPosition().x < 870 + player_speed) player->setPosition(player->getPosition().x + player_speed, player->getPosition().y);
        player->setRotation(0.0f);
        if (pressedW) player->setRotation(-45.0f);
        if (pressedS) player->setRotation(45.0f);
    }

}