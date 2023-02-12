#ifndef INPUT_HPP
# define INPUT_HPP

#include <SFML/Graphics.hpp>

struct t_button
{ bool    left, right, up, down, attack, escape; };

class Input
{
    public:
        Input();

        t_button    getbutton() const;
        void        inputHandler(sf::Event event, sf::RenderWindow &window);

    private:
        t_button    _button;
};

#endif