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
            //---- getters
        sf::Sprite          &getShipSprite();
        sf::RectangleShape  &getOutlineShape();
        sf::RectangleShape  &getFuelLvlShape();

            //---- methods
        void    displayParts();

    private:
        //---- member objects ----//
		sf::Texture		_texture;
		sf::Sprite		_sprite;
        int             _partOfSpaceship;
        int             _fuelLevel;
        sf::RectangleShape  _outline;
        sf::RectangleShape  _level;

        //---- private methods ----//
            //---- canonical form
        Spaceship(Spaceship const &rhs);
        Spaceship   &operator=(Spaceship const &rhs);

            //---- methods
        void        spriteSpaceshipElements();
        void        updateFuelLvl();
};

#endif