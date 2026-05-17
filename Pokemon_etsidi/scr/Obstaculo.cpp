#include "Obstaculo.h"
#include <freeglut.h>
#include "Colisiones.h"

// Metodos del obstaculo de piedra

bool Obs_Piedra::interrumpir(Pokemon &personaje)
{

	if (Colisiones::colision(Hitbox, Posicion, personaje.consultar_hitbox(), personaje.consultar_posicion()))
	{
		personaje.pos_arena = personaje.consultar_posicion() - personaje.dir_mov * personaje.velocidad;
		return true;
	}

	return false;
} 

void Obs_Piedra::dibujar()
{
	glTranslated(Posicion.x, Posicion.y, 0);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(111, 67, 33);
	glVertex3d(-Hitbox.x, -Hitbox.y, 0);
	glVertex3d(-Hitbox.x, Hitbox.y, 0);
	glColor3ub(111, 67, 33);
	glVertex3d(Hitbox.x, Hitbox.y, 0);
	glVertex3d(Hitbox.x, -Hitbox.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glTranslated(-Posicion.x, -Posicion.y, 0);
}

// Metodos del obstaculo de fuego

bool Obs_Fuego::interrumpir(Pokemon &personaje)
{

	if (Colisiones::colision(Hitbox, Posicion, personaje.consultar_hitbox(), personaje.consultar_posicion()) 
		&& personaje.consultar_estado() != EfectoEstado::Invulnerable)
	{
		personaje.modificar_estado(EfectoEstado::Quemadura, frames_fuego);
		return true;
	}
	return false;
}

void Obs_Fuego::dibujar()
{
	glTranslated(Posicion.x, Posicion.y, 0);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 0, 0);
	glVertex3d(-Hitbox.x, -Hitbox.y, 0);
	glVertex3d(-Hitbox.x, Hitbox.y, 0);
	glColor3ub(255, 0, 0);
	glVertex3d(Hitbox.x, Hitbox.y, 0);
	glVertex3d(Hitbox.x, -Hitbox.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glTranslated(-Posicion.x, -Posicion.y, 0);
}
