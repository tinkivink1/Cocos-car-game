#pragma once

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer // класс сцены
{
public:
    static cocos2d::Scene* createScene(); // метод создания сцены
    bool init() override; // метод инициализации

    CREATE_FUNC(HelloWorld); // макрос, который раскрывается и генерирует экземпляр класса подконтрольный GC (GarbageCollector движка cocos-2dx)
};
