#ifndef ALIEN_HPP
# define ALIEN_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include <random>
#include <chrono>
#include "Player.hpp"

class Alien
{
    public:
        //---- canonical form ----//
        Alien();
        ~Alien();

        //---- member methods ----//
            //---- Getters
        bool    isGameOver() const;

            //---- methods
        void    handlerAlien(Player &player, int *collisionMap);
        void    draw(sf::RenderWindow &window);

    private:
        //---- member objects ----//
        sf::Texture                         _texture;
        sf::Sprite                          _sprite;
        sf::Vector2i                        _dir;
        sf::Vector2i                        _anim;
        sf::Clock                           _clockAnim;
        std::default_random_engine          _rand;
        std::uniform_int_distribution<int>	_boxRand{-1, 1};
        bool                                _gameOver;

        //---- private methods ----//
            //---- canonical form
        Alien(Alien const &rhs);
        Alien   &operator=(Alien const &rhs);
        
            //---- methods
        void    animSprite();
        void    checkCollisionMap(int *collisionMap);
        void    randDirection();
        void    checkCollisionPlayer(Player &character);
};

#endif