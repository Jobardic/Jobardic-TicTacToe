#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

using namespace std;

extern void PrintEndScreen(string type);
extern bool multiplayer;
int board[9] = { 0,0,0,0,0,0,0,0,0 }; //the board as an array, 0 for empty, 1 for X, 2 for O
bool XTurn = false;
bool playerX = false;

void twoPlayer();
void singlePlayer();

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
        if (board[input - 1] == 0) { //if it's free, replace it
            board[input - 1] = s;
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
        if (board[ran] == 0) {
            board[ran] = s;
            break;
        }
    }
}

int checkWin() { //if statement has all the possible win permutations to check if they are occupied by X or O
    if ((board[0] == 1 && board[1] == 1 && board[2] == 1) || (board[3] == 1 && board[4] == 1 && board[5] == 1) || (board[6] == 1 && board[7] == 1 && board[8] == 1) || (board[0] == 1 && board[3] == 1 && board[6] == 1) || (board[1] == 1 && board[4] == 1 && board[7] == 1) || (board[2] == 1 && board[5] == 1 && board[8] == 1) || (board[0] == 1 && board[4] == 1 && board[8] == 1) || (board[2] == 1 && board[4] == 1 && board[6] == 1)) {
        //X win
        return 1;
    }
    else if ((board[0] == 2 && board[1] == 2 && board[2] == 2) || (board[3] == 2 && board[4] == 2 && board[5] == 2) || (board[6] == 2 && board[7] == 2 && board[8] == 2) || (board[0] == 2 && board[3] == 2 && board[6] == 2) || (board[1] == 2 && board[4] == 2 && board[7] == 2) || (board[2] == 2 && board[5] == 2 && board[8] == 2) || (board[0] == 2 && board[4] == 2 && board[8] == 2) || (board[2] == 2 && board[4] == 2 && board[6] == 2)) {
        //O win
        return 2;
    }
    return 0;
}

void singlePlayer() {
    for (int j = 0; j < 9; j++) { //resets the board
        board[j] = 0;
    }

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

        //PRINT BOARD HERE: FOR JOBARDIC-10

        int win = checkWin(); //checks win
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
    for (int j = 0; j < 9; j++) {
        board[j] = 0;
    }

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