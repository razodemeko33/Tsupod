/****************************************************
Name: [Your Name]
Date: [Date]
Problem Number: 4
Hours spent solving the problem: [Hours]
Instructor: Komogortsev, TSU
*****************************************************/

#ifndef tsuPod_h
#define tsuPod_h

#include <string>
using namespace std;

const int NUM_SONGS = 8; // Maximum number of songs
const int MEMORY_SIZE = 25; // Total memory size in MB

struct Song {
    string title;
    string artist;
    int size;
};

// Function prototypes
void initTsuPod(Song tsuPod[], int &totalMemoryUsed);
int addSong(Song tsuPod[], int &totalMemoryUsed, string newTitle, string newArtist, int size);
int removeSong(Song tsuPod[], int &totalMemoryUsed, string title);
void clearMemory(Song tsuPod[], int &totalMemoryUsed);
void showSongList(Song tsuPod[]);
void shuffle(Song tsuPod[]);

#endif
