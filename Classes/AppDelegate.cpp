#include "AppDelegate.h"
#include "MainScene.h"

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
        glview = GLViewImpl::create("Gonki"); // создаем окно просмотра
        glview->setFrameSize(1920, 1080); // устанавливаем его размер (для настольных систем)
        glview->setDesignResolutionSize(1920, 1080, ResolutionPolicy::EXACT_FIT);
        director->setOpenGLView(glview); // устанавливаем окно в базовый вид просмотра
        director->setClearColor(Color4F(0, 0, 0, 1));
    }
    auto scene = MainScene::createScene(); // создаем нашу первую сцену
    director->runWithScene(scene); // стартуем показ сцены

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
}

void AppDelegate::applicationWillEnterForeground() {
}
