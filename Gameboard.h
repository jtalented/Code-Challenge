#include <string>
#pragma once




//Gameboard Class stores all the gameboard spots with their associated values, X,O or Empty (-)
class Gameboard {
private:
    //that hold the value of each spot
    char spotOne;
    char spotTwo;
    char spotThree;
    char spotFour;
    char spotFive;
    char spotSix;
    char spotSeven;
    char spotEight;
    char spotNine;
public:
    Gameboard() {
        //initialize all values to be empty
        spotOne = '-';
        spotTwo = '-';
        spotThree = '-';
        spotFour = '-';
        spotFive = '-';
        spotSix = '-';
        spotSeven = '-';
        spotEight = '-';
        spotNine = '-';
    }
    
    //the setVal function passes and assigns a value to the provided location
    void setVal(int location, char newVal) {

        //select case assigns the associated spot with the passed in value
        switch (location) {
        case 1: spotOne = newVal; break;
        case 2: spotTwo = newVal; break;
        case 3: spotThree = newVal; break;
        case 4: spotFour = newVal; break;
        case 5: spotFive = newVal; break;
        case 6: spotSix = newVal; break;
        case 7: spotSeven = newVal; break;
        case 8: spotEight = newVal; break;
        default: spotNine = newVal; break;
        }
    }

        //the getVal function returns the value at the passed in board location
    char getVal(int location) {

        //select case returns the value associated with the passed in location
        switch (location) {
        case 1: return spotOne; break;
        case 2: return spotTwo; break;
        case 3: return spotThree; break;
        case 4: return spotFour; break;
        case 5: return spotFive; break;
        case 6: return spotSix; break;
        case 7: return spotSeven; break;
        case 8: return spotEight; break;
        default: return spotNine; break;
        }
    }
};
