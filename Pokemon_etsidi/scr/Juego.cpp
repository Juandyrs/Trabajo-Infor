#include "Juego.h"
#include "Pokemon.h"

void Juego::dibujar_Juego()
{
	//Dibujar el tablero

	//Dibujar la arena

	if (arena_activa)
	{
		Arena.dibuja_Personajes();
		Arena.dibuja_Ataques();
		Arena.dibuja_Obstaculos();
		Arena.dibuja_Arena();
		Arena.dibuja_BarrasVida();
	}
}

void Juego::mover_Juego(bool key[])
{
	//Formas de moverse en el tablero

	//Formas de moverse en la arena

	if (arena_activa)
	{
		Arena.mueve_personaje(key);
	}
}

void Juego::logica_Juego()
{
	//Lógica del juego, como pasar de la pantalla del tablero a la arena, etc.
}

void Juego::jugar()
{
	// Todo el codigo necesario para jugar 

	if (arena_activa) arena_combate(*new Distancia(), *new Basico());
	
}

void Juego::arena_combate(Pokemon &equipo1, Pokemon &equipo2)
{
	static bool primera_vez = true;

	if(primera_vez) 
	{
		Arena.inicializa_Arena(equipo1, equipo2);
		Arena.inicializa_obstaculos();
		primera_vez = false;
	}

	Arena.arena_combate();
	Arena.interaccion_obstaculos();
	Arena.limita_movimiento();
}
