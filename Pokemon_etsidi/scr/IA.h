#pragma once
#include "ArenaCombate.h"
#include "Tablero.h"

enum class Estado_Arena
{
	Buscar,
	Atacar,
	Esquivar,
	Defensivo
};

class IA
{
	inline static Estado_Arena estado_arena = Estado_Arena::Buscar;

public:

	friend class Juego;

	static void IA_Tablero(Tablero &tablero);
	static void IA_Combate_Arena(ArenaCombate &arena);

	static bool buscar_camino_arena(ArenaCombate &arena);
	
	Estado_Arena consultar_estado_arena() { return estado_arena; }
};

