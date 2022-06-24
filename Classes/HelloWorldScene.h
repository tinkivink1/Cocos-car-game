#pragma once

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer // класс сцены
{
public:
    static cocos2d::Scene* createScene(); // метод создани€ сцены
    bool init() override; // метод инициализации

    CREATE_FUNC(HelloWorld); // макрос, который раскрываетс€ и генерирует экземпл€р класса подконтрольный GC (GarbageCollector движка cocos-2dx)
};
