#pragma once

#include "cocos2d.h"

class  AppDelegate : private cocos2d::Application
{
public:
    AppDelegate();
    virtual ~AppDelegate();

    // �������� apple - ������
    bool applicationDidFinishLaunching() override; // ����� ����� ������������� ������. ����� ����� ���������� ���� ��� ������������� ���� � �������
    void applicationDidEnterBackground() override; // ����� ��� �������� ���������� � ������� �����
    void applicationWillEnterForeground() override;// ����� ��� �������� ���������� �� �������� ����
};
