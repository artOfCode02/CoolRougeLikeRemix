#include <iostream>
#include <conio.h>
#include "player.hpp"

/* 
 * INPUT PARAMETER: Key press from main program.
 * OUTPUT CONDITION: Player reacts according to key input.
*/
void Player::handlePlayerInput(int inputKey) {
	if (inputKey == 224) {
		int ch;
		movePlayer(ch = _getch());
	}
}

void Player::movePlayer(int inputKey) {
	int newX = x_pos;
	int newY = y_pos;

	if (inputKey == 72) { // Up Arrow
		newY--;
	} else if (inputKey == 80) { // Down Arrow
		newY++;
	} else if (inputKey == 75) { // Left Arrow
		newX--;
	} else if (inputKey == 77) { // Right Arrow
		newX++;
	}

	moveEntity(newX, newY);



}

