#pragma once
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include "cocos2d.h"
#include "Player.h"
using namespace cocos2d;
using namespace std;
USING_NS_CC;

class MainScene : public cocos2d::Layer // класс сцены
{
private:
    bool pressedW;
    bool pressedA;
    bool pressedS;
    bool pressedD;

    float player_speed = 0.0f;
    float MAX_SPEED = 12.0f;
    float ACCELERATION = 1.0f;
    const float kUpdateTick = 0.05f;
    
    Player* player1;
    Player* player2;

    Sprite* background = cocos2d::Sprite::create("background.png");
public:
    static cocos2d::Scene* createScene(); // метод создани€ сцены
    bool init() override; // метод инициализации
    void Update(float dt);
    CREATE_FUNC(MainScene); // макрос, который раскрываетс€ и генерирует экземпл€р класса подконтрольный GC (GarbageCollector движка cocos-2dx)
};
#endif // __GAME_SCENE_H__