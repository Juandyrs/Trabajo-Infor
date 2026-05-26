#pragma once

#include <iostream>
#include "Ataque.h"
#include "Vector2D.h"
#include "Hitbox.h"

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

	friend int main(int argc, char* argv[]);

	//Atributos Generales
	string nombre;
	Tipo tip1, tip2;
	Bando equipo;
	string sprite; //VA A SER LA RUTA HACIA 

	//Atributos del Tablero
	char simbolo;
	TipoMovimiento movimiento;
	int numero_casillas;
	Vector2D pos_tab;

	//Atributos de la Arena
	bool atacando;
	EfectoEstado efecto_estado;
	int duracion_efecto;
	double vida_max,vida_actual;
	double velocidad;
	double dano;
	double cooldown;
	HitboxRectangular hitbox;
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
		, hitbox(Vector2D( 0.0, 0.0 ) )
		, pos_arena{ 0.0, 0.0 }
		, dir_mov{ 0.0, 0.0 }
		, ataque(nullptr)
		, sprite("")
	{}

	friend class ArenaCombate;
	friend class Tablero;
	friend class Obs_Piedra;
	friend class InteraccionArena;
	friend class IA;

	void inicializa_datos(string n, char s, Bando b, Tipo tipo1, Tipo tipo2);
	void inicializa_stats(double v_max, double v_act, double vel);
	void inicializa_mov(TipoMovimiento mov, int nu_ca);
	
	//DIBUJADO
	void pokemondibuja(int f, int c);

	//TABLERO LOGICO 
	char obtener_simbolo() { return simbolo; }

	//Metodos Relacionados con el tablero
	Bando obtener_bando() { return equipo; } //para el color de la ficha
	string obtenersprite() { return sprite;  } //PARA PODER ENCONTRAR LA RUTA CON FACILIDAD EN EL DIBUJADO


	//Metodos Relacionados con la Arena


	void recibir_dano(double cantidad);
	void modificar_posicion(Vector2D nueva_pos) { pos_arena = nueva_pos; }
	void modificar_estado(EfectoEstado nuevo_estado, int duracion) { efecto_estado = nuevo_estado; duracion_efecto = duracion; }

	HitboxRectangular consultar_hitbox() const { return hitbox; }
	Vector2D consultar_posicion() const { return pos_arena; }
	string consultar_nombre() const { return nombre; }
	double consultar_vel() const { return velocidad; }
	double consultar_vida() const { return vida_actual; }
	double consultar_dano() const { return dano; }
	double consultar_vidamax() const { return vida_max; }
	double consultar_cd() const { return cooldown; }
	Ataque* consultar_ataque() const { return ataque; }
	EfectoEstado consultar_estado() const { return efecto_estado; }
	int consultar_duracion_estado() const { return duracion_efecto; }

	virtual void atacar(Pokemon &objetivo);
	void mover_arena(Vector2D dir);
	Vector2D siguiente_posicion(const Vector2D dir) const { return pos_arena + dir * velocidad; }
	
};

//El dano con el tiempo se aplicara cada 10 frames