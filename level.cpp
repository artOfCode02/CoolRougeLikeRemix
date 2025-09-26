#include <array>
#include <cstdlib>
#include <ctime>
#include <random>

#include "level.hpp"

std::array<int, 4> Level::generateRoomDimensions(int roomVarianceMax, int sectionMargin, std::array<int, 2> section) {
	/*srand(time(NULL));
	int roomVariance = rand() % roomVarianceMax;*/

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> distrib(5, roomVarianceMax);

	int roomVariance = distrib(gen);

	int xpos = sectionMargin + roomVariance + section[0];
	int ypos = sectionMargin + roomVariance + section[1];

	int width = sectionWidth - (roomVariance * sectionMargin);
	int height = sectionHeight -  sectionMargin - roomVariance;

	return { xpos, ypos, width, height };
}

Room Level::generateRoom(Room room, std::array<int, 4> roomDim) {
	room.x_pos = roomDim[0];
	room.y_pos = roomDim[1];
	room.width = roomDim[2];
	room.height = roomDim[3];

	return room;
}

void Level::drawRooms(std::array<Room, 6> rooms) {
	for (int i = 0; i < 6; i++) {
		rooms[i].drawRoom();
	}
}

