#pragma once

#include <iostream>
#include "Ataque.h"
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
	double dano;
	double cooldown;
	Vector2D Hitbox;
	Vector2D pos_arena;
	Vector2D dir_mov;

public:

	// Contructor por defecto necesario para evitar errores de inicializacion

	Pokemon()
		: nombre("")
		, tip1(Tipo::Ninguno)
		, tip2(Tipo::Ninguno)
		, equipo(Bando::Entrenador)
		, simbolo(' ')
		, movimiento(TipoMovimiento::Tierra)
		, numero_casillas(0)
		, vida_max(0.0)
		, vida_actual(0.0)
		, velocidad(0.0)
		, dano(0.0)
		, cooldown(0.0)
		, Hitbox{0.0, 0.0}
		, pos_arena{0.0, 0.0}
		, dir_mov{ 0.0, 0.0 }
	{}

	friend class ArenaCombate;
	friend class Tablero;
	friend class Distancia;
	friend class Basico;
	friend class Hechicero;
	friend class Tanque;
	friend class CambiaFormas;
	friend class Fenix;
	friend class Volador;
	friend class Obs_Piedra;

	void inicializa_datos(string n, char s, Bando b, Tipo tipo1, Tipo tipo2);
	void inicializa_stats(double v_max, double v_act, double vel);
	void inicializa_mov(TipoMovimiento mov, int nu_ca);
	char obtener_simbolo() { return simbolo; }

	//Metodos Relacionados con el tablero

	//Metodos Relacionados con la Arena

	virtual void atacar(Vector2D posicion, Vector2D dir) = 0;
	virtual void mueve_ataque() = 0;
	virtual bool colision_ataque(Pokemon &objetivo) = 0;
	virtual void atacar_dibujar() = 0;
};

