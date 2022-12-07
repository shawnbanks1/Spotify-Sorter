#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Song{
    private:
        int rank;
        string id;
        int streams;
        string name;
        string country;
        string genre;
        

    public:


        Song(){}

        Song(int rank, string id, int streams, string name, string country, string genre){
            this->rank = rank;
            this->id = id;
            this->streams = streams;
            this->name = name;
            this->country = country;
            this->genre = genre;
        }


        int getRank(){return rank;}

        string getID(){return id;}

        int getStreams(){return streams;}

        string getName(){return name;}

        string getCountry(){return country;}

        string getGenre(){return genre;}
        
};