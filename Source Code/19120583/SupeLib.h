#pragma once
#ifndef supelib
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <io.h>
#include <fcntl.h>

using namespace std;

void gotoxy(int column, int line);

int move();

void SetWindowSize(SHORT width, SHORT height);



#endif // !supelib