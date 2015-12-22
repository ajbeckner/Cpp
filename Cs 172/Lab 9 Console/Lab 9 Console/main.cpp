#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Thingie {
    
public:
    
    virtual void doYourThing(){
        
    }
    
    void printDescription(){
        cout << "Name:" << name_ << endl;
        cout << "Description: " << description_ << endl;
    }

protected:
    string name_;
    string description_;
    
};




class Weapon : public Thingie {
    
public:

    void doYourThing() {
        attack();
    }
    
protected:
    virtual void attack(){
        
    }

};



class Sword : public Weapon {
    
public:
 
    Sword(){
        name_ = "sword";
        description_ = "- slashes enemies.";
    }
 
    
private:
    
    void attack(){
        cout << "Slash, slash!" << endl;
    }
    

};



class Spear : public Weapon {
    
public:
    Spear(){
        name_ = "spear";
        description_ = "- jabs enemies.";
    }
private:
    
    void attack(){
        cout << "Jab, jab!" << endl;
    }
    

};




class Potion : public Thingie {
public:
    
    Potion(){
        name_  = "potion";
        description_ = "- drink this! It resores health." ;

    }
    
    void doYourThing(){
        drink();
    }
    
private:
    
    void drink(){
        cout << "Slurp, Slurp!" << endl;
    }
    
};


class Bag {
    
public:
    
    void printContents(){
        cout << "The bag has: " << endl;
        for (int i = 0; i < bag.size(); i++){
            bag[i]->printDescription();
            cout << endl;
        }
    }
    
    void putInBag(Thingie & thing){
        bag.push_back(& thing);
    }
    int size(){
        return bag.size();
    }
    vector<Thingie *> bag;
};
 

int main(int argc, const char * argv[]) {
    
    

    cout << "The thingies are being created" << endl;
    
    Bag myBag;
    
    Sword mySword;
    
    Spear mySpear;
    Potion mYPotion;
    
    
    cout << "We are picking up the thingies" << endl;
    
    myBag.putInBag(mySword);
    myBag.putInBag(mySpear);
    myBag.putInBag(mYPotion);
    
    myBag.printContents();
    
    cout << "Let's use the contents! : " << endl;
    for (int i = 0; i < myBag.size(); i++){
        myBag.bag[i]->doYourThing();
    }
    
    return 0;
}


