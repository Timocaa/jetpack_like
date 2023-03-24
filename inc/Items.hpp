#ifndef ITEMS_HPP
# define ITEMS_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <random>
#include <chrono>
#include "Player.hpp"

#define SPRITE_SIZE	40
#define SPEED_FALL	3

class Items
{
	public:
		//---- canonical form ----//
		Items();
		~Items();

		//---- Getters ----//
		sf::Sprite	&getGazSprite();
		bool		needGaz() const;

		//---- member methods ----//
		void		handlerItems(Player &player, int *collisionMap);


	private:
		//---- member object ----//
		sf::Texture							_gazTexture;
		sf::Sprite							_gazSprite;
		sf::Clock							_clockAnim;
		sf::Clock							_clockItemPop;
		sf::Vector2i						_anim;
		bool								_falling;
		bool								_gaz;
		std::default_random_engine			_rand;
		std::uniform_int_distribution<int>	_boxRand{0, 24};

		//---- canonical form ----//
		Items(Items const &rhs);
		Items	&operator=(Items const &rhs);

		//---- private methods ----//
		void	animItems();
};

#endif
