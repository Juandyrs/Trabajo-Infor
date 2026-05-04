#pragma once

#include "Vector2D.h"
#include "Pokemon.h"

class Obstaculo
{
protected:

	Vector2D Hitbox;
	Vector2D Posicion;

public:

	Obstaculo()
		: Hitbox(0, 0)
		, Posicion(0, 0)
	{}

	virtual void interrumpir(Pokemon &personaje) = 0;
	virtual void dibujar() = 0;
};

class Obs_Piedra :
	public Obstaculo
{

public:

	Obs_Piedra(Vector2D pos)
	{
		Hitbox = { 1.0, 1.0 };
		Posicion = pos;
	}

	void interrumpir(Pokemon &personaje) override;
	void dibujar() override;
};

class Obs_Fuego :
	public Obstaculo
{

public:

	Obs_Fuego(Vector2D pos)
	{
		Hitbox = { 1.0, 1.0 };
		Posicion = pos;
	}

	void interrumpir(Pokemon &personaje) override;
	void dibujar() override;
};