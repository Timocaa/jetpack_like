#include "../inc/Input.hpp"

// default constructor
Input::Input()
{
    _button.up = false;
    _button.right = false;
    _button.left = false;
    _button.escape = false;
    _button.down = false;
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