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
#include <ctime>
#include <cstdlib>
#include "mastermind.hpp"

using namespace std;

int main()
{	
	do { //this do while loop lets the user replay the game indefinitely
		game_message(); //Displays instructions and menu
		srand(time(NULL)); //seeds the random generator
		// initialize the four strings that will store user input
		string first, second, third, fourth; 
		//initialize the four game pieces [of class Pieces] that will be used to store the key
		Pieces piece_one, piece_two, piece_three, piece_four; 
		//for debugging purposes, outputs the secret key
		//get_key(piece_one, piece_two, piece_three, piece_four); 
		//accepts user input and compares to secret key
		user_input(first, second, third, fourth, piece_one, piece_two, piece_three, piece_four); 
	} while(play_again());
}



