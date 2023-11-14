cmake_minimum_required(VERSION 3.24)
project(Playlist_Maker)

set(CMAKE_CXX_STANDARD 14)

add_executable(M2OEP_avece
        main.cpp Song.h Song.cpp Playlist.cpp Playlist.h Podcast.cpp Podcast.h)

add_executable(testing
        testing.cpp Song.h Song.cpp Playlist.cpp Playlist.h Podcast.cpp Podcast.h)
