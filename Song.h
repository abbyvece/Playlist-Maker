//
// Created by abbyv on 9/14/2023.
//

#ifndef M1OEP_AVECE_SONG_H
#define M1OEP_AVECE_SONG_H
#include <string>
#include <iostream>
#include <iomanip>
#include<limits>
#include<vector>
using namespace std;

class Song{

public:
    // enum genre for users to pick a song genre
    enum genre{
        pop,
        rap,
        rock,
        country,
        other,
        podcast
    };

    // default constructor
    Song();

    //constructor
    Song(string title,
    string artist,
    genre songGenre,
    int minutes,
    int seconds);

    // getters
    string getTitle()const;
    string getArtist()const;
    virtual genre getSongGenre()const;
    int getMinutes()const;
    int getSeconds()const;

    // setters
    void setTitle(string newTitle);
    void setArtist(string newArtist);
    virtual void setSongGenre(genre newSongGenre);
    void setMinutes(int newMinutes);
    void setSeconds(int newSeconds);

    //functions
    int menu()const; // gives user a list of things they can do and returns their choice

    //overloaded print
    // overloaded operators
    friend ostream& operator << (ostream& outs, const Song& song){
        outs << left << setw(5) << song.getTitle();
        return outs;
    }


protected:
    string title;
    string artist;
    genre songGenre;
    int minutes;
    int seconds;

};

#endif //M1OEP_AVECE_SONG_H
