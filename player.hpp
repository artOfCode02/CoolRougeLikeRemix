#pragma once

#include "entity.hpp"

class Player : public Entity {
public:
	Player(int x, int y) : Entity(x, y, '@', '.') {
		displayEntity();
	}

	void handlePlayerInput(int inputKey);

	void movePlayer(int keyInput);
};