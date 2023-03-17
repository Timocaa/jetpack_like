#ifndef GAME_HPP
# define GAME_HPP

#include <SFML/Graphics.hpp>
#include <exception>

#include "Input.hpp"
#include "Map.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>

#define WIN_WIDTH	1120
#define WIN_HEIGHT	720
#define SPRITE_SIZE	40

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
		sf::Sprite			_heroSprite;

		Input				_input;
		sf::Text			_txt;

		//---- canonical form ----//
		Game(Game const &rhs);
		Game	&operator=(Game const &rhs);
};

#endif
