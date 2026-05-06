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

	virtual void atacar(Vector2D posicion, Vector2D dir) = 0;
	virtual void mueve_ataque() = 0;
	virtual bool colision_ataque(Pokemon &objetivo) = 0;
	virtual void atacar_dibujar() = 0;

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

	friend class Distancia;
	friend class Hechicero;
	friend class Tanque;
	friend class ArenaCombate;

	void atacar(Vector2D posicion, Vector2D dir) override;
	void atacar_dibujar() override;
	bool colision_ataque(Pokemon &objetivo) override;
	void mueve_ataque() override { pos_atk = pos_atk + vel_proyectil; }
};

class Melee :
	public Ataque
{
	double rango_ataque{};
	double ancho_ataque{};
	double frame_ataque{};

public:

	Melee()
		: Ataque()
		, rango_ataque(0.0)
		, ancho_ataque(0.0)
		, frame_ataque(0.0)
	{}

	Melee(double dano, Vector2D dir, Vector2D pos, double rango, double ancho, double frame)
		: Ataque(dano, dir, pos)
		, rango_ataque(rango)
		, ancho_ataque(ancho)
		, frame_ataque(frame)
	{}

	friend class Basico;
	friend class ArenaCombate;

	void atacar(Vector2D posicion, Vector2D dir) override;
	void atacar_dibujar() override;
	bool colision_ataque(Pokemon& objetivo) override;
	void mueve_ataque() override {} // Para evitar errores, el ataque melee no se mueve, por ahora

};

class Area :
	public Ataque
{
	double radio_ataque{};
	double frame_ataque{};

public:

	Area(double dano, Vector2D dir, Vector2D pos, double radio, double frame)
		: Ataque(dano, dir, pos)
		, radio_ataque(radio)
		, frame_ataque(frame)
	{}

	friend class Pokemon;
	friend class Fenix;
	friend class Volador;
	friend class ArenaCombate;

	void atacar(Vector2D posicion, Vector2D dir) override;
	void atacar_dibujar() override;
	bool colision_ataque(Pokemon &objetivo) override;
	void mueve_ataque() override {} // Para evitar errores, el ataque de Area no se mueve, por ahora

};