#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class Bat{
    //declare position
    Vector2f m_Position;

    //declare shape
    RectangleShape m_Shape;

    //declare speed
    float m_Speed = 1000.0f;


    //declare bool var for right and left movement
    bool m_movingRight = false;
    bool m_movingLeft = false;

    public:
    //declare constructor method
    Bat(float startX, float startY);

    //declare get_Position() method
    FloatRect get_Position();

    //declare get_Shape()
    RectangleShape get_Shape();

    //declare moveRight()
    void moveRight();

    //declare moveLeft()
    void moveLeft();

    //declare stopRight()
    void stopRight();

    //declare stopLeft()
    void stopLeft();

    //declare update()
    void update(Time);
};