#include <iostream>

#include "core.hpp"
#include "entity.hpp"

using namespace std;

void Entity::moveEntity(int newX, int newY) {
	printXY(x_pos, y_pos, standingOnSurfaceType);

	int moveCode = collisionDetect(newX, newY);

	if (moveCode == 0) {
		x_pos = newX;
		y_pos = newY;
	}

	displayEntity();
}

void Entity::displayEntity() {
	printXY(x_pos, y_pos, symbol);
}

/* MOVE CODES:
*  -1 = Unknown / Blank
*   0 = Passable ('.')
*   1 = Impassable ('|' or '-')
*   2 = Door
* 
 */

int Entity::collisionDetect(int newX, int newY) {
	char ch = readCharAtXY(newX, newY);

	switch (ch) {
	case '.':
		standingOnSurfaceType = '.';
		return 0;
	case '|':
		return 1;
	case '-':
		return 1;
	default:
		return -1;
	}
}