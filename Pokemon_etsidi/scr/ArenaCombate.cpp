#include "ArenaCombate.h"
#include <freeglut.h>

bool atk1 = false, atk1_ini = false, atk2 = false, atk2_ini = false;

void ArenaCombate::dibuja_Arena()
{
	//Dibujar el suelo de la arena
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

	//Dibujar barras de vida 

	//Barra de vida del equipo 1

	if (equipo1.vida_actual >= 0)
	{
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3ub(255, 0, 0);
		glVertex3d(-dimensiones_arena.x - 4, -equipo1.vida_actual / 10 - 0.5, 0);
		glVertex3d(-dimensiones_arena.x - 4, equipo1.vida_actual / 10 + 0.5, 0);
		glColor3ub(255, 0, 0);
		glVertex3d(-dimensiones_arena.x - 2, equipo1.vida_actual / 10 + 0.5, 0);
		glVertex3d(-dimensiones_arena.x - 2, -equipo1.vida_actual / 10 - 0.5, 0);
		glEnd();
		glEnable(GL_LIGHTING);
	}

	//Contenedor de Barra de vida del equipo 1



	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex3d(-dimensiones_arena.x - 4, -dimensiones_arena.y - 0.5, 0);
	glVertex3d(-dimensiones_arena.x - 4, dimensiones_arena.y + 0.5, 0);
	glColor3ub(255, 255, 255);
	glVertex3d(-dimensiones_arena.x - 2, dimensiones_arena.y + 0.5, 0);
	glVertex3d(-dimensiones_arena.x - 2, -dimensiones_arena.y - 0.5, 0);
	glEnd();
	glEnable(GL_LIGHTING);

	//Barra de vida del equipo 2

	if (equipo2.vida_actual >= 0)
	{
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3ub(255, 0, 0);
		glVertex3d(dimensiones_arena.x + 4, -equipo2.vida_actual / 10 - 0.5, 0);
		glVertex3d(dimensiones_arena.x + 4, equipo2.vida_actual / 10 + 0.5, 0);
		glColor3ub(255, 0, 0);
		glVertex3d(dimensiones_arena.x + 2, equipo2.vida_actual / 10 + 0.5, 0);
		glVertex3d(dimensiones_arena.x + 2, -equipo2.vida_actual / 10 - 0.5, 0);
		glEnd();
		glEnable(GL_LIGHTING);
	}

	//Contenedor de Barra de vida del equipo 2

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex3d(dimensiones_arena.x + 4, -dimensiones_arena.y - 0.5, 0);
	glVertex3d(dimensiones_arena.x + 4, dimensiones_arena.y + 0.5, 0);
	glColor3ub(255, 255, 255);
	glVertex3d(dimensiones_arena.x + 2, dimensiones_arena.y + 0.5, 0);
	glVertex3d(dimensiones_arena.x + 2, -dimensiones_arena.y - 0.5, 0);
	glEnd();
	glEnable(GL_LIGHTING);
}

void ArenaCombate::dibuja_Personajes()
{
	//PlaceHolders hay que cambiarlos
	glColor3ub(255,255,0);
	glTranslated(equipo1.pos_arena.x, equipo1.pos_arena.y, 0);
	glutSolidSphere(1, 20, 20);
	glTranslated(-equipo1.pos_arena.x, -equipo1.pos_arena.y, 0);

	glTranslated(equipo2.pos_arena.x, equipo2.pos_arena.y, 0);
	glutSolidSphere(1, 20, 20);
	glTranslated(-equipo2.pos_arena.x, -equipo2.pos_arena.y, 0);

	if (atk1)
	{
		equipo1.atacar_dibujar();;
	}
	if (atk2)
	{
		equipo2.atacar_dibujar();;
	}

}

void ArenaCombate::arena_combate()
{
	if (atk1_ini)
	{
		atk1 = true;
		equipo1.atacar(equipo1.pos_arena, equipo1.dir_mov);
		atk1_ini = false;
	}
	if (atk2_ini)
	{
		atk2 = true;
		equipo2.atacar(equipo2.pos_arena, equipo2.dir_mov);
		atk2_ini = false;
	}

	if (atk1)
	{
		equipo1.mueve_ataque();
		atk1 = !equipo1.colision_ataque(equipo2);
	}

	if (atk2)
	{
		equipo2.mueve_ataque();
		atk2 = !equipo2.colision_ataque(equipo1);
	}
}

void ArenaCombate::mueve_personaje(bool key[])
{

	if ((key['w']|| key['W']) && equipo1.pos_arena.y < dimensiones_arena.y)
	{
		equipo1.pos_arena.y += 0.1;
		equipo1.dir_mov = { 0.0, 1.0 };
	}
	if ((key['s'] || key['S']) && equipo1.pos_arena.y > -dimensiones_arena.y)
	{
		equipo1.pos_arena.y -= 0.1;
		equipo1.dir_mov = { 0.0, -1.0 };
	}
	if ((key['d'] || key['D']) && equipo1.pos_arena.x < dimensiones_arena.x)
	{
		equipo1.pos_arena.x += 0.1;
		equipo1.dir_mov = { 1.0, 0.0 };
	}
	if ((key['a'] || key['A']) && equipo1.pos_arena.x > -dimensiones_arena.x)
	{
		equipo1.pos_arena.x -= 0.1;
		equipo1.dir_mov = { -1.0, 0.0 };
	}
	if ((key['f'] || key['F'])) atk1_ini = true;

	if ((key['i'] || key['I']) && equipo2.pos_arena.y < dimensiones_arena.y)
	{
		equipo2.pos_arena.y += 0.1;
		equipo2.dir_mov = { 0.0, 1.0 };
	}
	if ((key['k'] || key['K']) && equipo2.pos_arena.y > -dimensiones_arena.y)
	{
		equipo2.pos_arena.y -= 0.1;
		equipo2.dir_mov = { 0.0, -1.0 };
	}
	if ((key['l'] || key['L']) && equipo2.pos_arena.x < dimensiones_arena.x)
	{
		equipo2.pos_arena.x += 0.1;
		equipo2.dir_mov = { 1.0, 0.0 };
	}
	if ((key['j'] || key['J']) && equipo2.pos_arena.x > -dimensiones_arena.x)
	{
		equipo2.pos_arena.x -= 0.1;
		equipo2.dir_mov = { -1.0, 0.0 };
	}
	if ((key['h'] || key['H'])) atk2_ini = true;	
}
 