#ifndef Lab_2_console_SetCard_h
#define Lab_2_console_SetCard_h

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class SetCard {
public:
    
    //Constructors:
    SetCard();
    SetCard(string shape, string shade, string color, string number);
    
    //Inspectors:
    string getShape();
    string getShade();
    string getColor();
    string getNumber();
    
    //Muators
    
    //NA
    
    
    //Facilitators:
    string toString();
    void output(ostream & out);
    
    
    
private:
    
    string shape_;
    string shade_;
    string color_;
    string number_;
    
};




#endif
