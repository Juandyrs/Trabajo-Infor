#pragma once

#include "Pokemon.h"
#include "Ataque.h"
#include "ArenaCombate.h"

class InteraccionArena
{
public:

	static void aplicar_Efectos(Pokemon &personaje);
	static bool colision_ataques_arena(ArenaCombate &obj, Pokemon &p);
};

