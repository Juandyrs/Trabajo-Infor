#include "Obstaculo.h"
#include <freeglut.h>
#include "Colisiones.h"

Vector2D Obstaculo::consultar_dim_hitbox() const
{
	HitboxRectangular* h = dynamic_cast<HitboxRectangular*>(hitbox);

	return h->rectangulo;
}

// Metodos del obstaculo de piedra

bool Obs_Piedra::interrumpir(Pokemon &personaje)
{

	if (Colisiones::colision(hitbox, personaje.consultar_hitbox()))
	{
		personaje.hitbox->pos = personaje.consultar_posicion() - personaje.dir_mov * personaje.velocidad;
		return true;
	}

	return false;
} 

void Obs_Piedra::dibujar()
{
	glColor3ub(111, 67, 33);
	hitbox->dibujar();
}

// Metodos del obstaculo de fuego

bool Obs_Fuego::interrumpir(Pokemon &personaje)
{

	if (Colisiones::colision(hitbox,personaje.consultar_hitbox()) 
		&& personaje.consultar_efecto_estado() != EfectoEstado::Invulnerable)
	{
		personaje.modificar_estado(EfectoEstado::Quemadura, frames_fuego);
		return true;
	}
	return false;
}

void Obs_Fuego::dibujar()
{
	glColor3ub(255, 0, 0);
	hitbox->dibujar();
}
