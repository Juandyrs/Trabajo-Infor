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
	{}

	void dibuja_Arena();
	void dibuja_Personajes();
	void arena_transicion();
	void inicializar_pos();
	void mueve_personaje(bool key[]);

};

