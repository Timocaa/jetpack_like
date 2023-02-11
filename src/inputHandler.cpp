//#include "../inc/main.hpp"
#include <SFML/Graphics.hpp>

void    inputHandler(sf::Event event, sf::RenderWindow &window)
{
    //close window by cross
    if (event.type == sf::Event::Closed)
        window.close();
}