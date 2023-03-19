#include "../inc/Input.hpp"

/*
*	brief:  Default constructor
*	params: void
*	return: void
*/
Input::Input(): _animHero(0, Idle), _clockAnim(), _clockIdle(), _heroHitBox()
{
	this->_button.up = false;
	this->_button.right = false;
	this->_button.left = false;
	this->_button.action = false;
	this->_button.escape = false;
	this->_idle = true;
	this->_fly = false;
	this->_dir = 1;
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
void	Input::handlerInput(sf::Event &event, sf::RenderWindow &window)
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
			this->_idle = true;
    	}
	}
}

/*
*	brief:  Manage the event if state of button
*	params: Game &
*	return: void
*/
void Input::checkBtn(sf::Sprite &heroSprite, int *collisionMap)
{
	int hPosX = round(heroSprite.getPosition().x / SPRITE_SIZE);
	int hPosY = round(heroSprite.getPosition().y / SPRITE_SIZE);
    if (_button.left == true)
    {
		if (!collisionMap[hPosX + (hPosY + 1) * 25])
			this->_fly = true;
		this->_idle = false;
		this->_dir = -1;
		if (!this->_fly)
			this->_animHero.y = Left;
		else
			this->_animHero.y = Up_left;
		hPosX = floor((heroSprite.getPosition().x - (SPEED)) / SPRITE_SIZE);
		if (heroSprite.getPosition().x - SPEED > 0)
			if (!collisionMap[hPosX + hPosY * 25])
				heroSprite.move(-SPEED, 0);
    }
    if (_button.right == true)
    {
		if (!collisionMap[hPosX + (hPosY + 1) * 25])
			this->_fly = true;
		this->_idle = false;
		this->_dir = 1;
		if (!this->_fly)
			this->_animHero.y = Right;
		else
			this->_animHero.y = Up_right;
		hPosX = ceil((heroSprite.getPosition().x + (SPEED)) / SPRITE_SIZE);
		if (heroSprite.getPosition().x < 1000 - SPRITE_SIZE)
			if (!collisionMap[hPosX + hPosY * 25])
				heroSprite.move(SPEED, 0);
    }
    if (_button.up == true)
    {
		this->_idle = false;
		this->_fly = true;
		if (this->_dir == 1)
			this->_animHero.y = Up_right;
		else
			this->_animHero.y = Up_left;
		hPosY = round((heroSprite.getPosition().y - (SPEED * 8)) / SPRITE_SIZE);
		if (heroSprite.getPosition().y - 1 > 0)
			if (!collisionMap[hPosX + hPosY * 25])
				heroSprite.move(0, -SPEED);
    }
    if (_button.action == true)
    {
		this->_idle = false;
		this->_animHero.y = Left;
		std::cout << "action baby..." << std::endl;
    }
	if (this->_fly && this->_button.up == false)
	{
		hPosY = round((heroSprite.getPosition().y + (SPEED * 7)) / SPRITE_SIZE);
		if (!collisionMap[hPosX + hPosY * 25])
			heroSprite.move(0, SPEED);
		else
			this->_fly = false;
	}
	this->animPlayer();
	heroSprite.setTextureRect(sf::IntRect(_animHero.x * SPRITE_SIZE, _animHero.y * SPRITE_SIZE,
								SPRITE_SIZE, SPRITE_SIZE));
}

/*
*	brief:  setting sprite animation for player
*	params: void
*	return: void
*/
void	Input::animPlayer()
{
	if (this->_clockAnim.getElapsedTime().asSeconds() > 0.05f)
	{
		if (!this->_idle)
			this->_animHero.x++;
		else
		{
			if (!this->_fly)
			{
				this->_animHero.y = 0;
				if (this->_clockIdle.getElapsedTime().asSeconds() > 0.7f)
				{
					this->_animHero.x++;
					this->_clockIdle.restart();
				}
			}	
			else
				this->_animHero.x = 0;
		}
		if (this->_animHero.x > 8)
			this->_animHero.x = 0;
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
