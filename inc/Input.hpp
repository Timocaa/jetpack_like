/* ************************************************************************** */
/*                                                                            */
/*                                         LLr::,::, ,:L    ,     :i;     .   */
/*   Input.hpp                             ,,.:::,   L;i   ::,    Y:; .:Li.   */
/*                                            i:;   :i:r   i::   ,i::i;,      */
/*   By:  Timoca                             ;ri,   UiiL  ;;:i   Yi::::       */
/*                                          .krj   UYLrY.,L;:r  lU7JYriYi,    */
/*   Created: 2023/03/19 17:47:45           qKKL  :Dd.;YlcLLlJ, iRk.  UYTK    */
/*   Updated: 2023/03/19 20:31:09           .UM.  RDD :DRi LU   DDK    ;cK    */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HPP
# define INPUT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Player.hpp"

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
		void	handlerInput(sf::Event &event, sf::RenderWindow &window, Player &player);
		void	handlerEvent(Player &player, int *collisionMap);

	private:
		//---- member object ----//
		t_button	_button;
		
		//---- canonical form ----//
		Input(Input const &rhs);
		Input	&operator=(Input const &rhs);
};

#endif