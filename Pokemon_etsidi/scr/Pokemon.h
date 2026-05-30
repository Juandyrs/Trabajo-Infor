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
	Tierra, Vuelo, Teletransporte, Hechizo
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

	void inicializa_datos(string n, char s, Bando b, Tipo tipo1, Tipo tipo2);
	void inicializa_stats(double v_max, double v_act, double vel);
	void inicializa_mov(TipoMovimiento mov, int nu_ca);
	char obtener_simbolo() { return simbolo; }

	//Metodos Relacionados con el tablero

	//Metodos Relacionados con la Arena

<<<<<<< Updated upstream
	virtual void atacar(Vector2D posicion, Vector2D dir) = 0;
	virtual void mueve_ataque() = 0;
	virtual bool colision_ataque(Pokemon& objetivo) = 0;
	virtual void atacar_dibujar() = 0;
=======

	void recibir_dano(double cantidad);
	void modificar_posicion(Vector2D nueva_pos) { hitbox->pos = nueva_pos; }
	void modificar_estado(EfectoEstado nuevo_estado, int duracion) { efecto_estado = nuevo_estado; duracion_efecto = duracion; }
	void modificar_dir(Vector2D dir) { dir_mov = dir; }

	Hitbox* consultar_hitbox() const { return hitbox; }
	Vector2D consultar_dim_hitbox() const;// Sirve por que todas son rectangulares
	Vector2D consultar_posicion() const { return hitbox->pos; }
	string consultar_nombre() const { return nombre; }
	double consultar_vel() const { return velocidad; }
	double consultar_vida() const { return vida_actual; }
	double consultar_dano() const { return dano; }
	double consultar_vidamax() const { return vida_max; }
	double consultar_cd() const { return cooldown; }
	Ataque* consultar_ataque() const { return ataque; }
	EfectoEstado consultar_efecto_estado() const { return efecto_estado; }
	Estado consultar_estado() const { return estado; }
	int consultar_duracion_estado() const { return duracion_efecto; }
	Vector2D consultar_dir() const { return dir_mov; }
	void cambiar_estado(Estado e) { estado = e; }

	virtual void atacar(Pokemon &objetivo);
	void mover_arena(double dt);
	Vector2D siguiente_posicion(const Vector2D dir, const double dt) const { return hitbox->pos + dir * velocidad * dt; }
	
	//para el hechizo de cura
	void cura_max() { vida_actual = vida_max; }

//HECHIZO TELETRANSPORTE
	void teletransporte() {	movimiento = TipoMovimiento::Hechizo;	numero_casillas = 999;	}
	void restablecermovimiento(TipoMovimiento mov, int casillas) { movimiento = mov; numero_casillas = casillas; }

//HECHIZO CAMBIO POSICION
	void cambioposicion(double posx, double posy) { pos_tab.x = posx, pos_tab.y = posy; }

>>>>>>> Stashed changes
};

