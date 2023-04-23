//Add winmm.lib to project settings

#include<windows.h>
#include<iostream>
#include<mmsystem.h>
#include<string>
#pragma comment(lib, "winmm.lib")
using namespace std;

string arr[] = {"Pyar Hua Iqrar Hua.wav","Mere Sapno Ki Rani.wav","Lag Jaa Gale.wav","Tere Jaisa Yaar.wav","In Ankhon Ki Masti.wav","Blackmail.wav"};

void AudioLoop1()
{
	cout << "Enter 1 for Pyar Hua Iqrar Hua" << endl;
	cout << "Enter 2 for Mere Sapno Ki Rani" << endl;
	cout << "Enter 3 for Lag Jaa Gale" << endl;
	cout << "Enter 4 for Tere Jaisa Yaar" << endl;
	cout << "Enter 5 for Blackmail" << endl;
	cout << "Enter 0 for Stopping Music" << endl;
	cout << "Enter -1 to Exit" << endl;
	for(int i=0; i!=-1; i++)
	{
		int input;
		cin >> input;
		if(input==1)
		{
			cout << "Playing Music -:" << endl;
	    	PlaySound(TEXT("Pyar Hua Iqrar Hua.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		else if(input==2)
		{
			cout << "Playing Music -:" << endl;
	    	PlaySound(TEXT("Mere Sapno Ki Rani.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		else if(input==3)
		{
			cout << "Playing Music -:" << endl;
	    	PlaySound(TEXT("Lag Jaa Gale.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		else if(input==4)
		{
			cout << "Playing Music -:" << endl;
	    	PlaySound(TEXT("Tere Jaisa Yaar.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		else if(input==5)
		{
			cout << "Playing Music -:" << endl;
	    	PlaySound(TEXT("Blackmail.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		else if(input == 0)
		{
			cout << "Stopping Music -:" << endl;
			PlaySound(0,0,0);
		}
		else if(input == -1)
		{
			cout << "STOPPED" << endl;
			break;
		}
	}
}

int main()
{
    AudioLoop1();
    return 0;
}
