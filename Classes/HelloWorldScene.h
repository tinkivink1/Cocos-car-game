#pragma once
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include "cocos2d.h"
using namespace cocos2d;
using namespace std;
class HelloWorld : public cocos2d::Layer // класс сцены
{
public:
    bool pressedW;
    bool pressedA;
    bool pressedS;
    bool pressedD;
    float player_speed = 8.0f;
    const float kUpdateTick = 0.01f;

    cocos2d::Sprite* player = cocos2d::Sprite::create("mainCar.png");

    static cocos2d::Scene* createScene(); // метод создания сцены
    bool init() override; // метод инициализации
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event);
    void Update(float dt);
    CREATE_FUNC(HelloWorld); // макрос, который раскрывается и генерирует экземпляр класса подконтрольный GC (GarbageCollector движка cocos-2dx)
};
#endif // __GAME_SCENE_H__