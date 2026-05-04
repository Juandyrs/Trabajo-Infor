#pragma once

#include "Vector2D.h"
#include "Pokemon.h"
#include "Obstaculo.h"

class ArenaCombate
{
	Vector2D dimensiones_arena{9,9};
	Pokemon &equipo1, &equipo2;
	Obs_Fuego obstaculo1{ Vector2D{0.0, 0.0} };

public:
	
	ArenaCombate() = default;

	ArenaCombate(Pokemon &t1, Pokemon &t2)
		: equipo1(t1)
		, equipo2(t2)
	{
		equipo1.pos_arena = { -dimensiones_arena.x + 2, 0 };
		equipo2.pos_arena = { dimensiones_arena.x - 2, 0 };
	}


	//Metodos de dibujo
	void dibuja_Arena();
	void dibuja_Personajes();
	void dibuja_BarrasVida();
	void dibuja_Ataques();
	void dibuja_Obstaculos();

	//Metodos de movimiento y ataque
	void arena_combate();
	void interaccion_obstaculos();
	void mueve_personaje(bool key[]);
	void limita_movimiento();
};

