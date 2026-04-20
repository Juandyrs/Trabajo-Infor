#pragma once

#include "Vector2D.h"
#include "Pokemon.h"

class ArenaCombate
{
	Vector2D pos_inicial_equipo1{-3,0.5}, pos_inicial_equipo2{3,0.5}, dimensiones_arena{5,5};
	Pokemon equipo1, equipo2;

public:
	
	void dibuja_Arena();
	void dibuja_Personajes();
	void inicializar_pos(Pokemon team1, Pokemon team2);
	void mueve_personaje(bool key[]);
};

