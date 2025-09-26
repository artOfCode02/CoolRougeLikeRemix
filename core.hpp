#pragma once

std::array<int, 2> getCursorPosition();

void gotoXY(int x, int y);

void printXY(int x, int y, char ch);

int readCharAtXY(int x, int y);

std::array<int, 2> getConsoleDimensions();