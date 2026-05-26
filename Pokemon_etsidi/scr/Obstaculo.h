#pragma once

#include "Vector2D.h"
#include "Pokemon.h"
#include "Hitbox.h"

class Obstaculo
{
protected:

	HitboxRectangular hitbox;
	Vector2D Posicion;

public:

	Obstaculo()
		: hitbox(Vector2D(0, 0))
		, Posicion(0, 0)
	{}

	Obstaculo(Vector2D pos)
		: hitbox(Vector2D(0.5, 0.5))
		, Posicion(pos)
	{}

	virtual bool interrumpir(Pokemon& personaje) = 0;
	virtual void dibujar() = 0;

	HitboxRectangular consultar_hitbox() const { return hitbox; }
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