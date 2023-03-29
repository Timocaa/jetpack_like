#ifndef SPACESHIP
# define SPACESHIP

#include <SFML/Graphics.hpp>
#include "Player.hpp"

class Spaceship
{
    public:
        //---- canonical form ----//
        Spaceship();
        ~Spaceship();
        //---- member methods ----//
        void    displayParts(Player &player);

    private:
        //---- member objects ----//
		sf::Texture		_texture;
		sf::Sprite		_sprite;
        int             _partOfSpaceship;
        int             _fuelLevel;

        //---- private methods ----//
            //---- canonical form
        Spaceship(Spaceship const &rhs);
        Spaceship   &operator=(Spaceship const &rhs);

            //---- methods
        void        spriteSpaceshipElements();
        void        updateFuelLvl();
};

#endif