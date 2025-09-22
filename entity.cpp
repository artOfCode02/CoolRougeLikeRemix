#include <iostream>

#include "core.hpp"
#include "entity.hpp"

using namespace std;

void Entity::displayEntity() {
	printXY(x_pos, y_pos, symbol);
}