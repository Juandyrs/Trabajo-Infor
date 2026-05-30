#pragma once

#include "Pokemon.h"
#include "cmath"
#include "Casilla.h"
#include "Cursor.h"

enum class TURNO {JUGADOR1, JUGADOR2};

class Tablero
{
	friend class Cursor;

	Pokemon* matriz[9][9] = { nullptr }; //Creo la matriz 9x9 de punteros a pokemons (VACIA) SE LLENA EN LA INICIALIZACIÓN
	TURNO Turnoactual;
	int numeroturno = 1;

	//LOGICA MOVIMIENTOS
<<<<<<< Updated upstream
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



=======
	Cursor cursor;
	Casilla* casillas[9][9]={nullptr};


	//COMBATE, PASAR LOS PUNTEROS AL EXTERIOR (JUEGO)
	Pokemon* ataque = nullptr;
	Pokemon* defensa = nullptr;
	TipoCasilla casillaarena;
	void cargadatosarena();
	int filaCombate;
	int columnaCombate;
	bool arenabandera = false; //FLAG QUE MANDA A JUEGO
	
	//HECHIZOS
	bool flagmenu = false;          //MANU
	bool hechizousadoturno = false; //NO MAS DE UN HECHIZO POR TURNO
	bool modohechizo = false;       //TIENE SELECCIONADO UN HECHIZO
	int hechizoseleccionado = 0;	//EL HECHIZO SELECCIONADO
	int filaBloqueada = -1;		//LO PONGO ASI PARA NO MODIFICAR CONSTRUCTORES 
	int colBloqueada = -1;
	int turnosBloqueo = 0;


public:

	void colocar_pokemon(int f, int c, Pokemon* p) { matriz[f][c] = p; } // no se puede poner &p puesto que p ya es un puntero a pokemon 
	
	Tablero() = default;
	
	void imprimir(); //IMPRIMIR TABLERO LOGICO
	void inicializar_tablero();
	//para leer el tablero en 2D
	Pokemon* get_pokemon(int f, int c) { return matriz[f][c]; }

	//DIBUJARSE A SI MISMO Y A LOS POKEMONS O CASILLAS CORRESPONDIENTES o menu de hechizos
	void tablerodibuja();
	void dibujar_tableroyfichas();
	void dibujar_menu_hechizos();
	void dibujarmenu(bool key[]);

	//SON PARA VER LAS CONDICIONES DE MOVIMIENTO DEL TABLERO
	bool casillaocupada(int ff, int cf);
	bool casillaaliado(int ff, int cf, Pokemon* p);
	bool casillaenemigo(int ff, int cf, Pokemon* p);


	//RELACIONADAS CON LOS TURNOS
	void cambiarturno(); 
	void conteoturno(); 
	void turnofinalizadoexito(); //VA A SER DONDE MOVER FICHA DETECTE TRUE Y HAGA EL CONTEO Y EL CAMBIO DE TURNO.


	//para comprobar condiciones de victoria
	bool controla_puntos_poder(Bando b); //victoria por puntos de poder
	bool quedan_piezas(Bando b);         // victoria porque al otro no le quedan piezas
>>>>>>> Stashed changes

	//TABLERO MUEVE (FUNCION GLOBAL PARA PASAR A JUEGO)
	void tableromueve(bool key[]);

	//CURSOR
	void cogerpieza(bool key[]);
	void soltarpieza(bool key[]);
<<<<<<< Updated upstream

=======

	//para cargar los pokemons en sus respectivos vectores de cada bando
	void cargar_pokemons(Pokemon* p);

	//HECHIZOS
	void reseteohechizos();
	void seleccionarhechizo(bool key[]);
	void hechizoteletransporte(bool key[]);
	void hechizocuracion(bool key[]);
	void hechizorevivir(bool key[]);
	void hechizobloquear(bool key[]);

>>>>>>> Stashed changes
};

