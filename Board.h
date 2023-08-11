/** 
 * CS2103 Coding Exercise Special Semester 1 (Refactor Version)
 * File:   Board.h
 * 
 * There are TWELVE files for this REFACTORED project.
 * main.cpp, Mine.h, GameBox.cpp, GameBox.h, GameState.cpp, GameState.h
 * Board.h, Board.cpp, API.h, API.cpp, UI.h, UI.cpp
 */

#ifndef BOARD_H
#define	BOARD_H
#define FILENAME "in.txt"
#include <fstream>
#include <string>
#include <iostream>
#include "GameBox.h"
#include "GameState.h"

using namespace std;

class Board {
    private:
        int _openMine;
        int _closeMine;
        int _maxMine;
        int _decision;
        int _openedNumbers;
        int _totalNumbers;
    
    protected:
        GameBox *_tempHolder;
        GameBox *_boxArray;
        GameState *_gameStatus;
        int _xSize;
        int _ySize;
        int _maxLength;
        char _click;
        
        
    public:
        Board();
        virtual ~Board();

        void InitialiseBoard();
        int getXSize();
        int getYSize();
        int getMaxLength();
        GameState* getStatus();
        int scanBoard();
        void printBoard();
        void printOpenBoard();
        void assignClick(char,int,int);
        
        void checkAdj(int);
        void checkLeft(int);
        void checkRight(int);
        void checkTop(int);
        void checkBtm(int);
        void checkBtmLeft(int);
        void checkBtmRight(int);
        void checkTopLeft(int);
        void checkTopRight(int);
        
        void openClick(int);
        void markClick(int);
};

#endif	/* BOARD_H */
