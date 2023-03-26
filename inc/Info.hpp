#ifndef INFO_HPP
# define INFO_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <string>
#include "Player.hpp"

class Info
{
    public:
        //---- canonical form ----//
        Info();
        ~Info();

        //---- member methods ----//
        void    update(Player &player);
        void    draw(sf::RenderWindow &window);

    private:
        //---- member objects ----//
		sf::Font			_font;
		sf::Text			_gaz;
		sf::Text			_gazValue;

        //---- private methods ----//
            //---- canonical form
        Info(Info const &rhs);
        Info    &operator=(Info const &rhs);
            //---- methods
        void    initText(sf::Text &txt, std::string const &str);
};

#endif