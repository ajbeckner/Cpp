#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void) {
    string  input,firstName, lastName, firstLetterFirstName, firstLetterLastName, lastLetterLastName;
    map<string,string> newFirstNames, newLastNames1,newLastNames2;

    newFirstNames["A"] = "Stinky";
    newFirstNames["B"] = "Lumpy";
    newFirstNames["C"] = "Buttercup";
    newFirstNames["D"] = "Gidget";
    newFirstNames["E"] = "Crusty";
    newFirstNames["F"] = "Greasy";
    newFirstNames["G"] = "Fluffy";
    newFirstNames["H"] = "Cheeseball";
    newFirstNames["I"] = "Chim-Chim";
    newFirstNames["J"] = "Poopsie";
    newFirstNames["K"] = "Flunky";
    newFirstNames["L"] = "Booger";
    newFirstNames["M"] = "Pinky";
    newFirstNames["N"] = "Zippy";
    newFirstNames["O"] = "Goober";
    newFirstNames["p"] = "Doofus";
    newFirstNames["Q"] = "Slimy";
    newFirstNames["R"] = "Loopy";
    newFirstNames["S"] = "Snotty";
    newFirstNames["T"] = "Falafel";
    newFirstNames["U"] = "Dorkey";
    newFirstNames["V"] = "Squeezit";
    newFirstNames["W"] = "Oprah";
    newFirstNames["X"] = "Skipper";
    newFirstNames["Y"] = "Dinky";
    newFirstNames["Z"] = "Zsa-Zsa";
    
    newLastNames1["A"] = "Diaper";
    newLastNames1["B"] = "Toilet";
    newLastNames1["C"] = "Giggle";
    newLastNames1["D"] = "Bubble";
    newLastNames1["E"] = "Girdle";
    newLastNames1["F"] = "Barf";
    newLastNames1["G"] = "Lizard";
    newLastNames1["H"] = "Waffle";
    newLastNames1["I"] = "Cootie";
    newLastNames1["J"] = "Monkey";
    newLastNames1["K"] = "Potty";
    newLastNames1["L"] = "Liver";
    newLastNames1["M"] = "Banana";
    newLastNames1["N"] = "Rhino";
    newLastNames1["O"] = "Burger";
    newLastNames1["p"] = "Hamster";
    newLastNames1["Q"] = "Toad";
    newLastNames1["R"] = "Gizard";
    newLastNames1["S"] = "Pizza";
    newLastNames1["T"] = "Gerbil";
    newLastNames1["U"] = "Chicken";
    newLastNames1["V"] = "Pickle";
    newLastNames1["W"] = "Chucle";
    newLastNames1["X"] = "Tofu";
    newLastNames1["Y"] = "Gorilla";
    newLastNames1["Z"] = "Stinker";
    
    newLastNames2["a"] = "head";
    newLastNames2["b"] = "mouth";
    newLastNames2["c"] = "face";
    newLastNames2["d"] = "nose";
    newLastNames2["e"] = "tush";
    newLastNames2["f"] = "breath";
    newLastNames2["g"] = "pants";
    newLastNames2["h"] = "shorts";
    newLastNames2["i"] = "lips";
    newLastNames2["j"] = "honker";
    newLastNames2["k"] = "butt";
    newLastNames2["l"] = "brain";
    newLastNames2["m"] = "tushie";
    newLastNames2["n"] = "chunks";
    newLastNames2["o"] = "hiney";
    newLastNames2["p"] = "biscuits";
    newLastNames2["q"] = "toes";
    newLastNames2["r"] = "buns";
    newLastNames2["s"] = "fanny";
    newLastNames2["t"] = "sniffer";
    newLastNames2["u"] = "sprinkles";
    newLastNames2["v"] = "kisser";
    newLastNames2["w"] = "squirt";
    newLastNames2["x"] = "humperdink";
    newLastNames2["y"] = "brains";
    newLastNames2["z"] = "juice";

    cout << "What is your name?" << endl;
    getline(cin, input);
    
    firstName = input.substr(0,input.find(" "));
    lastName = input.substr(input.find(" ") + 1, input.length());
    
    
    firstLetterFirstName = firstName.substr(0,1);
    firstLetterLastName = lastName.substr(0,1);
    lastLetterLastName = lastName.substr(lastName.length() - 1, 1);
    
    
    cout << "Your new name is " + newFirstNames[firstLetterFirstName] + " " + newLastNames1[firstLetterLastName] + newLastNames2[lastLetterLastName] <<endl;

}
