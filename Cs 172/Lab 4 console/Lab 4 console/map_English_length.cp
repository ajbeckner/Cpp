//----------------------------------------------------------------------------
//
//--------------------------------- Map Test ---------------------------------
//
//----------------------------------------------------------------------------
//
// Map Test
//
// This program demonstrates use of the map<> container class:
//   - building maps between strings and English_length 
//     and between English_length and string 
//   - manipulating elements of the map
//
// JL Popyack, April 2006 
//
//----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "English_length.h"
using namespace std ;

int main(void)
{
//---------------------------------------------
//	Create a map that allows us to convert text
//  to English lengths:
//---------------------------------------------
	map<string,English_length> equivalent ;

	equivalent["inch"] = English_length(1) ;
    equivalent["inches"] = English_length(1) ;
	equivalent["foot"] = 12*equivalent["inch"] ;
    equivalent["feet"] = 12*equivalent["inch"] ;
    equivalent["yard"] = 3*equivalent["foot"];
    equivalent["yards"] = 3*equivalent["foot"];
    equivalent["furlong"] = 220*equivalent["yard"];
    equivalent["furlongs"] = 220*equivalent["yard"];
    equivalent["mile"] = 5280*equivalent["feet"];
    equivalent["miles"] = 5280*equivalent["feet"];
    
//---------------------------------------------
//	Now the inverse map, that allows us to find
//  the text description of an English length:
//---------------------------------------------

	//---------------------------------------------
	//	In this space, declare the map, named
	//  description, and assign it descriptions for 
	//  inch, foot, yard, furlong, and mile.
	//---------------------------------------------
    map<English_length,string> description ;

	description[English_length(1)] = "inch" ;
    description[12*equivalent["inch"]] = "foot" ;
    description[3*equivalent["foot"]] = "yard" ;
    description[220*equivalent["yard"]] = "furlong" ;
    description[5280*equivalent["feet"]] = "mile" ;



//---------------------------------------------
//	Investigate contents of map by allowing the
//  user to input a text description of a length
//  e.g., "3 feet" and return an English_length
//  e.g., 3*equivalent["foot"] .
//---------------------------------------------
	int n ;
	string len ;
	do
	{
		cout << "Input a measurement (e.g., '3 feet'): " ;
		cin >> n >> len ;
		English_length el = n*equivalent[len] ;
		cout << el << endl ;

		//---------------------------------------------
		//	In this space, check whether el is a 'known
		//  unit of measurement' (e.g., 1 mile) by
		//  checking whether it is defined in the map.
		//  If so, print its text description ("1 mile").
		//---------------------------------------------


	} while( n!=0 ) ;

    

	return 0 ;
}