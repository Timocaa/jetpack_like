#include "../inc/Input.hpp"

/*
*	brief:  Default constructor
*	params: void
*	return: void
*/
Input::Input()
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
    	}
	}
}

/*
*	brief:  Manage the event if state of button
*	params: Game &
*	return: void
*/
void Input::checkBtn(sf::Text &txt)
{
    if (_button.left == true)
    {
		txt.setString("go to the Left...");
    }
    if (_button.right == true)
    {
		txt.setString("go to the Right...");
    }
    if (_button.up == true)
    {
		txt.setString("go to Jump...");
    }
    if (_button.action == true)
    {
		txt.setString("take a snapshot...");
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
