#pragma once

#include "Vector2D.h"
#include "Pokemon.h"

class ArenaCombate
{
	Vector2D dimensiones_arena{9,9};
	Pokemon &equipo1, &equipo2;

public:
	
	ArenaCombate() = default;

	ArenaCombate(Pokemon &t1, Pokemon &t2)
		: equipo1(t1)
		, equipo2(t2)
	{
		equipo1.pos_arena = { -dimensiones_arena.x + 2, 0 };
		equipo2.pos_arena = { dimensiones_arena.x - 2, 0 };
	}

	void dibuja_Arena();
	void dibuja_Personajes();
	void arena_combate();
	void mueve_personaje(bool key[]);
	void limita_movimiento();

};

