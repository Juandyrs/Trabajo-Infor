#pragma once

#include "Pokemon.h"
#include "Ataque.h"
#include "ArenaCombate.h"

class InteraccionArena
{
public:

	static void aplicar_Efectos(Pokemon &personaje);
	static bool colision_ataques_arena(ArenaCombate &obj, Ataque &p);
	static bool colisiona_ataques_obst(ListaObstaculos &obs, Ataque &p);
};

