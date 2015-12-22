//
//  main.cpp
//  Homework1Console
//
//  Created by Anthony John Beckner on 7/14/15.
//  Copyright (c) 2015 ajbecknerapps. All rights reserved.
//

#include <iostream>
#include <string>
#include "Movie.h"

using namespace std;

void promptForMovie(Movie & myMovie);

int main(int argc, const char * argv[]) {
    Movie movie1 = Movie("Inception");
    Movie movie2, movie3, movie4, movie5;
    
    movie1.setDirector("Chrisopher Nolan");
    movie1.setYear(2010);
    movie1.setRating(PG13);
    movie1.setURL("http://www.imdb.com/title/tt1375666/");
    
    promptForMovie(movie2);
    promptForMovie(movie3);
    promptForMovie(movie4);
    promptForMovie(movie5);
    
    movie1.output(cout);
    movie2.output(cout);
    movie3.output(cout);
    movie4.output(cout);
    movie5.output(cout);

    
    return 0;
}

void promptForMovie(Movie & myMovie){
    string input;
    cout << "\nTell me about the next movie:" << endl;
    cout << "What is the title of your movie?" << endl;
    getline(cin,input) ; cout << endl;
    myMovie = Movie(input);
    cout << "Who is the director of your movie?" << endl;
    getline(cin,input) ; cout << endl;
    myMovie.setDirector(input);
    cout << "What is the year of your movie?" << endl;
    getline(cin,input) ; cout << endl;
    myMovie.setYear(atoi(input.c_str()));
    cout << "What is the rating of your movie?" << endl;
    getline(cin,input) ; cout << endl;
    Movie_Rating rating;
    while(true){
        if (input == "PG" || input == "pg"){
            rating = PG;
            break;
        } else if (input == "G" || input == "g"){
            rating = G;
            break;
        } else if (input == "PG13" || input == "pg13"){
            rating = G;
            break;
        } else if (input == "R" || input == "r"){
            rating = G;
            break;
        } else if (input == "NC17" || input == "nc17"){
            rating = G;
            break;
        } else if (input == "NR" || input == "nr"){
            rating = G;
            break
        } else {
            cout << "What is the rating of your movie?" << endl;
            getline(cin,input) ; cout << endl;
        }
    }
    myMovie.setRating(rating);
    cout << "What is the IMDB url of your movie?" << endl;
    getline(cin,input) ; cout << endl;
    myMovie.setURL(input);
}

