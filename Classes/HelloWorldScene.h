#pragma once

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer // ����� �����
{
public:
    static cocos2d::Scene* createScene(); // ����� �������� �����
    bool init() override; // ����� �������������

    CREATE_FUNC(HelloWorld); // ������, ������� ������������ � ���������� ��������� ������ �������������� GC (GarbageCollector ������ cocos-2dx)
};
