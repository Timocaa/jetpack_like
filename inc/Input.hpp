#ifndef INPUT_HPP
# define INPUT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#define SPRITE_SIZE	40
#define SPEED		3
#define GRAV_SPEED	2

struct t_button
{
	bool	right;
	bool	left;
	bool	up;
	bool	action;
	bool	escape;
};

enum Dir
{
	Idle,
	Right,
	Left,
	Up_right,
	Up_left
};

class Input
{
	public:
		//---- canonical form ----//
		Input();
		~Input();
		//---- member method ----//
		void	handlerInput(sf::Event &event, sf::RenderWindow &window);
		void	checkBtn(sf::Sprite &heroSprite, int *collisionMap);

	private:
		//---- member object ----//
		t_button	_button;
		
		sf::Vector2i	_animHero;
		sf::Clock		_clockAnim;
		sf::Clock		_clockIdle;
		bool			_idle;
		sf::FloatRect	_heroHitBox;
		bool			_fly;
		int				_dir;

		//---- canonical form ----//
		Input(Input const &rhs);
		Input	&operator=(Input const &rhs);
		//---- private methode ----//
		void	animPlayer();
		void	checkCollision(sf::Sprite &heroSprite, int *collisionMap);
};

#endif
