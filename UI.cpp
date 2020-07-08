/** 
 * CS2103 Coding Exercise Special Semester 1 (Refactor Version)
 * File:   UI.cpp
 * Author: Kenneth Pan (U090283H)
 * Email: u0900283@nus.edu.sg
 * 
 * There are TWELVE files for this REFACTORED project.
 * main.cpp, Mine.h, GameBox.cpp, GameBox.h, GameState.cpp, GameState.h
 * Board.h, Board.cpp, API.h, API.cpp, UI.h, UI.cpp
 */

#include "UI.h"

UI::UI() 
{
    _click = 0;
    _gridRow = 0 ;
    _gridColumn = 0;
}

UI::~UI() 
{
}

int UI::getGridColumn()
{
    return _gridColumn;
}

int UI::getGridRow()
{
    return _gridRow;
}

char UI::getClick()
{
    return _click;
}

void UI::userInput()
{
    int _flag = -1;
    _click = 0;
    _gridRow = 0;
    _gridColumn = 0;
    
    cin >> _click;
    switch(_click)
    {
        case 'q':
        case 'Q':
            _flag = 0;
            break;
        case 'r':
        case 'R':
            _flag = 1;
            break;
        case 'l':
        case 'L':
            _flag = 2;
            break;
                    
        default:
            break;
    }

    if(_flag == 1 || _flag == 2)
    {
        cin >> _gridColumn >> _gridRow;
    }
    
    switch(_click)
        {
            case 'q':
                _click = 'Q';
                break;
            case 'r':
                _click = 'R';
                break;
            case 'l':
                _click = 'L';
                break;
                    
            default:
                break;
        }    
}
