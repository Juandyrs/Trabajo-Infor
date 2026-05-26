#pragma once

#include "Vector2D.h"
#include "Hitbox.h"

class Ataque
{
protected:

	Vector2D dir_atk;
	Vector2D pos_atk;
	Hitbox *hitbox;

public:

	Ataque()
		: dir_atk{ 0.0, 0.0 }
		, pos_atk{ 0.0, 0.0 }
		, hitbox(nullptr)
	{}

	Ataque(Vector2D dir, Vector2D pos)
		: dir_atk(dir)
		, pos_atk(pos)
		, hitbox(nullptr)
	{}

	void set_direccion(Vector2D dir) { dir_atk = dir; }
	void set_posicion(Vector2D pos) { pos_atk = pos; }

	friend class ArenaCombate;
	friend class InteraccionesArena;

	virtual void iniciar_ataque(Vector2D posicion, Vector2D dir) = 0;
	virtual void mueve_ataque() = 0;
	virtual void atacar_dibujar() = 0;
	virtual Hitbox* consultar_hitbox() { return hitbox; }
};

class Rango :
	public Ataque
{
	Vector2D vel_proyectil;

public:

	Rango()
		: Ataque()
		, vel_proyectil{ 0.0, 0.0 }
	{
		hitbox = new HitboxCircular();
	}

	Rango(Vector2D dir, Vector2D pos, double vel, double radio)
		: Ataque(dir, pos)
		, vel_proyectil(vel*dir_atk)
	{
		hitbox = new HitboxCircular(radio);
	}

	friend class ArenaCombate;

	void iniciar_ataque(Vector2D posicion, Vector2D dir) override;
	void atacar_dibujar() override;
	void mueve_ataque() override { pos_atk = pos_atk + vel_proyectil; }
};

class Melee :
	public Ataque
{
	int frame_ataque{};

public:

	Melee()
		: Ataque()
		, frame_ataque(0)
	{
		hitbox = new HitboxRectangular();
	}

	Melee(Vector2D dir, Vector2D pos, double rango, double ancho, int frame)
		: Ataque(dir, pos)
		, frame_ataque(frame)
	{
		hitbox = new HitboxRectangular(Vector2D(rango, ancho));
	}

	friend class ArenaCombate;

	void iniciar_ataque(Vector2D posicion, Vector2D dir) override;
	void atacar_dibujar() override;
	void mueve_ataque() override {} // Para evitar errores, el ataque melee no se mueve, por ahora

};

class Area :
	public Ataque
{
	int frame_ataque{};

public:

	Area(Vector2D dir, Vector2D pos, double radio, int frame)
		: Ataque(dir, pos)
		, frame_ataque(frame)
	{
		hitbox = new HitboxCircular(radio);
	}

	friend class ArenaCombate;

	void iniciar_ataque(Vector2D posicion, Vector2D dir) override;
	void atacar_dibujar() override;
	void mueve_ataque() override {} // Para evitar errores, el ataque de Area no se mueve, por ahora
};