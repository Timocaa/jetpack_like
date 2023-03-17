#include "../inc/Input.hpp"

/*
*	brief:  Default constructor
*	params: void
*	return: void
*/
Input::Input(): _animHero(0, Idle), _clockAnim(), _heroHitBox()
{
	this->_button.up = false;
	this->_button.right = false;
	this->_button.left = false;
	this->_button.action = false;
	this->_button.escape = false;
	this->_idle = true;
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
void Input::checkBtn(sf::Sprite &heroSprite)
{
    if (_button.left == true)
    {
		this->_idle = false;
		this->_animHero.y = Left;
		heroSprite.move(-SPEED, 0);
    }
    if (_button.right == true)
    {
		this->_idle = false;
		this->_animHero.y = Right;
		heroSprite.move(SPEED, 0);
    }
    if (_button.up == true)
    {
		this->_idle = false;
		this->_animHero.y = Up_right;
		heroSprite.move(0, -SPEED);
    }
    if (_button.action == true)
    {
		this->_idle = false;
		this->_animHero.y = Left;
		std::cout << "action baby..." << std::endl;
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
			this->_animHero.y = 0;
		}
		if (this->_animHero.x > 8)
			this->_animHero.x = 0;
		this->_clockAnim.restart();
	}
}

/*
*	brief:  Check if player go to collision with map elements
*	params: sf::FloatRect &, sf::FloatRect &
*	return: void
*/
void	Input::checkCollision(sf::Sprite &heroSprite, sf::FloatRect cubBox)
{
	sf::FloatRect	heroBox = heroSprite.getGlobalBounds();
	if (heroBox.intersects(cubBox))
	{
		std::cout << "hit...!\n";
		heroSprite.move(0, 0);
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
