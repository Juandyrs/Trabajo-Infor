#pragma once
#include "ArenaCombate.h"
#include "Tablero.h"
#include "tiposp/Basico.h"
#include "tiposp/Distancia.h"

//distintos tableros
enum EstadoPantalla { MENU, TABLERO_ESTRATEGICO, ARENA_FIGHT };

class Juego
{
	bool arena_activa{ false }; // Es true por ahora para probar la arena 
	bool IA_activa{ false }; // Es true por ahora para probar la Ia
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


	void inicializar_tablero(); 
	void inicializar_tablero(Tablero t) { Mitablerito = t; }

};

