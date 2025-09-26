#pragma once

#include "core.hpp"

class Room {
public:
	int x_pos;
	int y_pos;

	int width;
	int height;
	
	Room() {}

	Room(int x_in, int y_in, int width_in, int height_in) : 
		x_pos(x_in), 
		y_pos(y_in), 
		width(width_in), 
		height(height_in) {}

	void drawRoom();
};