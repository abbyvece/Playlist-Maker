//
// Created by abbyv on 9/12/2023.
//
#include <iostream>
#include <fstream>
#include "Song.h"
#include "Playlist.h"
#include "Podcast.h"
using namespace std;

// Makes a song object
Song makeSongObject();
Podcast makePodcastObject();


int main(){
    int numPlaylists = 0;
    Song s("red", "taylor swift", Song::pop , 4, 20);
    Playlist playlist1, playlist2, playlist3, playlist4, playlist5, p;
    vector <Song> p1, p2, p3, p4, p5;
    int choice = s.menu();

    // does things based on user choice
    while(choice != 6){
        if(choice == 1){
            string newPlaylistName;
            if(numPlaylists == 0){
                numPlaylists++;
                cout << "What would you like to name this playlist?" << endl;
                cout << " >>>";
                getline(cin,newPlaylistName);
                playlist1.setPlaylistName(newPlaylistName);
            }else if(numPlaylists == 1){
                numPlaylists++;
                cout << "What would you like to name this playlist?" << endl;
                cout << " >>>";
                getline(cin,newPlaylistName);
                playlist2.setPlaylistName(newPlaylistName);
            }else if(numPlaylists == 2){
                numPlaylists++;
                cout << "What would you like to name this playlist?" << endl;
                cout << " >>>";
                getline(cin,newPlaylistName);
                playlist3.setPlaylistName(newPlaylistName);
            }else if(numPlaylists == 3){
                numPlaylists++;
                cout << "What would you like to name this playlist?" << endl;
                cout << " >>>";
                getline(cin,newPlaylistName);
                playlist4.setPlaylistName(newPlaylistName);
            }else if(numPlaylists == 4){
                numPlaylists++;
                cout << "What would you like to name this playlist?" << endl;
                cout << " >>>";
                getline(cin,newPlaylistName);
                playlist5.setPlaylistName(newPlaylistName);
            }else{
                cout << "The max number of playlists is 5" << endl;
            }


        }else if(choice == 2){
            if(numPlaylists == 0){
                cout << "You have no playlists" << endl;
            }else{
                Song newSong = makeSongObject();
                int playlistChoice = p.choosePlaylist(playlist1, playlist2, playlist3, playlist4, playlist5, numPlaylists);
                if(playlistChoice == 1){
                    playlist1.addSongToPlaylist(p1, newSong);
                }else if(playlistChoice ==2){
                    playlist2.addSongToPlaylist(p2, newSong);
                }else if(playlistChoice ==3){
                    playlist3.addSongToPlaylist(p3, newSong);
                }else if(playlistChoice ==4){
                    playlist4.addSongToPlaylist(p4, newSong);
                }else if(playlistChoice ==5){
                    playlist5.addSongToPlaylist(p5, newSong);
                }
            }
        }else if (choice == 3){
            if(numPlaylists == 0){
                cout << "You have no playlists" << endl;
            }else{
                Podcast newPodcast = makePodcastObject();
                int playlistChoice = p.choosePlaylist(playlist1, playlist2, playlist3, playlist4, playlist5, numPlaylists);
                cout << "we got here" << endl;
                if(playlistChoice == 1){
                    playlist1.addSongToPlaylist(p1, newPodcast);
                }else if(playlistChoice ==2){
                    playlist2.addSongToPlaylist(p2, newPodcast);
                }else if(playlistChoice ==3){
                    playlist3.addSongToPlaylist(p3, newPodcast);
                }else if(playlistChoice ==4){
                    playlist4.addSongToPlaylist(p4, newPodcast);
                }else if(playlistChoice ==5){
                    playlist5.addSongToPlaylist(p5, newPodcast);
                }
            }
        }else if(choice == 4){
            if(numPlaylists == 0){
                cout << "You don't have any playlists" << endl;
            }else{
                p.displayAllPlaylists(playlist1, playlist2, playlist3, playlist4, playlist5, numPlaylists);
            }
        }else if(choice == 5){
            if(numPlaylists == 0){
                cout << "You don't have any playlists" << endl;
            }else {
                int playlistChoice = p.choosePlaylist(playlist1, playlist2, playlist3, playlist4, playlist5, numPlaylists);
                if(playlistChoice == 1){
                    playlist1.displaySongs(p1);
                }else if(playlistChoice ==2){
                    playlist2.displaySongs(p2);
                }else if(playlistChoice ==3){
                    playlist3.displaySongs(p3);
                }else if(playlistChoice ==4){
                    playlist4.displaySongs(p4);
                }else if(playlistChoice ==5){
                    playlist5.displaySongs(p5);
                }
            }
        }
        choice = s.menu();
    }

    ofstream outFile1;
    outFile1.open("../playlist1.txt");
    ofstream outFile2;
    outFile2.open("../playlist2.txt");
    ofstream outFile3;
    outFile3.open("../playlist3.txt");
    ofstream outFile4;
    outFile4.open("../playlist4.txt");
    ofstream outFile5;
    outFile5.open("../playlist5.txt");

    outFile1 << playlist1.getPlaylistName() << endl;
    for(int i = 0; i < p1.size(); i++){
        outFile1 << i + 1 << ". " << p1[i].getTitle() << endl;
    }
    outFile1.close();

    outFile2 << playlist2.getPlaylistName() << endl;
    for(int i = 0; i < p2.size(); i++){
        outFile2 << i + 1 << ". " << p2[i].getTitle() << endl;
    }
    outFile2.close();

    outFile3 << playlist3.getPlaylistName() << endl;
    for(int i = 0; i < p3.size(); i++){
        outFile3 << i + 1 << ". " << p3[i].getTitle() << endl;
    }
    outFile3.close();

    outFile4 << playlist4.getPlaylistName() << endl;
    for(int i = 0; i < p4.size(); i++){
        outFile4 << i + 1 << ". " << p4[i].getTitle() << endl;
    }
    outFile4.close();

    outFile5 << playlist5.getPlaylistName() << endl;
    for(int i = 0; i < p5.size(); i++){
        outFile5 << i + 1 << ". " << p5[i].getTitle() << endl;
    }
    outFile5.close();

    cout << "Thanks for using the program" << endl;
};

Song makeSongObject(){
    int choice;
    string title, artist;
    bool isNumber = false;
    Song::genre songGenre;

    cout << "Enter song title: ";
    getline(cin, title);
    cout << "Enter song artist: ";
    getline(cin, artist);

    cout << "What is the genre (choose number 1-5)" << endl;
    cout << "1. Pop" << endl;
    cout << "2. Rap" << endl;
    cout << "3. Rock" << endl;
    cout << "4. Country" << endl;
    cout << "5. Other" << endl;
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
    switch(choice){
        case 1:
            songGenre = Song::pop;
            break;
        case 2:
            songGenre = Song::rap;
            break;
        case 3:
            songGenre = Song::rock;
            break;
        case 4:
            songGenre = Song::country;
            break;
        case 5:
            songGenre = Song::other;
    }
    Song newSong(title, artist, songGenre, 0,0 );
    return newSong;
}

Podcast makePodcastObject(){
    int choice;
    string title, artist;
    bool isNumber = false;
    Song::genre songGenre;
    int episodeNum;

    cout << "Enter podcast title: ";
    getline(cin, title);

    while(isNumber == false){
        cout << "Enter episode Number :";
        cin >> episodeNum;
        if(cin.fail()){
            cout << "That is not a valid choice"<< endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (cin.gcount() > 1) {
            cout << "That is not a valid choice" << endl;
            cin.clear();
        }else{
            isNumber = true;
        }
    }
    cout << "Enter podcast4 artist: ";
    getline(cin, artist);
    songGenre = Song::podcast;

    Podcast newPodcast(title, artist, songGenre, 0, 0, episodeNum);
    return newPodcast;
}