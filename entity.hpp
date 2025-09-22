#pragma once

#include "core.hpp"

using namespace std;

class Entity {
public:
	int x_pos;
	int y_pos;

	char symbol;

	Entity(int x_in, int y_in, char symbol_in) : x_pos(x_in), y_pos(y_in), symbol(symbol_in) {}

	void displayEntity();
};