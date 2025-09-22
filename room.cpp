#include <iostream>
#include "room.hpp"

void Room::drawRoom() {
	int x = x_pos;
	int y = y_pos;

	// Draw First Row (Row 0)
	for (int i = 0; i < width; i++) {
		printXY(x + i, y, '-');
	}

	// Draw rows 1 to height - 1
	y++;
	for (int i = 0; i < height - 1; i++) {
		printXY(x, y + i, '|');
		for (int j = 1; j < width - 1; j++) {
			printXY(x + j, y + i, '.');
		}
		printXY(x + width - 1, y + i, '|');
	}

	// Draw last row
	y = y_pos + height;
	for (int i = 0; i < width; i++) {
		printXY(x + i, y, '-');
	}
}