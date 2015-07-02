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
***   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU    ***
***   General Public License for more details:                            ***
***    <http://www.gnu.org/licenses/>              						  ***
***                                                                       ***
****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include "mastermind.hpp"

using namespace std;

//******************************** colour pieces class begin

Pieces::Pieces() {
	setColour();
	
}

void Pieces::setColour() {
	//The rand function is seeded in main
	value = rand() % 8;
		switch (value) {
		case 0:
			string_colour = "red";
			break;
		case 1:
			string_colour = "orange";
			break;
		case 2:
			string_colour = "yellow";
			break;
		case 3:
			string_colour = "green";
			break;
		case 4:
			string_colour = "blue";
			break;
		case 5:
			string_colour = "magenta";
			break;
		case 6:
			string_colour = "violet";
			break;
		case 7:
			string_colour = "white";
			break;
	}
}

void Pieces::setColour(Colour given_colour) {
	value = given_colour;
	switch (value) {
		case 0:
			string_colour = "red";
			break;
		case 1:
			string_colour = "orange";
			break;
		case 2:
			string_colour = "yellow";
			break;
		case 3:
			string_colour = "green";
			break;
		case 4:
			string_colour = "blue";
			break;
		case 5:
			string_colour = "magenta";
			break;
		case 6:
			string_colour = "violet";
			break;
		case 7:
			string_colour = "white";
			break;
	}	
}

void Pieces::getColour() {
	cout << string_colour << " ";
}

char Pieces::getColourletter(Pieces piece) {
	return(piece.string_colour[0]);
}

//************************************* colour pieces class end

void game_message() {
	int choice = 0;
	
	cout << "Welcome to MASTERMIND! The code breaking game for two players.";
	
	while (choice != 3) {
		cout << "\nHit 1 for instructions.\nHit 2 to for game info.\nHit 3 to begin. ";
		cin >> choice;
		switch (choice) {
			case 1:
				show_instructions();
				break;
			case 2:
				show_info();
			case 3:
				break; //continue with game
			default:
				cout << "\nYou did not enter a valid choice, please try again.";
		}
	}
}

void show_instructions() {
	cout << "The objective of this game is to figure out the computer's 4 coloured code.\nFirst, select 4 colours:\n\tRed\n\tOrange\n\tYellow"
			"\n\tGreen\n\tBlue\n\tMagenta\n\tViolet\n\tWhite\nNext, use the clues to determine your next guess:\n\tX means right colour right place"
			"\n\tO means right colour wrong place.";
	cout << "\nExample:\n\tCode:\tRed\tYellow\tBlue\tWhite\n\tGuess:\tRed\tGreen\tWhite\tOrange\n\tResult: X O";
}

void show_info() {
	cout << "\nMastermind 1.0 in C++\n\nYAZAN OBEIDI\nAll Rights Reserved 2014, 2015\n";
}

bool play_again() {
	char input;
	bool result=1;
	bool valid = 0;
	do {
		cout << "\nWould you like to play again? (y - yes, n - no); ";
		cin >> input;
		if (input == 'Y' || input == 'y' || input == 'n' || input == 'N') {
			
			if (input == 'Y' || input == 'y') {
				result = 0;
			}
		}
		else {
			cout <<"\nYou did not enter a valid choice, please try again.";
			cout << "End Game";
			valid = 1;
		}
	} while (!result);
	return(!result);
}

void get_key(Pieces &firstp, Pieces &secondp, Pieces &thirdp, Pieces& fourthp) {
	//For debugging purposes.... returns code to console
	firstp.getColour();
	secondp.getColour();
	thirdp.getColour();
	fourthp.getColour(); 
}

void user_input(string first, string second, string third, string fourth, Pieces firstp, Pieces secondp, Pieces thirdp, Pieces fourthp) {
	int counter = 0;
	
	while(counter < 4) {
	
		cout << "\nPlease enter four colours separated by a space: ";
		cin >> first >> second >> third >> fourth;
		
		//FIRST STRING
		if(first[0] == firstp.getColourletter(firstp)) {
			cout << "X";
			counter++;
		}
		else if (first[0] == secondp.getColourletter(secondp) || first[0] == thirdp.getColourletter(thirdp) || first[0] == fourthp.getColourletter(fourthp)) {
			cout << "O";
		}
		//SECOND STRING
			if(second[0] == secondp.getColourletter(secondp)) {
		cout << "X";
			counter++;
		}
		else if (second[0] == firstp.getColourletter(firstp) || second[0] == thirdp.getColourletter(thirdp) || second[0] == fourthp.getColourletter(fourthp)) {
			cout << "O";
		}	
		//THIRD STRING
			if(third[0] == thirdp.getColourletter(thirdp)) {
			cout << "X";
		counter++;
		}
		else if (third[0] == secondp.getColourletter(secondp) || third[0] == firstp.getColourletter(firstp) || third[0] == fourthp.getColourletter(fourthp)) {
			cout << "O";
		}
		//FOURTH STRING
			if(fourth[0] == fourthp.getColourletter(fourthp)) {
			cout << "X";
			counter++;
		}
		else if (fourth[0] == secondp.getColourletter(secondp) || fourth[0] == thirdp.getColourletter(thirdp) || fourth[0] == firstp.getColourletter(firstp)) {
			cout << "O";
		}
	}
		if(counter >= 4)
		{
			cout << " ...\n\nCongratulations! You have cracked the code!!";
		}
}
