#pragma once
#include <iostream>

using namespace std;

enum class Bando {
	Entrenador, Team_Rocket
};
enum class TipoMovimiento {
	Tierra, Vuelo, Teletransporte
};

class Pokemon
{
protected:
	string nombre;
	char simbolo;
	Bando equipo;
	string tipo1, tipo2;
	double vida_max,vida_actual;
	double velocidad;
	double tiempo_recarga;
	double daño;
	double velocidad_proyectil;
	TipoMovimiento movimiento;
	int numero_casillas;

	/* void inicializa_datos(string n, char s, Bando b, string tipo1, string tipo2) 
	*/
	
	

};

