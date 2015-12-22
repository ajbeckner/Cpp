//----------------------------------------------------------------------------
//
//-------------------------------- Personality -------------------------------
// 
//----------------------------------------------------------------------------
//
//  Program Name: Person.cpp
//
//  This is a test program for investigating use of pointers in class design
//  and implementation.
//
//  This program contains a partial class declaration and definition for a
//  Person class
//
//----------------------------------------------------------------------------
//
//  Author:         P Zoski, JL Popyack
//  Date:           05/10/3
//
//----------------------------------------------------------------------------


	#include <iostream>
	#include <string>
	#include <ciso646>
	using namespace std ;


//----------------------------------------------------------------------------
//
//  Person class
//    Declaration
//
//----------------------------------------------------------------------------


	class Person
	{
		public:

		//------------------------------------------------------
		//----- Constructors -----------------------------------
		//------------------------------------------------------

			Person() ;
			Person(string name) ;
			~Person() ;

		//------------------------------------------------------
		//----- Inspectors -------------------------------------
		//------------------------------------------------------

			string getName() ;
			Person * getSpouse() ;
			
		//------------------------------------------------------
		//----- Mutators ---------------------------------------
		//------------------------------------------------------

			bool marry(Person & p) ;
			
		private:
			string name_ ;
			Person * spouse_ ;
			Person * son_ ;
			Person * daughter_ ;
	} ;

    Person * newborn(string name);
    Person * newkid(string name);


//----------------------------------------------------------------------------
//
//  Person class
//    Implementation
//
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//----- Constructors ---------------------------------------------------------
//----------------------------------------------------------------------------

	Person::Person()
	{
        //spouse_ = NULL;
        son_ = NULL;
        daughter_ = NULL;
    }

	Person::Person(string name)
	{ 
		name_ = name ;
        //spouse_ = NULL;
        son_ = NULL;
        daughter_ = NULL;
	}

	Person::~Person()
	{ }

//----------------------------------------------------------------------------
//----- Inspectors -----------------------------------------------------------
//----------------------------------------------------------------------------

	string Person::getName()
	{ 
		return name_ ;
	}

	Person * Person::getSpouse()
	{ 
		return spouse_ ;
	}

//----------------------------------------------------------------------------
//----- Mutators -------------------------------------------------------------
//----------------------------------------------------------------------------

	bool Person::marry(Person & p)
	{ 
	//----------------------------------------------------------------------------
	// parameter must be passed by reference, otherwise implicit
	// object will marry a copy of p
	//----------------------------------------------------------------------------

		//----------------------------------------------------------------------------
		// can't get married if a Person is already married
		//----------------------------------------------------------------------------
			if (spouse_ != NULL or p.spouse_ != NULL)
				 return false ; 
	     
		//----------------------------------------------------------------------------
		// implicit Person marries person p
		// p marries implicit Person
		//----------------------------------------------------------------------------
			spouse_ = & p; 
			p.spouse_ = this ;  
		
		return true;  
	}

	
//----------------------------------------------------------------------------
//
//------------------------------- Main Program -------------------------------
//
//----------------------------------------------------------------------------

	int main(void)
	{
        /*
		Person George("George Jetson"), 
		       Jane("Jane Jetson"), 
		       Judy("Judy Jetson"), 
		       Elroy("Elroy Jetson") ;
        
        George.marry(Jane);
		
        cout << "George's spouse: " << George.getSpouse()->getName() << endl;
        cout << "Jane's spouse: " << Jane.getSpouse()->getName() << endl;
        cout << "George's spouse: " << Jane.getName() << endl;
        cout << "Jane's spouse: " << George.getName() << endl;
        //if (Elroy.getSpouse() != NULL)
        //cout << "Elroy's spouse: " << Elroy.getSpouse()->getName() << endl;
        //if (Judy.getSpouse() != NULL)
        //cout << "Judy's spouse: " << Judy.getSpouse()->getName() << endl;
         */

        Person * a = newborn("a") ;
        Person * b = newborn("b") ;
        Person * c = newborn("c") ;
        a->marry(*b) ;
        cout << a->getSpouse()->getName() << endl ;
        cout << b->getSpouse()->getName() << endl ;
        
        
        Person * d = newkid("d") ;
        Person * e = newkid("e") ;
        Person * f = newkid("f") ;
        d->marry(*e) ;
        
        cout << d->getSpouse()->getName() << endl ;
        cout << e->getSpouse()->getName() << endl ;
        
        
		return 0 ;
	}

Person * newborn(string name)
{
    Person p(name) ;
    return &p ;
}

Person * newkid(string name)
{
    Person * p = new Person(name) ;
    return p ;
}


