#include<SFML/Graphics.hpp>

using namespace sf;


int main(){
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    VideoMode vm(resolution.x, resolution.y);

    RenderWindow window(vm, "Hello Window");

    RectangleShape rect1;
    Vector2f d1;
    d1.x = 200.0f;
    d1.y = 100.0f;
    rect1.setSize(d1);
    rect1.setOutlineThickness(2);
    rect1.setOutlineColor(Color::Magenta);
    rect1.setFillColor(Color::Cyan);
    rect1.setPosition(Vector2f(resolution.x/2.0-d1.x/2.0, resolution.y/2.0-d1.y/2.0));

    //game loop
    while(window.isOpen()){




        //window.clear(Color::Cyan);
        window.clear(Color(255,178,102));

        //draw objects
        window.draw(rect1);

        window.display();
    }
    return 0;
}