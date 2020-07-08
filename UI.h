/** 
 * CS2103 Coding Exercise Special Semester 1 (Refactor Version)
 * File:   UI.h
 * Author: Kenneth Pan (U090283H)
 * Email: u0900283@nus.edu.sg
 * 
 * There are TWELVE files for this REFACTORED project.
 * main.cpp, Mine.h, GameBox.cpp, GameBox.h, GameState.cpp, GameState.h
 * Board.h, Board.cpp, API.h, API.cpp, UI.h, UI.cpp
 */

#ifndef UI_H
#define	UI_H
#include <iostream>

using namespace std;

class UI{
    private:
        char _click;
        int _gridRow;
        int _gridColumn;
        
    public:
        UI();
        virtual ~UI();
    
        void userInput();
        int getGridRow();
        int getGridColumn();
        char getClick();
};

#endif	/* UI_H */
