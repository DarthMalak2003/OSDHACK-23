#include <iostream>
#include <string>
#include <vector>
using namespace std;

class VirtualCassette {
private:
    std::string name; 
    std::vector<std::string> songs; 
    bool isPlaying; 
    int currentSongIndex; 

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
    VirtualCassette cassette("My Mixtape");

    cassette.addSong("Song 1");
    cassette.addSong("Song 2");
    cassette.addSong("Song 3");

    cassette.play();
    cassette.nextSong();
    cassette.nextSong();

    cassette.ejectCassette();

    return 0;
}
