#pragma once

#include "Pokemon.h"
#include "Vector2D.h"

class Colisiones
{
	
public:

	static bool colision(const Vector2D rect1, const Vector2D pos1, const Vector2D rect2, const Vector2D pos2); // Colision entre dos hitbox rectangulares
	static bool colision(const double radio, const Vector2D pos, const Vector2D Hitbox2, const Vector2D pos2); // Colision entre hitbox circular y rectangular
	static bool colision(const double r1, const Vector2D pos1, const double r2, const Vector2D pos2);
	static bool colision(const Vector2D rect, const Vector2D pos, const Vector2D dir, const Vector2D origen, int a); // Colision entre una hitbox rectangular y una recta conociendo la direccion y el origen de la recta
	static bool colision(const double r, const Vector2D pos, const Vector2D dir, const Vector2D origen, int a); // Colision entre una hitbox circular y un segmento conociendo dos puntos
	static bool colision(Hitbox *h1, Hitbox *h2); //Colision entre dos hitbox genericas
	static bool colision(Hitbox *h1, const Vector2D dir, const Vector2D origen); //Colision entre una hitbox y un rayo
};

