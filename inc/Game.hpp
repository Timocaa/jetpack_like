#ifndef GAME_HPP
# define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Input.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>

#define WIN_WIDTH	800
#define WIN_HEIGHT	576

class Game
{
	public:
		//---- canonical form ----//
		Game();
		~Game();
		//---- member methods ----//
		void	start();
		void	initText(std::string const &str);

	private:
		//---- member object ----//
		sf::RenderWindow	_window;
		sf::Font			_font;
		sf::Texture			_heroTexture;
		
		Input				_input;
		sf::Text			_txt;

		//---- canonical form ----//
		Game(Game const &rhs);
		Game	&operator=(Game const &rhs);
};

#endif
