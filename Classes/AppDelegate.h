#pragma once

#include "cocos2d.h"

class  AppDelegate : private cocos2d::Application
{
public:
    AppDelegate();
    virtual ~AppDelegate();

    // наследие apple - систем
    bool applicationDidFinishLaunching() override; // вызов после инициализации движка. Здесь можно записывать свой код инициализации окна и прочего
    void applicationDidEnterBackground() override; // вызов при переводе приложения в фоновый режим
    void applicationWillEnterForeground() override;// вызов при переводе приложения на передний план
};
