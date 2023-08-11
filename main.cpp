/** 
 * CS2103 Coding Exercise Special Semester 1 (Refactor Version)
 * File:   main.cpp
 * 
 * There are TWELVE files for this REFACTORED project.
 * main.cpp, Mine.h, GameBox.cpp, GameBox.h, GameState.cpp, GameState.h
 * Board.h, Board.cpp, API.h, API.cpp, UI.h, UI.cpp
 */

/** in.txt has to be in the same folder as the main.cpp for it to work*/

/**
 * main holds API
 * API holds Board and UI
 * Board holds GameState and GameBox
 *  
 * 1) main() will start by creating API class.
 * 2) API class will initialise create Board class and initialise the readFile
 * 3) After API has initialised the board, it calls up UI class for user inputs
 * 4) UI process some basic algorithm before returning the result to API
 * 5) API controls and continue the flow of the game.
 * 6) API passes the computational buik to Board class to process.
 * 
 */

#include "Mine.h"

int main() 
{                  
    API _gameStart;
    
    return 0;
}

