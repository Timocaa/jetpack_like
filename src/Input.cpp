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
Input::Input(): _clockAnim(), _clockIdle()
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
    	        case sf::Keyboard::W: _button.up = true; break;
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
void Input::checkBtn(Player &player, int *collisionMap)
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
		hPosX = floor((player.getSprite().getPosition().x - (SPEED)) / SPRITE_SIZE);
		if (player.getSprite().getPosition().x - SPEED > 0)
			if (!collisionMap[hPosX + hPosY * 25])
				player.getSprite().move(-SPEED, 0);
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
		hPosX = ceil((player.getSprite().getPosition().x + (SPEED)) / SPRITE_SIZE);
		if (player.getSprite().getPosition().x < 1000 - SPRITE_SIZE)
			if (!collisionMap[hPosX + hPosY * 25])
				player.getSprite().move(SPEED, 0);
    }
    if (_button.up == true)
    {
		// set player in movement
		player.setIdle(false);
		// set player is flying
		player.setFly(true);
		// set sprite for animation
		if (player.getDir() == 1)
			player.setAnimY(Up_right);
		else
			player.setAnimY(Up_left);
		// check collision above the player
		hPosY = round((player.getSprite().getPosition().y - (SPEED * 8)) / SPRITE_SIZE);
		if (player.getSprite().getPosition().y - 1 > 0)
			if (!collisionMap[hPosX + hPosY * 25])
				player.getSprite().move(0, -SPEED);
    }
    if (_button.action == true)
    {
		player.setIdle(false);
		player.setAnimY(Left);
		std::cout << "action baby..." << std::endl;
    }
	// handler gravity fall
	if (player.isFlying() && this->_button.up == false)
	{
		// check collision under the player
		hPosY = round((player.getSprite().getPosition().y + (SPEED * 7)) / SPRITE_SIZE);
		if (!collisionMap[hPosX + hPosY * 25])
			player.getSprite().move(0, SPEED);
		else
			player.setFly(false);
	}
	// handler animation sprite for player
	this->animPlayer(player);
	player.getSprite().setTextureRect(sf::IntRect(player.coordSprite().x * SPRITE_SIZE,
							player.coordSprite().y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
}

/*
*	brief:  setting sprite animation for player
*	params: void
*	return: void
*/
void	Input::animPlayer(Player &player)
{
	// check time passed for change the sprite of player
	if (this->_clockAnim.getElapsedTime().asSeconds() > 0.05f)
	{
		// check if player is in movement
		if (!player.isIdle())
			player.setAnimX(player.coordSprite().x + 1);
		else
		{
			// check if player is flying
			if (!player.isFlying())
			{
				player.setAnimY(0);
				// check time passed for animation of player static
				if (this->_clockIdle.getElapsedTime().asSeconds() > 0.7f)
				{
					player.setAnimX(player.coordSprite().x + 1);
					this->_clockIdle.restart();
				}
			}	
			else
				player.setAnimX(0);
		}
		// handle loop of sprite animation
		if (player.coordSprite().x > 8)
			player.setAnimX(0);
		this->_clockAnim.restart();
	}

}

/*
*	brief:  Destructor
*	params: void
*	return: void
*/
Input::~Input()
{
}
