#include "Juego.h"
#include "Pokemon.h"
#include "IA.h"

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

	if (arena_activa) arena_combate(*new Distancia("Grovile", Bando::Entrenador, Tipo::Planta, Tipo::Ninguno, { 0,1 }), 
		*new Basico("Scraggy", Bando::Team_Rocket, Tipo::Lucha, Tipo::Siniestro, { 1,7 }));
	
}

void Juego::arena_combate(Pokemon &equipo1, Pokemon &equipo2)
{
	static bool primera_vez = true;

	if(primera_vez) 
	{
		Arena.inicializa_Arena(equipo1, equipo2, IA_activa);
		Arena.inicializa_obstaculos();
		IA::estado_arena = Estado_Arena::Buscar;
		primera_vez = false;
	}

	Arena.arena_combate();
	Arena.interaccion_obstaculos();
	Arena.limita_movimiento();

	if (IA_activa) 
	{
		IA::IA_Combate_Arena(Arena);
	}
}

void Juego::inicializar_tablero() {
	
}