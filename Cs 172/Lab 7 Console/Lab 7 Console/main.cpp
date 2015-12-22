
#include <iostream>
#include <string>
#include "DUPoint.h"
#include "DULine.h"
#include <vector>

using namespace std ;


int main(void){
    
    DUPoint p(3,8);
    DUPoint * pPtr = new DUPoint(3,8) ;
    DUPoint * qPtr = new DUPoint(9,64);
    
    int x, y;
    
    x = pPtr->getX();
    y = pPtr->getY();
    
    cout << "(" << x << "," << y << ")" << endl;
    cout << * pPtr << endl;
    
    int temp;
    
    temp = pPtr->getX();
    pPtr->setX(pPtr->getY());
    pPtr->setY(temp);
    
    x = pPtr->getX();
    y = pPtr->getY();
    
    cout << "(" << x << "," << y << ")" << endl;
    cout << * pPtr << endl;
    
    DULine L(p, *pPtr) ;
    cout << L << endl ;
    
    L.setPoint1(* qPtr);
    cout << L << endl ;
    
    cout << qPtr->getY() << endl;
    
    vector<DUPoint* > triangle(3);
    triangle[0] = new DUPoint(0,0);
    triangle[1] = new DUPoint(4,0);
    triangle[2] = new DUPoint(4,3);
    
    for (int i = 0; i < 3; i++){
        
        string input;
        
        cout << "x?: ";
        
        getline(cin, input);
        
        triangle[i]->setX(atoi(input.c_str()));
        
        cout << "y?: ";
        
        getline(cin, input);
        
        triangle[i]->setY(atoi(input.c_str()));
        
    }
    
    cout << "Triangle: ";
    for(int i = 0; i < 3; i++){
        cout << *triangle[i] << ", ";
    }
    cout << endl;
    
    
    
    return 0;
}