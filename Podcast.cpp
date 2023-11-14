//
// Created by abbyv on 10/5/2023.
//

#include "Podcast.h"
Podcast::Podcast() : Song(), episodeNum(-1) {
}

Podcast::Podcast(string title,
                 string artist,
                 genre songGenre,
                 int minutes,
                 int seconds,
                 int episodeNum) : Song(title, artist, songGenre, minutes, seconds){
    this -> episodeNum = episodeNum;
}

void Podcast::setEpisdodeNum(int newEpisodeNum){
    episodeNum = newEpisodeNum;
}

int Podcast::getEpisodeNum()const{
    return  episodeNum;
}

Podcast::genre Podcast::getSongGenre() const{
    return songGenre;
}

void Podcast::setSongGenre(Podcast::genre newSongGenre){
    newSongGenre = Podcast::podcast;
}