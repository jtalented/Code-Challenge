#include <iostream>
#include "Game.h"

int main() {
	//userIn tracks the user's input as an integer, both for menu selection, as well as board selection
	int userIn;
	//boolean tracks when the game is over
	bool quit = false;
	bool repeat = false;

	//welcome the user
	std::cout << "Hello and welcome to Tic-Tac-Toe!" << std::endl << "Be the first one to get three in a Row!" << std::endl << std::endl;

	//overarching loop that can either repeat or end the games
	while (quit == false) {
		userIn = 0;
		//creates a new game object
		Game newGame;

		if (repeat == false) {
			//display the menu as well as the options
			std::cout << "Main Menu:" << std::endl;
			std::cout << "Press 1 to Begin Playing!" << std::endl;
			std::cout << "Press 2 to Quit" << std::endl;

			//collect the users input
			if (!(std::cin >> userIn)) {
				std::cin.clear();
				std::cin.ignore(123, '\n');
			}

			//switch statement chooses the correct option
			switch (userIn) {
			case 1: repeat = newGame.PlayGame(); break;
				//close the game
			case 2: quit = true; break;
			default: std::cout << "Please enter a valid input" << std::endl << std::endl << std::endl; break;
			}
			//clear the terminal
			system("cls");
		}
		else {
			repeat = newGame.PlayGame();
			//clear the terminal
			system("cls");
		}

	 }

	//thank the user for playing
	std::cout << "Thanks for Playing!";

}
