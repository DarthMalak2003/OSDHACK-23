#include <iostream>
#include<windows.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

// Constants
const int NUM_CASSETTES = 5;
const int MAX_ROTATION_ANGLE = 360;
const int ROTATION_SPEED = 5;
const int NUM_FRAMES = 10;
const char CASSETTE_CHAR = 'C';
const char PLAYER_CHAR = 'P';
const char EMPTY_CHAR = ' ';

// Function to generate random cassette positions
void generateCassettePositions(int cassettePositions[], int maxPosition) {
    srand(time(0));  // Seed the random number generator with current time

    for (int i = 0; i < NUM_CASSETTES; i++) {
        cassettePositions[i] = rand() % maxPosition + 1;
    }
}

// Function to display the cassette player and cassettes
void displayCassettePlayer(int cassettePositions[], int playerPosition) {
    for (int i = 0; i < NUM_FRAMES; i++) {
        system("CLS");  // Clear the terminal screen

        // Display the cassette player
        cout << "  " << string(MAX_ROTATION_ANGLE, '-') << "  " << endl;
        cout << " | " << string(MAX_ROTATION_ANGLE - playerPosition, EMPTY_CHAR)
             << PLAYER_CHAR << string(playerPosition, EMPTY_CHAR) << " | " << endl;
        cout << "  " << string(MAX_ROTATION_ANGLE, '-') << "  " << endl;

        // Display the cassettes
        for (int j = 0; j < NUM_CASSETTES; j++) {
            cout << " | " << string(cassettePositions[j], EMPTY_CHAR)
                 << CASSETTE_CHAR << string(MAX_ROTATION_ANGLE - cassettePositions[j], EMPTY_CHAR) << " | " << endl;
        }

        usleep(100000);  // Pause for 100 milliseconds (0.1 seconds)
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int cassettePositions[NUM_CASSETTES];  // Array to store cassette positions
    int playerPosition = 0;  // Initial position of the cassette player

    generateCassettePositions(cassettePositions, MAX_ROTATION_ANGLE);  // Generate random cassette positions

    while (true) {
        displayCassettePlayer(cassettePositions, playerPosition);  // Display cassette player and cassettes
        playerPosition = (playerPosition + ROTATION_SPEED) % MAX_ROTATION_ANGLE;  // Update player position

        // Update cassette positions randomly
        for (int i = 0; i < NUM_CASSETTES; i++) {
            if (rand() % 2 == 0) {
                cassettePositions[i] = (cassettePositions[i] + ROTATION_SPEED) % MAX_ROTATION_ANGLE;
            } else {
                cassettePositions[i] = (cassettePositions[i] - ROTATION_SPEED + MAX_ROTATION_ANGLE) % MAX_ROTATION_ANGLE;
            }
        }
    }

    return 0;
}

