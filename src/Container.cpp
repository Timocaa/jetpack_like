#include "../inc/Container.hpp"

/*
*   brief:  Default Constructor
*   param:  void
*   return: void
*/
Container::Container(): _texture(), _sprite(), _falling(true), _boxUp(false),
                        _clockPop(),
			            _rand(std::chrono::system_clock::now().time_since_epoch().count()),
                        _boxQuantity(0), _boxType(0)
{
    // load texture for container item
	if (!this->_texture.loadFromFile("res/sprites/containers.png"))
		throw std::logic_error("");
	// set texture on container sprite
	this->_sprite.setTexture(this->_texture);
}

/*
*   brief:  Copy Constructor
*   param:  Continer const &
*   return: void
*/
Container::Container(Container const &rhs)
{
    *this = rhs;
}

/*
*   brief:  Assignement operator
*   param:  Container const &
*   return: Container &
*/
Container   &Container::operator=(Container const &rhs)
{
    (void)rhs;
    return (*this);
}

/*
*   brief:  Access to container sprite 
*   param:  void
*   return: sf::Sprite &
*/
sf::Sprite  &Container::getSprite()
{
    return (this->_sprite);
}

/*
*   brief:  check if a container is in game
*   param:  void
*   return: bool
*/
bool    Container::containerUp() const
{
    return (this->_boxUp);
}

/*
*   brief:  check if a container is needed
*   param:  void
*   return: bool
*/
bool    Container::needBox() const
{
    if (this->_boxQuantity < 10)
        return (true);
    return (false);
}

/*
*   brief:  Rand position in x for display another Container
*   params: void
*   return: void
*/
void    Container::randPosition()
{
    if (this->_clockPop.getElapsedTime().asSeconds() > POP_BOX && !this->_boxUp)
	{
		int posX = this->_boxRand(this->_rand) * SPRITE_SIZE;
		this->_sprite.setPosition(posX, -SPRITE_SIZE);
		this->_boxUp = true;
        this->_clockPop.restart();
	}
}

/*
*   brief:  Manage Container item if is in windows
*   params: Player &
*   return: void
*/
void    Container::handling(Player &player, int *collisionMap)
{
    if (this->_falling == true)
	{
		int IPosX = round(this->_sprite.getPosition().x / SPRITE_SIZE);
		int IPosY = round((this->_sprite.getPosition().y + (SPEED_FALL_ITEM * 7)) / SPRITE_SIZE);
		if (!collisionMap[IPosX + IPosY * 25])
			this->_sprite.move(0, SPEED_FALL_ITEM);
		else
			this->_falling = false;
	}
	// check collision with player
	sf::FloatRect	playerHitBox = player.getSprite().getGlobalBounds();
	sf::FloatRect	itemHitBox = this->_sprite.getGlobalBounds();
	if (playerHitBox.intersects(itemHitBox))
	{
		player.setPossesion(true);
        this->_boxQuantity++;
		this->_boxUp = false;
		this->_falling = true;
		this->_clockPop.restart();
	}
	// update animation for items
	this->animSprite();
	this->_sprite.setTextureRect(sf::IntRect(this->_boxType * SPRITE_SIZE,
								    0, SPRITE_SIZE, SPRITE_SIZE));
}

/*
*   brief:  set part sprite of type box
*   param:  void
*   return: void
*/
void    Container::animSprite()
{
    if (this->_boxQuantity < 4)
        this->_boxType = 0;
    else
        this->_boxType = 1;
}

/*
*   brief:  Destructor
*   param:  void
*   return: void
*/
Container::~Container()
{
}