#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;

extern string playerName; //assumes playerName exists and is defined elsewhere before being used.

void PrintWin(); void PrintLose(); void PrintDraw(); void QuitGame();

void PrintEndScreen(string type) //PrintEndScreen("WIN") if player won, PrintEndScreen("LOSE") if player lost, PrintEndScreen("DRAW") if draw.
{
	char endscreenInput;

	//First part of end screen 
	if (type == "WIN")
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

	cout << "\nWhat's Next, " << playerName << "?\n";
	cout << "=== r - Replay Game\n";
	cout << "=== m - Return to Main Menu\n";
	cout << "=== q - Quit Game\n";
	cin >> endscreenInput;

	switch (endscreenInput)
	{
		case 'r':
			//BeginGame(); or whatever function related to JOBARDIC-7's task
			break;
		case 'm':
			//PrintTitle(); or whatever function related to JOBARDIC-7's task
			break;
		case 'q':
			QuitGame();
			break;
	}


	cout << "quit check";
}


void PrintWin() //prints the first section of the end screen with "you win" text part
{
	cout << "Debug: WIN";
}
void PrintLose() //prints the first section of the end screen with "you lose" text part
{
	cout << "Debug: LOSE";
}
void PrintDraw() //prints the first section of the end screen with "game is a draw" text part
{
	cout << "Debug: DRAW";
}
void QuitGame() //quits the program with a final message
{
	cout << "\nSee you next time, " << playerName << "!\n";
	exit(EXIT_SUCCESS);
}