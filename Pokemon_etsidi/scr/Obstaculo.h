#pragma once

#include "Vector2D.h"
#include "Pokemon.h"
#include "Hitbox.h"

class Obstaculo
{
protected:

	Hitbox *hitbox;
	int vida; //Todos tienen vida pero no todos se pueden destruir
	bool destruible; // Si es true se puede destruir, si no es false

public:

	Obstaculo()
		: hitbox()
		, vida(0)
		, destruible(false)
	{}

	Obstaculo(Vector2D pos, bool d, int v = 0)
		: hitbox(new HitboxRectangular(Vector2D(0.5, 0.5), pos))
		, vida(v)
		, destruible(d)
	{}

	friend ArenaCombate;
	friend InteraccionArena;

	virtual bool interrumpir(Pokemon& personaje) = 0;
	virtual void dibujar() = 0;

	Hitbox* consultar_hitbox() const { return hitbox; }
	Vector2D consultar_posicion() const { return hitbox->pos; }
	Vector2D consultar_dim_hitbox() const; // Funciona porque todas son rectangulares

	bool es_destruible() const { return destruible; }
};

class Obs_Piedra :
	public Obstaculo
{

public:

	Obs_Piedra(Vector2D pos)
		: Obstaculo(pos, true, 3)
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
		: Obstaculo(pos, false)
	{}

	bool interrumpir(Pokemon &personaje) override;
	void dibujar() override;
};