#include "../inc/Spaceship.hpp"

/*
*   brief:  Default constructor
*   param:  void
*   return: void
*/
Spaceship::Spaceship():	_texture(), _sprite(), _partOfSpaceship(4), _fuelLevel(4)
{
    // load texture of spaceship from file
	if (!this->_texture.loadFromFile("res/sprites/spaceship.png"))
		throw std::logic_error("");
	// set texture to sprite for use
	this->_sprite.setTexture(this->_texture);
}

/*
*   brief:  Copy constructor
*   param:  Spaceship const &
*   return: void
*/
Spaceship::Spaceship(Spaceship const &rhs)
{
    *this = rhs;
}

/*
*   brief:  Assignement operator
*   param:  Spaceship const &
*   return: Spaceship &
*/
Spaceship   &Spaceship::operator=(Spaceship const &rhs)
{
    (void)rhs;
    return (*this);
}

/*
*   brief:  manage display of spaceship elements and fuel level
*   param:  Player &
*   return: void
*/
void    Spaceship::displayParts(Player &player)
{
    if (this->_partOfSpaceship > 0)
        this->_partOfSpaceship--;
    else
        this->_fuelLevel--;
    this->spriteSpaceshipElements();
    if (!this->_partOfSpaceship)
        this->updateFuelLvl();
}

/*
*   brief:  Set sprite of spaceship elements
*   param:  void
*   return: void
*/
void    Spaceship::spriteSpaceshipElements()
{
    switch (this->_partOfSpaceship)
    {
        case 0:
            this->_sprite.setTextureRect(sf::IntRect(this->_partOfSpaceship * SPRITE_SIZE,
								    0, SPRITE_SIZE, SPRITE_SIZE * 4));
            this->_sprite.setPosition(0, 600 - SPRITE_SIZE * 4);
            break;
        case 1:
            this->_sprite.setTextureRect(sf::IntRect(this->_partOfSpaceship * SPRITE_SIZE,
								    0, 120, SPRITE_SIZE * 3));
            this->_sprite.setPosition(0, 600 - SPRITE_SIZE * 3);
            break;
        case 2:
            this->_sprite.setTextureRect(sf::IntRect(this->_partOfSpaceship * SPRITE_SIZE,
								    0, 120, SPRITE_SIZE * 2));
            this->_sprite.setPosition(0, 600 - SPRITE_SIZE * 2);
            break;
        case 3:
            this->_sprite.setTextureRect(sf::IntRect(this->_partOfSpaceship * SPRITE_SIZE,
								    0, 120, SPRITE_SIZE));
            this->_sprite.setPosition(0, 600 - SPRITE_SIZE);
            break;
        default:
            break;
    }
}

/*
*   brief:  update display offuel level
*   param:  void
*   return: void
*/
void    Spaceship::updateFuelLvl()
{
    //on vera plus tard la je vais me coucher
}

/*
*   brief:  Destructor
*   param:  void
*   return: void
*/
Spaceship::~Spaceship()
{
}