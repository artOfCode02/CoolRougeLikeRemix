#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <array>

#include "core.hpp"

using namespace std;

std::array<int, 2> getCursorPosition() {
    int x;
    int y;

    POINT pos;
    if (GetCursorPos(&pos)) {
        x = pos.x;
        y = pos.y;
    }
    else {
        std::cerr << "Failed to get cursor position." << std::endl;
    }

    return { x, y };
}

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

int readCharAtXY(int x, int y) {

    std::array<int, 2> currentPos = getCursorPosition();

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

    gotoXY(currentPos[0], currentPos[1]);

    return charBuffer;
}

std::array<int, 2> getConsoleDimensions() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (hConsole == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Error: Could not get console handle.\n");
        exit(1);
    }

    int columns;
    int rows;

    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
    else {
        fprintf(stderr, "Error: Could not get console screen buffer info.\n");
        exit(1);
    }

    return { columns, rows };
}

