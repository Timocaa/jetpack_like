#ifndef INPUT_HPP
# define INPUT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#define SPRITE_SIZE	40
#define SPEED		2

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
		void	checkBtn(sf::Sprite &heroSprite);
		void	checkCollision(sf::Sprite &heroSprite, sf::FloatRect cubBox);

	private:
		//---- member object ----//
		t_button	_button;
		
		sf::Vector2i	_animHero;
		sf::Clock		_clockAnim;
		bool			_idle;
		sf::FloatRect	_heroHitBox;

		//---- canonical form ----//
		Input(Input const &rhs);
		Input	&operator=(Input const &rhs);
		//---- private methode ----//
		void	animPlayer();
};

#endif
