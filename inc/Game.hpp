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
#include <vector>

#include "Player.hpp"
#include "Input.hpp"
#include "Map.hpp"
#include "Items.hpp"
#include "Info.hpp"
#include "Alien.hpp"

#include <string>

#include <sstream>
#include <utility>

#define WIN_WIDTH	1000
#define WIN_HEIGHT	720
#define COLS		25
#define LINES		18
#define NBALIENS	3

class Game
{
	public:
		//---- canonical form ----//
		Game();
		~Game();
		//---- member methods ----//
		void	start();

	private:
		//---- member object ----//
		sf::RenderWindow		_window;
		Player					_player;
		Input					_input;
		Map						_map;
		Items					_item;
		Info					_info;
		std::vector<Alien *>	_aliens;

		int					_mapLoaded[450];
		int					_mapCollisionLoaded[450];

		//---- private methods ----//
			//---- canonical form
		Game(Game const &rhs);
		Game	&operator=(Game const &rhs);
			
			//---- methods
		void	mapLoader(std::string const &file_map, int type);
		bool	checkEndOfGame();
};

#endif
