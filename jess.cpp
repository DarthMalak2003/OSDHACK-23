#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class to represent a virtual cassette
class VirtualCassette {
private:
    std::string name; // Name of the cassette
    std::vector<std::string> songs; // List of songs in the cassette
    bool isPlaying; // Whether the cassette is currently playing
    int currentSongIndex; // Index of the currently playing song

public:
    VirtualCassette(const std::string& cassetteName) {
        name = cassetteName;
        isPlaying = false;
        currentSongIndex = 0;
    }

    void addSong(const std::string& songName) {
        songs.push_back(songName);
    }

    void play() {
        if (songs.empty()) {
            std::cout << "No songs loaded in the cassette." << std::endl;
        } else if (isPlaying) {
            std::cout << "Cassette \"" << name << "\" is already playing." << std::endl;
        } else {
            std::cout << "Playing cassette \"" << name << "\"." << std::endl;
            isPlaying = true;
        }
    }

    void stop() {
        if (songs.empty()) {
            std::cout << "No songs loaded in the cassette." << std::endl;
        } else if (!isPlaying) {
            std::cout << "Cassette \"" << name << "\" is not currently playing." << std::endl;
        } else {
            std::cout << "Stopped cassette \"" << name << "\"." << std::endl;
            isPlaying = false;
        }
    }

    void nextSong() {
        if (songs.empty()) {
            std::cout << "No songs loaded in the cassette." << std::endl;
        } else if (!isPlaying) {
            std::cout << "Cassette \"" << name << "\" is not currently playing." << std::endl;
        } else {
            currentSongIndex = (currentSongIndex + 1) % songs.size();
            std::cout << "Playing next song: \"" << songs[currentSongIndex] << "\"." << std::endl;
        }
    }

    void ejectCassette() {
        if (songs.empty()) {
            std::cout << "No songs loaded in the cassette." << std::endl;
        } else {
            stop();
            std::cout << "Ejecting cassette \"" << name << "\"." << std::endl;
            songs.clear();
            currentSongIndex = 0;
        }
    }
};

int main() {
    // Create a virtual cassette
    VirtualCassette cassette("My Mixtape");

    // Load songs into the cassette
    cassette.addSong("Song 1");
    cassette.addSong("Song 2");
    cassette.addSong("Song 3");

    // Play songs
    cassette.play();
    cassette.nextSong();
    cassette.nextSong();

    // Eject the cassette
    cassette.ejectCassette();

    return 0;
}
