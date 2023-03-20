#ifndef ITEMS_HPP
# define ITEMS_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

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

		//---- member methods ----//
		void		handlerItems(int *collisionMap);


	private:
		//---- member object ----//
		sf::Texture		_gazTexture;
		sf::Sprite		_gazSprite;
		sf::Clock		_clockAnim;
		sf::Vector2i	_anim;
		bool			_falling;

		//---- canonical form ----//
		Items(Items const &rhs);
		Items	&operator=(Items const &rhs);

		//---- private methods ----//
		void	animItems();
};

#endif
