//
//  Movie.cpp
//  Homework 4
//
//  Created by Anthony John Beckner on 8/31/15.
//  Copyright (c) 2015 ajbecknerapps. All rights reserved.
//

//
//  Actor.cpp
//  Homework1Console
//
//  Created by Anthony John Beckner on 7/14/15.
//  Copyright (c) 2015 ajbecknerapps. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "List.h"
#include "Actor.h"
#include "Movie.h"

using namespace std;

// ------------------------------------------------------
// ----- Constructors -----------------------------------
// ------------------------------------------------------

Actor::Actor() {
    
}

Actor::Actor(const string & name) {
    name_ = name;
}


Actor::Actor(Actor & actor){
    name_ = actor.getname();
    movies_ = actor.getMovies();
    
}



// ------------------------------------------------------
// ----- Destructor -------------------------------------
// ------------------------------------------------------

Actor::~Actor(){
    movies_.List::clear();
}

// ------------------------------------------------------
// ----- Inspectors -------------------------------------
// ------------------------------------------------------

string Actor::getname() const {
    return name_;
}

int Actor::getNumMovies() const {
    return movies_.size();
}

Movie* Actor::getMovie(int index) const {
    if (index < movies_.size())
        return movies_[index];
    else
        return NULL;
}

List<Movie*> Actor::getMovies() const {
    return movies_;
}

// ------------------------------------------------------
// ----- Mutators ---------------------------------------
// ------------------------------------------------------

void Actor::setname(const string& name) {
    name_ = name;
}


void Actor::addMovie(Movie* movie) {
    movies_.push_back(movie);
    //movies_[movies_.size() - 1] = movie;
}


void Actor::output(ostream &out) {
    
    out << "name: " + name_ << endl;
    out << "Movies: " << endl;
    for (int i = 0; i < movies_.size(); i++){
        out << movies_[i] << endl;
    }
    
}

