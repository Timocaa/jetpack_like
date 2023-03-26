#ifndef GAZ_HPP
# define GAZ_HPP

#include <SFML/Graphics.hpp>
#include <random>
#include <chrono>
#include "Player.hpp"

class Gaz
{
    public:
        //---- canonical form ----//
        Gaz();
        ~Gaz();

        //---- member methods ----//
            //---- Getters
        sf::Sprite  &getGazSprite();
        bool        needGaz() const;

            //---- methods
        void        randPosition();
        void        handling(Player &player, int *collisionMap);

    private:
        //---- member objects ----//
        sf::Texture                         _gazTexture;
		sf::Sprite	                        _gazSprite;
		bool	                            _falling;
		bool		                        _needGaz;
		sf::Vector2i                        _anim;
		sf::Clock		                    _clockItemPop;
		std::default_random_engine			_rand;
		std::uniform_int_distribution<int>	_boxRand{0, 24};
		sf::Clock							_clockAnim;

        //---- private methods ----//
            //---- canonical form
        Gaz(Gaz const &rhs);
        Gaz &operator=(Gaz const &rhs);

            //---- methods
        void    animSprite();
};

#endif