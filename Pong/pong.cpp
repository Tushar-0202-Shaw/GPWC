#include "Bat.h"
#include "Ball.h"
#include<SFML/Graphics.hpp>
#include<sstream>
// #include <cstdlib> 
// #include <ctime>

using namespace sf;

int main(){
    //create a video mode object
    VideoMode vm(1600,900);

    //create and open a window for the game
    RenderWindow window(vm, "Pong!!!", Style::Fullscreen);

    //Declare and initialize score and lives variable
    int score = 0;
    int lives = 3;

    //create a bat
    Bat bat(window.getSize().x/2.0, window.getSize().y-10.0);

    //create a ball
    Ball ball(window.getSize().x/2.0, 0);

    //create a text object called HUD(Heads Up Display)
    Font font;

    //load font
    font.loadFromFile("fonts/KOMIKAP_.ttf");

    //set the font
    Text hud;
    hud.setFont(font);

    //set font size
    hud.setCharacterSize(75.0);

    //choose a color
    hud.setFillColor(Color::Red);

    //set position of the text
    hud.setPosition(20.0, 20.0);

    //declare clock object for timing
    Clock clock;

    //srand(time(0));

    while(window.isOpen()){
        //handle player input
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
        }

        //quit the game when the window is closed
        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }

        //handle playing inputs
        //left cursor movement
        if(Keyboard::isKeyPressed(Keyboard::Left)){
            if(bat.get_Position().left <= 0){
                bat.stopLeft();
            }
            else{
                bat.moveLeft();
            }
        }
        else{
            bat.stopLeft();
        }

        //right cursor movement
        if(Keyboard::isKeyPressed(Keyboard::Right)){
            if(bat.get_Position().left+bat.get_Position().width >= 1600.0){
                bat.stopRight();
            }
            else{
                bat.moveRight();
            }
        }
        else{
            bat.stopRight();
        }
        //update the delta time
        Time dt = clock.restart();

        //update the bat
        bat.update(dt);

        //update the ball
        ball.update(dt);

        //update the HUD text
        std::stringstream ss;
        ss<<"Score: "<<score<<" Lives: "<<lives;
        hud.setString(ss.str());    

        //handle ball hitting the bottom
        if(ball.getPosition().top >= window.getSize().y){
            lives--;
            if(lives <= 0){ //start new game
                lives = 3;
                score = 0;
            }
            ball.reboundBottom();
            // float randomX = rand() % window.getSize().x;
            // ball = Ball(randomX, 0);
        }

        //handle ball hitting the top
        if(ball.getPosition().top <= 0){
            score++;
            ball.reboundBatOrTop();
        }

        //handle ball hitting sides
        if(ball.getPosition().left <= 0 || ball.getPosition().left+ball.getPosition().width >= window.getSize().x){
            ball.reboundSides();
        }

        //has the ball hit the ball
        if(ball.getPosition().intersects(bat.get_Position())){
            //if hit detected, reverse the ball and increase the score
            score++;
            ball.reboundBatOrTop();
            ball.update(dt);
            bat.update(dt);
        }

        //clear the window
        window.clear();

        //draw the bat, the ball and the HUD
        window.draw(bat.get_Shape());
        window.draw(ball.getShape());
        window.draw(hud);

        //display
        window.display();
    }
}