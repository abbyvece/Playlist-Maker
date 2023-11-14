//
// Created by abbyv on 10/5/2023.
//

#ifndef M2OEP_AVECE_PODCAST_H
#define M2OEP_AVECE_PODCAST_H

#include "Song.h"

class Podcast : public Song{
public:
    Podcast();

    explicit Podcast(string title,
                     string artist,
                     genre songGenre,
                     int minutes,
                     int seconds,
                     int episodeNum);

    void setEpisdodeNum(int episodeNum);

    int getEpisodeNum() const;

    virtual genre getSongGenre() const override;

    virtual void setSongGenre(genre newSongGenre) override;

    //overloaded print
    // overloaded operators

    friend ostream& operator << (ostream& outs, const Podcast& podcast){
        outs << left << setw(5) << podcast.getTitle() << "-episode #" << podcast.getEpisodeNum() << endl;
        return outs;
    }

protected:
    int episodeNum;

};

#endif //M2OEP_AVECE_PODCAST_H
