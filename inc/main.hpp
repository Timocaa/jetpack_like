#ifndef MAIN_HPP
# define MAIN_HPP

// includes
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "../inc/Input.hpp"

//defines
#define WIN_WIDHT   800
#define WIN_HEIGHT  600
#define STEP        2

// prototypes
bool    loadFont();
void    initText(std::string const str);
void    chckBtn();
#endif