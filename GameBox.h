/** 
 * CS2103 Coding Exercise Special Semester 1 (Refactor Version)
 * File:   GameBox.h
 *
 * There are TWELVE files for this REFACTORED project.
 * main.cpp, Mine.h, GameBox.cpp, GameBox.h, GameState.cpp, GameState.h
 * Board.h, Board.cpp, API.h, API.cpp, UI.h, UI.cpp
 */

#ifndef GAMEBOX_H
#define	GAMEBOX_H

#include <string>

using namespace std;

class GameBox {    
    protected:
        string _characterMap;
        bool _isOpened;  
        char _openedBox;
        char _closedBox;
        int _closedBoxIndex;
        
        int checkBox(char);
        void writeOpenedBox(char);
        bool getStatus();
        int checkRightClick();
        void resetBox();
        
    public:                      
        GameBox();
        virtual ~GameBox();
        
        char readOpenBox();
        char readBox();
        void openBox();
        void forceOpenBox();
        void writeClosedBox();
        void setupBox(char);
};
#endif	/* GAMEBOX_H */
