#pragma once

#include "Vector2D.h"
#include "Pokemon.h"

class ArenaCombate
{
	Vector2D pos_equipo1{0.5,3}, pos_equipo2{0.5,-3}, dimensiones_arena{5,5};

public:
	

	void dibuja_Arena();
	void dibuja_Personajes(Pokemon &equipo1, Pokemon &equipo2);
};

