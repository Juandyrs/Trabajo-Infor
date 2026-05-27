#pragma once

#include "Vector2D.h"
#include <freeglut.h>

enum class TipoHitbox
{
	Rectangular, Circular, Ninguno
};

struct Hitbox
{
	TipoHitbox tipo;
	Vector2D pos;

	Hitbox() : tipo(TipoHitbox::Ninguno) {}

	Hitbox(TipoHitbox tip) : tipo(tip) {}

	Hitbox(TipoHitbox tip, Vector2D posi)
		: tipo(tip)
		, pos(posi)
	{}

	virtual TipoHitbox consultar_tipo() const = 0; //No tiene sentido que exista un objeto de tipo hitbox 
	virtual void dibujar() = 0;
};

struct HitboxRectangular: public Hitbox
{
	Vector2D rectangulo;

	HitboxRectangular() 
		: Hitbox(TipoHitbox::Rectangular) 
		, rectangulo({0,0})
	{}

	HitboxRectangular(Vector2D rect)
		: Hitbox(TipoHitbox::Rectangular)
		, rectangulo(rect)
	{}

	HitboxRectangular(Vector2D rect, Vector2D posi)
		: Hitbox(TipoHitbox::Rectangular, posi)
		, rectangulo(rect)
	{
	}

	TipoHitbox consultar_tipo() const override { return TipoHitbox::Rectangular; }
	Vector2D consultar_posicion() const { return pos; }
	void dibujar() override;
};

struct HitboxCircular : public Hitbox
{
	double radio;

	HitboxCircular() 
		: Hitbox(TipoHitbox::Circular)
		, radio(0.0) 
	{}

	HitboxCircular(double r)
		: Hitbox(TipoHitbox::Circular)
		, radio(r)
	{}

	HitboxCircular(double r, Vector2D posi)
		: Hitbox(TipoHitbox::Circular, posi)
		, radio(r)
	{
	}

	TipoHitbox consultar_tipo() const override { return TipoHitbox::Circular; }
	void dibujar() override;
};