#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    auto director = Director::getInstance(); // получаем экземпляр директора. Он требуется для перехода между сценами. Пока у нас только одна сцена
    auto glview = director->getOpenGLView(); // получаем базовый вид просмотра OpenGL. Отрисовка будет происходить с помощью GL
    if (!glview) {
        glview = GLViewImpl::create("Hello World"); // создаем окно просмотра
        glview->setFrameSize(640, 480); // устанавливаем его размер (для настольных систем)
        director->setOpenGLView(glview); // устанавливаем окно в базовый вид просмотра
    }

    auto scene = HelloWorld::createScene(); // создаем нашу первую сцену
    director->runWithScene(scene); // стартуем показ сцены

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
}

void AppDelegate::applicationWillEnterForeground() {
}
