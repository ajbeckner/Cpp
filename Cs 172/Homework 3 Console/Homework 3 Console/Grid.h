//
//  Grid.h
//  Homework 3 Console
//
//  Created by Anthony John Beckner on 8/7/15.
//  Copyright (c) 2015 ajbecknerapps. All rights reserved.
//

#ifndef __Homework_3_Console__Grid__
#define __Homework_3_Console__Grid__

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace::std;

class Grid
{
public:
    //Constructor & Destructor
    Grid();
    ~Grid();
    
    //Mutator
    void applyMove(int startPosRow, int startPosColumn, int endPosRow, int endPosColumn);
    void removePeg(int row, int column);
    
    vector<int> & operator[] (int index);
    
    //Facilitators
    bool isLegalMove(int startPosRow, int startPosColumn, int endPosRow, int endPosColumn);
    int checkMoves();
    void display(ostream & out);
    
private:
    vector< vector<int> > grid_;
    
};

//auxillary ovverides
ostream & operator<< (ostream out, Grid grid);


#endif /* defined(__Homework_3_Console__Grid__) */
