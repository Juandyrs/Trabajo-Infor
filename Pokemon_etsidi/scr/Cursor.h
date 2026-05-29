#pragma once
#include "Pokemon.h"

class Cursor
{
	friend class Tablero; 

	

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

public:


	void dibujarcursor();
	void inicializarcursor(int f, int c);

	//ESPECIFICAS DE CURSOR


	//COSAS INTERNAS Y CARGA DE DATOS DE LA FICHA SELECCIONADA
	void cursorpillaficha(Pokemon* p);
	void cursorsueltaficha();
	void distancialactual();

	bool cursorllevaficha() const { return llevaficha; } 
	Pokemon* obtenerfichacursor() const { return fichaencursor; }
	int obtenerMovimientoRestante() const { return maxdistancia; }





	//MOVIMIENTO DE CURSOR
	void Cursormover(bool key[], Pokemon* matriz[9][9]);
};

