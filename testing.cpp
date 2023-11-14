//
// Created by abbyv on 10/8/2023.
//
#include <iostream>
#include <vector>
#include "Playlist.h"
#include "Podcast.h"
#include "Song.h"
using namespace std;

bool testProject();

int main(){
    if(testProject()){
        cout << "All test cases passed" << endl;
    }
    return 0;
}

bool testProject(){
    bool passed = true;
    Playlist p1 = Playlist("playlist1");
    if(p1.getPlaylistName() != "playlist1"){
        cout << "failed playlist getPlaylistName" << endl;
        passed = false;
    }

    Song s1 = Song("Song1", "Artist1", Song::pop, 0, 0);
    if(s1.getTitle() != "Song1"){
        cout << "failed song getTitle" << endl;
        passed = false;
    }
    if(s1.getArtist() != "Artist1"){
        cout << "failed song getArtist" << endl;
        passed = false;
    }
    if(s1.getSongGenre() != Song::pop){
        cout << "failed song getSongGenre" << endl;
        passed = false;
    }

    vector<Song> playlistVector;

    p1.addSongToPlaylist(playlistVector, s1);
    if(playlistVector[0].getTitle() != "Song1"){
        cout << "failed adding song to playlist" << endl;
        passed = false;
    }

    Podcast pod1 = Podcast("Podcast1", "Artist2", Song::podcast, 0, 0, 3);
    if(pod1.getTitle() != "Podcast1"){
        cout << "failed podcast getTitle" << endl;
        passed = false;
    }
    if(pod1.getArtist() != "Artist2"){
        cout << "failed podcast getArtist" << endl;
        passed = false;
    }
    if(pod1.getSongGenre() != Podcast::podcast){
        cout << "failed podcast getsonggenre" << endl;
        passed = false;
    }
    if(pod1.getEpisodeNum() != 3){
        cout << "failed podcast getEpisodeNumber" << endl;
        passed = false;
    }

    p1.addSongToPlaylist(playlistVector, pod1);
    if(playlistVector[1].getTitle() != "Podcast1"){
        cout << "failed adding podcast to playlist" << endl;
        passed = false;
    }

    return passed;
}