#pragma once

#include "Vector2D.h"

class Ataque
{
protected:

	double dano;
	Vector2D dir_atk;
	Vector2D pos_atk;

public:

	Ataque()
		: dano(0.0)
		, dir_atk{ 0.0, 0.0 }
		, pos_atk{ 0.0, 0.0 }
	{}

	Ataque(double d, Vector2D dir, Vector2D pos)
		: dano(d)
		, dir_atk(dir)
		, pos_atk(pos)
	{}


	void set_direccion(Vector2D dir) { dir_atk = dir; }
	void set_posicion(Vector2D pos) { pos_atk = pos; }

	friend class Pokemon;
	friend class Distancia;
	friend class ArenaCombate;

};

class Rango :
	public Ataque
{
	Vector2D vel_proyectil;
	double radio_proyectil;

public:

	Rango(double d, Vector2D dir, Vector2D pos, double vel, double radio)
		: Ataque(d, dir, pos)
		, vel_proyectil(vel*dir_atk)
		, radio_proyectil(radio)
	{}

	friend class Distancia;
	friend class ArenaCombate;
};

class Melee :
	public Ataque
{
	double rango_ataque{};
	double ancho_ataque{};

public:

	Melee(double r, double a)
	{
		rango_ataque = r;
		ancho_ataque = a;
	}

	friend class Pokemon;
	friend class ArenaCombate;
};

class Area :
	public Ataque
{
	double radio_ataque{};

public:

	Area(double r)
	{
		radio_ataque = r;
	}

	friend class Pokemon;
	friend class ArenaCombate;
};