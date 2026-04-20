#include "ArenaCombate.h"
#include <freeglut.h>

void ArenaCombate::dibuja_Arena()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 0);
	glVertex3d(-dimensiones_arena.x, -dimensiones_arena.y, 0);
	glVertex3d(-dimensiones_arena.x, dimensiones_arena.y, 0);
	glColor3ub(0, 255, 0);
	glVertex3d(dimensiones_arena.x, dimensiones_arena.y, 0);
	glVertex3d(dimensiones_arena.x, -dimensiones_arena.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);
}

void ArenaCombate::dibuja_Personajes()
{
	//PlaceHolders hay que cambiarlos
	glTranslated(equipo1.pos_arena.x, equipo1.pos_arena.y, 0);
	glutSolidSphere(1, 20, 20);
	glTranslated(-equipo1.pos_arena.x, -equipo1.pos_arena.y, 0);

	glTranslated(equipo2.pos_arena.x, equipo2.pos_arena.y, 0);
	glutSolidSphere(1, 20, 20);
	glTranslated(-equipo2.pos_arena.x, equipo2.pos_arena.y, 0);
}

void ArenaCombate::inicializar_pos(Pokemon team1, Pokemon team2)
{
	equipo1 = team1;
	equipo2 = team2;

	equipo1.pos_arena = pos_inicial_equipo1;
	equipo2.pos_arena = pos_inicial_equipo2;
}

void ArenaCombate::mueve_personaje(bool key[])
{
	if (key['w'] && equipo1.pos_arena.y < dimensiones_arena.y) equipo1.pos_arena.y += 0.1;
	if (key['s'] && equipo1.pos_arena.y > -dimensiones_arena.y) equipo1.pos_arena.y -= 0.1;
	if (key['d'] && equipo1.pos_arena.x < dimensiones_arena.x) equipo1.pos_arena.x += 0.1;
	if (key['a'] && equipo1.pos_arena.x > -dimensiones_arena.x) equipo1.pos_arena.x -= 0.1;

	if (key['i'] && equipo2.pos_arena.y < dimensiones_arena.y) equipo2.pos_arena.y += 0.1;
	if (key['k'] && equipo2.pos_arena.y > -dimensiones_arena.y) equipo2.pos_arena.y -= 0.1;
	if (key['l'] && equipo2.pos_arena.x < dimensiones_arena.x) equipo2.pos_arena.x += 0.1;
	if (key['j'] && equipo2.pos_arena.x > -dimensiones_arena.x) equipo2.pos_arena.x -= 0.1;
}
 