#pragma once
#include <iostream>
#include "Vector2D.h"

using namespace std;

enum class Bando {
	Entrenador, Team_Rocket
};
enum class Tipo {Tierra, Agua, Fuego, 
	Planta, Siniestro, Bicho, Dragon, Electrico,
	Hada, Lucha, Fire, Volador, Fantasma,Normal, 
	Acero, Veneno, Psiquico, Hielo,Ninguno
};

enum class TipoMovimiento {
	Tierra, Vuelo, Teletransporte
};

class Pokemon
{
protected:

	//Atributos Generales
	string nombre;
	Tipo tip1, tip2;
	Bando equipo;

	//Atributos del Tablero
	char simbolo;
	TipoMovimiento movimiento;
	int numero_casillas;

	//Atributos de la Arena
	double vida_max,vida_actual;
	double velocidad;
	double tiempo_recarga;
	double dano;
	double velocidad_proyectil;
	Vector2D pos_arena;

public:

	friend class ArenaCombate;

	void inicializa_datos(string n, char s, Bando b, Tipo tipo1, Tipo tipo2);
	void inicializa_stats(double v_max, double v_act, double vel, double timp,double da, double vel_proy);
	void inicializa_mov(TipoMovimiento mov, int nu_ca);
	char obtener_simbolo() { return simbolo; }
	
	//Metodos Relacionados con el tablero

	//Metodos Relacionados con la Arena
};

