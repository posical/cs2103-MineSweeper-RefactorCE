/** 
 * CS2103 Coding Exercise Special Semester 1 (Refactor Version)
 * File:   GameState.cpp
 * 
 * There are TWELVE files for this REFACTORED project.
 * main.cpp, Mine.h, GameBox.cpp, GameBox.h, GameState.cpp, GameState.h
 * Board.h, Board.cpp, API.h, API.cpp, UI.h, UI.cpp
 */

#include "GameBox.h"
#include "GameState.h"
#include <iostream>

using namespace std;

GameState::GameState() 
{
    _isOpened = 1;
    _status = 2;
}

GameState::~GameState() 
{
}

bool GameState::checkState()
{
    return getStatus();
}

void GameState::printMsg(int check)
{
    switch(check)
    {
        case 0:
            printWin();
            break;
            
        case 1:
            printLose();
            break;
        
        case 2:
            printInProgress();
            break;
        
        default:
            break;
    }
}

void GameState::printWin()
{
    cout << WIN_GAME << endl;
}

void GameState::printLose()
{
    cout << LOSE_GAME << endl;
}

void GameState::printInProgress()
{
    cout << ERR_END << endl;
}

void GameState::checkValue(int msg)
{
    printMsg(msg);
}

void GameState::closeState()
{
    _isOpened = 0;
}
