#include <string>
#include <iostream>
#include "Gameboard.h"
#pragma once

class Game {
private:
    //each game has its own board object
    Gameboard board;
    bool playerWon = false;;
    bool tie = false;


    //this function is called by play game, and allows the player to make a move
    void PlayerMove();

    //this function is called by play game, and calculates and makes a move for the computer
    void ComputerMove();

    //this function is called by play game, and calculates if the game is over at the end of each move
    bool CheckEndGame();

    //this function displays the current gameboard
    void DisplayBoard();

public:

    /*PlayGame function starts a gameand returns the yes or no in a bool value to show if the game should close
    or if another game can be played */
    bool PlayGame();

};

