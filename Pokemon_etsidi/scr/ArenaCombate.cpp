#include "ArenaCombate.h"
#include <freeglut.h>

bool atk1 = false, atk2 = false;

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

	if (atk1)
	{
		equipo1.atacar_dibujar();;
	}
	if (atk2)
	{
		equipo2.atacar_dibujar();;
	}

}

void ArenaCombate::arena_transicion()
{
	if (atk1)
	{
		equipo1.atacar(equipo1.pos_arena, equipo1.dir_mov);
	}

	if (atk2)
	{
		equipo2.atacar(equipo2.pos_arena, equipo2.dir_mov);
	}
}

void ArenaCombate::inicializar_pos()
{

	equipo1.pos_arena = {-dimensiones_arena.x + 2, 0};
	equipo2.pos_arena = {dimensiones_arena.x - 2, 0};

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
	if ((key['f'] || key['F'])) atk1 = true;

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
	if ((key['h'] || key['H'])) atk2 = true;	
}
 