#include "Game.h"


/*PlayGame function starts a gameand returns the yes or no in a bool value to show if the game should close
or if another game can be played */
bool Game::PlayGame() { 
    //bool keeps track of turns
    bool playerTurn = false;
    bool endGame = false;
    int playerInput = 0;

    //ask the player if they would like to go first
    std::cout << "Would you like to go first? (1 = Y, 2 = N)" << std::endl;

    //loop until the correct input is collected
    while (playerInput != 1 && playerInput != 2) {
        //ensure the input is valid
        if (!(std::cin >> playerInput)) {
            std::cin.clear();
            std::cin.ignore(123, '\n');
        }

        if (playerInput != 1 && playerInput != 2) {
            std::cout << "Please enter a valid number (1 = Y, 2 = N)" << std::endl;
        }
    }
    //change the starting player to the person
    if (playerInput == 1) {
        playerTurn = true;
    }

    //loop through player and computer turns
    while (endGame == false) {
        //if its the computers turn execute their move, then change turns
        if (playerTurn == false) {
            ComputerMove();
            playerTurn = true;
        }
        //if its the players turn allow them to execute their move, then change turns
        else {
            PlayerMove();
            playerTurn = false;
        }
        //check if the game is over
        endGame = CheckEndGame();
    }

    //clear the terminal
    system("cls");

    //display the winner or if it was a tie
    if (tie == true) {
        std::cout << "The game is a tie!" << std::endl;
    }
    else {
        if (playerWon == true) {
            std::cout << "You Won!!!" << std::endl;
        }
        else {
            std::cout << "You Lost! :(" << std::endl;
        }
    }

    //The finished game is
    DisplayBoard();

    //if the game is over, as the user if they would like to play again
    std::cout << "Would you like to play again? (1 = Y, 2 = N)" << std::endl;

    playerInput = 0;
    //loop until the correct input is collected
    while (playerInput != 1 && playerInput != 2) {
        //ensure the input is valid
        if (!(std::cin >> playerInput)) {
            std::cin.clear();
            std::cin.ignore(123, '\n');
        }
        if (playerInput != 1 && playerInput != 2) {
            std::cout << "Please enter a valid number (1 = Y, 2 = N)" << std::endl;
        }
    }


    //return true if the player would like to play again
    if (playerInput == 1) {
        return true;
    }
    else {
        return false;
    }
}

//this function is called by play game, and allows the player to make a move
void Game::PlayerMove() {
    bool validSpot = false;
    int playerInput;

    //clear the terminal
    system("cls");

    //display the current board
    DisplayBoard();
    
    //ask the user which space they would like to fill
    std::cout << "Please enter a space to fill (spots are 1-9 ascending, a - denotes an empty location)" << std::endl;

    //loop until the correct input is collected
    while (validSpot != true) {
        //ensure the input is valid
        if (!(std::cin >> playerInput)) {
            std::cin.clear();
            std::cin.ignore(123, '\n');
        }
        if (board.getVal(playerInput) == '-') {
            validSpot = true;
            //set that spot to the players character
            board.setVal(playerInput, 'X');
        }
        else {
            std::cout << "Please enter an open spot" << std::endl;
        }
    }
}

//this function is called by play game, and calculates and makes a move for the computer
void Game::ComputerMove() {

    //if no spots are taken, take the middle
    if (board.getVal(1) != '-' && board.getVal(2) != '-' && board.getVal(3) != '-' && board.getVal(4) != '-' &&
        board.getVal(5) != '-' && board.getVal(6) != '-' && board.getVal(7) != '-' && board.getVal(8) != '-' &&
        board.getVal(9) != '-') {

        board.setVal(5, 'O');
    }
    
    //checks priority one locations (check to see if the computer can win with a specific location)


    //check horizontals

        //check top row
    else if (board.getVal(1) == '-' && board.getVal(2) == 'O' && board.getVal(3) == 'O') {
        board.setVal(1, 'O');
    }
    else if (board.getVal(1) == 'O' && board.getVal(2) == '-' && board.getVal(3) == 'O') {
        board.setVal(2, 'O');
    }
    else if (board.getVal(1) == 'O' && board.getVal(2) == 'O' && board.getVal(3) == '-') {
        board.setVal(3, 'O');
    }
        //check middle row
    else if (board.getVal(4) == '-' && board.getVal(5) == 'O' && board.getVal(6) == 'O') {
        board.setVal(4, 'O');
    }
    else if (board.getVal(4) == 'O' && board.getVal(5) == '-' && board.getVal(6) == 'O') {
        board.setVal(5, 'O');
    }
    else if (board.getVal(4) == 'O' && board.getVal(5) == 'O' && board.getVal(6) == '-') {
        board.setVal(6, 'O');
    }
        //check bottom row
    else if (board.getVal(7) == '-' && board.getVal(8) == 'O' && board.getVal(9) == 'O') {
        board.setVal(7, 'O');
    }
    else if (board.getVal(7) == 'O' && board.getVal(8) == '-' && board.getVal(9) == 'O') {
        board.setVal(8, 'O');
    }
    else if (board.getVal(7) == 'O' && board.getVal(8) == 'O' && board.getVal(9) == '-') {
        board.setVal(9, 'O');
    }

    //check verticals

        //column one
    else if (board.getVal(1) == '-' && board.getVal(4) == 'O' && board.getVal(7) == 'O') {
        board.setVal(1, 'O');
    }
    else if (board.getVal(1) == 'O' && board.getVal(4) == '-' && board.getVal(7) == 'O') {
        board.setVal(4, 'O');
    }
    else if (board.getVal(1) == 'O' && board.getVal(4) == 'O' && board.getVal(7) == '-') {
        board.setVal(7, 'O');
    }
        //column two
    else if (board.getVal(2) == '-' && board.getVal(5) == 'O' && board.getVal(8) == 'O') {
        board.setVal(2, 'O');
    }
    else if (board.getVal(2) == 'O' && board.getVal(5) == '-' && board.getVal(8) == 'O') {
        board.setVal(5, 'O');
    }
    else if (board.getVal(2) == 'O' && board.getVal(5) == 'O' && board.getVal(8) == '-') {
        board.setVal(8, 'O');
    }
        //column three
    else if (board.getVal(3) == '-' && board.getVal(6) == 'O' && board.getVal(9) == 'O') {
        board.setVal(3, 'O');
    }
    else if (board.getVal(3) == 'O' && board.getVal(6) == '-' && board.getVal(9) == 'O') {
        board.setVal(6, 'O');
    }
    else if (board.getVal(3) == 'O' && board.getVal(6) == 'O' && board.getVal(9) == '-') {
        board.setVal(9, 'O');
    }
    
    //check diagonals
        //right diagonal
    else if (board.getVal(1) == '-' && board.getVal(5) == 'O' && board.getVal(9) == 'O') {
        board.setVal(1, 'O');
    }
    else if (board.getVal(1) == 'O' && board.getVal(5) == '-' && board.getVal(9) == 'O') {
        board.setVal(5, 'O');
    }
    else if (board.getVal(1) == 'O' && board.getVal(5) == 'O' && board.getVal(9) == '-') {
        board.setVal(9, 'O');
    }
        //left diagonal
    else if (board.getVal(3) == '-' && board.getVal(5) == 'O' && board.getVal(7) == 'O') {
        board.setVal(3, 'O');
    }
    else if (board.getVal(3) == 'O' && board.getVal(5) == '-' && board.getVal(7) == 'O') {
        board.setVal(5, 'O');
    }
    else if (board.getVal(3) == 'O' && board.getVal(5) == 'O' && board.getVal(7) == '-') {
        board.setVal(7, 'O');
    }
    //--------------------------------------------------------------------- end of checking for win locations (priority one)


    //checks priority two locations (checks to see immediate threats)
    else if (board.getVal(1) == '-' && board.getVal(2) == 'X' && board.getVal(3) == 'X') {
        board.setVal(1, 'O');
    }
    else if (board.getVal(1) == 'X' && board.getVal(2) == '-' && board.getVal(3) == 'X') {
        board.setVal(2, 'O');
    }
    else if (board.getVal(1) == 'X' && board.getVal(2) == 'X' && board.getVal(3) == '-') {
        board.setVal(3, 'O');
    }
    //check middle row
    else if (board.getVal(4) == '-' && board.getVal(5) == 'X' && board.getVal(6) == 'X') {
        board.setVal(4, 'O');
    }
    else if (board.getVal(4) == 'X' && board.getVal(5) == '-' && board.getVal(6) == 'X') {
        board.setVal(5, 'O');
    }
    else if (board.getVal(4) == 'X' && board.getVal(5) == 'X' && board.getVal(6) == '-') {
        board.setVal(6, 'O');
    }
    //check bottom row
    else if (board.getVal(7) == '-' && board.getVal(8) == 'X' && board.getVal(9) == 'X') {
        board.setVal(7, 'O');
    }
    else if (board.getVal(7) == 'X' && board.getVal(8) == '-' && board.getVal(9) == 'X') {
        board.setVal(8, 'O');
    }
    else if (board.getVal(7) == 'X' && board.getVal(8) == 'X' && board.getVal(9) == '-') {
        board.setVal(9, 'O');
    }

    //check verticals

        //column one
    else if (board.getVal(1) == '-' && board.getVal(4) == 'X' && board.getVal(7) == 'X') {
        board.setVal(1, 'O');
    }
    else if (board.getVal(1) == 'X' && board.getVal(4) == '-' && board.getVal(7) == 'X') {
        board.setVal(4, 'O');
    }
    else if (board.getVal(1) == 'X' && board.getVal(4) == 'X' && board.getVal(7) == '-') {
        board.setVal(7, 'O');
    }
    //column two
    else if (board.getVal(2) == '-' && board.getVal(5) == 'X' && board.getVal(8) == 'X') {
        board.setVal(2, 'O');
    }
    else if (board.getVal(2) == 'X' && board.getVal(5) == '-' && board.getVal(8) == 'X') {
        board.setVal(5, 'O');
    }
    else if (board.getVal(2) == 'X' && board.getVal(5) == 'X' && board.getVal(8) == '-') {
        board.setVal(8, 'O');
    }
    //column three
    else if (board.getVal(3) == '-' && board.getVal(6) == 'X' && board.getVal(9) == 'X') {
        board.setVal(3, 'O');
    }
    else if (board.getVal(3) == 'X' && board.getVal(6) == '-' && board.getVal(9) == 'X') {
        board.setVal(6, 'O');
    }
    else if (board.getVal(3) == 'X' && board.getVal(6) == 'X' && board.getVal(9) == '-') {
        board.setVal(9, 'O');
    }

    //check diagonals
        //right diagonal
    else if (board.getVal(1) == '-' && board.getVal(5) == 'X' && board.getVal(9) == 'X') {
        board.setVal(1, 'O');
    }
    else if (board.getVal(1) == 'X' && board.getVal(5) == '-' && board.getVal(9) == 'X') {
        board.setVal(5, 'O');
    }
    else if (board.getVal(1) == 'X' && board.getVal(5) == 'X' && board.getVal(9) == '-') {
        board.setVal(9, 'O');
    }
    //left diagonal
    else if (board.getVal(3) == '-' && board.getVal(5) == 'X' && board.getVal(7) == 'X') {
        board.setVal(3, 'O');
    }
    else if (board.getVal(3) == 'X' && board.getVal(5) == '-' && board.getVal(7) == 'X') {
        board.setVal(5, 'O');
    }
    else if (board.getVal(3) == 'X' && board.getVal(5) == 'X' && board.getVal(7) == '-') {
        board.setVal(7, 'O');
    }

    //--------------------------------------------------------------------- end of checking for win locations (priority two)

    //checks priority three locations (middle, corners edge opposite of opponents
    else if (board.getVal(5) == '-') {
        board.setVal(5, 'O');
    }
    //check opposite corners
    else if (board.getVal(1) == 'X' && board.getVal(9) == '-') {
        board.setVal(9, 'O');
    }
    else if (board.getVal(9) == 'X' && board.getVal(1) == '-') {
        board.setVal(1, 'O');
    }
    else if (board.getVal(3) == 'X' && board.getVal(7) == '-') {
        board.setVal(7, 'O');
    }
    else if (board.getVal(7) == 'X' && board.getVal(3) == '-') {
        board.setVal(3, 'O');
    }
    //check opposite edges
    else if (board.getVal(4) == 'X' && board.getVal(6) == '-') {
    board.setVal(6, 'O');
    }
    else if (board.getVal(6) == 'X' && board.getVal(4) == '-') {
    board.setVal(4, 'O');
    }
    else if (board.getVal(2) == 'X' && board.getVal(8) == '-') {
    board.setVal(8, 'O');
    }
    else if (board.getVal(8) == 'X' && board.getVal(2) == '-') {
    board.setVal(2, 'O');
    }

    //check if the middle is taken, choose the smallest available integer
    else if (board.getVal(5) == '-') {
        board.setVal(5, 'O');
    }
    else {
        bool spotFilled = false;
        int iterator = 0;
        while (spotFilled == false) {
            if (board.getVal(iterator) == '-') {
                board.setVal(iterator, 'O');
                spotFilled = true;
            }
        }
    }
}

//this function is called by play game, and calculates if the game is over at the end of each move
bool Game::CheckEndGame() {
    //if all spots are filled return true
    if (board.getVal(1) != '-' && board.getVal(2) != '-' && board.getVal(3) != '-' && board.getVal(4) != '-' &&
        board.getVal(5) != '-' && board.getVal(6) != '-' && board.getVal(7) != '-' && board.getVal(8) != '-' &&
        board.getVal(9) != '-') {

        //declare a tie
        tie = true;
        return true;

    }
    //if one player has three in a row return true
    
    //check horizontals
    else if (board.getVal(1) == board.getVal(2) && board.getVal(1) == board.getVal(3) && board.getVal(1) != '-') {
        //check if player or computer won
        if (board.getVal(1) == 'X') {
            playerWon = true;
        }
        else {
            playerWon = false;
        }
        return true;
    }
    else if (board.getVal(4) == board.getVal(5) && board.getVal(4) == board.getVal(6) && board.getVal(4) != '-') {
        //check if player or computer won
        if (board.getVal(4) == 'X') {
            playerWon = true;
        }
        else {
            playerWon = false;
        }
        return true;
    }
    else if (board.getVal(7) == board.getVal(8) && board.getVal(7) == board.getVal(9) && board.getVal(7) != '-') {
        //check if player or computer won
        if (board.getVal(7) == 'X') {
            playerWon = true;
        }
        else {
            playerWon = false;
        }
        return true;
    }

    //check verticals
    else if (board.getVal(1) == board.getVal(4) && board.getVal(1) == board.getVal(7) && board.getVal(1) != '-') {
        //check if player or computer won
        if (board.getVal(1) == 'X') {
            playerWon = true;
        }
        else {
            playerWon = false;
        }
        return true;
    }
    else if (board.getVal(2) == board.getVal(5) && board.getVal(2) == board.getVal(8) && board.getVal(2) != '-') {
        //check if player or computer won
        if (board.getVal(2) == 'X') {
            playerWon = true;
        }
        else {
            playerWon = false;
        }
        return true;
    }
    else if (board.getVal(3) == board.getVal(6) && board.getVal(3) == board.getVal(9) && board.getVal(3) != '-') {
        //check if player or computer won
        if (board.getVal(3) == 'X') {
            playerWon = true;
        }
        else {
            playerWon = false;
        }
        return true;
    }

    //check diagonals
    else if (board.getVal(1) == board.getVal(5) && board.getVal(1) == board.getVal(9) && board.getVal(1) != '-') {
        //check if player or computer won
        if (board.getVal(1) == 'X') {
            playerWon = true;
        }
        else {
            playerWon = false;
        }
        return true;
    }
    else if (board.getVal(3) == board.getVal(5) && board.getVal(3) == board.getVal(7) && board.getVal(3) != '-') {
        //check if player or computer won
        if (board.getVal(3) == 'X') {
            playerWon = true;
        }
        else {
            playerWon = false;
        }
        return true;
    }
    else {
        //otherwise return false keep playing
        return false;
    }

}

void Game::DisplayBoard() {
    std::cout << board.getVal(1) << board.getVal(2) << board.getVal(3) << std::endl;
    std::cout << board.getVal(4) << board.getVal(5) << board.getVal(6) << std::endl;
    std::cout << board.getVal(7) << board.getVal(8) << board.getVal(9) << std::endl << std::endl;
}

