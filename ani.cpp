#include <iostream>
#include <unistd.h> // for usleep() function

void clearScreen() {
  // Function to clear console screen
  std::cout << "\033[2J\033[1;1H";
}

int main() {
  const int numFrames = 4; // number of animation frames
  const int delayMs = 500000; // delay between frames in microseconds

  // Animation frames using ASCII art
  const char* frames[numFrames] = {
    R"(
      ┏━━━━━━━━┓
      ┃        ┃
      ┃ [■■■■] ┃
      ┃ [■■■■] ┃
      ┃        ┃
      ┃  PLAY  ┃
      ┃        ┃
      ┗━━━━━━━━┛
    )",
    R"(
      ┏━━━━━━━━┓
      ┃        ┃
      ┃ [■■■■] ┃
      ┃ [■■■■] ┃
      ┃        ┃
      ┃ PAUSE  ┃
      ┃        ┃
      ┗━━━━━━━━┛
    )",
    R"(
      ┏━━━━━━━━┓
      ┃        ┃
      ┃ [■■■■] ┃
      ┃ [■■■■] ┃
      ┃        ┃
      ┃ STOP   ┃
      ┃        ┃
      ┗━━━━━━━━┛
    )",
    R"(
      ┏━━━━━━━━┓
      ┃        ┃
      ┃ [■■■■] ┃
      ┃ [■■■■] ┃
      ┃        ┃
      ┃ EJECT  ┃
      ┃        ┃
      ┗━━━━━━━━┛
    )"
  };

  // Loop to display the animation
  while (true) {
    for (int i = 0; i < numFrames; i++) {
      clearScreen();
      std::cout << frames[i] << std::endl;
      usleep(delayMs);
    }
  }

  return 0;
}
