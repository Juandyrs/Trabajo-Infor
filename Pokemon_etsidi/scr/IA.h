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

enum class Estado_Tablero
{
	Decidir, Pensar, Actuar
};

class IA
{
	inline static Estado_Arena estado_arena = Estado_Arena::Buscar;
	inline static Estado_Tablero estado_tablero = Estado_Tablero::Decidir;
	inline static double dt;
	inline static double tiempo_pensar{ 0.3 }, tiempo;
	inline static bool sujetada{ false };

public:

	friend class Juego;
	friend class ArenaCombate;

	static void IA_Tablero(Tablero &tablero);
	static void IA_Combate_Arena(ArenaCombate &arena);

	static bool buscar_camino_arena(ArenaCombate &arena);
	
	Estado_Arena consultar_estado_arena() { return estado_arena; }
};

