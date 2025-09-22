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
	printXY(x_pos, y_pos, ' ');

	int oldX = x_pos;
	int oldY = y_pos;

	if (inputKey == 72) { // Up Arrow
		y_pos--;
	} else if (inputKey == 80) { // Down Arrow
		y_pos++;
	} else if (inputKey == 75) { // Left Arrow
		x_pos--;
	} else if (inputKey == 77) { // Right Arrow
		x_pos++;
	}

	displayEntity();

}