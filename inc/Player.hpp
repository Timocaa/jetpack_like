/* ************************************************************************** */
/*                                                                            */
/*                                         LLr::,::, ,:L    ,     :i;     .   */
/*   Player.hpp                            ,,.:::,   L;i   ::,    Y:; .:Li.   */
/*                                            i:;   :i:r   i::   ,i::i;,      */
/*   By:  Timoca                             ;ri,   UiiL  ;;:i   Yi::::       */
/*                                          .krj   UYLrY.,L;:r  lU7JYriYi,    */
/*   Created: 2023/03/19 17:47:20           qKKL  :Dd.;YlcLLlJ, iRk.  UYTK    */
/*   Updated: 2023/03/19 20:18:50           .UM.  RDD :DRi LU   DDK    ;cK    */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
	public:
		//---- canonical form ----//
		Player();
		~Player();
		//---- member methods ----//
			//---- Getters
		sf::Sprite		&getSprite();
		int				getDir() const;
		bool			isFlying() const;
		bool			isIdle() const;
		sf::Vector2i	coordSprite() const;

			//---- Setters
		void			setDir(int dir);
		void			setFly(bool flying);
		void			setIdle(bool idle);
		void			setAnimX(int value);
		void			setAnimY(int value);

	private:
		//---- member objects ----//
		sf::Texture		_texture;
		sf::Sprite		_sprite;
		int				_direction;
		bool			_isFliyng;
		bool			_idle;
		sf::Vector2i	_anim;

		//---- canonical form ----//
		Player(Player const &rhs);
		Player	&operator=(Player const &rhs);
};

#endif