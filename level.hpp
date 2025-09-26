#pragma once

#include <iostream>
#include <array>
#include <cstdlib>

#include "core.hpp"
#include "room.hpp"

class Level {
public:
	std::array<int, 2> consoleDimensions = getConsoleDimensions();

	std::array<Room, 6> rooms;

	int totalWidth = consoleDimensions[0];
	int totalHeight = consoleDimensions[1] - 6;

	// Defining section width and height
	const int sectionWidth = totalWidth / 3;
	const int sectionHeight = totalHeight / 2;

	// Dividing the level into 6 equal sections
	std::array<int, 2> section1 = { 0, 0 };
	std::array<int, 2> section2 = { sectionWidth , 0 };
	std::array<int, 2> section3 = { (2 * sectionWidth), 0 };
	std::array<int, 2> section4 = { 0, sectionHeight };
	std::array<int, 2> section5 = { sectionWidth, sectionHeight };
	std::array<int, 2> section6 = { (2 * sectionWidth), sectionHeight };

	
	// Defining the possible dimensions of a room
	const int sectionMargin = 3;

	const int roomVarianceMax = 8;

	std::array<int, 4> generateRoomDimensions(int roomVarianceMax, int sectionMargin, std::array<int, 2> section);

	std::array<int, 4> room1dim = generateRoomDimensions(roomVarianceMax, sectionMargin, section1);
	std::array<int, 4> room2dim = generateRoomDimensions(roomVarianceMax, sectionMargin, section2);
	std::array<int, 4> room3dim = generateRoomDimensions(roomVarianceMax, sectionMargin, section3);
	std::array<int, 4> room4dim = generateRoomDimensions(roomVarianceMax, sectionMargin, section4);
	std::array<int, 4> room5dim = generateRoomDimensions(roomVarianceMax, sectionMargin, section5);
	std::array<int, 4> room6dim = generateRoomDimensions(roomVarianceMax, sectionMargin, section6);

	std::array<std::array<int, 4>, 6> roomDims = { room1dim, room2dim, room3dim, room4dim, room5dim, room6dim };

	Room generateRoom(Room room, std::array<int, 4> roomDim);

	void drawRooms(std::array<Room, 6> rooms);

	//Other Variables
	int lvlNumber;

	// Level Constructor
	Level(int lvlNumber_in) : lvlNumber(lvlNumber_in) {
		for (int i = 0; i < 6; i++) {
			rooms[i] = generateRoom(rooms[i], roomDims[i]);
		}
		drawRooms(rooms);
	}
};