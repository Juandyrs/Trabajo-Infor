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
	friend class IA;

	bool IA_activa{ false };

	Pokemon* matriz[9][9] = { nullptr }; //Creo la matriz 9x9 de punteros a pokemons (VACIA) SE LLENA EN LA INICIALIZACIÓN
	TURNO Turnoactual;
	int numeroturno = 1;
	Pokemon* fichaSeleccionada = nullptr; //PARA LA FICHA SELECCIONADA
	bool fichaYaSeleccionada = false; //SIRVE PARA SABER SI ESTA AGARRADA
	vector <Pokemon*> equipo_entrenador; 
	vector <Pokemon*> equipo_rocket;
	inline static int f_seleccionada, c_seleccionada;

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


	//ESTADISTICAS

	float tiempo_aux = 0.0f;
	float intervalo_aux = 0.15f;
	int frame_aux = 0;
	int total_frames_aux = 15;
	ETSIDI::SpriteSequence* sprite_aux = nullptr;
	Pokemon* pokemon_anterior = nullptr;

public:
	Tablero() = default;
	

	//IMPIMIR TABLERO LOGICO, COLOCAR POKEMONS Y REINICAR PARTIDA
    void imprimir();
	void reiniciar_tablero();
	void inicializar_tablero();
	void colocar_pokemon(int f, int c, Pokemon* p) { matriz[f][c] = p; }


	//DIBUJARSE A SI MISMO Y A LOS POKEMONS O CASILLAS CORRESPONDIENTES o menu de hechizos O ESTADISTICAS
	void tablerodibuja();
	void dibujar_tableroyfichas();
	void dibujar_menu_hechizos();
	void dibujarestadisticas();

	//SON PARA VER LAS CONDICIONES DE MOVIMIENTO DEL TABLERO
	bool casillaocupada(int ff, int cf);
	bool casillaaliado(int ff, int cf, Pokemon* p);
	bool casillaenemigo(int ff, int cf, Pokemon* p);
	
	//TURNO
	void cambiarturno(); 
	void conteoturno(); 
	void turnofinalizadoexito(); //VA A SER DONDE MOVER FICHA DETECTE TRUE Y HAGA EL CONTEO Y EL CAMBIO DE TURNO.


	//COMBATE, PASAR LOS PUNTEROS AL EXTERIOR (JUEGO)
	Pokemon* ataque = nullptr;
	Pokemon* defensa = nullptr;
	TipoCasilla casillaarena;
	void cargadatosarena();
	int filaCombate;
	int columnaCombate;
	bool arenabandera = false;

	//DIBUJAR COSAS
	void imprimir_turno();
	void dibujar_fondo_tablero();
	void dibujar_mov_posibles();

	//para comprobar condiciones de victoria
	bool controla_puntos_poder(Bando b); //victoria por puntos de poder
	bool quedan_piezas(Bando b);         // victoria porque al otro no le quedan piezas

	//TABLERO MUEVE (FUNCION GLOBAL PARA PASAR A JUEGO)
	void tableromueve(bool key[]);

	//MOVIMIENTO PIEZAS TABLERO
	void cogerpieza(bool key[]);
	void soltarpieza(bool key[]);

	//CARGA DE POKEMONS
	void cargar_pokemons(Pokemon* p);
	vector <Pokemon*> obtener_pokemons_muertos_detu_bando();

	//HECHIZOS
	void hechizosmueve(bool key[]);	
	bool lanzar_hechizo(int id_hechizo, int f, int c);

	//IA
	void habilitar_IA() { IA_activa = true; }
	Pokemon* consultar_pok(int i, int j) const { return matriz[i][j]; };
	int consultar_fila_seleccionada() const { return f_seleccionada; }
	int consultar_columna_seleccionada() const { return c_seleccionada; }


	//ESTADISTICAS Y MOVIMIENTO EN TABLERO
	void movimientopiezassprite();
	void actualiza(double dt);


};

