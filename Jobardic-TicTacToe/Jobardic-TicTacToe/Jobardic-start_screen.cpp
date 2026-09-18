#include <iostream>
#include <windows.h>
#include <cstdlib>
#include "Jobardic-game_loop.h"
using namespace std;

string PlayerName = "";
bool hasName = false;
bool multiplayer = false;
void singlePlayer();
void twoPlayer();

void StartGame(bool multiplayer); void MainMenu_Screen(bool); void Guide_Screen();

/*
comments by matt: 
ATTEMPTED: Also up to you, but should MainMenu_Screen have a boolean argument which determines if setting-name part of the code runs?
Might make more sense when used by the end screen's replay game functionality.
*/

void MainMenu_Screen(bool alreadyHasName) 
{
	system("cls");

	hasName = alreadyHasName;
	cout << "Tic Tac Toe\n";
	while (!hasName)
	{
		cout << "Please enter your name: ";
		cin >> PlayerName; 
		hasName = true;
	}

	char mainMenuInput = ' ';
	cout << "Welcome, " << PlayerName << "! Type a command to continue:\n";
	cout << "=== 1 - Single Player Game\n";
	cout << "=== 2 - Multiplayer Game\n";
	cout << "=== g - Guide\n";
	cout << "=== q - Quit Game\n";
	cout << "";

	bool x = false;
	while (!x)
	{
		cin >> mainMenuInput;
		if (mainMenuInput == '1' || mainMenuInput == '2' || mainMenuInput == 'g' || mainMenuInput == 'q')
		{
			x = true;
		}
		else
		{
			cout << "Invalid input. Please enter a valid command:\n";
			cout << "=== 1 - Single Player Game\n";
			cout << "=== 2 - Multiplayer Game\n";
			cout << "=== g - Guide\n";
			cout << "=== q - Quit Game\n";
		}
	}

	switch (mainMenuInput)
	{
	case '1':
		StartGame(false);
		break;
	case '2':
		StartGame(true);
		break;
	case 'g':
		Guide_Screen();
		break;
	}
}

void Guide_Screen()
{
	system("cls");
	cout << "\nIn Tac Tac Toe, two players take turns marking spaces in a 3x3 grid, one with X and the other with O.\n";

	cout << "The game is won by marking 3 spaces in the same row, column, or diagonal. \n";
	cout << " O |   | X " << endl;
	cout << "---+---+---" << endl;
	cout << " O | X | X    <---  X wins!" << endl;
	cout << "---+---+---" << endl;
	cout << "   | O | X " << endl;

	cout << "\nYou can't mark a space that is already filled. If there are no more spaces available and no winner, the game is a draw.\n";
	cout << " X | O | O " << endl;
	cout << "---+---+---" << endl;
	cout << " O | X | X    <---  Draw" << endl;
	cout << "---+---+---" << endl;
	cout << " X | X | O " << endl;

	cout << "__________________________________________________________________________\n";

	cout << "\nTo choose which space to mark, type the number corresponding to the space according to this diagram:\n";
	cout << " 1 | 2 | 3 " << endl;
	cout << "---+---+---" << endl;
	cout << " 4 | 5 | 6 " << endl;
	cout << "---+---+---" << endl;
	cout << " 7 | 8 | 9 " << endl;

	char guideInput = ' ';
	cout << "\nEnter any character to return to the main menu: ";
	cin >> guideInput;
	cout << endl;
	MainMenu_Screen(true);
}

void StartGame(bool multiplayer)
{
	if (multiplayer) {
		XTurn = true;
		twoPlayer();
	} else {
		cout << "Enter x to play X" << endl << "Enter o to play O" << endl;
		string input;
		cin >> input;
		XTurn = true;
		if (input == "X" || input == "x") {
			playerX = true;
			singlePlayer();
		}
		else if (input == "o" || input == "O") {
			playerX = false;
			singlePlayer();
		}
	}
	//transition to the actual game, JOBARDIC-7 needs to be done
}

void QuitGame() //quits the program with a final message
{
	cout << "\nSee you next time, " << PlayerName << "!\n";
	exit(EXIT_SUCCESS);
}