#include "Obstaculo.h"
#include <freeglut.h>
#include "Colisiones.h"

// Metodos del obstaculo de piedra

void Obs_Piedra::interrumpir(Pokemon &personaje)
{

	if (Colisiones::colision(Hitbox, Posicion, personaje.consultar_hitbox(), personaje.consultar_posicion()))
	{
		personaje.pos_arena = personaje.consultar_posicion() - personaje.dir_mov * personaje.velocidad;
	}

} 

void Obs_Piedra::dibujar()
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

// Metodos del obstaculo de fuego

void Obs_Fuego::interrumpir(Pokemon &personaje)
{

	double dano_fuego{ 2.0 };
	double frames_fuego{ 30.0 };
	static double frame{ frames_fuego };
	static double contador_fuego{ 10 };
	double velocidad_extincion_fuego{ 1 };

	if (Colisiones::colision(Hitbox, Posicion, personaje.consultar_hitbox(), personaje.consultar_posicion())
		&& (contador_fuego == 10))
	{
		personaje.recibir_dano(dano_fuego);
		contador_fuego = 0;
		frame = frames_fuego;
	}

	if (frame <= 0)
	{
		frame = frames_fuego;
		contador_fuego = 10;
	}

	frame -= velocidad_extincion_fuego;

	if (contador_fuego < 10) contador_fuego++;
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
