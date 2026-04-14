#pragma once
#include <iostream>

using namespace std;

enum class Bando {
	Entrenador, Team_Rocket
};
enum class Tipo {Tierra, Agua, Fuego, 
	Planta, Siniestro, Bicho, Dragon, Electrico,
	Hada, Lucha, Fire, Volador, Fantasma,Normal, 
	Acero, Veneno, Psiquico, Hielo
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
	Tipo tip1, tip2;
	double vida_max,vida_actual;
	double velocidad;
	double tiempo_recarga;
	double dano;
	double velocidad_proyectil;
	TipoMovimiento movimiento;
	int numero_casillas;

public:

	void inicializa_datos(string n, char s, Bando b, Tipo tipo1, Tipo tipo2);
	void inicializa_stats(double v_max, double v_act, double vel, double timp,double da, double vel_proy);
	void inicializa_mov(TipoMovimiento mov, int nu_ca);

	

};

