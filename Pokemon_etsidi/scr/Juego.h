#pragma once
#include "ArenaCombate.h"
#include "Tablero.h"
#include "tiposp/Basico.h"
#include "tiposp/Distancia.h"

class Juego
{
	bool arena_activa{ true }; // Es true por ahora para probar la arena 
	ArenaCombate Arena;
	Tablero Mitablerito;

public:
	Juego() = default;

	void dibujar_Juego();
	void mover_Juego(bool key[]);
	void logica_Juego();
	void jugar();
	void arena_combate(Pokemon& equipo1, Pokemon& equipo2);
	void inicializar_tablero();

};

