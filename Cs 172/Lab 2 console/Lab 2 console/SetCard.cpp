#include <stdio.h>
#include "SetCard.h"
using namespace std;

//Constructors

SetCard::SetCard(){
}

SetCard::SetCard(string shape, string shade, string color, string number){
    shape_ = shape;
    shade_ = shade;
    color_ = color;
    number_ = number;
}

string SetCard::getShape(){
    return shape_;
}

string SetCard::getShade(){
    return shade_;
}

string SetCard::getColor(){
    return getColor();
}

string SetCard::getNumber(){
    return number_;
}

string SetCard::toString(){
    return "SetCard";
}

void SetCard::output(ostream & out){
    
}

