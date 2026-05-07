#pragma once

#include "Pokemon.h"
#include "Vector2D.h"

class Colisiones
{
	
public:

	static bool colision(Vector2D rect1, Vector2D pos1, Vector2D rect2, Vector2D pos2); // Colision entre dos hitbox rectangulares
	static bool colision(double radio, Vector2D pos, Vector2D Hitbox2, Vector2D pos2); // Colision entre hitbox circular y rectangular
};

