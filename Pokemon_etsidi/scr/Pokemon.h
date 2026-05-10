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

enum class EfectoEstado {
	Ninguno, Quemadura, Invulnerable  //Veneno, Paralisis, Congelacion Posibles implementaciones futuras
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
	bool atacando;
	EfectoEstado efecto_estado;
	int duracion_efecto;
	double vida_max,vida_actual;
	double velocidad;
	double dano;
	double cooldown;
	Vector2D Hitbox;
	Vector2D pos_arena;
	Vector2D dir_mov;
	Ataque *ataque;

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
		, atacando(false)
		, efecto_estado(EfectoEstado::Ninguno)
		, duracion_efecto(0)
		, vida_max(0.0)
		, vida_actual(0.0)
		, velocidad(0.0)
		, dano(0.0)
		, cooldown(0.0)
		, Hitbox{ 0.0, 0.0 }
		, pos_arena{ 0.0, 0.0 }
		, dir_mov{ 0.0, 0.0 }
		, ataque(nullptr)
	{}

	friend class ArenaCombate;
	friend class Tablero;
	friend class Obs_Piedra;
	friend class InteraccionArena;

	void inicializa_datos(string n, char s, Bando b, Tipo tipo1, Tipo tipo2);
	void inicializa_stats(double v_max, double v_act, double vel);
	void inicializa_mov(TipoMovimiento mov, int nu_ca);
	char obtener_simbolo() { return simbolo; }

	//Metodos Relacionados con el tablero

	//Metodos Relacionados con la Arena


	void recibir_dano(double cantidad);
	void modificar_posicion(Vector2D nueva_pos) { pos_arena = nueva_pos; }
	void modificar_estado(EfectoEstado nuevo_estado, int duracion) { efecto_estado = nuevo_estado; duracion_efecto = duracion; }

	Vector2D consultar_hitbox() const { return Hitbox; }
	Vector2D consultar_posicion() const { return pos_arena; }
	double consultar_vida() const { return vida_actual; }
	EfectoEstado consultar_estado() const { return efecto_estado; }
	int consultar_duracion_estado() const { return duracion_efecto; }

	virtual void atacar(Pokemon& objetivo);
	void mover_arena(Vector2D dir);
};

//El dano con el tiempo se aplicara cada 10 frames