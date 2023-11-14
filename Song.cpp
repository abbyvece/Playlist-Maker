//
// Created by abbyv on 9/14/2023.
//

#include "Song.h"

Song::Song() : title("N/A"), artist("N/A"), songGenre(other), minutes(0), seconds(0){}

Song::Song(string title,
           string artist,
           genre songGenre,
           int minutes,
           int seconds){

    this -> title = title;
    this -> artist = artist;
    this -> songGenre = songGenre;
    this -> minutes = minutes;
    this -> seconds = seconds;
}

string Song::getTitle() const{
    return title;
}

string Song::getArtist()const{
    return artist;
}

Song::genre Song::getSongGenre()const{
    return songGenre;
}

int Song::getMinutes()const{
    return minutes;
}

int Song::getSeconds()const{
    return seconds;
}

void Song::setTitle(string newTitle) {
    title = newTitle;
}

void Song::setArtist(string newArtist) {
    artist = newArtist;
}

void Song::setSongGenre(genre newSongGenre) {
    songGenre = newSongGenre;
}

void Song::setMinutes(int newMinutes) {
    minutes = newMinutes;
}

void Song::setSeconds(int newSeconds) {
    seconds = newSeconds;
}

int Song::menu() const {
    int choice;
    bool isNumber = false;
    cout << "Please select one of the following options" << endl;
    cout << "1. Create Playlist" << endl;
    cout << "2. Add Song to Playlist" << endl;
    cout << "3. Add Podcast to Playlist" << endl;
    cout << "4. View all Playlists" << endl;
    cout << "5. View Songs in a Playlist" << endl;
    cout << "6. Quit" << endl;

    while(isNumber == false){
        cout << "Please enter your choice: ";
        cin >> choice;
        if(cin.fail()){
            cout << "That is not a valid choice"<< endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (cin.gcount() > 1){
            cout << "That is not a valid choice"<< endl;
            cin.clear();
        }else if (choice > 6 || choice < 1){
            cout << "Please enter a number between 1 and 6"<< endl;
        }else{
            isNumber = true;
        }
    }
    return choice;
}

