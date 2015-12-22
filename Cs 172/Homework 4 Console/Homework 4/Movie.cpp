//
//  Movie.cpp
//  Homework1Console
//
//  Created by Anthony John Beckner on 7/14/15.
//  Copyright (c) 2015 ajbecknerapps. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "List.h"
#include "Movie.h"
#include "Actor.h"
using namespace std;

// ------------------------------------------------------
// ----- Constructors -----------------------------------
// ------------------------------------------------------

Movie::Movie() {

}

Movie::Movie(const string & title) {
    title_ = title;
}

Movie::Movie(const string & title,const string & director,Movie_Rating rating,unsigned int year, const string & path) {
    title_ = title;
    director_ = director;
    rating_ = rating;
    year_ = year;
    url_ = path;
    actors_ = List<Actor*>();
    
}

Movie::Movie(Movie & movie){
    title_ = movie.getTitle();
    director_ = movie.getDirector();
    rating_ = movie.getRating();
    year_ = movie.getYear();
    url_ = movie.getURL();
    actors_ = movie.getActors();
    
}



// ------------------------------------------------------
// ----- Destructor -------------------------------------
// ------------------------------------------------------

Movie::~Movie(){
    actors_.List::clear();
}

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

int Movie::getNumActors() const {
    return actors_.size();
}

Actor* Movie::getActor(int index) const {
    if (index < actors_.size())
        return actors_[index];
    else
        return NULL;
}

List<Actor*> Movie::getActors() const {
    return actors_;
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

void Movie::addActor(Actor* actor) {
    actors_.push_back(actor);
    //actors_[actors_.size() - 1] = actor;
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
    out << "Actors: " << endl;
    for (int i = 0; i < actors_.size(); i++){
        out << actors_[i] << endl;
    }
    
}

