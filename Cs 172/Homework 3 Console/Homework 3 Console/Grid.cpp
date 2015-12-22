//
//  Grid.cpp
//  Homework 3 Console
//
//  Created by Anthony John Beckner on 8/7/15.
//  Copyright (c) 2015 ajbecknerapps. All rights reserved.
//

#include "Grid.h"


//vector< vector<int> > grid_;

Grid::Grid(){
    
    //grid_.resize(4);
    
    vector<int> row0 = vector<int>(4);
    vector<int> row1 = vector<int>(4);
    vector<int> row2 = vector<int>(4);
    vector<int> row3 = vector<int>(4);
    
    for (int i = 0;i<4;i++) row0[i] = 1;
    for (int i = 0;i<4;i++) row1[i] = 1;
    for (int i = 0;i<4;i++) row2[i] = 1;
    for (int i = 0;i<4;i++) row3[i] = 1;

    grid_.push_back(row0);
    grid_.push_back(row1);
    grid_.push_back(row2);
    grid_.push_back(row3);
}

Grid::~Grid(){
    grid_.clear();
}

//Mutator
void Grid::applyMove(int startPosRow, int startPosColumn, int endPosRow, int endPosColumn){
    
    int jumpPosRow = (startPosRow + endPosRow)/2;
    int jumpPosColumn = (startPosColumn + endPosColumn)/2;
    
    grid_[startPosRow][startPosColumn] = 0;
    grid_[endPosRow][endPosColumn] = 1;
    grid_[jumpPosRow][jumpPosColumn] = 0;
}

void Grid::removePeg(int row, int column) {
    grid_[row][column] = 0;
}

vector<int> & Grid::operator[] (int index){
    return grid_[index];
}

//Facilitator
bool Grid::isLegalMove(int startPosRow, int startPosColumn, int endPosRow, int endPosColumn){
    
    int jumpPosRow = (startPosRow + endPosRow)/2;
    int jumpPosColumn = (startPosColumn + endPosColumn)/2;
    
    bool checkBoardsize = (startPosRow<4) && (endPosRow<4) && (startPosColumn<4) && (endPosColumn<4);
    if (!checkBoardsize) return 0;
    int dist1 = abs(startPosRow - endPosRow);
    int dist2 = abs(startPosColumn - endPosColumn);
    bool checkCorrectDistance = (dist1 == 2 && dist2 == 2) || (dist1 == 2 && dist2 == 0) || (dist2 == 2 && dist1 == 0);
    bool checkStartPosForPeg = grid_[startPosRow][startPosColumn] == 1;
    bool checkEndPosForSpace = grid_[endPosRow][endPosColumn] == 0;
    bool checkJumpPosForPeg = grid_[jumpPosRow][jumpPosColumn] == 1;
    
    return (checkCorrectDistance && checkStartPosForPeg && checkEndPosForSpace && checkJumpPosForPeg);
}

int Grid::checkMoves(){
    int numMoves = 0;
    int numPieces = 0;
    int exitCode;
    for (int i = 0; i<4;i++){
        for (int j = 0; j<4;j++){
            if (grid_[i][j] == 1){
                numPieces++;
            }
            for (int k = 0;k<4;k++){
                for (int l = 0;l<4;l++){
                    if (isLegalMove(i,j,k,l)){
                        numMoves++;
                    }
                }
            }
        }
    }
    if (numMoves == 0 && numPieces == 1){
        cout << "You win!!! You have beaten the PegBoard!" << endl;
        exitCode = -1;
    } else if (numMoves == 0){
        cout << "You get nothing. You Lose! Good day, Sir!!!" << endl;
        exitCode = -1;
    } else {
        
    }
    return exitCode;
}

void Grid::display(ostream & out){
    out << setw(13)<< "0 1 2 3  " << endl;
    out << setw(13)<< "+---------+" << endl;
    for (int i = 0; i<grid_.size();i++){
        out << setw(1) << i << setw(3) << "| ";
        for (int j = 0; j < grid_[i].size();j++){
            if (grid_[i][j] == 1) {
                out << "X ";
            } else {
                out << "O ";
            }
        }
        out << "|" << endl;
    }
    out << setw(13)<< "+---------+" << endl;
    
}

ostream & operator<< (ostream & out, Grid grid){
    grid.display(out);
    return out;
}


