/****************************************************
Name: [Your Name]
Date: [Date]
Problem Number: 4
Hours spent solving the problem: [Hours]
Instructor: Komogortsev, TSU
*****************************************************/

#include <iostream>
#include "tsuPod.h"
using namespace std;

int main() {
    Song tsuPod[NUM_SONGS];
    int totalMemoryUsed = 0;

    // Initialize the tsuPod
    initTsuPod(tsuPod, totalMemoryUsed);
    cout << "Initialized tsuPod:" << endl;
    showSongList(tsuPod);
    cout << endl;

    // Test successful song addition
    cout << "Adding songs..." << endl;
    addSong(tsuPod, totalMemoryUsed, "Runaway1", "Bon Jovi1", 1);
    addSong(tsuPod, totalMemoryUsed, "Runaway2", "Bon Jovi2", 2);
    addSong(tsuPod, totalMemoryUsed, "Runaway3", "Bon Jovi3", 3);
    addSong(tsuPod, totalMemoryUsed, "Runaway4", "Bon Jovi4", 1);
    addSong(tsuPod, totalMemoryUsed, "Runaway5", "Bon Jovi5", 5);
    addSong(tsuPod, totalMemoryUsed, "Runaway6", "Bon Jovi6", 6);
    addSong(tsuPod, totalMemoryUsed, "Runaway7", "Bon Jovi7", 1);
    addSong(tsuPod, totalMemoryUsed, "Runaway8", "Bon Jovi8", 1);
    showSongList(tsuPod);
    cout << endl;

    // Test unsuccessful song addition (memory limit exceeded)
    cout << "Attempting to add another song (should fail due to memory limit):" << endl;
    int retCode = addSong(tsuPod, totalMemoryUsed, "Runaway9", "Bon Jovi9", 6);
    if (retCode == -1) {
        cout << "Not enough memory to add song (Total memory: 25), occupied: "<<totalMemoryUsed << endl;
    }
    showSongList(tsuPod);
    cout << endl;

    // Test unsuccessful song addition (no empty slots)
    cout << "Attempting to add another song (should fail due to no empty slots):" << endl;
    retCode = addSong(tsuPod, totalMemoryUsed, "Runaway10", "Bon Jovi10", 1);
    if (retCode == -2) {
        cout << "No empty slots available, total slots:8" << endl;
    }
    showSongList(tsuPod);
    cout << endl;

    // Test successful song removal
    cout << "Removing song 'Runaway1':" << endl;
    retCode = removeSong(tsuPod, totalMemoryUsed, "Runaway1");
    if (retCode == 0) {
        cout << "Song 'Runaway1' removed successfully" << endl;
    }
    showSongList(tsuPod);
    cout << endl;

    // Test unsuccessful song removal (song not found)
    cout << "Attempting to remove song 'Runaway100' (should fail):" << endl;
    retCode = removeSong(tsuPod, totalMemoryUsed, "Runaway100");
    if (retCode == -1) {
        cout << "Return code: " << retCode << " (Expected: -1)" << endl;
        cout << "Song 'Runaway100' not found" << endl;
    }
    showSongList(tsuPod);
    cout << endl;

    // Test clearing the song list
    cout << "Clearing the song list:" << endl;
    clearMemory(tsuPod, totalMemoryUsed);
    showSongList(tsuPod);
    cout << endl;

    // Test shuffle functionality
    cout << "Adding songs for shuffle test..." << endl;
    addSong(tsuPod, totalMemoryUsed, "Song1", "Artist1", 1);
    addSong(tsuPod, totalMemoryUsed, "Song2", "Artist2", 2);
    addSong(tsuPod, totalMemoryUsed, "Song3", "Artist3", 3);
    cout << "Before shuffle:" << endl;
    showSongList(tsuPod);
    cout << endl;

    cout << "After shuffle:" << endl;
    shuffle(tsuPod);
    showSongList(tsuPod);
    cout << endl;

    return 0;
}
