#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;

string PlayerName = "asdfasdfasdf"; // weird default but figured it could be used to check if they already put their name

bool multiplayer = false;

/*
comments by matt: 
perhaps could have the player enter "sp" and "mp" for singleplayer and multiplayer if thats better ?
Also up to you, but should MainMenu_Screen have a boolean argument which determines if setting-name part of the code runs?
Might make more sense when used by the end screen's replay game functionality.
Would also just make the default name "Player"
Also i believe the "start game" function itself would be what Joseph defines for JOBARDIC-7 task
*/

void MainMenu_Screen() 
{
	cout << "Tic Tac Toe\n";
	while (PlayerName == "asdfasdfasdf")
	{
		cout << "Please enter your name: ";
		cin >> PlayerName; 
	}

	char mainMenuInput;
	cout << "Welcome, " << PlayerName << "! Type a command to continue:\n";
	cout << "=== s - Single Player Game\n";
	cout << "=== m - Multiplayer Game\n"; // maybe this should be a different letter since m is used for main menu?
	cout << "=== g - Guide\n";
	cin >> mainMenuInput;
	switch (mainMenuInput)
	{
	case 's':
		StartGame(false);
		break;
	case 'm':
		StartGame(true);
		break;
	case 'g':
		Guide_Screen();
		break;
	}
}

void Guide_Screen()
{

}

void StartGame(bool multiplayer)
{
	//transition to the actual game
}

/*void SetPlayerName(string name)
{
	PlayerName = name;
}*/