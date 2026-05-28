#pragma once

#include "Pokemon.h"
#include "cmath"
#include "Casilla.h"
#include <vector>
enum class VENTAJA { JUGADOR, NADA, ROCKET }; //SERVIARÁ MAS ADELANTE PARA LOS MODOS Y VENTAJAS
enum class TURNO {JUGADOR1, JUGADOR2};


class Tablero
{

	Pokemon* matriz[9][9] = { nullptr }; //Creo la matriz 9x9 de punteros a pokemons (VACIA) SE LLENA EN LA INICIALIZACIÓN
	TURNO Turnoactual;
	int numeroturno = 1;
	Pokemon* fichaSeleccionada = nullptr; //PARA LA FICHA SELECCIONADA
	bool fichaYaSeleccionada = false; //SIRVE PARA SABER SI ESTA AGARRADA
	vector <Pokemon*> equipo_entrenador; 
	vector <Pokemon*> equipo_rocket; 

	Casilla* casillas[9][9]={nullptr};
	int cursor_f = 0, cursor_c = 0; //posicion del cursor del tablero

public:

	void colocar_pokemon(int f, int c, Pokemon* p) { matriz[f][c] = p; } // no se puede poner &p puesto que p ya es un puntero a pokemon 
	void dibujar_casillas();
	void imprimir();
	void inicializar_tablero();
	//para leer el tablero en 2D
	Pokemon* get_pokemon(int f, int c) { return matriz[f][c]; }

	//DIBUJARSE A SI MISMO Y A LOS POKEMONS O CASILLAS CORRESPONDIENTES
	void tablerodibuja();

	//SON PARA VER LAS CONDICIONES DE MOVIMIENTO DEL TABLERO
	int distancia(int fi, int ci, int ff ,int cf);
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
	void seleccionficha(int f, int c); //PARA SELECCIONAR LA FICHA
	void cambiarturno(); 
	void conteoturno(); 
	bool preparacioncombate(); //PARA PASARLE LOS PUNTEROS A JUEGO Y QUE SE INICIALICE LA ARENA Y CAMBIE DE TABLERO A ARENA
	bool turnofinalizadoexito(); //VA A SER DONDE MOVER FICHA DETECTE TRUE Y HAGA EL CONTEO Y EL CAMBIO DE TURNO.


	//para mover el cursor y sacar el pokemon que esta en esa casilla 

	void mover_cursor(int df, int dc) {cursor_f = max(0, min(8, cursor_f + df)); cursor_c = max(0, min(8, cursor_c + dc));}
	Pokemon* seleccionar_cursor() { return matriz[cursor_f][cursor_c]; }
	int obtener_cursor_f() const { return cursor_f; }
	int obtener_cursor_c() const { return cursor_c; }

	//para comprobar condiciones de victoria
	bool controla_puntos_poder(Bando b); //victoria por puntos de poder
	bool quedan_piezas(Bando b);         // victoria porque al otro no le quedan piezas

	//para cargar los pokemons en sus respectivos vectores de cada bando

	void cargar_pokemons(Pokemon* p);

};

