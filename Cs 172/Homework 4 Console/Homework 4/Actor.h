// ----------------------------------------------------------------------------
//
//  Actor class
//    Header
//
//  This class represents a Actor, featuring a name, director, rating,
//  year of release, and URL for further information in the Internet
//  Actor Database (IMDB, http://www.imdb.com ) .
//
// ----------------------------------------------------------------------------
//
//  Author:         JL Popyack
//  Date:           4/4/4
//  Modified:       4/2/14  -- JL Popyack, removed destructor
//
// ----------------------------------------------------------------------------

#ifndef Homework1Console_Actor_h
#define Homework1Console_Actor_h

#include <string>
#include <vector>
#include "List.h"
//#include "Movie.h"
using namespace std;

class Movie;
class Actor
{
public:
    
    // ------------------------------------------------------
    // ----- Constructors -----------------------------------
    // ------------------------------------------------------
    
    Actor();
    Actor(const string & name);
    Actor(Actor & actor);
    
    // ------------------------------------------------------
    // ----- Destructor -------------------------------------
    // ------------------------------------------------------
    
    ~Actor();  // To be implemented in a future assignment.
	  	
    // ------------------------------------------------------
    // ----- Inspectors -------------------------------------
    // ------------------------------------------------------
	  	
    string getname() const ;
    int getNumMovies() const;
    Movie* getMovie(int index) const;
    List<Movie*> getMovies() const;
	  	
    // ------------------------------------------------------
    // ----- Mutators ---------------------------------------
    // ------------------------------------------------------
    void setname(const string& name) ;
    void output(ostream &out) ;
    void addMovie(Movie* movie);
    
    // ----------------------------------------------------------
    // ----------------------------------------------------------
    
private:
    string       name_ ;
    List<Movie*> movies_;
    
};

#endif
