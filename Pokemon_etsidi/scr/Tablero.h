#pragma once

#include "Pokemon.h"
#include "cmath"
#include "Casilla.h"
#include "Cursor.h"
#include "Tablero.h"
#include <vector>
#include "Textos.h"

using namespace std;

enum class VENTAJA { JUGADOR, NADA, ROCKET }; //SERVIARÁ MAS ADELANTE PARA LOS MODOS Y VENTAJAS
enum class TURNO {JUGADOR1, JUGADOR2};


class Tablero
{
	friend class Cursor;
	friend class Juego;

	Pokemon* matriz[9][9] = { nullptr }; //Creo la matriz 9x9 de punteros a pokemons (VACIA) SE LLENA EN LA INICIALIZACIÓN
	TURNO Turnoactual;
	int numeroturno = 1;
	Pokemon* fichaSeleccionada = nullptr; //PARA LA FICHA SELECCIONADA
	bool fichaYaSeleccionada = false; //SIRVE PARA SABER SI ESTA AGARRADA
	vector <Pokemon*> equipo_entrenador; 
	vector <Pokemon*> equipo_rocket; 

	//LOGICA MOVIMIENTOS
	
	int Movimientosrestantes = 0; 
	Cursor cursor;
	Casilla* casillas[9][9]={nullptr};
	
	//para hechizos y su menu

	bool menu_hechizos_abierto = false; 
	int hechizo_cargado = 0;
	int f_hechicero = 0; 
	int c_hechicero = 0;
	Pokemon* p_revivir = nullptr;
	int estado_hechizo = 1;

public:

	void colocar_pokemon(int f, int c, Pokemon* p) { matriz[f][c] = p; } // no se puede poner &p puesto que p ya es un puntero a pokemon 
	

	Tablero() = default;
	
void imprimir();
	void inicializar_tablero();
	//para leer el tablero en 2D
	Pokemon* get_pokemon(int f, int c) { return matriz[f][c]; }

	//DIBUJARSE A SI MISMO Y A LOS POKEMONS O CASILLAS CORRESPONDIENTES o menu de hechizos
	void tablerodibuja();
	void dibujar_tableroyfichas();
	void dibujar_menu_hechizos();

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
	
	void revivirficha(Pokemon* p, int x, int y); //REVIVIR FICHA COMO INDICA EL NOMBRE
	void seleccionficha(int f, int c); //PARA SELECCIONAR LA FICHA
	void cambiarturno(); 
	void conteoturno(); 
	void turnofinalizadoexito(); //VA A SER DONDE MOVER FICHA DETECTE TRUE Y HAGA EL CONTEO Y EL CAMBIO DE TURNO.

	//para mover el cursor y sacar el pokemon que esta en esa casilla 

	//COMBATE, PASAR LOS PUNTEROS AL EXTERIOR (JUEGO)
	Pokemon* ataque = nullptr;
	Pokemon* defensa = nullptr;
	TipoCasilla casillaarena;
	void cargadatosarena();
	int filaCombate;
	int columnaCombate;
	bool arenabandera = false;

	

	//para comprobar condiciones de victoria
	bool controla_puntos_poder(Bando b); //victoria por puntos de poder
	bool quedan_piezas(Bando b);         // victoria porque al otro no le quedan piezas

	//TABLERO MUEVE (FUNCION GLOBAL PARA PASAR A JUEGO)
	void tableromueve(bool key[]);
	//para cargar los pokemons en sus respectivos vectores de cada bando y obtener los muertos 

	void cogerpieza(bool key[]);
	void soltarpieza(bool key[]);
	void cargar_pokemons(Pokemon* p);
	vector <Pokemon*> obtener_pokemons_muertos_detu_bando();

	//para lanzar los hechizos
	bool lanzar_hechizo(int id_hechizo, int f, int c);

	
};

