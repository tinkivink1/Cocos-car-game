#pragma once

#include "cocos2d.h"
class HelloWorld : public cocos2d::Layer // ����� �����
{
public:
    bool pressedW;
    bool pressedA;
    bool pressedS;
    bool pressedD;
    float player_speed = 8.0f;
    cocos2d::Sprite* player = cocos2d::Sprite::create("mainCar.png");

    static cocos2d::Scene* createScene(); // ����� �������� �����
    bool init() override; // ����� �������������
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* unused_event);
    void Update(float dt);
    CREATE_FUNC(HelloWorld); // ������, ������� ������������ � ���������� ��������� ������ �������������� GC (GarbageCollector ������ cocos-2dx)
};
