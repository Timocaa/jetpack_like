#ifndef INPUT_HPP
# define INPUT_HPP

#include <SFML/Graphics.hpp>

struct t_button
{
	bool	right;
	bool	left;
	bool	up;
	bool	action;
	bool	escape;
};

class Input
{
	public:
		//---- canonical form ----//
		Input();
		~Input();
		//---- member method ----//
		void	handlerInput(sf::Event &event, sf::RenderWindow &window);
		void	checkBtn(sf::Text &txt);

	private:
		//---- member object ----//
		t_button	_button;
		//---- canonical form ----//
		Input(Input const &rhs);
		Input	&operator=(Input const &rhs);
};

#endif
