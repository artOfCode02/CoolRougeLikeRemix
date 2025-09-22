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

/* ENDS UP CHANGING THE LOCATION OF CURSOR TO x AND y */
int readCharAtXY(int x, int y) {
    gotoXY(x, y); // Go to inputted location.

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        std::cerr << "Error getting console handle." << std::endl;
        return 1;
    }

    COORD charCoord;
    charCoord.X = x;
    charCoord.Y = y;
    
    TCHAR charBuffer;
    DWORD charsRead;

    if (!ReadConsoleOutputCharacter(hConsole, &charBuffer, 1, charCoord, &charsRead)) {
        std::cerr << "Error reading console output character." << std::endl;
        return 1;
    }

    return charBuffer;
}

