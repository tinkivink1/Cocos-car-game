#pragma once
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include "cocos2d.h"
#include "Player.h"
using namespace cocos2d;
using namespace std;

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
    cocos2d::Sprite* leftWall = cocos2d::Sprite::create("wall.png");
    cocos2d::Sprite* rightWall = cocos2d::Sprite::create("wall.png");
    cocos2d::Sprite* top = cocos2d::Sprite::create("top.png");
    cocos2d::Sprite* bottom = cocos2d::Sprite::create("top.png");
    cocos2d::Sprite* line = cocos2d::Sprite::create("line.png");
    cocos2d::Sprite* redline = cocos2d::Sprite::create("redline.png");

    Player player1 = Player("player1.png");
    Player player2 = Player("player2.png");
public:
    static cocos2d::Scene* createScene(); // метод создани€ сцены
    bool init() override; // метод инициализации

    void Update(float dt);
    //cocos2d::Rect rectOfSprite(cocos2d::Sprite* sprite);
    CREATE_FUNC(MainScene); // макрос, который раскрываетс€ и генерирует экземпл€р класса подконтрольный GC (GarbageCollector движка cocos-2dx)
};
#endif // __GAME_SCENE_H__