#pragma once

#include "Pokemon.h"
#include "Ataque.h"

class InteraccionArena
{
public:

	static void aplicar_Efectos(Pokemon &personaje);
	static bool colision_ataques(Pokemon &objetivo, Ataque &atk);
};

