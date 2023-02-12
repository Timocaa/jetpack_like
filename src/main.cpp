#include "../inc/main.hpp"

//global variable
sf::Font            font;
sf::Text            txt;
sf::RenderWindow    window;
Input               input;
int                 posX = 20;

int main()
{
    // window option
    sf::ContextSettings option;
    option.antialiasingLevel = 8;
    // window creation 
    window.create(sf::VideoMode(WIN_WIDHT, WIN_HEIGHT, 32), "... New Game ...", sf::Style::Default, option);
    // vsync activation
    window.setVerticalSyncEnabled(true);
    // loading font
    if (!loadFont())
        return (0);
    // text initialisation
    initText("Hello World...!");

    //create circle
    sf::CircleShape circle(75);
    circle.setFillColor(sf::Color(109, 158, 235));
    circle.setOutlineColor(sf::Color::Green);
    circle.setOutlineThickness(5);
    // create triangle
    sf::CircleShape triangle(42, 3);
    triangle.setFillColor(sf::Color::Blue);
    // create free form
    sf::ConvexShape form;
    form.setPointCount(5);
    form.setPoint(0, sf::Vector2f(0.f, 0.f));
    form.setPoint(1, sf::Vector2f(150.f, 10.f));
    form.setPoint(2, sf::Vector2f(120.f, 90.f));
    form.setPoint(3, sf::Vector2f(30.f, 100.f));
    form.setPoint(4, sf::Vector2f(0.f, 50.f));
    form.setFillColor(sf::Color(10, 200, 120));

    // stop if window is closed
    while (window.isOpen())
    {
        sf::Event   event;
        while (window.pollEvent(event))
        {
            // management inputs and event
            input.inputHandler(event, window);
            chckBtn();
            circle.setPosition(posX, 200);

        }

        // set background window in black 
        window.clear(sf::Color::Black);

        // here all modifications for the window
        window.draw(txt);
        window.draw(circle);
        window.draw(triangle);

        // display all modifications in the window
        window.display();
    }
    
    // end of programm
    return 0;
}

// check if font is propely established
bool    loadFont()
{
    if (!font.loadFromFile("res/Anglican.ttf")) //set the path of font depending launch
    {
        std::cerr << "Error loading font..." << std::endl;
        return (false);
    }
    return (true);
}

//set text option
void    initText(std::string  const str)
{
    // set the font for text
    txt.setFont(font);
    // set characters in text
    txt.setString(str);
    // set height of font
    txt.setCharacterSize(42);
    // set color of text
    txt.setFillColor(sf::Color::Cyan);
    // set style of text
    txt.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void chckBtn()
{
    if (input.getbutton().left == true)
    {
        initText("Left");
        posX -= 10;
        if (posX < 20)
            posX = 20;
        initText(std::to_string(posX));
    }
    if (input.getbutton().right == true)
    {
        initText("Right");
        posX += 10;
        if (posX > 600)
            posX = 600;
        initText(std::to_string(posX));
    }
    if (input.getbutton().up == true)
        initText("Up");
    if (input.getbutton().down == true)
        initText("Down");
    if (input.getbutton().escape == true)
        initText("Esc");
    if (input.getbutton().attack == true)
        initText("Attack");
}