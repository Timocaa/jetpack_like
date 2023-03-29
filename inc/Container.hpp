#ifndef CONTAINER_HPP
# define CONTAINER_HPP

#include <SFML/Graphics.hpp>
#include <random>
#include <chrono>
#include "Player.hpp"

class Container
{
    public:
        //---- canonical form ----//
        Container();
        ~Container();

        //---- member methods ----//
            //---- Getters
        sf::Sprite  &getSprite();
        bool        containerUp() const;
        bool        needBox() const;

            //---- methods
        void        randPosition();
        void        handling(Player &player, int *collisionMap);

    private:
        //---- member objects ----//
        sf::Texture                         _texture;
		sf::Sprite	                        _sprite;
		bool	                            _falling;
		bool		                        _boxUp;
        sf::Clock		                    _clockPop;
		std::default_random_engine			_rand;
		std::uniform_int_distribution<int>	_boxRand{0, 24};
        int                                 _boxQuantity;
        int                                 _boxType;

        //---- private methods ----//
            //---- canonical form
        Container(Container const &rhs);
        Container   &operator=(Container const &rhs);

            //---- methods
        void        animSprite();
};

#endif