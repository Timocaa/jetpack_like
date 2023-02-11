#include "../inc/main.hpp"


int main()
{
    sf::Font    font;
    // window creation 
    sf::RenderWindow    window(sf::VideoMode(WIN_WIDHT, WIN_HEIGHT, 32), "... New Game ...");
    // vsync activation
    window.setVerticalSyncEnabled(true);
    // loading font
    if (!loadFont(font))
        return (0);
    // text initialisation
    sf::Text    txt;
    initText(txt, font, "Hello World...!");


    // stop if window is closed
    while (window.isOpen())
    {
        sf::Event   event;
        while (window.pollEvent(event))
        {
            // management inputs and event
            inputHandler(event, window);
        }

        // set background window in black 
        window.clear(sf::Color::Black);

        // here all modifications for the window
        window.draw(txt);

        // display all modifications in the window
        window.display();
    }
    
    // end of programm
    return 0;
}