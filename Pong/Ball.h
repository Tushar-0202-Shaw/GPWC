#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class Ball{
    private:
        //Position
        Vector2f m_Position;

        //Shape
        CircleShape m_Shape;

        //Speed
        float m_Speed = 1000.0f;

        //X-Direction
        float m_DirectionX = 0.2f;
        
        //Y-Direction
        float m_DirectionY = 0.2f;

    public:
        //Constructor
        Ball(float startX,float startY);

        //getPosition()
        FloatRect getPosition();

        //getShape()
        CircleShape getShape();

        //getXVelocity()
        float getXVelocity();

        //reboundSides()
        void reboundSides();

        //reboundBatOrTop()
        void reboundBatOrTop();

        //reboundBottom()
        void reboundBottom();

        //update(time)
        void update(Time dt);
};