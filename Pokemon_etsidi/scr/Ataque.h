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

	Ataque(double dano, Vector2D dir, Vector2D pos)
		: dano(dano)
		, dir_atk(dir)
		, pos_atk(pos)
	{}


	void set_direccion(Vector2D dir) { dir_atk = dir; }
	void set_posicion(Vector2D pos) { pos_atk = pos; }

	friend class Pokemon;
	friend class Distancia;
	friend class ArenaCombate;
	friend class InteraccionesArena;

	virtual void iniciar_ataque(Vector2D posicion, Vector2D dir) = 0;
	virtual void mueve_ataque() = 0;
	virtual bool colision_ataque(Pokemon &objetivo) = 0;
	virtual void atacar_dibujar() = 0;
	virtual double consultar_rango() const = 0;

};

class Rango :
	public Ataque
{
	Vector2D vel_proyectil;
	double radio_proyectil;

public:

	Rango()
		: Ataque()
		, vel_proyectil{ 0.0, 0.0 }
		, radio_proyectil(0.0)
	{}

	Rango(double dano, Vector2D dir, Vector2D pos, double vel, double radio)
		: Ataque(dano, dir, pos)
		, vel_proyectil(vel*dir_atk)
		, radio_proyectil(radio)
	{}


	friend class ArenaCombate;

	void iniciar_ataque(Vector2D posicion, Vector2D dir) override;
	void atacar_dibujar() override;
	bool colision_ataque(Pokemon &objetivo) override;
	void mueve_ataque() override { pos_atk = pos_atk + vel_proyectil; }
	double consultar_rango() const override { return radio_proyectil; }
};

class Melee :
	public Ataque
{
	double rango_ataque{};
	double ancho_ataque{};
	int frame_ataque{};

public:

	Melee()
		: Ataque()
		, rango_ataque(0.0)
		, ancho_ataque(0.0)
		, frame_ataque(0)
	{}

	Melee(double dano, Vector2D dir, Vector2D pos, double rango, double ancho, int frame)
		: Ataque(dano, dir, pos)
		, rango_ataque(rango)
		, ancho_ataque(ancho)
		, frame_ataque(frame)
	{}

	friend class ArenaCombate;

	void iniciar_ataque(Vector2D posicion, Vector2D dir) override;
	void atacar_dibujar() override;
	bool colision_ataque(Pokemon& objetivo) override;
	void mueve_ataque() override {} // Para evitar errores, el ataque melee no se mueve, por ahora
	double consultar_rango() const override { return rango_ataque; }

};

class Area :
	public Ataque
{
	double radio_ataque{};
	int frame_ataque{};

public:

	Area(double dano, Vector2D dir, Vector2D pos, double radio, int frame)
		: Ataque(dano, dir, pos)
		, radio_ataque(radio)
		, frame_ataque(frame)
	{}

	friend class ArenaCombate;

	void iniciar_ataque(Vector2D posicion, Vector2D dir) override;
	void atacar_dibujar() override;
	bool colision_ataque(Pokemon &objetivo) override;
	void mueve_ataque() override {} // Para evitar errores, el ataque de Area no se mueve, por ahora
	double consultar_rango() const override { return radio_ataque; }

};