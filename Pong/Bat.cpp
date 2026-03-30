#include "Bat.h"

//Definitions of all methods of Bat class as written below
//Constructor
Bat::Bat(float startX, float startY){
    m_Position.x = startX;
    m_Position.y = startY;
    Vector2f d1;
    d1.x = 100.0;
    d1.y = 10.0;
    m_Shape.setSize(d1);
    m_Shape.setPosition(m_Position);
}

//get_Position()
FloatRect Bat::get_Position(){
    return m_Shape.getGlobalBounds();
}

//get_Shape()
RectangleShape Bat::get_Shape(){
    return m_Shape;
}

//moveRight()
void Bat::moveRight(){
    m_movingRight = true;
}

//moveLeft()
void Bat::moveLeft(){
    m_movingLeft = true;
}

//stopRight()
void Bat::stopRight(){
    m_movingRight = false;
}

//stopLeft()
void Bat::stopLeft(){
    m_movingLeft = false;
}

//update(Time dt)
void Bat::update(Time dt){
    if(m_movingLeft){
        m_Position.x -= m_Speed*dt.asSeconds();
    }
    if(m_movingRight){
        m_Position.x += m_Speed*dt.asSeconds();
    }
    m_Shape.setPosition(m_Position);
}