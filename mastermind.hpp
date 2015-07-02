/****************************************************************************
*****************************************************************************
**********                                                         **********
**********                Mastermind in C++ 1.0.0                  **********
**********                                                         **********
**********                      Coded By                           **********
**********                                                         **********
**********                    YAZAN OBEIDI                         **********
**********                                                         **********
**********      This game is based off the board game called       **********
**********                                                         **********
**********                     MASTERMIND                          **********
**********                                                         ********** 
*****************************************************************************
*****************************************************************************
*****************************************************************************
***                                                                       ***
***   Copyright 2014, 2015 Yazan Obeidi                                   ***
***                                                                       ***
***   This is free software: you can redistribute it and/or modify        ***
***   it under the terms of the GNU General Public License as published   ***
***   by the Free Software Foundation, either version 3 of the License,   ***
***   or (at your option) any later version.                              ***
***                                                                       ***
***   This program is distributed in the hope that it will be useful,     ***
***   but WITHOUT ANY WARRANTY; without even the implied warranty of      ***
***   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the       ***
***   GNU General Public License for more details:                        ***
***    <http://www.gnu.org/licenses/>              						  ***
***                                                                       ***
****************************************************************************/

#include <iostream>
#include <string>
#include <ctime>

#ifndef MASTERMIND_HEADER_HPP
#define MASTERMIND_HEADER_HPP

enum Colour {red, orange, yellow, green, blue, magenta, violet, white};

class Pieces {
	public:
		Pieces(); //constructor that defines the colour randomly.
		void getColour();
		void setColour();
		void setColour(Colour given_colour);
		std::string string_colour;
		char getColourletter(Pieces piece);
	private: 
		int value;
};

//displays game message
void game_message();
//displays instructions
void show_instructions();
//shows additional game info
void show_info();
//allows user to play again
bool play_again();
//outputs the secret key
void get_key(Pieces &firstp, Pieces &secondp, Pieces &thirdp, Pieces& fourthp);
//consumes and checks input - also includes counters to indicate when user has won
void user_input(std::string first, std::string second, std::string third, std::string fourth, Pieces firstp, Pieces secondp, Pieces thirdp, Pieces fourthp);


#endif 
