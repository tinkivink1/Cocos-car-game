#include "Player.h"

Player::Player(const char* spriteFileName) {
    player = cocos2d::Sprite::create(spriteFileName);
}

cocos2d::Sprite* Player::GetSprite() { return player; }

vector<cocos2d::Sprite*>* Player::GetLines() { return playerLines; }

int Player::GetDirection(cocos2d::Sprite* line) { return (int)line->getRotation() / 45; }

// передвижение спрайта по экрану(раньше было по нажатию на клавиши поэтому WASD) 
void Player::Control() {
    while (true) {
        if (pressedW) {
            player->setRotation(-90.0f);
            if (player->getPosition().y < 1080 + player_speed) player->setPosition(player->getPosition().x, player->getPosition().y + player_speed);
        }
        if (pressedS) {
            player->setRotation(90.0f);
            if (player->getPosition().y > 50 - player_speed) player->setPosition(player->getPosition().x, player->getPosition().y - player_speed);
        }
        if (pressedA) {
            if (player->getPosition().x > 70 - player_speed) player->setPosition(player->getPosition().x - player_speed, player->getPosition().y);
            player->setRotation(180.0f);
            if (pressedW) player->setRotation(-135.0f);
            if (pressedS) player->setRotation(135.0f);
        }
        if (pressedD) {
            if (player->getPosition().x < 1920 + player_speed) player->setPosition(player->getPosition().x + player_speed, player->getPosition().y);
            player->setRotation(0.0f);
            if (pressedW) player->setRotation(-45.0f);
            if (pressedS) player->setRotation(45.0f);
        }
        Sleep(10);
    }
}

// механника разгона(была идея сделать механнику движения по инерции, но не хватило времени) 
void Player::SpeedControl() {
    while (true)
        if (IsMoving()) {
            if (player_speed < MAX_SPEED)
                for (float dt = 0; dt < MAX_SPEED / ACCELERATION && IsMoving() && player_speed < MAX_SPEED; dt += 0.01) {
                    player_speed = player_speed + ACCELERATION * dt;
                    Sleep(10);
                }
        }
        else {
            if (player_speed > 0)
                for (float dt = 0; dt < MAX_SPEED / ACCELERATION && !IsMoving() && player_speed > 0; dt += 0.01) {
                    player_speed = player_speed - ACCELERATION * dt;
                    if (player_speed < 0)
                        player_speed = 0;
                    Sleep(10);
                }
        }
}


// проверка: находится ли машинка/игрок в движении
bool Player::IsMoving() {
    return (pressedW || pressedA || pressedS || pressedD || *direction1 || *direction2);
}

// проверка: является ли узел линией, отвечающей за коллизию
bool Player::isLine(cocos2d::Node* node, vector<cocos2d::Sprite*>* lines) {
    for (int i = 0; i < lines->size(); i++) {
        if ((cocos2d::Node*)(*lines)[i] == node) return true;
    }
    return false;
}


// отрисовка отрезков, отвечающих за столкновение 
// если есть колизия - краный, нет - белый
void Player::initLines(cocos2d::Node* scene, Player player2) {
    auto childNode = scene->getChildren();
    bool intersection = false;


    for (int i = 0; i < 8; i++) {
        intersection = false;
        for (int k = 0; k < childNode.size(); k++) {
            //
            playerLines->push_back(cocos2d::Sprite::create("line.png"));
            (*playerLines)[i]->setAnchorPoint(cocos2d::Vec2(0, 0.5));
            (*playerLines)[i]->setRotation(i * 45);
            // создание "круга" из линий
            (*playerLines)[i]->setName("line");
            (*playerLines)[i]->setPosition(player->getPositionX(), player->getPositionY());
            if ((*playerLines)[i]->getBoundingBox().intersectsRect(childNode.at(k)->getBoundingBox())
                && !childNode.at(k)->getBoundingBox().equals(player->getBoundingBox())) {
                if ((playerLines != nullptr && player2.GetLines() != nullptr)
                    && !isLine(childNode.at(k), playerLines)
                    && !isLine(childNode.at(k), player2.GetLines()))
                {
                    intersection = true;
                    break;
                }
            }
        }
        if (intersection) {
            (*playerLines)[i] = cocos2d::Sprite::create("redline.png");
            (*playerLines)[i]->setName("redline");
            (*playerLines)[i]->setAnchorPoint(cocos2d::Vec2(0, 0.5));
            (*playerLines)[i]->setRotation(i * 45);
            (*playerLines)[i]->setPosition(player->getPositionX(), player->getPositionY());
        }

        scene->addChild((*playerLines)[i]);
    }
}


// очистка отрезков, отвечающих за столкновение
void Player::removeLines(cocos2d::Node* scene) {
    if (playerLines != nullptr) {
        for (int i = 0; i < playerLines->size(); i++) {
            scene->removeChild((*playerLines)[i]);
        }
        playerLines->clear();
    }
}


// сброс предыдущего направления движения и установка заданного
// Цифры задают направление по часовой стрелке
// 0 - вправо
// 1 - вправо-вниз
// 2 - вниз
// ...
// 7 - вправо-вверх
void Player::SetMovementsDirtection(int dirNum) {
    switch (dirNum)
    {
    case 0:
        SetDirectionNull();
        *direction1 = pressedD;
        *direction1 = true;
        break;
    case 1:
        SetDirectionNull();
        *direction1 = pressedD;
        *direction1 = true;
        *direction2 = pressedS;
        *direction2 = true;
        break;
    case 2:
        SetDirectionNull();
        *direction1 = pressedS;
        *direction1 = true;
        break;
    case 3:
        SetDirectionNull();
        *direction1 = pressedA;
        *direction1 = true;
        *direction2 = pressedS;
        *direction2 = true;
        break;
    case 4:
        SetDirectionNull();
        *direction1 = pressedA;
        *direction1 = true;
        break;
    case 5:
        SetDirectionNull();
        *direction1 = pressedA;
        *direction1 = true;
        *direction2 = pressedW;
        *direction2 = true;
        break;
    case 6:
        SetDirectionNull();
        *direction1 = pressedW;
        *direction1 = true;
        break;
    case 7:
        SetDirectionNull();
        *direction1 = pressedD;
        *direction1 = true;
        *direction2 = pressedW;
        *direction2 = true;
        break;
    default:
        break;
    }
    currentDirectionNumber = dirNum;
}

// сброс направления движения
void Player::SetDirectionNull() {
    if (direction1 != nullptr) *direction1 = false;
    if (direction2 != nullptr) *direction2 = false;
    direction1 = nullptr;
    direction2 = nullptr;
}







// если на направлении движения препятствие направление меняется на свободное
void Player::MovementLogic(cocos2d::Node* scene, Player player2) {
    while (true) {
        initLines(scene, player2);
        if ((*playerLines)[currentDirectionNumber]->getName() == "redline") {
            for (int i = 0; i < playerLines->size(); i++) {
                if ((*playerLines)[i]->getName() == "line")
                    SetMovementsDirtection(i);
            }
        }
        Control();
        Sleep(10);
    }
}