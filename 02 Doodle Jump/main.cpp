#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
using namespace sf;

struct point
{ int x,y;};

int initFont(sf::Text * text);

int main()
{
    srand(time(0));

    // Create the main window
    RenderWindow app(VideoMode(400, 533), "Doodle Game!");
    app.setFramerateLimit(60);

    // Load sprites to display
    Texture t1,t2,t3;
    t1.loadFromFile("images/background.png");
    t2.loadFromFile("images/platform.png");
    t3.loadFromFile("images/doodle.png");

    Sprite sBackground(t1), sPlat(t2), sPers(t3);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("resources/17 Blackwell Academy.ogg"))
        return EXIT_FAILURE;
    // Play the music
    music.play();
    

    // Load the sounds used in the game
    sf::SoundBuffer jumpSoundBuffer;
    if (!jumpSoundBuffer.loadFromFile("resources/ball.wav"))
        return EXIT_FAILURE;
    sf::Sound jumpSound(jumpSoundBuffer);

    // Init a font
    sf::Text text;
    //initFont(&text);
       // Load the text font
    sf::Font font;
    if (!font.loadFromFile("resources/KoPubWorld Batang Bold.ttf"))
        return EXIT_FAILURE;

    // Initialize the pause message
    text.setFont(font);
    text.setCharacterSize(40);
    text.setPosition(170.f, 150.f);
    text.setFillColor(sf::Color::Black);
    sf::String s = L"당신의 이름은 무엇입니까?";
    text.setString(s);
    //text.setString("test");


    point plat[20];

    for (int i=0;i<10;i++)
      {
       plat[i].x=rand()%400;
       plat[i].y=rand()%533;
      }

	int x=100,y=100,h=200;
    float dx=0,dy=0;

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) x+=3;
        if (Keyboard::isKeyPressed(Keyboard::Left)) x-=3;

        dy+=0.2;
        y+=dy;
        if (y > 500) { dy = -10; jumpSound.play();  } // floor jump

	    if (y<h)
        for (int i=0;i<10;i++)
        {
          y=h;
          plat[i].y=plat[i].y-dy;
          if (plat[i].y>533) {plat[i].y=0; plat[i].x=rand()%400;}
        }

	    for (int i=0;i<10;i++)
        if ((x+50>plat[i].x) && (x+20<plat[i].x+68)
            && (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0)) {
            dy = -10; 
            jumpSound.play(); 
        } // jump

	    sPers.setPosition(x,y);

        app.draw(sBackground);
        app.draw(sPers);
        for (int i=0;i<10;i++)
        {
        sPlat.setPosition(plat[i].x,plat[i].y);
        app.draw(sPlat);
        }

        app.draw(text);

        app.display();
    }

    return 0;
}

int initFont(sf::Text * text)
{
    return 0;
}