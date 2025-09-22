#include <iostream>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#include "core.hpp"

using namespace std;


void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printXY(int x, int y, char ch) {
    gotoXY(x, y);
    std::cout << ch;
}

