#include <iostream>
#include <windows.h>
#include <cstdlib>
#include "Jobardic-game_loop.h"
using namespace std;

extern string PlayerName; //assumes playerName exists and is defined elsewhere before being used.
extern bool multiplayer;

void PrintWin(); void PrintLose(); void PrintDraw(); void PrintPlayerWin(string player);
extern void StartGame(bool multiplayer); extern void MainMenu_Screen(bool); extern void QuitGame();
void PrintEndScreen(string type) //PrintEndScreen("X") if player X won, PrintEndScreen("O") if player O won, PrintEndScreen("DRAW") if draw, PrintEndScreen("WIN") if singleplayer & player won, PrintEndScreen("LOSE") if singleplayer & player lost.
{
	char endscreenInput;

	//First part of end screen 
	if (multiplayer)
	{
		if (type == "X" || type == "O") {
			PrintPlayerWin(type);
		}
		else {
			PrintDraw();
		}
	}
	else if (type == "WIN")
	{
		PrintWin();
	}
	else if (type == "LOSE")
	{
		PrintLose();
	}
	else if (type == "DRAW")
	{
		PrintDraw();
	}
	else {
		cout << "\n\n!!!!PrintEndScreen() Error: Invalid Screen Type!!!!\n!!!!Valid End Screens: 'WIN','LOSE','DRAW'!!!!";
		return;
	}

	
	//Second part of end screen: where the user is prompted for a further action

	cout << "\nWhat's Next?\n";
	cout << "=== r - Replay Game\n";
	cout << "=== m - Return to Main Menu\n";
	cout << "=== q - Quit Game\n";
	cin >> endscreenInput;

	switch (endscreenInput)
	{
		case 'r':
			//function related to JOBARDIC-7's task: StartGame()

			if (multiplayer) StartGame(true);
			else StartGame(false);

			break;

		case 'm':
			//function related to JOBARDIC-8's task
			MainMenu_Screen(true);
			break;

		case 'q':
			QuitGame();
			break;
	}
}


void PrintWin() //prints the first section of the end screen with "you win" text part
{
	cout << "<---------------->" << endl;
	cout << "!!!! YOU WON !!!!" << endl;
	//+ stats related to game?
	cout << "<---------------->" << endl;
}
void PrintLose() //prints the first section of the end screen with "you lose" text part
{
	cout << "<---------------->" << endl;
	cout << ".... YOU LOSE ...." << endl;
	//+ stats related to game?
	cout << "<---------------->" << endl;
}
void PrintDraw() //prints the first section of the end screen with "game is a draw" text part
{
	cout << "<------------------------>" << endl;
	cout << "  - - GAME IS A DRAW - -  " << endl;
	//+ stats related to game?
	cout << "<------------------------>" << endl;
}

void PrintPlayerWin(string player)
{
	cout << "<---------------->" << endl;
	cout << "!!!! " << player << " WON !!!!" << endl;
	cout << "<---------------->" << endl;
}

/*void QuitGame() //quits the program with a final message     
{
	cout << "\nSee you next time, " << PlayerName << "!\n";
	exit(EXIT_SUCCESS);
}*/