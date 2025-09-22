// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/* PROGRAM START */

#include <iostream>
#include <Windows.h>
#include <conio.h>


#include "core.hpp"
#include "entity.hpp"
#include "player.hpp"


int main()
{
 
    int ch;

    Player man(5, 5);

    man.displayEntity();

    while ((ch = _getch()) != 81) {
        man.handlePlayerInput(ch);
    }


    std::cout << "Quitting Program" << std::endl;


    return 0;
}

/* PROGRAM END */

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
