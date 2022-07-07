#pragma once

#include "cocos2d.h"

using namespace std;
class Player
{
private:
    bool pressedW;
    bool pressedA;
    bool pressedS;
    bool pressedD;

    bool* direction1, *direction2;
    float player_speed = 0.0f;
    float MAX_SPEED = 18.0f;
    float ACCELERATION = 1.0f;

    int currentDirectionNumber; 
    cocos2d::Sprite* player;

    bool isLine(cocos2d::Node* node, vector<cocos2d::Sprite*>* lines);
    bool IsMoving();
    void SetDirectionNull();
public:
    Player(const char* spriteFileName);
    vector<cocos2d::Sprite*>* playerLines;

    cocos2d::Sprite* GetSprite();
    vector<cocos2d::Sprite*>* GetLines();
    void Control();
    void SpeedControl();
    void MovementLogic(cocos2d::Node* scene, Player player2, cocos2d::Sprite* background);
    //void initLines(cocos2d::Node* scene, Player player2);
    vector<cocos2d::Sprite*>* initLines(cocos2d::Node* scene, Player player2, cocos2d::Sprite* background);
    void removeLines(cocos2d::Node* scene);
    int GetDirection(cocos2d::Sprite* line);
    void SetMovementsDirtection(int dirNum);
};

