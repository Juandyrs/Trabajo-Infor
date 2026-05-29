#pragma once
#include "ArenaCombate.h"
#include "Tablero.h"
#include "tiposp/Basico.h"
#include "tiposp/Distancia.h"
#include "Textos.h"

//distintos tableros
enum EstadoPantalla { MENU, TABLERO, ARENA,FIN,HECHIZOS };
enum class ResultadoJuego { NOGANADOR, GANADORENTRENADOR, GANADORROCKET };



class Juego
{

	bool IA_activa{ false };
	ArenaCombate Arena;
	Tablero Mitablerito;
	EstadoPantalla pantallaActual{ MENU };
	ResultadoJuego resultado{ ResultadoJuego::NOGANADOR};

public:

	Juego() = default;

	void dibujar_Juego();
	void mover_Juego(bool key[]);
	void logica_Juego();
	void jugar();
	void arena_combate(Pokemon& equipo1, Pokemon& equipo2, TipoCasilla tipo);
	void comprobar_victoria();
	void animar();
	void actualizar_juego(double dt);
	void TableroArena();
	void ArenaTablero();

};

