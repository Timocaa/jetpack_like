#ifndef INPUT_HPP
# define INPUT_HPP

#include "prog.hpp"

struct t_button
{ bool  left, right, up, down,
        attack, escape; };

class Input
{
    public:
        Input();

        t_button    getbutton() const;
        void        inputHandler(sf::Event event, sf::RenderWindow &window);
        void        chckBtn(sf::RenderWindow &window, int *posX, int *posY, sf::Vector2i &anim);
        ~Input();
    private:
        t_button    _button;
};

#endif