//
// Created by abbyv on 9/16/2023.
//

#ifndef M1OEP_AVECE_PLAYLIST_H
#define M1OEP_AVECE_PLAYLIST_H
#include <string>
#include <iostream>
#include<limits>
#include<vector>
#include "Song.h"
using namespace std;

class Playlist{
public:
    //constructors
    Playlist();
    Playlist(string playlistName);

    //getters
    string getPlaylistName()const;

    //setters
    void setPlaylistName(string newPlaylistName);

    //functions
    // adds song to vector, returns nothing
    void addSongToPlaylist(vector<Song> &vec, const Song &newSong);

    // displays all playlist names based on how many playlists there are
    void displayAllPlaylists(Playlist &p1, Playlist &p2, Playlist &p3, Playlist &p4, Playlist &p5, int numPlaylists);

    //returns the users choice of playlists, also based on how many playlists there are
    int choosePlaylist(Playlist &p1, Playlist &p2, Playlist &p3, Playlist &p4, Playlist &p5, int numPlaylists);

    // uses the vector of songs to display a playlist
    void displaySongs(vector<Song> &vec);

    // overloaded operators
    friend ostream& operator << (ostream& outs, const Playlist& playlist){
        outs << left << setw(5) << playlist.getPlaylistName();
        return outs;
    }



private:
    string playlistName;
    int numSongs = 0;
    Song *playlistHolder;
};


#endif //M1OEP_AVECE_PLAYLIST_H
