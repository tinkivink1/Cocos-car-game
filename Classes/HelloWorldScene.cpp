#include "HelloWorldScene.h"

USING_NS_CC; // ������ ������������� ������������ ��� cocos2d::

Scene* HelloWorld::createScene()
{
    // ��� ���������, ������� ��������� Cocos - 2dx ��� ��������� ��� ��������� ���������� ������. ������� ��� �� ������� ������ �������� ����� delete ��� ������� � ���������������� ���������
    auto scene = Scene::create(); // ������� �����
    auto layer = HelloWorld::create(); // ������� ���� �����

    scene->addChild(layer); // ��������� ���� ��� ������� �� �����

    return scene;
}

bool HelloWorld::init()
{
    if (!Layer::init()) // ���� �� �� ����� ������������������� - ������ �������
    {
        return false;
    }

    auto label = Label::createWithSystemFont("Hello Cocos 2dx", "Arial", 48); // ������� ����� ��� ������ ������. 
    auto visibleSize = Director::getInstance()->getVisibleSize(); // �������� ������� ���� ��������� (��, ��� ����� ��������)
    Vec2 origin = Director::getInstance()->getVisibleOrigin(); // �������� ������ ��������, ��� ��������� �� ������ �����������


    label->setPosition(cocos2d::Vec2(400, 230)); // ������ �� �������� �����������. �� - ��������� � ���� ����������� Cocos - 2dx ����� ��������� ��������� � ��������, �� ����� ������!
    this->addChild(label, 1);
    // ������� ��������� ����� ��� �������. ������ �������� - ��� z - ������������������
    return true;
}
