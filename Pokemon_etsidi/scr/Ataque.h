#pragma once

#include "Vector2D.h"
#include "Hitbox.h"

class Pokemon;

class Ataque
{
protected:

	Vector2D dir_atk;
	Hitbox *hitbox;
	double dano;

public:

	Ataque()
		: dir_atk{ 0.0, 0.0 }
		, hitbox(nullptr)
		, dano(0.0)
	{}

	Ataque(Vector2D dir, Vector2D pos, double d)
		: dir_atk(dir)
		, hitbox(nullptr)
		, dano(d)
	{}

	void set_direccion(Vector2D dir) { dir_atk = dir; }
	void set_posicion(Vector2D pos) { hitbox->pos = pos; }

	friend class ArenaCombate;
	friend class InteraccionArena;

	virtual void iniciar_ataque(Vector2D posicion, Vector2D dir) = 0;
	virtual void mueve_ataque() = 0;
	virtual void atacar_dibujar() = 0;
	virtual bool colision_ataque(Pokemon &objetivo) = 0;
	virtual Hitbox* consultar_hitbox() { return hitbox; }
	virtual Ataque* clonar() const = 0;
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

	Rango(double d, Vector2D dir, Vector2D pos, double vel, double radio)
		: Ataque(dir, pos, d)
		, vel_proyectil(vel*dir_atk)
	{
		hitbox = new HitboxCircular(radio, pos);
	}

	friend class ArenaCombate;

	void iniciar_ataque(Vector2D posicion, Vector2D dir) override;
	void atacar_dibujar() override;
	void mueve_ataque() override { hitbox->pos += vel_proyectil; }
    bool colision_ataque(Pokemon &objetivo) override;
	virtual Ataque* clonar() const override;
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

	Melee(double d, Vector2D dir, Vector2D pos, double rango, double ancho, int frame)
		: Ataque(dir, pos, d)
		, frame_ataque(frame)
	{
		hitbox = new HitboxRectangular(Vector2D(rango, ancho), pos);
	}

	friend class ArenaCombate;
	friend class InteraccionArena;

	void iniciar_ataque(Vector2D posicion, Vector2D dir) override;
	void atacar_dibujar() override;
	void mueve_ataque() override {} // Para evitar errores, el ataque melee no se mueve, por ahora
	bool colision_ataque(Pokemon &objetivo) override;
	virtual Ataque* clonar() const override;
};

class Area :
	public Ataque
{
	int frame_ataque{};

public:

	Area()
		: Ataque()
		, frame_ataque{ 0 }
	{
		hitbox = new HitboxCircular();
	}

	Area(double d, Vector2D dir, Vector2D pos, double radio, int frame)
		: Ataque(dir, pos, d)
		, frame_ataque(frame)
	{
		hitbox = new HitboxCircular(radio, pos);
	}

	friend class ArenaCombate;

	void iniciar_ataque(Vector2D posicion, Vector2D dir) override;
	void atacar_dibujar() override;
	void mueve_ataque() override {} // Para evitar errores, el ataque de Area no se mueve, por ahora
	bool colision_ataque(Pokemon &objetivo) override;
	virtual Ataque* clonar() const override;
};