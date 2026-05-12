#pragma once

#include "Vector2D.h"
#include "Pokemon.h"
#include "Obstaculo.h"
#include "ListaObstaculos.h"

class ArenaCombate
{
	Vector2D dimensiones_arena{9,9};
	Pokemon &equipo1, &equipo2;
	ListaObstaculos obstaculos;
	bool IA_activa; // Es true por ahora para probar la Ia

public:
	
	ArenaCombate()
		: equipo1(*new Pokemon())
		, equipo2(*new Pokemon())
	{
		equipo1.pos_arena = { -dimensiones_arena.x + 2, 0 };
		equipo2.pos_arena = { dimensiones_arena.x - 2, 0 };
	}


	ArenaCombate(Pokemon &t1, Pokemon &t2, bool ia)
		: equipo1(t1)
		, equipo2(t2)
		, IA_activa(ia)
	{
		equipo1.pos_arena = { -dimensiones_arena.x + 2, 0 };
		equipo2.pos_arena = { dimensiones_arena.x - 2, 0 };
	}

	friend class IA;

	//Metodos de dibujo
	void dibuja_Arena();
	void dibuja_Personajes();
	void dibuja_BarrasVida();
	void dibuja_Ataques();
	void dibuja_Obstaculos();

	//Metodos de movimiento y ataque
	void arena_combate();
	void interaccion_obstaculos();
	void inicializa_obstaculos();
	void mueve_personaje(bool key[]);
	void limita_movimiento();

	//Metodos de inicializacion y reseteo
	void inicializa_Arena(Pokemon &t1, Pokemon &t2, bool ia);
};

