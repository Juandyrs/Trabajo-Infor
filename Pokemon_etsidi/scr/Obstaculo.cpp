#include "Obstaculo.h"
#include <freeglut.h>

// Metodos del obstaculo de piedra

void Obs_Piedra::interrumpir(Pokemon& personaje)
{
	double distancia_x = abs(Posicion.x - personaje.pos_arena.x);
	double distancia_y = abs(Posicion.y - personaje.pos_arena.y);

	if (distancia_x < (Hitbox.x + personaje.consultar_hitbox().x) && distancia_y < (Hitbox.y + personaje.consultar_hitbox().y))
	{
		personaje.pos_arena = personaje.consultar_posicion() - personaje.dir_mov * personaje.velocidad;
	}

}

void Obs_Piedra::dibujar()
{
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
}

// Metodos del obstaculo de fuego

void Obs_Fuego::interrumpir(Pokemon &personaje)
{

	double distancia_x = abs(Posicion.x - personaje.consultar_posicion().x);
	double distancia_y = abs(Posicion.y - personaje.consultar_posicion().y);

	double dano_fuego{ 2.0 };
	double frames_fuego{ 30.0 };
	static double frame{ frames_fuego };
	static double contador_fuego{ 10 };
	double velocidad_extincion_fuego{ 1 };

	if ((distancia_x < (Hitbox.x + personaje.consultar_hitbox().x) && distancia_y < (Hitbox.y + personaje.consultar_hitbox().y) 
		&& (contador_fuego == 10)))
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
}
