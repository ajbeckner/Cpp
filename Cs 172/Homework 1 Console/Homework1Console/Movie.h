// ----------------------------------------------------------------------------
//
//  Movie class
//    Header
//
//  This class represents a movie, featuring a title, director, rating,
//  year of release, and URL for further information in the Internet
//  Movie Database (IMDB, http://www.imdb.com ) .
//
// ----------------------------------------------------------------------------
//
//  Author:         JL Popyack
//  Date:           4/4/4
//  Modified:       4/2/14  -- JL Popyack, removed destructor
//
// ----------------------------------------------------------------------------

#ifndef Homework1Console_Movie_h
#define Homework1Console_Movie_h

#include <string>
using namespace std;


enum Movie_Rating {G,PG,PG13,R,NC17,NR} ;


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

class Movie
{
public:
    
    // ------------------------------------------------------
    // ----- Constructors -----------------------------------
    // ------------------------------------------------------
    
    Movie();
    Movie(const string& title) ;
    Movie(const string& title,
          const string& director,
          Movie_Rating rating,
          unsigned int year,
          const string& path) ;
    
    // ------------------------------------------------------
    // ----- Destructor -------------------------------------
    // ------------------------------------------------------
    
    //	~Movie();  // To be implemented in a future assignment.
	  	
    // ------------------------------------------------------
    // ----- Inspectors -------------------------------------
    // ------------------------------------------------------
	  	
    string getTitle() const ;
    string getDirector() const ;
    Movie_Rating getRating() const ;
    unsigned int getYear() const ;
    string getURL() const ;
	  	
    // ------------------------------------------------------
    // ----- Mutators ---------------------------------------
    // ------------------------------------------------------
    void setTitle(const string& title) ;
    void setDirector(const string& director) ;
    void setRating(Movie_Rating rating)  ;
    void setYear(unsigned int year)  ;
    void setURL(const string& path)  ;
    void output(ostream &out) ;
    
    // ----------------------------------------------------------
    // ----------------------------------------------------------
    
private:
    string       title_ ;
    string       director_ ;
    Movie_Rating rating_ ;
    unsigned int year_ ;
    string       url_ ;
    
};

#endif
