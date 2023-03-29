/* ************************************************************************** */
/*                                                                            */
/*                                         LLr::,::, ,:L    ,     :i;     .   */
/*   Items.hpp                             ,,.:::,   L;i   ::,    Y:; .:Li.   */
/*                                            i:;   :i:r   i::   ,i::i;,      */
/*   By:  Timoca                             ;ri,   UiiL  ;;:i   Yi::::       */
/*                                          .krj   UYLrY.,L;:r  lU7JYriYi,    */
/*   Created: 2023/03/26 17:20:44           qKKL  :Dd.;YlcLLlJ, iRk.  UYTK    */
/*   Updated: 2023/03/26 17:20:46           .UM.  RDD :DRi LU   DDK    ;cK    */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITEMS_HPP
# define ITEMS_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Player.hpp"
#include "Gaz.hpp"
#include "Container.hpp"

class Items
{
	public:
		//---- canonical form ----//
		Items();
		~Items();

		//---- Getters ----//
	//	sf::Sprite	&getGazSprite();
		bool		needGaz() const;

		//---- member methods ----//
		void		handlerItems(Player &player, int *collisionMap);
		void		draw(sf::RenderWindow &window);

	private:
		//---- member object ----//
		Gaz			_gaz;
		Container	_box;

		//---- canonical form ----//
		Items(Items const &rhs);
		Items	&operator=(Items const &rhs);

		//---- private methods ----//
};

#endif
