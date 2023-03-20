/* ************************************************************************** */
/*                                                                            */
/*                                         LLr::,::, ,:L    ,     :i;     .   */
/*   Game.hpp                              ,,.:::,   L;i   ::,    Y:; .:Li.   */
/*                                            i:;   :i:r   i::   ,i::i;,      */
/*   By:  Timoca                             ;ri,   UiiL  ;;:i   Yi::::       */
/*                                          .krj   UYLrY.,L;:r  lU7JYriYi,    */
/*   Created: 2023/03/19 17:47:34           qKKL  :Dd.;YlcLLlJ, iRk.  UYTK    */
/*   Updated: 2023/03/19 18:33:18           .UM.  RDD :DRi LU   DDK    ;cK    */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

#include <SFML/Graphics.hpp>
#include <exception>
#include <fstream>
#include <cctype>

#include "Player.hpp"
#include "Input.hpp"
#include "Map.hpp"
#include "Items.hpp"

#include <string>
#include <vector>
#include <sstream>
#include <utility>

#define WIN_WIDTH	1000
#define WIN_HEIGHT	720
#define SPRITE_SIZE	40
#define COLS		25
#define LINES		18

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
		Player				_player;
		Input				_input;
		Map					_map;
		Items				_item;

		int					_mapLoaded[450];
		int					_mapCollisionLoaded[450];
		sf::Text			_txt;

		//---- for Debug ----//
		sf::RectangleShape	_rects[450];
		//---- canonical form ----//
		Game(Game const &rhs);
		Game	&operator=(Game const &rhs);
		void	mapLoader(std::string const &file_map, int type);
};

#endif
