/** 
 * CS2103 Coding Exercise Special Semester 1 (Refactor Version)
 * File:   API.cpp
 * Author: Kenneth Pan (U090283H)
 * Email: u0900283@nus.edu.sg
 * 
 * There are TWELVE files for this REFACTORED project.
 * main.cpp, Mine.h, GameBox.cpp, GameBox.h, GameState.cpp, GameState.h
 * Board.h, Board.cpp, API.h, API.cpp, UI.h, UI.cpp
 */

#include "API.h"

API::API() 
{
     _gameBoard.InitialiseBoard();
     _xSize = _gameBoard.getXSize();
     _ySize = _gameBoard.getYSize();
     _maxLength = _gameBoard.getMaxLength();
     int _gamePlayFlag = 2;
     int _qCounter = 0;
     
     do{
         _gamePlayFlag = _gameBoard.scanBoard();
         
         if(_gamePlayFlag == 2)
         {
            _gameBoard.printBoard();
            _qCounter = 0;
            
            do{
                _keyCmd.userInput();
         
                _click = _keyCmd.getClick();
                _gridRow = _keyCmd.getGridRow();
                _gridColumn = _keyCmd.getGridColumn();
        
                if(_click == 'R' || _click == 'L')
                    {  
                        _qCounter = 1;
                        _gameBoard.assignClick(_click,_gridColumn,_gridRow);
                    }
                
                if(_click == 'Q' && _qCounter == 0)
                {
                    _gameBoard.getStatus()->checkValue(2);
                }
                
            }while(_click != 'Q');
         }
         
     }while(_gameBoard.getStatus()->checkState() == 1);
        
     _gameBoard.printOpenBoard();
}

API::~API() 
{
}
