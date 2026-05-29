#pragma once

#include "Pokemon.h"
#include "cmath"
#include "Casilla.h"
#include "Cursor.h"

enum class VENTAJA { JUGADOR, NADA, ROCKET }; //SERVIARÁ MAS ADELANTE PARA LOS MODOS Y VENTAJAS
enum class TURNO {JUGADOR1, JUGADOR2};

class Tablero
{
	friend class Cursor;

	Pokemon* matriz[9][9] = { nullptr }; //Creo la matriz 9x9 de punteros a pokemons (VACIA) SE LLENA EN LA INICIALIZACIÓN
	TURNO Turnoactual;
	int numeroturno = 1;

	//LOGICA MOVIMIENTOS
	Pokemon* fichaseleccionada = nullptr; //PARA LA FICHA SELECCIONADA
	bool fichayaseleccionada = false; //SIRVE PARA SABER SI ESTA AGARRADA
	int Movimientosrestantes = 0; 
	Cursor cursor;
	Casilla* casillas[9][9]={nullptr};

public:

	void colocar_pokemon(int f, int c, Pokemon* p) { matriz[f][c] = p; } // no se puede poner &p puesto que p ya es un puntero a pokemon 
	

	Tablero() = default;
void imprimir();
	void inicializar_tablero();
	//para leer el tablero en 2D
	Pokemon* get_pokemon(int f, int c) { return matriz[f][c]; }

	//DIBUJARSE A SI MISMO Y A LOS POKEMONS O CASILLAS CORRESPONDIENTES
	void tablerodibuja();
	void dibujar_tableroyfichas();

	//SON PARA VER LAS CONDICIONES DE MOVIMIENTO DEL TABLERO
	int distanciarecorrida(int fi, int ci, int ff ,int cf);
	bool casillaocupada(int ff, int cf);
	bool casillaaliado(int ff, int cf, Pokemon* p);
	bool casillaenemigo(int ff, int cf, Pokemon* p);
	bool movimientoTipoValido(Pokemon* p, int fi, int ci, int ff, int cf); //DETERMINA SI LOS MOVIMIENTOS SON VALIDOS
	bool movimientoTerrestre(Pokemon* p, int fi, int ci, int ff, int cf);
	bool movimientoVolador(Pokemon* p, int fi, int ci, int ff, int cf);
	bool movimientoPsiquico(Pokemon* p, int fi, int ci, int ff, int cf);
	int movimientovalido(Pokemon* p, int nx, int ny); //LO HE HECHO CON INT PARA QUE DIGA POR QUE PUEDE O NO PUEDE MOVER 0 es invalido, 1 es vacio, 2 enemigo, 3 aliado 
	bool moverficha(Pokemon* p, int ff, int cf); //ES LO QUE DICE SI LA FICHA SE HA PODIDO MOVER Y SI LO HACE O NO
	void revivirficha(Pokemon* p, int x, int y); //REVIVIR FICHA COMO INDICA EL NOMBRE
	void cambiarturno(); 
	void conteoturno(); 
	bool preparacioncombate(); //PARA PASARLE LOS PUNTEROS A JUEGO Y QUE SE INICIALICE LA ARENA Y CAMBIE DE TABLERO A ARENA
	void turnofinalizadoexito(); //VA A SER DONDE MOVER FICHA DETECTE TRUE Y HAGA EL CONTEO Y EL CAMBIO DE TURNO.




	//TABLERO MUEVE (FUNCION GLOBAL PARA PASAR A JUEGO)
	void tableromueve(bool key[]);

	void cogerpieza(bool key[]);
	void soltarpieza(bool key[]);

};

