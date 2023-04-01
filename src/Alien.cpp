#include "../inc/Alien.hpp"

/*
*   brief:  Default constructor
*   param:  void
*   return: void
*/
Alien::Alien(): _texture(), _sprite(), _dir(0, 0),
                _anim(0, 0), _clockAnim(),
				_rand(std::chrono::system_clock::now().time_since_epoch().count()),
				_gameOver(false)
{
    // load texture of alien from file
	if (!this->_texture.loadFromFile("res/sprites/alien.png"))
		throw std::logic_error("");
	// set texture to sprite for use
	this->_sprite.setTexture(this->_texture);
	// set the position of alien on the map
	this->_sprite.setPosition(160, 300);
	this->_sprite.setTextureRect(sf::IntRect(0, 0, SPRITE_SIZE, SPRITE_SIZE));
	this->_dir.x = this->_boxRand(this->_rand);
	this->_dir.y = this->_boxRand(this->_rand);
	if (this->_dir.x == 0 && this->_dir.y == 0)
		this->_dir.x = 1;
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
*	brief:	check if the alien kill the player
*	param:	void
*	return:	bool
*/
bool Alien::isGameOver() const
{
	return (this->_gameOver);
}

/*
*   brief:  Manage alien movement
*   param:  Player &, int *
*   return: void
*/
void	Alien::handlerAlien(Player &player, int *collisionMap)
{
	// check collision with map for set direction
	this->checkCollisionMap(collisionMap);
	// check collision with player
	this->checkCollisionPlayer(player);
	// move alien
	this->_sprite.move(this->_dir.x * SPEED_PLAYER, this->_dir.y * SPEED_PLAYER);
	// update sprite of this alien
	this->animSprite();
	this->_sprite.setTextureRect(sf::IntRect(this->_anim.x * SPRITE_SIZE,
								this->_anim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
}

/*
*	brief:	Check map collision and set direction
*	params:	int *
*	return:	void
*/
void	Alien::checkCollisionMap(int *collisionMap)
{
	// recover position of the alien
	int posX = round(this->_sprite.getPosition().x / SPRITE_SIZE);
	int posY = round(this->_sprite.getPosition().y / SPRITE_SIZE);
	// check for right or left direction
	if (this->_dir.x == 1)
	{
		posX = ceil((this->_sprite.getPosition().x + SPEED_PLAYER) / SPRITE_SIZE);
		if (this->_sprite.getPosition().x + SPEED_PLAYER < 1000 - SPRITE_SIZE)
		{
			if (collisionMap[posX + posY * 25])
				this->randDirection();
		}
		else
			this->randDirection();
	}
	else if (this->_dir.x == -1)
	{
		posX = floor((this->_sprite.getPosition().x - SPEED_PLAYER) / SPRITE_SIZE);
		if (this->_sprite.getPosition().x - SPEED_PLAYER > 0)
		{
			if (collisionMap[posX + posY * 25])
				this->randDirection();
		}
		else
			this->randDirection();
	}
	// check for up or down direction
	if (this->_dir.y == 1)
	{
		posY = ceil((this->_sprite.getPosition().y + SPEED_PLAYER) / SPRITE_SIZE);
		if (this->_sprite.getPosition().y + SPEED_PLAYER < 600)
		{
			if (collisionMap[posX + posY * 25])
				this->randDirection();
		}
		else
			this->randDirection();
	}
	else if (this->_dir.y == -1)
	{
		posY = floor((this->_sprite.getPosition().y - SPEED_PLAYER) / SPRITE_SIZE);
		if (this->_sprite.getPosition().y - SPEED_PLAYER > 0)
		{
			if (collisionMap[posX + posY * 25])
				this->randDirection();
		}
		else
			this->randDirection();
	}
	// check if dirX and dirY null
	if (this->_dir.x == 0 && this->_dir.y == 0)
		this->_dir.x = 1;
}

/*
*	brief:	Update animation of Alien
*	params:	void
*	return:	void
*/
void	Alien::animSprite()
{
	// check time passed for change the sprite of player
	if (this->_clockAnim.getElapsedTime().asSeconds() > 0.05f)
	{
		this->_anim.x++;
		if (this->_anim.x > 5)
			this->_anim.x = 0;
		if (this->_dir.x == 1)
			this->_anim.y = 0;
		else
			this->_anim.y = 1;
		this->_clockAnim.restart();
	}	
}

/*
*   brief:  set with random all direction for this alien
*   param:  void
*   return: void
*/
void	Alien::randDirection()
{
	this->_dir.x = this->_boxRand(this->_rand);
	this->_dir.y = this->_boxRand(this->_rand);
}

/*
*   brief: 	check collision with the player
*   param:  Player &
*   return: void
*/
void	Alien::checkCollisionPlayer(Player &character)
{
	// create the hitbox for the alien
	sf::RectangleShape	alien(sf::Vector2f(30, 30));
	alien.setPosition(sf::Vector2f(_sprite.getPosition().x + 5, _sprite.getPosition().y + 5));
	// create the hitbox for the player
	sf::RectangleShape	player(sf::Vector2f(30, 30));
	player.setPosition(sf::Vector2f(character.getSprite().getPosition().x + 5,
						character.getSprite().getPosition().y + 5));
	//set the hitboxes coord
	sf::FloatRect	alienHitBox = alien.getGlobalBounds();
	sf::FloatRect	playerHitBox = player.getGlobalBounds();
	// check if is intersction under both
	if (alienHitBox.intersects(playerHitBox))
		this->_gameOver = true;
}

/*
*   brief:  Draw in the window the alien
*   param:  sf::RenderWindow &
*   return: void
*/
void	Alien::draw(sf::RenderWindow &window)
{
	window.draw(this->_sprite);
}

/*
*   brief:  Destructor
*   param:  void
*   return: void
*/
Alien::~Alien()
{
}