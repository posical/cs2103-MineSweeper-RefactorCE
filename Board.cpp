/** 
 * CS2103 Coding Exercise Special Semester 1 (Refactor Version)
 * File:   Board.cpp
 * Author: Kenneth Pan (U090283H)
 * Email: u0900283@nus.edu.sg
 * 
 * There are TWELVE files for this REFACTORED project.
 * main.cpp, Mine.h, GameBox.cpp, GameBox.h, GameState.cpp, GameState.h
 * Board.h, Board.cpp, API.h, API.cpp, UI.h, UI.cpp
 */

#include "Board.h"

Board::Board() 
{    
    _openMine = 0;
    _closeMine = 0;
    _maxMine = -1;
    _decision = -1;
    _openedNumbers = 0;
    _totalNumbers = -1;
}
Board::~Board() 
{
}

void Board::InitialiseBoard() 
{
    char _tempChar;
    
    ifstream readFile(FILENAME);
    readFile >> _xSize;
    readFile >> _ySize;
    _maxLength = _xSize*_ySize;
    _boxArray = new GameBox[_maxLength];
    
    for(int j=_maxLength-1;j>=0;j--)
        {
             readFile >> _tempChar;
             _tempHolder = 0;
             _tempHolder = new GameBox();
             _tempHolder->setupBox(_tempChar);
             _boxArray[j]=*_tempHolder;
        }
        
    readFile.close();
    
    for(int a=_maxLength-1;a>=0;a--)
    {
        if(_boxArray[a].readOpenBox()=='*')
        {
            _closeMine++;
        }
    }
    _maxMine = _closeMine;
    _totalNumbers = _maxLength - _maxMine;
    
    _gameStatus = new GameState();
}

void Board::markClick(int index)
{
    _boxArray[index].writeClosedBox();
}

void Board::openClick(int index)
{
    _boxArray[index].openBox();
}

int Board::getXSize()
{
    return _xSize;
}

int Board::getYSize()
{
    return _ySize;
}

int Board::getMaxLength()
{
    return _maxLength;
}

GameState* Board::getStatus()
{
    return _gameStatus;
}

int Board::scanBoard()
{
    _decision = 2;
    _openedNumbers =0;
    
        for(int z=0;z<_maxLength;z++)
    {
        if(_boxArray[z].readBox()=='*')
        {
            _openMine++;
            _closeMine--;
        }
        
        if(_boxArray[z].readBox()> 47 && _boxArray[z].readBox()<57)
        {
            _openedNumbers++;
        }
    }
        
        if(_openMine>0)
    {
        getStatus()->closeState();
        _decision = 1;
    }
        
        if(_closeMine==_maxMine && _openedNumbers==_totalNumbers)
    {
        getStatus()->closeState();
        _decision = 0;
    }
        
    return _decision;
}

void Board::printBoard()
{
   	int printFlag=0;
	for(int j=_maxLength-1;j>=0;j--)
	{
		cout << _boxArray[j].readBox() << " ";
	
		if(!((j)%(_xSize)) && printFlag!=0)
              	 {
               		cout << endl;
               	}
               printFlag++;
	} 
}

void Board::printOpenBoard()
{   
    for(int m=0;m<_maxLength;m++)
        {
            _boxArray[m].forceOpenBox();
        }
    
    switch(_decision)
    {
        case 0:
            _gameStatus->checkValue(0);
            break;
        case 1:
            _gameStatus->checkValue(1);            
            break;
        default:
            break;
    }
    
    printBoard();
}

void Board::assignClick(char _mouse, int _col , int _row)
{
    int index;
    if (_col == 0 || _row == 0)
    {
    }
    else
    {
        index = (_xSize-_col)+(_xSize*(_row-1));
        
        switch(_mouse)
        {
            case 'L':
                checkAdj(index);
                break;
            case 'R':
                markClick(index);
                break;
            default:
                break;
        }
    }
}

void Board::checkAdj(int index)
{
     if(_boxArray[index].readBox()=='/')
        {
        }
    else
        { 
            openClick(index);
            if(_boxArray[index].readOpenBox()=='0')
            {
                checkLeft(index);
                checkRight(index);
                checkTop(index);
                checkBtm(index);
                checkBtmLeft(index);
                checkBtmRight(index);
                checkTopLeft(index);
                checkTopRight(index);
            }
        }
}

void Board::checkLeft(int index)
{
    int left;
    left = index + 1;

    if((!(left%_xSize==0)) && _boxArray[left].readOpenBox()!='*' && _boxArray[index].readOpenBox()=='0')
    {
        _boxArray[left].openBox();
        checkLeft(left);
        checkTop(left);
        checkBtm(left);
        checkTopLeft(left);
        checkBtmLeft(left);
    }
}

void Board::checkRight(int index)
{
    int right;
    right = index - 1;
    
    if((!(right%_xSize==0)) && _boxArray[right].readOpenBox()!='*' && _boxArray[index].readOpenBox()=='0')
    {
        _boxArray[right].openBox();
        checkRight(right);
        checkTop(right);
        checkBtm(right);
        checkTopRight(right);
        checkBtmRight(right);
    }   
}

void Board::checkTop(int index)
{
        int top;
    top = index + _xSize;
    
    if(top<_maxLength && _boxArray[top].readOpenBox()!='*' && _boxArray[index].readOpenBox()=='0')
    {
        _boxArray[top].openBox();
        checkTop(top);
        checkLeft(top);
        checkRight(top);
        checkTopLeft(top);
        checkTopRight(top);
    }
}

void Board::checkBtm(int index)
{
    int btm;
    btm = index - _xSize;
    
    if(btm>=0 && _boxArray[btm].readOpenBox()!='*' && _boxArray[index].readOpenBox()=='0')
    {
        _boxArray[btm].openBox();
        checkBtm(btm);
        checkLeft(btm);
        checkRight(btm);
        checkBtmLeft(btm);
        checkBtmRight(btm);
    }
}

void Board::checkBtmLeft(int index)
{
    int btmleft;
    btmleft = index - _xSize + 1;
    
    if((btmleft>=0 && !(btmleft%_xSize==0)) && _boxArray[btmleft].readOpenBox()!='*' && _boxArray[index].readOpenBox()=='0')
    {
        _boxArray[btmleft].openBox();
        checkBtmLeft(btmleft);
    }
}

void Board::checkBtmRight(int index)
{
    int btmright;
    btmright = index - _xSize - 1;
    
    if((btmright>=0 && !(btmright%_xSize==0)) && _boxArray[btmright].readOpenBox()!='*' && _boxArray[index].readOpenBox()=='0')
    {
        _boxArray[btmright].openBox();
        checkBtmRight(btmright);
    }
}

void Board::checkTopLeft(int index)
{
    int topleft;
    topleft = index + _xSize +1;
    
    if((topleft<_maxLength && !(topleft%_xSize==0)) && _boxArray[topleft].readOpenBox()!='*' && _boxArray[index].readOpenBox()=='0')
    {
        _boxArray[topleft].openBox();
        checkTopLeft(topleft);
    }  
}

void Board::checkTopRight(int index)
{
    int topright;
    topright = index + _xSize - 1;
    
    if((topright<_maxLength && !(topright%_xSize==0)) && _boxArray[topright].readOpenBox()!='*' && _boxArray[index].readOpenBox()=='0')
    {
        _boxArray[topright].openBox();
        checkTopRight(topright);
    }
}
