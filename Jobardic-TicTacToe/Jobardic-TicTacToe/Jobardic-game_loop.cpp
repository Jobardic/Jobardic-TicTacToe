#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

using namespace std;


extern void PrintEndScreen(string type);
extern bool multiplayer;
//int board[9] = { 0,0,0,0,0,0,0,0,0 }; //the board as an array, 0 for empty, 1 for X, 2 for O
bool XTurn = false;
bool playerX = false;

void twoPlayer();
void singlePlayer();

class TicTacToe {

private: int slots[9];

    public:

	TicTacToe() {
        resetBoard();
	}

    void resetBoard()
    {
        for (int i = 0; i < 9; i++) {
            slots[i] = 0;
        }
    }

	void setSlot(int slot, int value) {
		if (slot >= 1 && slot <= 9) {
			slots[slot - 1] = value;
		}
	}

    //Returns the value of a slot
    //0=empty
	//1=X
	//2=O

    int getSlot(int slot) {
		if (slot >= 1 && slot <= 9) {
			return slots[slot - 1];
		}
		return -1;
    }

    void printBoard() {
        cout << endl;
        
        //Prints slots array for debugging purposes
        /*for (int k = 0; k < 9; k++)
        {
            cout << slots[k];
        }
        cout << endl;*/

		for (int i = 0; i < 9; i++) {
			char symbol = ' ';

			if (slots[i] == 1) {
				symbol = 'X';
			}
			else if (slots[i] == 2) {
				symbol = 'O';
			}
			cout <<" "<< symbol << " ";
            if (i % 3 != 2) {
				cout << "|";

            }
            if (i == 2 || i == 5) {
                cout << endl;
                cout << "---+---+---";
                cout << endl; //
            }
            if (i == 8)
            {
                cout << endl;
            }
            //cout << endl;
		}
    }
};

TicTacToe ticTacToeBoard;


void playerTurn(int s) { //takes the player input and sees if it's taken or not
    while (true) {
        cout << "======Choose your next slot======" << endl;
        int input;
        while (!(cin >> input) || input < 0 || input > 9) { //while loop keeps going until a valid character (1-9) is input
            string garbage;
            cin.clear();
            getline(cin, garbage);
            cout << "Invalid input, try again:" << endl;
        }
        if (ticTacToeBoard.getSlot(input) == 0) { //if it's free, replace it
            ticTacToeBoard.setSlot(input, s);
            break;
        }
        else { //if it's not, loop back
            cout << "Spot is taken!" << endl;
        }
    }
}

void botTurn(int s) { //randomly generates a number to put
    while (true) {
        int ran = rand() % 9;
        //cout << ran << " " << s << endl;
        if (ticTacToeBoard.getSlot(ran+1) == 0) {
            ticTacToeBoard.setSlot(ran+1, s);
            break;
        }
    }
}

int checkWin() { //if statement has all the possible win permutations to check if they are occupied by X or O
    if ((ticTacToeBoard.getSlot(0 + 1) == 1 && ticTacToeBoard.getSlot(1 + 1) == 1 && ticTacToeBoard.getSlot(2 + 1) == 1) || (ticTacToeBoard.getSlot(3 + 1) == 1 && ticTacToeBoard.getSlot(4 + 1) == 1 && ticTacToeBoard.getSlot(5 + 1) == 1) || (ticTacToeBoard.getSlot(6 + 1) == 1 && ticTacToeBoard.getSlot(7 + 1) == 1 && ticTacToeBoard.getSlot(8 + 1) == 1) || (ticTacToeBoard.getSlot(0 + 1) == 1 && ticTacToeBoard.getSlot(3 + 1) == 1 && ticTacToeBoard.getSlot(6 + 1) == 1) || (ticTacToeBoard.getSlot(1 + 1) == 1 && ticTacToeBoard.getSlot(4 + 1) == 1 && ticTacToeBoard.getSlot(7 + 1) == 1) || (ticTacToeBoard.getSlot(2 + 1) == 1 && ticTacToeBoard.getSlot(5 + 1) == 1 && ticTacToeBoard.getSlot(8 + 1) == 1) || (ticTacToeBoard.getSlot(0 + 1) == 1 && ticTacToeBoard.getSlot(4 + 1) == 1 && ticTacToeBoard.getSlot(8 + 1) == 1) || (ticTacToeBoard.getSlot(2 + 1) == 1 && ticTacToeBoard.getSlot(4 + 1) == 1 && ticTacToeBoard.getSlot(6 + 1) == 1)) {
        //X win
        return 1;
    }
    else if ((ticTacToeBoard.getSlot(0 + 1) == 2 && ticTacToeBoard.getSlot(1 + 1) == 2 && ticTacToeBoard.getSlot(2 + 1) == 2) || (ticTacToeBoard.getSlot(3 + 1) == 2 && ticTacToeBoard.getSlot(4 + 1) == 2 && ticTacToeBoard.getSlot(5 + 1) == 2) || (ticTacToeBoard.getSlot(6 + 1) == 2 && ticTacToeBoard.getSlot(7 + 1) == 2 && ticTacToeBoard.getSlot(8 + 1) == 2) || (ticTacToeBoard.getSlot(0 + 1) == 2 && ticTacToeBoard.getSlot(3 + 1) == 2 && ticTacToeBoard.getSlot(6 + 1) == 2) || (ticTacToeBoard.getSlot(1 + 1) == 2 && ticTacToeBoard.getSlot(4 + 1) == 2 && ticTacToeBoard.getSlot(7 + 1) == 2) || (ticTacToeBoard.getSlot(2 + 1) == 2 && ticTacToeBoard.getSlot(5 + 1) == 2 && ticTacToeBoard.getSlot(8 + 1) == 2) || (ticTacToeBoard.getSlot(0 + 1) == 2 && ticTacToeBoard.getSlot(4 + 1) == 2 && ticTacToeBoard.getSlot(8 + 1) == 2) || (ticTacToeBoard.getSlot(2 + 1) == 2 && ticTacToeBoard.getSlot(4 + 1) == 2 && ticTacToeBoard.getSlot(6 + 1) == 2)) {
        //O win
        return 2;
    }
    return 0;
}

void singlePlayer() {
    system("cls");
    ticTacToeBoard.resetBoard();
    int win = 0;

    for (int j = 0; j < 9; j++) { //resets the board
        ticTacToeBoard.setSlot(j + 1, 0);
    }
    ticTacToeBoard.printBoard();

    //PRINT BOARD HERE: FOR JOBARDIC-10

    for (int i = 0; i < 9; i++) { //9 times because that's how many possible turns there are
        /*for (int j = 0; j < 9; j++) {
            cout << board[j] << ", ";
        }
        cout << endl;*/
        if (XTurn) { //sorts who's to go based on whose turn it is and if they are X
            if (playerX) {
                playerTurn(1);
            }
            else {
                botTurn(1);
            }
            XTurn = false;
        }
        else if (!XTurn) {
            if (playerX) {
                botTurn(2);
            }
            else {
                playerTurn(2);
            }
            XTurn = true;
        }
        system("cls");

        ticTacToeBoard.printBoard();

        //PRINT BOARD HERE: FOR JOBARDIC-10

        win = checkWin(); //checks win
        if (win == 1) {
            if (playerX) {
                PrintEndScreen("WIN");
            } else {
                PrintEndScreen("LOSE");
            }
            break;
        }
        else if (win == 2) { //pretty straightforward
            if (!playerX) {
                PrintEndScreen("WIN");
            } else {
                PrintEndScreen("LOSE");
            }
            break;
        }
        if (i >= 8) {
            PrintEndScreen("DRAW");
        }
    }
}

void twoPlayer() { //same as singleplayer but there's no bot turn
    system("cls");

    ticTacToeBoard.resetBoard();

    for (int j = 0; j < 9; j++) {
        ticTacToeBoard.setSlot(j + 1, 0);
    }
    ticTacToeBoard.printBoard();

    //PRINT BOARD HERE: FOR JOBARDIC-10

    for (int i = 0; i < 9; i++) {
        if (XTurn) {
            playerTurn(1);
            XTurn = false;
        }
        else if (!XTurn) {
            playerTurn(2);
            XTurn = true;
        }
        system("cls");
        ticTacToeBoard.printBoard();

        //PRINT BOARD HERE: FOR JOBARDIC-10

        int win = checkWin();
        if (win == 1) {
            PrintEndScreen("X");
            break;
        }
        else if (win == 2) {
            PrintEndScreen("O");
            break;
        }
        if (i >= 9) { PrintEndScreen("DRAW"); }
    }
}