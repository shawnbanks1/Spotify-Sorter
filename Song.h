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
        int date;

    public:


        Song(){}

        Song(int rank, string id, int streams, string name, string country, string genre, string fDate){
            this->rank = rank;
            this->id = id;
            this->streams = streams;
            this->name = name;
            this->country = country;
            this->genre = genre;
            if(fDate.find('/') == string::npos){
                //this->date = (stoi(fDate)-1)*372;
            }
            else{
                istringstream SS(fDate);
                int month;
                int day;
                int year;
                string tmp;
                getline(SS,tmp,'/');
                month = stoi(tmp);
                getline(SS,tmp,'/');
                day = stoi(tmp);
                getline(SS,tmp);
                year = stoi(tmp);
                this->date = (month-1)*31 + day + (year-1)*372;
            }
        }


        int getRank(){return rank;}

        string getID(){return id;}

        int getStreams(){return streams;}

        string getName(){return name;}

        string getCountry(){return country;}

        string getGenre(){return genre;}

        int getDate(){return date;}

        string getDateF(){
            int tmp = date;
            int year = (tmp / 372) + 1;
            tmp%=372;
            int month = (tmp / 31) + 1;
            int day = tmp % 31;

            return to_string(month) + "/" + to_string(day) + "/" + to_string(year);

        }
        
};