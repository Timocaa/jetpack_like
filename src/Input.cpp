#include "../inc/Input.hpp"

// default constructor
Input::Input()
{
    _button.up = false;
    _button.right = false;
    _button.left = false;
    _button.down = false;
    
    _button.escape = false;
    
    _button.attack = false;
}

// getter struct button
t_button  Input::getbutton() const { return (_button); };

// management input events
void    Input::inputHandler(sf::Event event, sf::RenderWindow &window)
{
    //close window by cross
    if (event.type == sf::Event::Closed)
        window.close();
    //keybord event
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
            case sf::Keyboard::Escape: _button.escape = true; window.close(); break;
            case sf::Keyboard::A: _button.left = true; break;
            case sf::Keyboard::D: _button.right = true; break;
            case sf::Keyboard::W: _button.up = true; break;
            case sf::Keyboard::S: _button.down = true; break;
            default: break;
        }
    }
    if (event.type == sf::Event::KeyReleased)
    {
        switch (event.key.code)
        {
            case sf::Keyboard::Escape: _button.escape = false; break;
            case sf::Keyboard::A: _button.left = false; break;
            case sf::Keyboard::D: _button.right = false; break;
            case sf::Keyboard::W: _button.up = false; break;
            case sf::Keyboard::S: _button.down = false; break;
            default: break;
        }
    }
    // mouse event
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
            _button.attack = true;
    }
    if (event.type == sf::Event::MouseButtonReleased)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
            _button.attack = false;
    }
}

void Input::chckBtn(sf::RenderWindow &window, int *posX, int *posY)
{
    if (getbutton().left == true)
    {
        *posX -= STEP;
        if (*posX < 5)
            *posX = 5;
    }
    if (getbutton().right == true)
    {
        *posX += STEP;
        if (*posX > WIN_WIDHT - 105)
            *posX = WIN_WIDHT - 105;
    }
    if (getbutton().up == true)
    {
        *posY -= STEP;
        if (*posY <= 5)
            *posY = 5;
    }
    if (getbutton().down == true)
    {
        *posY += STEP;
        if (*posY > WIN_HEIGHT - 105)
            *posY = WIN_HEIGHT - 105;
    }
    if (getbutton().attack == true)
    {
        // record mouse coord and set pos of circle
        sf::Vector2i    mousePos;
        mousePos = sf::Mouse::getPosition(window);
        std::cout << "mouse.x = " << mousePos.x << "\n" << "mouse Y = " << mousePos.y << "\n\n";
        *posX = mousePos.x - 16;
        *posY = mousePos.y - 16;
        std::cout << "attack Button" << std::endl;
    }
}

Input::~Input() {};