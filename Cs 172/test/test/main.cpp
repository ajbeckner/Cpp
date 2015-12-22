//
//  main.cpp
//  test
//
//  Created by Anthony John Beckner on 9/3/15.
//  Copyright (c) 2015 ajbecknerapps. All rights reserved.
//

#include <iostream>
#include "FullName.h"
using namespace std;

int main() {
    
    string s1,s2;
    cout << "Input your first name: ";
    cin >> s1;
    cout << "\nInput your last name: " ;
    cin >> s2;
    cout << endl;
    
    cout << "s1: " << s1 << ", s2: " << s2 << endl;
    FullName myName(s1,s2);
    cout << "constructor for FullName called" << endl << endl;
    
    cout << "Printing with inspectors: " << endl;
    cout << "Your name is: " << myName.getFirst() << " " << myName.getLast() << "." << endl << endl;
    
    cout << "Printing with toString() method: " << endl;
    cout << "Your name is " << myName.toString() << "." << endl << endl;
    
    cout << "Printing with output() method: " << endl;
    cout << "Your name is "; myName.output(cout); cout << "." << endl;
    
    cout << "Printing your name with overloaded << operator: " << endl;
    cout << "Your name is " << myName << "." << endl;
    
    return 0;
}
