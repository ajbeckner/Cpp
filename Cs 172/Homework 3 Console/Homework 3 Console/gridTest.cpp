//
//  main.cpp
//  Homework 3 Console
//
//  Created by Anthony John Beckner on 8/7/15.
//  Copyright (c) 2015 ajbecknerapps. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "Grid.h"
using namespace std;

int askMove(int & rowPeg,int & columnPeg,int & rowHole,int & columnHole);

int main() {
    
    cout << "Welcome to the PegBoard! Remove the pegs to win by hopping. Input \"q\" to quit at any time.\n"<< endl;
    Grid myGrid;
    myGrid.display(cout);
    
    cout << "\nWhich Peg Should be removed to start?(row column) ";
    string input;
    getline(cin,input);
    if (input.find("q") != string::npos) return -1;
    int row = atoi(input.substr(0,input.find(" ")).c_str());
    int column = atoi(input.substr(input.find(" ")+1,1).c_str());
    
    myGrid.removePeg(row, column);
    myGrid.display(cout);
    
    while (true){
        int rowPeg, columnPeg, rowHole, columnHole;
        int exitCode = askMove(rowPeg,columnPeg,rowHole,columnHole);
        if (exitCode ==  -1) return -1;
        while(true){
            if (myGrid.isLegalMove(rowPeg, columnPeg, rowHole, columnHole)){
                myGrid.applyMove(rowPeg, columnPeg, rowHole, columnHole);
                break;
            }else {
                cout << "Illegal Move" << endl;
                int exitCode = askMove(rowPeg,columnPeg,rowHole,columnHole);
                if (exitCode ==  -1) return -1;

            }
        }
        myGrid.display(cout);
        if (myGrid.checkMoves() == -1) return -1;
    }

    return 0;
}

int askMove(int & rowPeg,int & columnPeg,int & rowHole,int & columnHole){
    try{
    cout << "\nEnter move: ";
    string input;
    getline(cin,input);
    if (input.size() != 7) throw exception();
    if (input.find("q") != string::npos) return -1;
    rowPeg = atoi(input.substr(0,input.find(" ")).c_str());
    columnPeg = atoi(input.substr(input.find(" ")+1,1).c_str());
    string input2 = input.substr(input.find(" ",input.find(" ")+1)+1);
    rowHole = atoi(input2.substr(0,input.find(" ")).c_str());
    columnHole = atoi(input2.substr(input.find(" ")+1,1).c_str());
    }catch (exception e){
        
    }
    return 0;
}
