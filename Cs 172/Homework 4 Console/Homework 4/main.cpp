#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Movie.h"
#include "Actor.h"
using namespace std;

bool compMov(Movie* m1,Movie* m2){
    return m1->getTitle() < m2->getTitle();
}
bool compAct(Actor* a1,Actor* a2){
    return a1->getname() < a2->getname();
}


string trim(string& str,const string& whitespace)
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content
    
    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;
    
    return str.substr(strBegin, strRange);
}
string trim(string& str)
{
    str = trim(str,"\t");
    str = trim(str,"\n");
    str = trim(str," ");
    return str;
}


Movie* checkNextForDup(vector<Movie*> mv, int & n, int & dupCt){
    if (mv[n+1] != NULL){
        bool a = mv[n]->getTitle().compare(mv[n+1]->getTitle()) == 0;
        bool b = mv[n]->getDirector().compare(mv[n+1]->getDirector()) == 0;
        bool c = mv[n]->getYear() == mv[n+1]->getYear();
        bool d = mv[n]->getRating() == mv[n+1]->getRating();
        if (a && b && c && d){
            dupCt++;
            n++;
            checkNextForDup(mv,n,dupCt);
        }
    }
    return mv[n];
}

int main() {
    vector<Movie*> movies;
    vector<Actor*> actors;
    ifstream file;
    
    file.open("CS172_Spring2014_Movie_inputs.txt");
    

    while (file.is_open()) {
        string title,director,year,rating,url,sactor;
        Movie* movie;
        Actor* actor;
        Movie_Rating r;
        
        getline(file,title);
        getline(file,director);
        getline(file,year);
        getline(file,rating);
        if (rating == "G"){ r = G;} else
        if (rating == "PG"){ r = PG;} else
        if (rating == "PG13"){ r = PG13;} else
        if (rating == "R"){ r = R;} else
        if (rating == "NC17"){ r = NC17;} else
        if (rating == "NR"){ r = NR;}
        getline(file,url);
        movie = new Movie(title, director, r, atoi(year.c_str()), url);
        getline(file,sactor);
        while (sactor.find("$$$") != 0){
            int flag = 0;
            for (int i = 0; i < actors.size(); i++){
                string name = actors[i]->getname();
                if(trim(name).find(trim(sactor)) != string::npos){
                    actors[i]->addMovie(movie);
                    movie->addActor(actors[i]);
                    flag = 1;
                }
            }
            if (flag == 0){
                actor = new Actor(sactor);
                actor->addMovie(movie);
                movie->addActor(actor);
                actors.push_back(actor);
            }
            
            getline(file,sactor);
        }
        movies.push_back(movie);
        
        if (file.eof())
          file.close();

    }
    sort(movies.begin(),movies.end(),compMov);
    sort(actors.begin(),actors.end(),compAct);
    
    cout << "There are " << movies.size() << " movies, beforehand." << endl;
    vector <Movie*> temp;
    for (int i = 0;i < movies.size();i++){
        int dupCt = 1;
        temp.push_back(checkNextForDup(movies, i,dupCt));
        if (dupCt > 1){
            cout << movies[i]->getTitle() << "had " << dupCt << " duplicates." << endl;
        }
    }
    movies = temp;
    
    cout << "There are " << movies.size() << " movies, after." << endl;
    
    string query = "";
    while(query != "q"){
        
        cout << endl;
        cout << "Would you like to do a search?" << endl;
        cout << "Search: ";
        getline(cin,query);
        
        int flag = 0;
        
        for (int i = 0;i < movies.size();i++){
            string thismovie = movies[i]->getTitle();
            if (trim(thismovie).find(trim(query)) != string::npos){
                cout << "The movie " << movies[i]->getTitle() << "features: " <<endl;
                for(int j = 0; j< movies[i]->getActors().size();j++){
                    cout << movies[i]->getActor(j)->getname() << endl;
                    flag = 1;
                }
            }
        }
        
        for (int i = 0;i < actors.size();i++){
            string thisactor = actors[i]->getname();
            //cout << trim(thisactor,"\n") << trim(query) << endl;
            if (trim(thisactor).find(trim(query)) != string::npos){
                cout << "The Actor " << actors[i]->getname() << "was in: " <<endl;
                for(int j = 0; j < actors[i]->getMovies().size();j++){
                    cout << actors[i]->getMovie(j)->getTitle() << endl;
                    flag = 1;
                }
            }
        }
        if (flag == 0){
            cout << "Sorry, no results were found." << endl;
            cout << "Try again, or quit with q" << endl;
        }
        
    }

 
}
