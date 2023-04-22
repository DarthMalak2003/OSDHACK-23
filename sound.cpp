//Add winmm.lib to project settings

#include<windows.h>
#include<iostream>
#include<mmsystem.h>
#include<string>

#pragma comment(lib, "winmm.lib")

using namespace std;

int main()
{
    cout << "Playing Music -:" << endl;
    PlaySound(TEXT("G:\\GitHub\\OSDHACK-23\\Pyar Hua Iqrar Hua.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    string input;
    getline(cin, input);
    PlaySound(0,0,0);
    cout << "Stopped Music" << endl;

    getline(cin, input);
    cout << "Playing Music" << endl;
    PlaySound(TEXT("G:\\GitHub\\OSDHACK-23\\Pyar Hua Iqrar Hua.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    getline(cin, input);
    return 0;
}