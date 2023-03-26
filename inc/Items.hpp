#ifndef ITEMS_HPP
# define ITEMS_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Player.hpp"
#include "Gaz.hpp"

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
		void		draw(sf::RenderWindow &window);

	private:
		//---- member object ----//
		Gaz	_gaz;	

		//---- canonical form ----//
		Items(Items const &rhs);
		Items	&operator=(Items const &rhs);

		//---- private methods ----//
};

#endif
