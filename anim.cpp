#include <ncurses.h>
#include <iostream>
using namespace std;

void drawCassettePlayer() {
  // Draw the cassette player using ASCII art
  mvprintw(0, 0, "┏━━━━━━━━┓");
  mvprintw(1, 0, "┃        ┃");
  mvprintw(2, 0, "┃ [■■■■] ┃");
  mvprintw(3, 0, "┃ [■■■■] ┃");
  mvprintw(4, 0, "┃        ┃");
  mvprintw(5, 0, "┃ [ PLAY]┃");
  mvprintw(6, 0, "┃ [EJECT]┃");
  mvprintw(7, 0, "┗━━━━━━━━┛");
  refresh();
}

void handlePlayButton() {
  // Handle play button click event
  mvprintw(5, 2, "Play button clicked!");
  refresh();
  // Add your play logic here
}

void handleEjectButton() {
  // Handle eject button click event
  mvprintw(6, 2, "Eject button clicked!");
  refresh();
  // Add your eject logic here
}

int main() {
  // Initialize ncurses
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);

  int ch;
  bool playButtonSelected = false;
  bool ejectButtonSelected = false;

  while ((ch = getch()) != 'q') {
    clear();
    drawCassettePlayer();

    // Highlight the currently selected button
    if (playButtonSelected) {
      attron(A_REVERSE);
      mvprintw(5, 2, " PLAY ");
      attroff(A_REVERSE);
    } else {
      mvprintw(5, 2, " PLAY ");
    }

    if (ejectButtonSelected) {
      attron(A_REVERSE);
      mvprintw(6, 2, " EJECT ");
      attroff(A_REVERSE);
    } else {
      mvprintw(6, 2, " EJECT ");
    }

    // Handle user input
    switch (ch) {
      case KEY_UP:
        playButtonSelected = true;
        ejectButtonSelected = false;
        break;
      case KEY_DOWN:
        ejectButtonSelected = true;
        playButtonSelected = false;
        break;
      case '\n':
        if (playButtonSelected) {
          handlePlayButton();
        } else if (ejectButtonSelected) {
          handleEjectButton();
        }
        break;
      default:
        break;
    }
  }

  // End ncurses
  endwin();

  return 0;
}
