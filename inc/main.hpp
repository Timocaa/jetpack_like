#ifndef MAIN_HPP
# define MAIN_HPP

// includes
#include "prog.hpp"
#include "Input.hpp"

// prototypes
bool    init_game(sf::RenderWindow &window, sf::Font &font);
void    initText(sf::Text &txt, sf::Font &font, std::string const str);
bool    loadFont(sf::Font &font);
void    chckBtn(sf::RenderWindow &window);
#endif