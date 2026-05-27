#pragma once

#include "Vector2D.h"
#include "Pokemon.h"
#include "Hitbox.h"

class Obstaculo
{
protected:

	Hitbox *hitbox;

public:

	Obstaculo()
		: hitbox()
	{}

	Obstaculo(Vector2D pos)
		: hitbox(new HitboxRectangular(Vector2D(0.5, 0.5), pos))
	{}

	friend ArenaCombate;

	virtual bool interrumpir(Pokemon& personaje) = 0;
	virtual void dibujar() = 0;

	Hitbox* consultar_hitbox() const { return hitbox; }
	Vector2D consultar_posicion() const { return hitbox->pos; }
	Vector2D consultar_dim_hitbox() const; // Funciona porque todas son rectangulares
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