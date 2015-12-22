//
//  FullName.cpp
//  test
//
//  Created by Anthony John Beckner on 9/3/15.
//  Copyright (c) 2015 ajbecknerapps. All rights reserved.
//

#include "FullName.h"
//#include <string>

using namespace std;
//Constructors

FullName::FullName(){
    first = "";
    last = "";
}

FullName::FullName(FullName & Fn){
    first = Fn.first;
    last = Fn.last;
}

FullName::FullName(string f, string l){
    first = f;
    last = l;
}

//Inspectors
string FullName::getFirst() const{
    return first;
}
string FullName::getLast() const{
    return last;
}

//Mutators
void FullName::setFirst(string f){
    first = f;
}
void FullName::setLast(string l){
    last = l;
}

string FullName::toString() const{
    return first + " " + last;
}

void FullName::output(ostream &out) const{
    out << toString();
}

ostream & operator << (ostream & sout, const FullName name){
    name.output(sout);
    return sout;
}

