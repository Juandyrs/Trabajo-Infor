#pragma once
#include "Pokemon.h"

enum class Direccion{ Arriba, Abajo, Izquierda, Derecha};

class Cursor
{
	friend class Tablero;
	friend class Juego;
	friend class IA;

	int columna, fila;
	bool llevaficha = false;       //SI LLEVA ALGO
	Pokemon* fichaencursor = nullptr; //POKEMON QUE SE LLEVA
	
	//MAX DISTANCIA Y FILAS Y COLUMNAS INICIALES PARA COMPROBAR MOVIMIENTOS VALIDOS
	int maxdistancia = 400; 
	int fi;
	int ci;
	TipoMovimiento Tipomov;
	int actualdistancia = 0; //DISTANCIA DESDE QUE TE MUEVES HASTA DONDE ESTAS
	int actualmaxdistancia = 0; //LA MAXIMA DISTANCIA QUE HAS ALCANZADO, LOS RESETEO CON LA FUNCION DE PILLAR LOS DATOS DEL POKEMON

	//DIRECCION DE MOVIMIENTO, SIRVE PARA ORIENTAR LOS SPRITES
	Direccion direccion_actual;

public:

	//DIBUJADO E INICIALIZAR
	void dibujarcursor();
	void inicializarcursor(int f, int c);

	//COSAS INTERNAS Y CARGA DE DATOS DE LA FICHA SELECCIONADA
	void cursorpillaficha(Pokemon* p);
	void cursorsueltaficha();
	bool cursorllevaficha() const { return llevaficha; } 
	Pokemon* obtenerfichacursor() const { return fichaencursor; }

	//MOVIMIENTO DE CURSOR
	void Cursormover(bool key[], Pokemon* matriz[9][9]);
	void mod_fila(bool sumar);
	void mod_columna(bool sumar);

	//RESETEO PARA PARTIDA NUEVA
	void resetear_cursor();
};

