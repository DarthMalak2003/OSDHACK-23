#include <iostream>
#include <unistd.h> // for usleep() function
#include <cstdlib> // for system() function

void clearScreen() {
  // Function to clear console screen
  system("clear"); // Use "cls" for Windows
}

const int ANCHO = 720, ALTO = 720;
void titulo(int x, int y, char *n="    "){
  outtextxy(x,y,n);
  } 

int prueba(int x, int y)
{
  rectangle(x,y,x+70,y+20);
  
  if(mousex()>x && mousex()<x+70 && mousey()>y && mousey()<y+20 && ismouseclick(WM_LBUTTONDOWN))
    {   
	    clearmouseclick(WM_LBUTTONDOWN);
    	return 1;
	}
  else
    {
    	clearmouseclick(WM_LBUTTONDOWN);
  	    return 0;
    }     
}

void estado (int x, int y, int c1, int c2)
{
    if(mousex()>x && mousex()<x+70 && mousey()>y && mousey()<y+20 )
	{
    	setcolor(c1);
	}
	else
	{
		setcolor(c2);
	}    
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
      ┃ [ PLAY]┃
      ┃ [EJECT]┃
      ┗━━━━━━━━┛
    )",
    R"(
      ┏━━━━━━━━┓
      ┃        ┃
      ┃ [■■■■] ┃
      ┃ [■■■■] ┃
      ┃        ┃
      ┃[PAUSE] ┃
      ┃ [EJECT]┃
      ┗━━━━━━━━┛
    )",
    R"(
      ┏━━━━━━━━┓
      ┃        ┃
      ┃ [■■■■] ┃
      ┃ [■■■■] ┃
      ┃        ┃
      ┃ [STOP] ┃
      ┃ [EJECT]┃
      ┗━━━━━━━━┛
    )",
    R"(
      ┏━━━━━━━━┓
      ┃        ┃
      ┃ [■■■■] ┃
      ┃ [■■■■] ┃
      ┃        ┃
      ┃[EJECT] ┃
      ┃ [ PLAY]┃
      ┗━━━━━━━━┛
    )"
  };

  int currentFrame = 0; // current frame index

  // Loop to display the animation
  while (true) {
    clearScreen();
    std::cout << frames[currentFrame] << std::endl;
    usleep(delayMs);

    // Handle user input
    std::cout << "Enter command (1 for PLAY, 2 for EJECT): ";
    int command;
    std::cin >> command;

    // Update current frame based on user input
    switch (command) {
      case 1: // PLAY
        currentFrame = 0;
        break;
      case 2: // EJECT
        currentFrame = 3;
        break;
      default:
        // Invalid input, do nothing
        break;
    }
  }

  return 0;
}
