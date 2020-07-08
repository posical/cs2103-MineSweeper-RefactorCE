/** 
 * CS2103 Coding Exercise Special Semester 1 (Refactor Version)
 * File:   API.h
 * Author: Kenneth Pan (U090283H)
 * Email: u0900283@nus.edu.sg
 * 
 * There are TWELVE files for this REFACTORED project.
 * main.cpp, Mine.h, GameBox.cpp, GameBox.h, GameState.cpp, GameState.h
 * Board.h, Board.cpp, API.h, API.cpp, UI.h, UI.cpp
 */

#ifndef API_H
#define	API_H
#define FILENAME "in.txt"
#include "Board.h"
#include "GameState.h"
#include "GameBox.h"
#include "UI.h"

class API: public Board {
    private:
        Board _gameBoard;
        UI _keyCmd;
        
        protected:
        char _click;
        int _gridRow;
        int _gridColumn;
    
    public:
        API();
        virtual ~API();
};

#endif	/* API_H */
