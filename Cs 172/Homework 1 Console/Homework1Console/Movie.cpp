//
//  Movie.cpp
//  Homework1Console
//
//  Created by Anthony John Beckner on 7/14/15.
//  Copyright (c) 2015 ajbecknerapps. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "Movie.h"

using namespace std;

// ------------------------------------------------------
// ----- Constructors -----------------------------------
// ------------------------------------------------------

Movie::Movie() {

}

Movie::Movie(const string& title) {
    title_ = title;
}

Movie::Movie(const string& title,const string & director,Movie_Rating rating,unsigned int year, const string & path) {
    
    director_ = director;
    rating_ = rating;
    year_ = year;
    url_ = path;
    
}

// ------------------------------------------------------
// ----- Destructor -------------------------------------
// ------------------------------------------------------

//	~Movie();  // To be implemented in a future assignment.

// ------------------------------------------------------
// ----- Inspectors -------------------------------------
// ------------------------------------------------------

string Movie::getTitle() const {
    return title_;
}

string Movie::getDirector() const {
    return director_;
}

Movie_Rating Movie::getRating() const {
    return rating_;
}

unsigned int Movie::getYear() const {
    return year_;
}

string Movie::getURL() const {
    return url_;
}

// ------------------------------------------------------
// ----- Mutators ---------------------------------------
// ------------------------------------------------------

void Movie::setTitle(const string& title) {
    title_ = title;
}

void Movie::setDirector(const string& director) {
    director_ = director;
}

void Movie::setRating(Movie_Rating rating)  {
    rating_ = rating;
}

void Movie::setYear(unsigned int year)  {
    year_ = year;
}

void Movie::setURL(const string& path)  {
    url_ = path;
}


void Movie::output(ostream &out) {
    
    out << "Title: " + title_ << endl;
    out << "Director: " + director_ << endl;
    out << "Year: " + to_string(year_) << endl;
    string rating;
    if (rating_ == G){ rating = "G";} else
    if (rating_ == PG){ rating = "PG";} else
    if (rating_ == PG13){ rating = "PG13";} else
    if (rating_ == R){ rating = "R";} else
    if (rating_ == NC17){ rating = "NC17";} else
    if (rating_ == NR){ rating = "NR";}
    out << "Rating: " + rating << endl;
    out << "IMDB Url: " + url_ << endl;cout << endl;
    
}

