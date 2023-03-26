#include "../inc/Gaz.hpp"

/*
*   brief:  Default constructor
*   params: void
*   return: void
*/
Gaz::Gaz(): _gazTexture(), _gazSprite(), _falling(true), _needGaz(false),
            _anim(), _clockItemPop(),
			_rand(std::chrono::system_clock::now().time_since_epoch().count())

{
    // load texture for gaz item
	if (!this->_gazTexture.loadFromFile("res/sprites/gaz.png"))
		throw std::logic_error("");
	// set texture on gaz sprite
	this->_gazSprite.setTexture(this->_gazTexture);
}

/*
*   brief:  Copy constructor
*   params: Gaz const &
*   return: void
*/
Gaz::Gaz(Gaz const &rhs)
{
    *this = rhs;
}

/*
*   brief:  Assignement operator
*   params: Gaz const &
*   return: Gaz &
*/
Gaz &Gaz::operator=(Gaz const &rhs)
{
    (void)rhs;
    return (*this);
}

/*
*   brief:  Return Sprite of Gaz item
*   params: void
*   return: sf::Sprite &
*/
sf::Sprite  &Gaz::getGazSprite()
{
    return (this->_gazSprite);
}

/*
*   brief:  Check if a gaz is in window
*   params: void
*   return: bool
*/
bool    Gaz::needGaz() const
{
    return (this->_needGaz);
}

/*
*   brief:  Rand position in x for display another Gaz bottle
*   params: int
*   return: void
*/
void    Gaz::randPosition()
{
    if (this->_clockItemPop.getElapsedTime().asSeconds() > POP_GAZ && !this->_needGaz)
	{
		int posX = this->_boxRand(this->_rand) * SPRITE_SIZE;
		this->_gazSprite.setPosition(posX, -SPRITE_SIZE);
		this->_needGaz = true;
        this->_clockItemPop.restart();
	}
}

/*
*   brief:  Manage Gaz item if is in windows
*   params: Player &
*   return: void
*/
void    Gaz::handling(Player &player, int *collisionMap)
{
    if (this->_falling == true)
	{
		int IPosX = round(this->_gazSprite.getPosition().x / SPRITE_SIZE);
		int IPosY = round((this->_gazSprite.getPosition().y + (SPEED_FALL_GAZ * 7)) / SPRITE_SIZE);
		if (!collisionMap[IPosX + IPosY * 25])
			this->_gazSprite.move(0, SPEED_FALL_GAZ);
		else
			this->_falling = false;
	}
	// check collision with player
	sf::FloatRect	playerHitBox = player.getSprite().getGlobalBounds();
	sf::FloatRect	itemHitBox = this->_gazSprite.getGlobalBounds();
	if (playerHitBox.intersects(itemHitBox))
	{
		player.setGaz(GAZ_GAIN);
		this->_needGaz = false;
		this->_falling = true;
		this->_clockItemPop.restart();
	}
	// update animation for items
	this->animSprite();
	this->_gazSprite.setTextureRect(sf::IntRect(this->_anim.x * SPRITE_SIZE,
								this->_anim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
}

/*
*	brief:	Update animation of gaz item
*	params:	void
*	return:	void
*/
void	Gaz::animSprite()
{
	// check time passed for change the sprite of player
	if (this->_clockAnim.getElapsedTime().asSeconds() > 0.05f)
	{
		if (!this->_falling)
			this->_anim.x++;
		else
			this->_anim.x = 0;
		if (this->_anim.x > 7)
			this->_anim.x = 0;
		this->_clockAnim.restart();
	}	
}

/*
*   brief:  Destructor
*   params: void
*   return: void
*/
Gaz::~Gaz()
{
}