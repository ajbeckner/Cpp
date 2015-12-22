

#include <vector>
#include <string>

#include "SetCard.h"
#include "SetDeck.h"

using namespace std;

SetDeck::SetDeck() {
    
    shapes.push_back("diamond");
    shapes.push_back("oval");
    shapes.push_back("squigle");
    shades.push_back("solid");
    shades.push_back("shaded");
    shades.push_back("outlined");
    colors.push_back("green");
    colors.push_back("red");
    colors.push_back("purple");
    numbers.push_back("1");
    numbers.push_back("2");
    numbers.push_back("3");
    
    for (int i = 0; i < shapes.size(); i++){
        for (int j = 0; j < shades.size(); j++) {
            for (int k = 0; k < colors.size(); k++) {
                for (int l = 0; l < numbers.size(); l++) {
                    deck[i*j*k*l] = SetCard(shapes[i],shades[j],colors[k],numbers[l]);
                }
            }
        }
    }
}

SetCard SetDeck::getCard() {
    SetCard card = deck[deck.size()];
    deck.pop_back();
    return card;
}

void SetDeck::shuffleCards() {
    
    for (int numCards = deck.size(); numCards>=0; numCards--) {
        int r = rand()%81;
        
        SetCard temp = deck[numCards];
        deck[numCards] = deck[r];
        deck[r] = temp;
        
    }
    
}


