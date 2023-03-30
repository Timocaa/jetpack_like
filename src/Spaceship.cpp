#include "../inc/Spaceship.hpp"

/*
*   brief:  Default constructor
*   param:  void
*   return: void
*/
Spaceship::Spaceship():	_texture(), _sprite(), _partOfSpaceship(4), _fuelLevel(4),
                        _outline(sf::Vector2f(10.f, 90.f)), _level(sf::Vector2f(10.f, 80.f))
{
    // load texture of spaceship from file
	if (!this->_texture.loadFromFile("res/sprites/spaceship.png"))
		throw std::logic_error("");
	// set texture to sprite for use
	this->_sprite.setTexture(this->_texture);
    // create rectanle for fuel level
    _outline.setFillColor(sf::Color::Black);
    _outline.setOutlineColor(sf::Color::White);
    _outline.setOutlineThickness(2);
    _outline.setPosition(10,500);
    _level.setFillColor(sf::Color::Red);
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
*   brief:  Get the Sprite of spaceship
*   param:  void
*   return: sf::Sprite  &
*/
sf::Sprite  &Spaceship::getShipSprite()
{
    return (this->_sprite);
}

/*
*   brief:  Get the outline rectangle of fuel lvl
*   param:  void
*   return: sf::RectangleShape &
*/
sf::RectangleShape  &Spaceship::getOutlineShape()
{
    return (this->_outline);
}

/*
*   brief:  Get the fuel lvl rectangle
*   param:  void
*   return: sf::RectangleShape &
*/
sf::RectangleShape  &Spaceship::getFuelLvlShape()
{
    return (this->_level);
}

/*
*   brief:  manage display of spaceship elements and fuel level
*   param:  Player &
*   return: void
*/
void    Spaceship::displayParts()
{
    if (this->_partOfSpaceship > 0)
        this->_partOfSpaceship--;
    else
        this->_fuelLevel--;
    this->spriteSpaceshipElements();
   // if (!this->_partOfSpaceship)
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
            this->_sprite.setTextureRect(sf::IntRect(0, this->_partOfSpaceship * SPRITE_SIZE,
								    120, SPRITE_SIZE * 4));
            this->_sprite.setPosition(0, 600 - SPRITE_SIZE * 3);
            break;
        case 1:
            this->_sprite.setTextureRect(sf::IntRect(0, this->_partOfSpaceship * SPRITE_SIZE,
								    120, SPRITE_SIZE * 3));
            this->_sprite.setPosition(0, 600 - SPRITE_SIZE * 2);
            break;
        case 2:
            this->_sprite.setTextureRect(sf::IntRect(0, this->_partOfSpaceship * SPRITE_SIZE,
								    120, SPRITE_SIZE * 2));
            this->_sprite.setPosition(0, 600 - SPRITE_SIZE);
            break;
        case 3:
            this->_sprite.setTextureRect(sf::IntRect(0, this->_partOfSpaceship * SPRITE_SIZE,
								    120, SPRITE_SIZE));
            this->_sprite.setPosition(0, 600);
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
    this->_level.setPosition(10, 500);
    this->_level.setSize(sf::Vector2f(10.f, 90.f));
    
    
}

/*
*   brief:  Destructor
*   param:  void
*   return: void
*/
Spaceship::~Spaceship()
{
}