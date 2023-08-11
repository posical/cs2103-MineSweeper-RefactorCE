/** 
 * CS2103 Coding Exercise Special Semester 1 (Refactor Version)
 * File:   GameState.h
 * 
 * There are TWELVE files for this REFACTORED project.
 * main.cpp, Mine.h, GameBox.cpp, GameBox.h, GameState.cpp, GameState.h
 * Board.h, Board.cpp, API.h, API.cpp, UI.h, UI.cpp
 */

#ifndef GAMESTATE_H
#define	GAMESTATE_H

#define ERR_END "IN PROGRESS"
#define LOSE_GAME "LOST"
#define WIN_GAME "WON"
#include "GameBox.h"
#include <string>

using namespace std;

class GameState: public GameBox {
    protected:
        int _status;
        
        void printMsg(int);
        void printWin();
        void printLose();
        void printInProgress();
        
    public:
        void checkValue(int);
        bool checkState();
        void closeState();
        GameState();
        virtual ~GameState();
};

#endif	/* GAMESTATE_H */
