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

	Obstaculo(Vector2D pos)
		: Hitbox(1.0, 1.0)
		, Posicion(pos)
	{}

	virtual bool interrumpir(Pokemon& personaje) = 0;
	virtual void dibujar() = 0;

	Vector2D consultar_hitbox() const { return Hitbox; }
	Vector2D consultar_posicion() const { return Posicion; }
};

class Obs_Piedra :
	public Obstaculo
{

public:

	Obs_Piedra(Vector2D pos)
		: Obstaculo(pos)
	{}
	

	bool interrumpir(Pokemon &personaje) override;
	void dibujar() override;
};

class Obs_Fuego :
	public Obstaculo
{
	int frames_fuego{ 100 };

public:

	Obs_Fuego(Vector2D pos)
		: Obstaculo(pos)
	{}

	bool interrumpir(Pokemon &personaje) override;
	void dibujar() override;
};