#pragma once
#include "Pokemon.h"
<<<<<<< Updated upstream
=======
#include "cmath"
#include "Casilla.h"
#include "Cursor.h"
#include "Tablero.h"
#include <vector>
#include "Textos.h"

using namespace std;


enum class TURNO {JUGADOR1, JUGADOR2};

>>>>>>> Stashed changes

class Tablero
{

	Pokemon* matriz[9][9] = { nullptr }; //Creo la matriz 9x9 de punteros a pokemons
	
public:
	void colocar_pokemon(int f, int c, Pokemon* p) { matriz[f][c] = p; } // no se puede poner &p puesto que p ya es un puntero a pokemon 
	void imprimir();

<<<<<<< Updated upstream
=======
	Tablero() = default;
	
void imprimir();
	void inicializar_tablero();
	//para leer el tablero en 2D

	//DIBUJARSE A SI MISMO Y A LOS POKEMONS O CASILLAS CORRESPONDIENTES o menu de hechizos
	void tablerodibuja();
	void dibujar_tableroyfichas();
	void dibujar_menu_hechizos();

	//SON PARA VER LAS CONDICIONES DE MOVIMIENTO DEL TABLERO
	
	bool casillaocupada(int ff, int cf);
	bool casillaaliado(int ff, int cf, Pokemon* p);
	bool casillaenemigo(int ff, int cf, Pokemon* p);
	
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

	//MOVIMIENTO PIEZAS TABLERO
	void cogerpieza(bool key[]);
	void soltarpieza(bool key[]);

	//para cargar los pokemons en sus respectivos vectores de cada bando
	void cargar_pokemons(Pokemon* p);
	vector <Pokemon*> obtener_pokemons_muertos_detu_bando();

	//para lanzar los hechizos
	bool lanzar_hechizo(int id_hechizo, int f, int c);

	//MENU HECHIZOS
	void hechizosmueve(bool key[]);

	void habilitar_IA() { IA_activa = true; }
>>>>>>> Stashed changes
};

