/** 
 * CS2103 Coding Exercise Special Semester 1 (Refactor Version)
 * File:   GameBox.cpp
 * 
 * There are TWELVE files for this REFACTORED project.
 * main.cpp, Mine.h, GameBox.cpp, GameBox.h, GameState.cpp, GameState.h
 * Board.h, Board.cpp, API.h, API.cpp, UI.h, UI.cpp
 */

#include "GameBox.h"

int GameBox::checkBox(char c)
{
    int i;
    for (i = 0;i<11;i++)
    {
        if(c==_characterMap[i])
        {
            break;
        }
    }
    
    return i;
}


void GameBox::writeOpenedBox(char c)
{
 _openedBox = _characterMap[checkBox(c)];   
}

GameBox::GameBox() 
{
    _characterMap = "012345678*-/?";
    _closedBoxIndex = 10;
    _isOpened = 0;
    _closedBox = _characterMap[_closedBoxIndex];
}

void GameBox::setupBox(char c)
{
    writeOpenedBox(c);
}

GameBox::~GameBox() 
{
}

bool GameBox::getStatus()
{
   return _isOpened;
}

char GameBox::readOpenBox()
{
     return _openedBox;
}

char GameBox::readBox()
{
    if(getStatus() == 1)
    {
        return _openedBox;
    }
    if(getStatus() == 0)
    {
        return _closedBox;
    }
}

void GameBox::forceOpenBox()
{
    _isOpened = 1;
}

void GameBox::openBox()
{
    if(_closedBox == '/')
    {
       _isOpened = 0;
    }
    else
    {
        _isOpened = 1;
    }
}

void GameBox::resetBox()
{
    _isOpened = 0;
}

int GameBox::checkRightClick()
{
    if(_closedBoxIndex == 12)
    {
        _closedBoxIndex = 10;
    }
    
    else 
    {
        _closedBoxIndex++;
    }
    return _closedBoxIndex;
}

void GameBox::writeClosedBox()
{
 _closedBox = _characterMap[checkRightClick()];   
}
