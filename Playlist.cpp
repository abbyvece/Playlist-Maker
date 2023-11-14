//
// Created by abbyv on 9/16/2023.
//

#include "Playlist.h"
 Playlist::Playlist() : playlistName("playlist"){
    playlistHolder = new Song[100];
}

 Playlist::Playlist(string playlistName){
    this -> playlistName = playlistName;
}

string Playlist::getPlaylistName() const {
    return playlistName;
}

void Playlist::setPlaylistName(string newPlaylistName) {
    playlistName = newPlaylistName;
}

void Playlist::addSongToPlaylist(vector<Song> &vec, const Song &newSong) {
    numSongs ++;
    vec.push_back(newSong);
}

void Playlist::displayAllPlaylists(Playlist &p1, Playlist &p2, Playlist &p3, Playlist &p4, Playlist &p5, int numPlaylists) {
    // there is definitly an easier way to do this, however i dont know it
    if(numPlaylists == 5){
        cout << "1. " << p1 << endl;
        cout << "2. " << p2 << endl;
        cout << "3. " << p3 << endl;
        cout << "4. " << p4 << endl;
        cout << "5. " << p5 << endl;
    }else if(numPlaylists == 4){
        cout << "1. " << p1 << endl;
        cout << "2. " << p2 << endl;
        cout << "3. " << p3 << endl;
        cout << "4. " << p4 << endl;
    }else if(numPlaylists == 3){
        cout << "1. " << p1 << endl;
        cout << "2. " << p2 << endl;
        cout << "3. " << p3 << endl;
    }else if(numPlaylists == 2){
        cout << "1. " << p1 << endl;
        cout << "2. " << p2 << endl;
    }else if (numPlaylists == 1){
        cout << "1. " << p1.getPlaylistName() << endl;
    }
}

int Playlist::choosePlaylist(Playlist &p1, Playlist &p2, Playlist &p3, Playlist &p4, Playlist &p5, int numPlaylists) {
    int choice;
    bool isNumber = false;
    cout << "What Playlist would you like to pick?" << endl;
    displayAllPlaylists( p1,  p2,  p3,  p4,  p5, numPlaylists);
    // input validation
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
        }else if (choice > 5 || choice < 1){
            cout << "Please enter a number between 1 and 5"<< endl;
        }else{
            isNumber = true;
        }
    }
    return choice;
}

void Playlist::displaySongs(vector<Song> &vec) {
    for(int i=0; i < vec.size(); i++){
        cout << i+1 << ". " << vec[i] << endl;
    }
}