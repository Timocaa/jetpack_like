#include "../inc/Alien.hpp"

/*
*   brief:  Default constructor
*   param:  void
*   return: void
*/
Alien::Alien(): _texture(), _sprite(), _dir(1, 0),
                _anim(0, 0), _clockAnim()
{
    // load texture of alien from file
	if (!this->_texture.loadFromFile("res/sprites/alien.png"))
		throw std::logic_error("");
	// set texture to sprite for use
	this->_sprite.setTexture(this->_texture);
	// set the position of alien on the map
	this->_sprite.setPosition(160, 600);
}

/*
*   brief:  Copy constructor
*   param:  Alien const &
*   return: void
*/
Alien::Alien(Alien const & rhs)
{
    *this = rhs;
}

/*
*   brief:  Assignement operator
*   param:  Alien const &
*   return: Alien &
*/
Alien   &Alien::operator=(Alien const &rhs)
{
    (void)rhs;
    return (*this);
}

/*
*   brief:  Destructor
*   param:  void
*   return: void
*/
Alien::~Alien()
{
}