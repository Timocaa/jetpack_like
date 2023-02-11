#ifndef MAIN_HPP
# define MAIN_HPP

// includes
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

//defines
#define WIN_WIDHT   800
#define WIN_HEIGHT  600

// prototypes
void    inputHandler(sf::Event event, sf::RenderWindow &window);
bool    loadFont(sf::Font &font);
void    initText(sf::Text &txt, sf::Font &font, std::string const str);

#endif