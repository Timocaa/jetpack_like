/* ************************************************************************** */
/*                                                                            */
/*                                         LLr::,::, ,:L    ,     :i;     .   */
/*   Input.cpp                             ,,.:::,   L;i   ::,    Y:; .:Li.   */
/*                                            i:;   :i:r   i::   ,i::i;,      */
/*   By:  Timoca                             ;ri,   UiiL  ;;:i   Yi::::       */
/*                                          .krj   UYLrY.,L;:r  lU7JYriYi,    */
/*   Created: 2023/03/19 17:50:20           qKKL  :Dd.;YlcLLlJ, iRk.  UYTK    */
/*   Updated: 2023/03/19 20:28:34           .UM.  RDD :DRi LU   DDK    ;cK    */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Input.hpp"

/*
*	brief:  Default constructor
*	params: void
*	return: void
*/
Input::Input(): _collected(false), _spaceship()
{
	this->_button.up = false;
	this->_button.right = false;
	this->_button.left = false;
	this->_button.action = false;
	this->_button.escape = false;
}

/*
*	brief:  Copy constructor
*	params: Input const&
*	return: void
*/
Input::Input(Input const &rhs)
{
	*this = rhs;
}

/*
*	brief:  Assignement operator
*	params: Input const&
*	return: Input &
*/
Input	&Input::operator=(Input const &rhs)
{
	(void)rhs;
	return (*this);
}

/*
*   brief:  check if first element is collected
*   param:  void
*   return: bool
*/
bool	Input::isCollected() const
{
	return (this->_collected);
}

/*
*	brief:  Handler keyboard event
*	params: sf::Event &, sf::RenderWindow &
*	return: void
*/
void	Input::handlerInput(sf::Event &event, sf::RenderWindow &window, Player &player)
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();
		if (event.type == sf::Event::KeyPressed)
    	{
 	       switch (event.key.code)
    	    {
            	case sf::Keyboard::A: _button.left = true; break;
	            case sf::Keyboard::D: _button.right = true; break;
    	        case sf::Keyboard::W:
					if (player.gazQuantity() > MIN_GAZ)
						_button.up = true;
					else
						_button.up = false;
					break;
        	    case sf::Keyboard::E: _button.action = true; break;
            	default: break;
	        }
   		}
	    if (event.type == sf::Event::KeyReleased)
    	{
        	switch (event.key.code)
	        {
        	    case sf::Keyboard::A: _button.left = false; break;
            	case sf::Keyboard::D: _button.right = false; break;
	            case sf::Keyboard::W: _button.up = false; break;
    	        case sf::Keyboard::E: _button.action = false; break;
        	    default: break;
       		 }
			player.setIdle(true);
    	}
	}
}

/*
*	brief:  Manage the event if state of button
*	params: Game &
*	return: void
*/
void Input::handlerEvent(Player &player, int *collisionMap)
{
	int hPosX = round(player.getSprite().getPosition().x / SPRITE_SIZE);
	int hPosY = round(player.getSprite().getPosition().y / SPRITE_SIZE);
    if (_button.left == true)
    {
		// check if walk on a solid
		if (!collisionMap[hPosX + (hPosY + 1) * 25])
			player.setFly(true);
		// set player in movement
		player.setIdle(false);
		// set dir of player
		player.setDir(-1);
		// set sprite for animation
		if (!player.isFlying())
			player.setAnimY(Left);
		else
			player.setAnimY(Up_left);
		// check collision in left
		hPosX = floor((player.getSprite().getPosition().x - (SPEED_PLAYER)) / SPRITE_SIZE);
		if (player.getSprite().getPosition().x - SPEED_PLAYER > 0)
			if (!collisionMap[hPosX + hPosY * 25])
				player.getSprite().move(-SPEED_PLAYER, 0);
    }
    if (_button.right == true)
    {
		// check if walk on a solid
		if (!collisionMap[hPosX + (hPosY + 1) * 25])
			player.setFly(true);
		// set player in movement
		player.setIdle(false);
		// set dir of player
		player.setDir(1);
		// set sprite for animation
		if (!player.isFlying())
			player.setAnimY(Right);
		else
			player.setAnimY(Up_right);
		// check collision in right
		hPosX = ceil((player.getSprite().getPosition().x + (SPEED_PLAYER)) / SPRITE_SIZE);
		if (player.getSprite().getPosition().x < 1000 - SPRITE_SIZE)
			if (!collisionMap[hPosX + hPosY * 25])
				player.getSprite().move(SPEED_PLAYER, 0);
    }
    if (_button.up == true && player.gazQuantity() > 0)
    {
		// set player in movement
		player.setIdle(false);
		// set player is flying
		player.setFly(true);
		player.setGaz(-2);
		// set sprite for animation
		if (player.getDir() == 1)
			player.setAnimY(Up_right);
		else
			player.setAnimY(Up_left);
		// check collision above the player
		hPosY = round((player.getSprite().getPosition().y - (SPEED_PLAYER * 8)) / SPRITE_SIZE);
		if (player.getSprite().getPosition().y - 1 > 0)
			if (!collisionMap[hPosX + hPosY * 25] && player.gazQuantity() > 0)
				player.getSprite().move(0, -SPEED_PLAYER);
    }
    if (_button.action == true)
    {
		if (player.getSprite().getPosition().x < 200
			&& player.getSprite().getPosition().y == 600)
		{
			// here pop the space ship or fuel lvl
			if (player.inPossession())
			{
				this->_spaceship.displayParts();
				this->_collected = true;
			}
			player.setPossesion(false);
		}
    }
	// handler gravity fall
	if (player.isFlying() && this->_button.up == false)
	{
		// check collision under the player
		hPosY = round((player.getSprite().getPosition().y + (SPEED_PLAYER * 7)) / SPRITE_SIZE);
		if (!collisionMap[hPosX + hPosY * 25])
			player.getSprite().move(0, SPEED_PLAYER);
		else
			player.setFly(false);
	}
	// handler animation sprite for player
	player.animPlayer();
	player.getSprite().setTextureRect(sf::IntRect(player.coordSprite().x * SPRITE_SIZE,
							player.coordSprite().y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
}

/*
*	brief:  Draw the spaceship and fuel lvl
*	params: void
*	return: void
*/
void	Input::drawSpaceship(sf::RenderWindow &window)
{
	window.draw(this->_spaceship.getShipSprite());
	window.draw(this->_spaceship.getOutlineShape());
	window.draw(this->_spaceship.getFuelLvlShape());
}

/*
*	brief:  Destructor
*	params: void
*	return: void
*/
Input::~Input()
{
}
