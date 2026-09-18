#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

using namespace std;

void singlePlayer();
void twoPlayer();
void playerTurn(int);
void botTurn(int);
int checkWin();
extern bool playerX;
extern bool XTurn;