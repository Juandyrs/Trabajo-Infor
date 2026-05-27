#pragma once
#include "Pokemon.h"
#include "cmath"
#include "Casilla.h"
enum class VENTAJA { JUGADOR, NADA, ROCKET }; //SERVIARÁ MAS ADELANTE PARA LOS MODOS Y VENTAJAS

class Tablero
{

	Pokemon* matriz[9][9] = { nullptr }; //Creo la matriz 9x9 de punteros a pokemons (VACIA) SE LLENA EN LA INICIALIZACIÓN
	Casilla* casillas[9][9]={nullptr};


public:

	void colocar_pokemon(int f, int c, Pokemon* p) { matriz[f][c] = p; } // no se puede poner &p puesto que p ya es un puntero a pokemon 
	void dibujar_casillas();
	void imprimir();
	void inicializar_tablero();
	//para leer el tablero en 2D
	Pokemon* get_pokemon(int f, int c) { return matriz[f][c]; }


	//SON PARA VER LAS CONDICIONES DE MOVIMIENTO DEL TABLERO
	int distancia(int x1, int y1, int x2, int y2);
	bool casillaocupada(int f, int c);
	bool casillaaliado(int f, int c, Pokemon* p);
	bool casillaenemigo(int f, int c, Pokemon* p);
	int movimientovalido(Pokemon* p, int nx, int ny); //LO HE HECHO CON INT PARA QUE DIGA POR QUE PUEDE O NO PUEDE MOVER 0 es invalido, 1 es vacio, 2 enemigo, 3 aliado 


};

