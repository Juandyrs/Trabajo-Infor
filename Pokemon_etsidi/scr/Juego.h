#pragma once
#include "ArenaCombate.h"
#include "Tablero.h"
#include "tiposp/Basico.h"
#include "tiposp/Distancia.h"

//distintos tableros
enum EstadoPantalla { MENU, TABLERO, ARENA };

class Juego
{
	bool IA_activa{ false };
	ArenaCombate Arena;
	Tablero Mitablerito;
	EstadoPantalla pantallaActual{ MENU };
public:

	Juego() = default;

	void dibujar_Juego();
	void mover_Juego(bool key[]);
	void logica_Juego();
	void jugar();
	void arena_combate(Pokemon& equipo1, Pokemon& equipo2);

};

