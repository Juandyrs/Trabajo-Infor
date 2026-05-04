#include "Obstaculo.h"
#include <freeglut.h>

void Obs_Piedra::interrumpir(Pokemon& personaje)
{
	double distancia_x = abs(Posicion.x - personaje.pos_arena.x);
	double distancia_y = abs(Posicion.y - personaje.pos_arena.y);

	if (distancia_x < (Hitbox.x + personaje.Hitbox.x) && distancia_y < (Hitbox.y + personaje.Hitbox.y))
	{
		personaje.pos_arena = personaje.pos_arena - personaje.dir_mov * personaje.velocidad;
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

void Obs_Fuego::interrumpir(Pokemon& personaje)
{

}

void Obs_Fuego::dibujar()
{

}
