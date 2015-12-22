//
//  FullName.h
//  test
//
//  Created by Anthony John Beckner on 9/3/15.
//  Copyright (c) 2015 ajbecknerapps. All rights reserved.
//

#ifndef __test__FullName__
#define __test__FullName__

#include <iostream>
#include <string>
using namespace std;

class FullName{
public:
    
    //Constructors
    
    FullName();
    
    FullName(FullName & Fn);
    
    FullName(string f, string l);
    
    //Inspectors
    string getFirst() const;
    string getLast() const;
    
    //Mutators
    void setFirst(string f);
    void setLast(string l);
    
    //facilitators
    string toString() const;
    
    void output(ostream &out) const;
private:
    string first;
    string last;
};

ostream & operator << (ostream & sout, const FullName name);

#endif /* defined(__test__FullName__) */
