#ifndef MAIN_HPP
# define MAIN_HPP

// includes
#include "prog.hpp"
#include "Input.hpp"

// game variables
struct s_game
{
    Input               input;
    sf::RenderWindow    window;
    sf::Text            txt;
    sf::Font            font;
    sf::Texture         player;
    sf::Sprite          player_sprite;
    int                 posX;
    int                 posY;
};


// prototypes
bool    init_game(s_game &data);
void    initText(sf::Text &txt, sf::Font &font, std::string const str);
bool    loadFont(sf::Font &font);
#endif