/* ************************************************************************** */
/*                                                                            */
/*                                         LLr::,::, ,:L    ,     :i;     .   */
/*   Info.hpp                              ,,.:::,   L;i   ::,    Y:; .:Li.   */
/*                                            i:;   :i:r   i::   ,i::i;,      */
/*   By:  Timoca                             ;ri,   UiiL  ;;:i   Yi::::       */
/*                                          .krj   UYLrY.,L;:r  lU7JYriYi,    */
/*   Created: 2023/03/26 17:19:32           qKKL  :Dd.;YlcLLlJ, iRk.  UYTK    */
/*   Updated: 2023/03/26 17:19:41           .UM.  RDD :DRi LU   DDK    ;cK    */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_HPP
# define INFO_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <string>
#include "Player.hpp"

class Info
{
    public:
        //---- canonical form ----//
        Info();
        ~Info();

        //---- member methods ----//
        void    update(Player &player);
        void    draw(sf::RenderWindow &window);

    private:
        //---- member objects ----//
		sf::Font			_font;
		sf::Text			_gaz;
		sf::Text			_gazValue;

        //---- private methods ----//
            //---- canonical form
        Info(Info const &rhs);
        Info    &operator=(Info const &rhs);
            //---- methods
        void    initText(sf::Text &txt, std::string const &str);
};

#endif
