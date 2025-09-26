#include <iostream>

#include "debug.hpp"

void displayDebugInfo(Player user, Level level) {
	gotoXY(0, 0);
	std::cout << "Player Info:" << std::endl;
	std::cout << "- Player Positon: " << user.x_pos << ", " << user.y_pos << std::endl;
	std::cout << "- Player Standing On Square: " << user.standingOnSurfaceType << std::endl;

	std::cout << std::endl;

	std::cout << "Level Info:" << std::endl;

	for (int i = 0; i < 6; i++) {
		std::cout << "- Room" << i + 1 << ":" << std::endl;
		std::cout << "  + Room" << i + 1 << " Position: " << level.rooms[i].x_pos << ", " << level.rooms[i].y_pos << std::endl;
		std::cout << "  + Room" << i + 1 << " Dimensions: " << level.rooms[i].x_pos << ", " << level.rooms[i].y_pos << std::endl;

		std::cout << std::endl;
	}
	

	

}