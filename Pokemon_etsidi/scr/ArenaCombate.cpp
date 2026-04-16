#include "ArenaCombate.h"
#include <freeglut.h>

void ArenaCombate::dibuja_Arena()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 0);
	glVertex3d(-dimensiones_arena.x, 0, -dimensiones_arena.y);
	glVertex3d(-dimensiones_arena.x, 0, dimensiones_arena.y);
	glColor3ub(0, 255, 0);
	glVertex3d(dimensiones_arena.x, 0, dimensiones_arena.y);
	glVertex3d(dimensiones_arena.x, 0, -dimensiones_arena.y);
	glEnd();
	glEnable(GL_LIGHTING);
}

void ArenaCombate::dibuja_Personajes(Pokemon& equipo1, Pokemon& equipo2)
{
	//PlaceHolders hay que cambiarlos
	glTranslated(pos_equipo1.x, 0, pos_equipo1.y);
	glutSolidSphere(1, 20, 20);
	glTranslated(-pos_equipo1.x, 0, -pos_equipo1.y);

	glTranslated(pos_equipo2.x, 0, pos_equipo2.y);
	glutSolidSphere(1, 20, 20);
	glTranslated(-pos_equipo2.x, 0, -pos_equipo2.y);
}
