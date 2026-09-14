// Jobardic-TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Jobardic-test_header.h"
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

int board[9] = { 0,0,0,0,0,0,0,0,0 }; //the board as an array, 0 for empty, 1 for X, 2 for O
bool singleplayer = true;
bool XTurn = false;
bool playerX = true;
bool gameOver = true; //bools to confirm what game mode or player type each game is

void menu(); //FORWARD DECLARATION so all the functions in the code can reference the menu and go back to it ==do not remove==

string bt(int num) { //short for board translate
    if (num == 0) { return " "; }
    else if (num == 1) { return "X"; }
    else if (num == 2) { return "O"; }
}

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

void singlePlayer(int first) {
    gameOver = false;
    for (int j = 0; j < 9; j++) { //resets the board
        board[j] = 0;
    }
    cout << " " << bt(board[0]) << " | " << bt(board[1]) << " | " << bt(board[2]) << endl; //prints the board
    cout << "---+---+---" << endl;
    cout << " " << bt(board[3]) << " | " << bt(board[4]) << " | " << bt(board[5]) << endl;
    cout << "---+---+---" << endl;
    cout << " " << bt(board[6]) << " | " << bt(board[7]) << " | " << bt(board[8]) << endl << endl;
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
        cout << " " << bt(board[0]) << " | " << bt(board[1]) << " | " << bt(board[2]) << endl;
        cout << "---+---+---" << endl;
        cout << " " << bt(board[3]) << " | " << bt(board[4]) << " | " << bt(board[5]) << endl;
        cout << "---+---+---" << endl;
        cout << " " << bt(board[6]) << " | " << bt(board[7]) << " | " << bt(board[8]) << endl << endl;
        int win = checkWin(); //checks win
        if (win == 1) {
            if (playerX) {
                cout << "!!!YOU WON!!!" << endl << endl;
                gameOver = true;
            }
            else {
                cout << "...you lost..." << endl << endl;
                gameOver = true;
            }
            break;
        }
        else if (win == 2) { //pretty straightforward
            if (!playerX) {
                cout << "!!!YOU WON!!!" << endl << endl;
                gameOver = true;
            }
            else {
                cout << "...you lost..." << endl << endl;
                gameOver = true;
            }
            break;
        }
        if (i >= 8) { cout << "Tie Game!" << endl << endl; }
    }
    gameOver = true;
    //gameOverScreen(first);
    while (true) { //end menu to choose what to do next
        cout << "Play again?" << endl << "=== r - Replay" << endl << "=== m - Menu" << endl << "=== q - Quit" << endl;
        string str;
        cin >> str;
        if (str == "r") {
            if (first == 1) {
                XTurn = true;
                playerX = true;
            }
            else {
                XTurn = true;
                playerX = false;
            }
            singlePlayer(first);
        }
        else if (str == "m") { menu(); }
        else if (str == "q") { exit(0); }
        else { cout << "Unknown input, please try again" << endl; }
    }
}

void twoPlayer(int first) { //same as singleplayer but there's no bot turn
    gameOver = false;
    for (int j = 0; j < 9; j++) {
        board[j] = 0;
    }
    cout << " " << bt(board[0]) << " | " << bt(board[1]) << " | " << bt(board[2]) << endl;
    cout << "---+---+---" << endl;
    cout << " " << bt(board[3]) << " | " << bt(board[4]) << " | " << bt(board[5]) << endl;
    cout << "---+---+---" << endl;
    cout << " " << bt(board[6]) << " | " << bt(board[7]) << " | " << bt(board[8]) << endl << endl;
    for (int i = 0; i < 9; i++) {
        if (XTurn) {
            playerTurn(1);
            XTurn = false;
        }
        else if (!XTurn) {
            playerTurn(2);
            XTurn = true;
        }
        cout << " " << bt(board[0]) << " | " << bt(board[1]) << " | " << bt(board[2]) << endl;
        cout << "---+---+---" << endl;
        cout << " " << bt(board[3]) << " | " << bt(board[4]) << " | " << bt(board[5]) << endl;
        cout << "---+---+---" << endl;
        cout << " " << bt(board[6]) << " | " << bt(board[7]) << " | " << bt(board[8]) << endl << endl;
        int win = checkWin();
        if (win == 1) {
            cout << "Player X wins!" << endl << endl;
            gameOver = true;
            break;
        }
        else if (win == 2) {
            cout << "Player O wins!" << endl << endl;
            gameOver = true;
            break;
        }
        if (i >= 9) { cout << "Tie Game!" << endl << endl; }
    }
    gameOver = true;
    cout << endl << "Tie Game!" << endl << endl;
    while (true) {
        cout << "Play again?" << endl << "=== r - Replay" << endl << "=== m - Menu" << endl << "=== q - Quit" << endl;
        string str;
        cin >> str;
        if (str == "r") {
            XTurn = true;
            twoPlayer(first);
        }
        else if (str == "m") { menu(); }
        else if (str == "q") { exit(0); }
        else { cout << "Unknown input, please try again" << endl; }
    }
}

void chooseX0(int type) {
    if (type == 2) {
        XTurn = true;
        twoPlayer(1);
    }
    cout << "Enter x to play X" << endl << "Enter o to play O" << endl;
    string input;
    cin >> input;
    XTurn = true;
    if (input == "X" || input == "x") {
        if (type == 1) {
            playerX = true;
            singlePlayer(1);
        }
    }
    else if (input == "o" || input == "O") {
        if (type == 1) {
            playerX = false;
            singlePlayer(2);
        }
    }
}

void menu() {
    cout << "Welcome to Tic-Tac-Toe!" << endl << "1 - Single player (against bot)" << endl << "2 - Two player" << endl << "g - Guide" << endl << "q - quit" << endl;
    string str;
    cin >> str;
    if (str == "1") {
        singleplayer = true;
        chooseX0(1);
    }
    else if (str == "2") {
        singleplayer = false;
        chooseX0(2);
    }
    else if (str == "g") {
        cout << endl << "Guide here:" << endl;
        cout << " 1 | 2 | 3 " << endl;
        cout << "-----------" << endl;
        cout << " 4 | 5 | 6 " << endl;
        cout << "-----------" << endl;
        cout << " 7 | 8 | 9 " << endl;
        menu();
    }
    else if (str == "q") {
        exit(0);
    }
    else {
        cout << "Unknown input, please try again" << endl;
        menu();
    }
}

int main()
{
    srand(time(0));
    menu();
}

