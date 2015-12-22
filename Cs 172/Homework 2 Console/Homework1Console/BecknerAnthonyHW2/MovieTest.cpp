//
//  main.cpp
//  Homework1Console
//
//  Created by Anthony John Beckner on 7/14/15.
//  Copyright (c) 2015 ajbecknerapps. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Movie.h"

using namespace std;

int main() {
    
    string line;
    ifstream fin;
    fin.open("/Homework1Console/Movie_setup_ajb392.txt");
    
    vector<Movie> myMovies;
    if (fin.is_open()){
        while (!fin.eof()){
            Movie myMovie;
            getline(fin,line);
            myMovie = Movie(line);
            getline(fin,line);
            myMovie.setDirector(line);
            getline(fin,line);
            myMovie.setYear(atoi(line.c_str()));
            getline(fin,line);
            Movie_Rating rating;
            while(true){
                if (line == "PG" || line == "pg"){
                    rating = PG;
                    break;
                } else if (line == "G" || line == "g"){
                    rating = G;
                    break;
                } else if (line == "PG13" || line == "pg13"){
                    rating = G;
                    break;
                } else if (line == "R" || line == "r"){
                    rating = G;
                    break;
                } else if (line == "NC17" || line == "nc17"){
                    rating = G;
                    break;
                } else if (line == "NR" || line == "nr"){
                    rating = G;
                    break;
                }
            }
            myMovie.setRating(rating);
            getline(fin,line);
            myMovie.setURL(line);
            do {
                getline(fin,line);
                myMovie.addActor(line);
            } while (line != "$$$$" );
            myMovies.pop_back();
            myMovies[myMovies.size()-1] = myMovie;
        }
        fin.close();
        
    } else{
        cout << "Unable to open file" << endl;
    }
    for (int i = 0; 1 < myMovies.size(); i++){
        myMovies[i].output(cout);
    }
        
    
    return 0;
}

