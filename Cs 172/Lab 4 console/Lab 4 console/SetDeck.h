#ifndef __Lab_4_console__SetDeck__
#define __Lab_4_console__SetDeck__

#include <vector>
#include <string>

#include "SetCard.h"

class SetDeck {
public:
    
    //Constructors:
    SetDeck();
    
    //Inspectors:

    //NA
    
    //Muators
    
    //NA
    
    
    //Facilitators:
    SetCard getCard();
    void shuffleCards();
    
    
    
private:
    
    vector<SetCard> deck;
    vector<string> shapes, shades, colors, numbers;

};


#endif /* defined(__Lab_4_console__SetDeck__) */
