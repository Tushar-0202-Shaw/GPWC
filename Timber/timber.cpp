#include<SFML/Graphics.hpp>
#include<sstream>

using namespace sf;
using namespace std;
void updateBranches(int);
const int NUM_BRANCHES=6;
enum class side{LEFT, RIGHT, NONE};
side playerPostition = side::LEFT;
side branchPositions[NUM_BRANCHES];
Sprite Branches[NUM_BRANCHES];


int main(){
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    VideoMode vm(resolution.x, resolution.y);

    RenderWindow window(vm, "Timber!!!");

    Texture backgroundTexture;
    backgroundTexture.loadFromFile("graphics/background.png");

    Sprite backgroundSprite;                                        
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0,0);

    Texture treeTexture;
    treeTexture.loadFromFile("graphics/tree.png");

    Sprite treeSprite;                                        
    treeSprite.setTexture(treeTexture);
    treeSprite.setPosition((resolution.x/2.0 - 300/2.0), 0);

    Texture beeTexture;
    beeTexture.loadFromFile("graphics/bee.png");

    Sprite beeSprite;                                        
    beeSprite.setTexture(beeTexture);
    beeSprite.setPosition((-50), (resolution.y/1.5));

    Texture cloudTexture;
    cloudTexture.loadFromFile("graphics/cloud.png");

    Sprite cloudSprite;                                        
    cloudSprite.setTexture(cloudTexture);
    cloudSprite.setPosition(-300, 0);

    Sprite cloudSprite1;                                        
    cloudSprite1.setTexture(cloudTexture);
    cloudSprite1.setPosition(-300, 150);

    Sprite cloudSprite2;                                        
    cloudSprite2.setTexture(cloudTexture);
    cloudSprite2.setPosition(-300, 0);

    float beeSpeed = 0.0f;
    float beeHeight = 0.0f;
    bool beeActive = false;
    float cloudSpeed = 0.0f;
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloudHeight = 0.0f;
    float cloud1Height = 0.0f;
    float cloud2Height = 0.0f;
    bool cloudActive = false;
    bool cloud1Active = false;
    bool cloud2Active = false;

    //clock and time set
    Clock clock;

    RectangleShape timeBar;
    float timeBarStartWidth = 400.0f;
    float timeBarHeight = 80.0f;
    timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
    timeBar.setFillColor(Color::Red);
    timeBar.setPosition(resolution.x/2.0-timeBarStartWidth/2.0, resolution.y-100);
    float timeRemaining = 20.0f;
    float timeBarWidthPerSecond = timeBarStartWidth/timeRemaining;

    bool paused = true;

    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");
    Text messageText;
    messageText.setFont(font);
    messageText.setFillColor(Color::White);
    messageText.setCharacterSize(100);
    messageText.setString("Press Enter to Start");
    FloatRect textRect = messageText.getLocalBounds();
    messageText.setOrigin((textRect.left + textRect.width) / 2.0, (textRect.top + textRect.height) / 2.0);
    messageText.setPosition(resolution.x / 2.0, resolution.y / 2.0);

    // Score
    Text scoreText;
    scoreText.setFont(font);
    scoreText.setFillColor(Color::Red);
    scoreText.setCharacterSize(75);
    scoreText.setString("Score = 0");
    scoreText.setPosition(20, 20);
    int score = 0;

    Texture branchTexture;
    branchTexture.loadFromFile("graphics/branch.png");

    for(int i=0; i<NUM_BRANCHES; i++){
        Branches[i].setTexture(branchTexture);
        Branches[i].setOrigin(220, 20);
        Branches[i].setPosition(-2000,-2000);
    }
    updateBranches(1);
    updateBranches(2);
    updateBranches(3);
    updateBranches(4);
    updateBranches(5);

    Texture playerTexture;
    playerTexture.loadFromFile("graphics/player.png");

    Sprite playerSprite;                                        
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(resolution.x/2-400, 600);

    //Side of the player
    side sidePlayer = side::LEFT;

    //Grave stone
    Texture ripTexture;
    ripTexture.loadFromFile("graphics/rip.png");

    Sprite ripSprite;                                        
    ripSprite.setTexture(ripTexture);
    ripSprite.setPosition(480, 640);

    //Axe
    Texture axeTexture;
    axeTexture.loadFromFile("graphics/axe.png");

    Sprite axeSprite;                                        
    axeSprite.setTexture(axeTexture);
    axeSprite.setPosition(resolution.x/2.0-300, 700);


    //Line up axe with tree
    const int AXE_POSITION_LEFT = resolution.x/2.0-300;
    const int AXE_POSITION_RIGHT = resolution.x/2.0+150;

    //Flying log
    Texture logTexture;
    logTexture.loadFromFile("graphics/log.png");

    Sprite logSprite;                                        
    logSprite.setTexture(logTexture);
    logSprite.setPosition((resolution.x / 2.0 - 150), 720);

    //Other declarations for flying log
    bool logActive = false;
    float logSpeedX = 1000;
    float logSpeedY = -1500;

    //Control player input
    bool acceptInput = false;

    //Prepare the sound's -> chopping, timeout, dead


    //game loop
    while(window.isOpen()){
        
        Time dt = clock.restart();
        //handle user input -> discrete event handling
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }

            //start the game pressing enter key
            if(event.type == Event::KeyPressed && event.key.code == Keyboard::Return){
                paused = false;
                
                //reset time
                timeRemaining = 6; // 1 sec passed after the game start

                //reset score
                score=0;

                //make all branches disappear
                for(int i=0; i<NUM_BRANCHES; i++){
                    branchPositions[i] = side::NONE;
                }

                //make grave stone hidden
                ripSprite.setPosition(2000, 2000);

                //move the player into the position
                playerSprite.setPosition(resolution.x/2-400, 600);

                //make acceptInput true
                acceptInput = true;

            }
            
            if(acceptInput){
                //handle right cursor key
                // Handle right key
                if(Keyboard::isKeyPressed(Keyboard::Right)){
                    // update score
                    score++;

                    // update time remaining
                    timeRemaining -= dt.asSeconds();

                    // set the player side to right
                    sidePlayer = side::RIGHT;

                    // set the player position
                    playerSprite.setPosition(resolution.x/2+250, 600);

                    // set the axe position
                    //axeSprite.setPosition(AXE_POSITION_RIGHT, axeSprite.getPosition().y);
                    axeSprite.setPosition(AXE_POSITION_RIGHT, axeSprite.getPosition().y);

                    // set the log position, log-speed on X to fly on the left, logActive -> enabled
                    logSprite.setPosition((resolution.x / 2.0 - 150), 600);
                    logSpeedX = 5000;
                    logActive = true;

                    // update branches
                    updateBranches(score);

                    // play a chop sound

                }

                // Handle left key
                if(Keyboard::isKeyPressed(Keyboard::Left)){
                    // update score
                    score++;

                    // update time remaining
                    timeRemaining -= dt.asSeconds();

                    // set the player side to left
                    sidePlayer = side::LEFT;

                    // set the player position
                    playerSprite.setPosition(resolution.x/2-400, 600);

                    // set the axe position
                    //axeSprite.setPosition(AXE_POSITION_LEFT, axeSprite.getPosition().y);
                    axeSprite.setPosition(AXE_POSITION_LEFT, axeSprite.getPosition().y);

                    // set the log position, log-speed on X to fly on the left, logActive -> enabled
                    logSprite.setPosition((resolution.x / 2.0 - 150), 600);
                    logSpeedX = -5000;
                    logActive = true;

                    // update branches
                    updateBranches(score);

                    // play a chop sound
        
                }// End left key
            }// End of if(acceptInput)


        }

        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }

        if(!paused){

            //Time dt = clock.restart();
            //scene updates if game is running
            timeRemaining -= dt.asSeconds();

            timeBar.setSize(Vector2f(timeBarWidthPerSecond*timeRemaining, timeBarHeight));
        
            if (timeRemaining <= 0.0f){
                paused = true;
                messageText.setString("Time Out!!!");
                textRect = messageText.getLocalBounds();
                messageText.setOrigin(textRect.left + textRect.width / 2.0, textRect.top + textRect.height / 2.0);
                messageText.setPosition(resolution.x / 2.0, resolution.y / 2.0);
            }


            if(!beeActive){
                srand(time(0)*10);
                beeSpeed = rand()%125+125;

                srand(time(0)*20);
                beeHeight = rand()%500+500;

                beeSprite.setPosition(2000, beeHeight);
                beeActive = true;
            }else{
                beeSprite.setPosition(beeSprite.getPosition().x - beeSpeed*dt.asSeconds(), beeSprite.getPosition().y);
                if(beeSprite.getPosition().x<-100){
                    beeActive = false;
                }
            }
            
            if(!cloudActive){
                srand(time(0)*10);
                cloudSpeed = rand()%100+100;

                srand(time(0)*20);
                cloudHeight = rand()%150;

                cloudSprite.setPosition(-200, cloudHeight);
                cloudActive = true;
            }else{
                cloudSprite.setPosition(cloudSprite.getPosition().x + cloudSpeed*dt.asSeconds(), cloudSprite.getPosition().y);
                if(cloudSprite.getPosition().x>2000){
                    cloudActive = false;
                }
            }

            if(!cloud1Active){
                srand(time(0)*30);
                cloud1Speed = rand()%100+100;

                srand(time(0)*40);
                cloud1Height = rand()%300;

                cloudSprite1.setPosition(-400, cloud1Height);
                cloud1Active = true;
            }else{
                cloudSprite1.setPosition(cloudSprite1.getPosition().x + cloud1Speed*dt.asSeconds(), cloudSprite1.getPosition().y);
                if(cloudSprite1.getPosition().x>2000){
                    cloud1Active = false;
                }
            }

            if(!cloud2Active){
                srand(time(0)*50);
                cloud2Speed = rand()%100+100;

                srand(time(0)*60);
                cloud2Height = rand()%450;

                cloudSprite2.setPosition(-600, cloud2Height);
                cloud2Active = true;
            }else{
                cloudSprite2.setPosition(cloudSprite2.getPosition().x + cloud2Speed*dt.asSeconds(), cloudSprite2.getPosition().y);
                if(cloudSprite2.getPosition().x>2000){
                    cloud2Active = false;
                }
            }
            std::stringstream ss;
            ss<<"Score = "<<score;
            scoreText.setString(ss.str());

            for(int i=0; i<NUM_BRANCHES; i++){
                float branchHeight = i*150;
                if(branchPositions[i] == side::LEFT){
                    Branches[i].setPosition(470, branchHeight);
                    Branches[i].setRotation(180); //flip
                }
                else if(branchPositions[i] == side::RIGHT){
                    Branches[i].setPosition(1170, branchHeight);
                    Branches[i].setRotation(0); //flip
                }
                else{
                    Branches[i].setPosition(3000, branchHeight);
                }
            }
            // updateBranches(1);
            // updateBranches(2);
            // updateBranches(3);
            // updateBranches(4);
            // updateBranches(5);

            //Handle a flying log
            if(logActive){
                logSprite.setPosition(logSprite.getPosition().x+logSpeedX*dt.asSeconds(), logSprite.getPosition().y+logSpeedY*dt.asSeconds());
                if(logSprite.getPosition().x<-100 || logSprite.getPosition().x>2000){
                    logSprite.setPosition((resolution.x / 2.0 - 150), 600);
                    logActive = false;
                }
            }

            //Has the player been squished by a branch?
             if(branchPositions[5] == sidePlayer){
                //pause the game
                paused = true;

                //accepting noinput
                acceptInput = false;

                //hide the player
                playerSprite.setPosition(2000,2000);

                //show the grave stone
                ripSprite.setPosition(480, 640);

                //show 'Game Over!!!' message
                messageText.setString("Game Over!!!");
                textRect = messageText.getLocalBounds();
                messageText.setOrigin((textRect.left+textRect.width) / 2.0, (textRect.height+textRect.top)/ 2.0);
                messageText.setPosition(resolution.x/2.0, resolution.y/2.0);

                //play sound of death


             }
        }// end of if(!paused)


        //clear window
        window.clear();

        //draw
        window.draw(backgroundSprite);
        window.draw(cloudSprite);
        window.draw(cloudSprite1);
        window.draw(cloudSprite2);
        for(int i=0; i<NUM_BRANCHES; i++){
            window.draw(Branches[i]);
        }
        window.draw(treeSprite);
        window.draw(logSprite);
        window.draw(axeSprite);
        window.draw(playerSprite);
        window.draw(ripSprite);
        window.draw(beeSprite);
        window.draw(timeBar);
        window.draw(scoreText);
        if(paused){
            window.draw(messageText);
        }
       
        //display
        window.display();
    }
    return 0;
}

void updateBranches(int seed){
    //shift each position one place to right
    for(int i=NUM_BRANCHES-1; i>0; i--){
        branchPositions[i] = branchPositions[i-1];
    }
    //update oth position
    srand(time(0)+seed);
    int r=rand()%3;
    switch(r){
        case 0: branchPositions[0] = side::LEFT;
                break;
        case 1: branchPositions[0] = side::RIGHT;
                break;
        default: branchPositions[0] = side::NONE;
    }
}




