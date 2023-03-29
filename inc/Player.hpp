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

#define SPEED_PLAYER	3
#define GRAV_SPEED		2
#define MAX_GAZ 		1000
#define MIN_GAZ 		0
#define SPRITE_SIZE	    40
#define SPEED_FALL_ITEM	3
#define POP_GAZ         5
#define POP_BOX			3
#define GAZ_GAIN        250

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
		int				gazQuantity() const;

			//---- Setters
		void			setDir(int dir);
		void			setFly(bool flying);
		void			setIdle(bool idle);
		void			setAnimX(int value);
		void			setAnimY(int value);
		void			setGaz(int value);

			//---- public methods
		void			animPlayer();

	private:
		//---- member objects ----//
		sf::Texture		_texture;
		sf::Sprite		_sprite;
		int				_direction;
		bool			_fly;
		bool			_idle;
		sf::Vector2i	_anim;
		sf::Clock		_clockAnim;
		sf::Clock		_clockIdle;
		int				_gaz;

		//---- canonical form ----//
		Player(Player const &rhs);
		Player	&operator=(Player const &rhs);
};

#endif
