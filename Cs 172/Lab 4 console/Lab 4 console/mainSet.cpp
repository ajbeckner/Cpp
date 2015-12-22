//
//  mainSet.cpp
//  Lab 4 console
//
//  Created by Anthony John Beckner on 7/17/15.
//  Copyright (c) 2015 ajbecknerapps. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

//#include "SetCard.h"

using namespace std;

int main(void) {
    
    int i = 0;
    bitset<4> b;
    int r;
    srand(9);
    
    while (true) {
        r = rand()%4;
        b.set(r);
        i++;
        
        if(b[0]*b[1]*b[2]*b[3] == 1) {
            break;
        }
    }
    cout << "It took " + to_string(i) + " trials." << endl;
    return 0;
}