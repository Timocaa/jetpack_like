/* ************************************************************************** */
/*                                                                            */
/*                                         LLr::,::, ,:L    ,     :i;     .   */
/*   Player.cpp                            ,,.:::,   L;i   ::,    Y:; .:Li.   */
/*                                            i:;   :i:r   i::   ,i::i;,      */
/*   By:  Timoca                             ;ri,   UiiL  ;;:i   Yi::::       */
/*                                          .krj   UYLrY.,L;:r  lU7JYriYi,    */
/*   Created: 2023/03/19 17:51:24           qKKL  :Dd.;YlcLLlJ, iRk.  UYTK    */
/*   Updated: 2023/03/19 20:28:53           .UM.  RDD :DRi LU   DDK    ;cK    */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Player.hpp"

/*
*	brief:	Default constructor
*	params:	void
*	return:	void
*/
Player::Player():	_texture(), _sprite(), _direction(1), _isFliyng(false),
					_idle(true), _anim(0, 0)
{
	// load texture of player from file
	if (!this->_texture.loadFromFile("res/sprites/player.png"))
		throw std::logic_error("");
	// set texture to sprite for use
	this->_sprite.setTexture(this->_texture);
	// set the position of player on the map
	this->_sprite.setPosition(160, 600);
}

/*
*	brief:	Copy constructor
*	params:	Player const &
*	return:	void
*/
Player::Player(Player const &rhs)
{
	*this = rhs;
}

/*
*	brief:	Getter of Sprite object
*	params:	void
*	return:	sf::Sprite &
*/
sf::Sprite	&Player::getSprite()
{
	return (this->_sprite);
}

/*
*	brief:	Getter of player Direction (1 to the right; -1 to the left)
*	params:	void
*	return:	int
*/
int	Player::getDir() const
{
	return (this->_direction);
}

/*
*	brief:	Getter of state of player is flying or not
*	params:	void
*	return:	bool
*/
bool	Player::isFlying() const
{
	return (this->_isFliyng);
}

/*
*	brief:	Getter of state of player is idle or not
*	params:	void
*	return:	bool
*/
bool	Player::isIdle() const
{
	return (this->_idle);
}

/*
*	brief:	Getter of coord of current sprite
*	params:	void
*	return:	sf::Vector2i
*/
sf::Vector2i	Player::coordSprite() const
{
	return (this->_anim);
}

/*
*	brief:	Set the direction of player (1 to the right; -1 to the left)
*	params:	int
*	return:	void
*/
void	Player::setDir(int dir)
{
	this->_direction = dir;
}

/*
*	brief:	Set if player is flying or not
*	params:	bool
*	return:	void
*/
void	Player::setFly(bool fly)
{
	this->_isFliyng = fly;
}

/*
*	brief:	Set if player is idle or not
*	params:	bool
*	return:	void
*/
void	Player::setIdle(bool idle)
{
	this->_idle = idle;
}

/*
*	brief:	Set the value X of tileset player
*	params:	int
*	return:	void
*/
void	Player::setAnimX(int value)
{
	this->_anim.x = value;
}

/*
*	brief:	Set the value Y of tilset player
*	params:	int
*	return:	void
*/
void	Player::setAnimY(int value)
{
	this->_anim.y = value;
}

/*
*	brief:	Assignement operator
*	params:	Player const &
*	return:	Player &
*/
Player	&Player::operator=(Player const &rhs)
{
	(void)rhs;
	return (*this);
}

/*
*	brief:	Destructor
*	params:	void
*	return:	void
*/
Player::~Player()
{
}
