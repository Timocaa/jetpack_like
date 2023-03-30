#ifndef ALIEN_HPP
# define ALIEN_HPP

#include <SFML/Graphics.hpp>
#include "Player.hpp"

class Alien
{
    public:
        //---- canonical form ----//
        Alien();
        ~Alien();

        //---- member methods ----//

    private:
        //---- member objects ----//
        sf::Texture     _texture;
        sf::Sprite      _sprite;
        sf::Vector2i    _dir;
        sf::Vector2i    _anim;
        sf::Clock       _clockAnim;

        //---- private methods ----//
        Alien(Alien const &rhs);
        Alien   &operator=(Alien const &rhs);
};

#endif