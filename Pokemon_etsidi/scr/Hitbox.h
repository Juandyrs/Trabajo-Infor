#pragma once
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

	Hitbox() : tipo(TipoHitbox::Ninguno) {}

	Hitbox(TipoHitbox tip) : tipo(tip) {}

	virtual TipoHitbox consultar_tipo() = 0; //No tiene sentido que exista un objeto de tipo hitbox 
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

	TipoHitbox consultar_tipo() override { return TipoHitbox::Rectangular; }
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

	TipoHitbox consultar_tipo() override { return TipoHitbox::Circular; }
	void dibujar() override { glutSolidSphere(radio, 20, 20);}
};