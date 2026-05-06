#include "ArenaCombate.h"
#include <freeglut.h>

bool atk1 = false, atk1_ini = false, atk2 = false, atk2_ini = false;
double cd1 = 0.0, cd2 = 0.0;

//Metodos de dibujo

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

}

void ArenaCombate::dibuja_Personajes()
{
	//PlaceHolders hay que cambiarlos
	if (equipo1.vida_actual > 0)
	{
		// Para probar hitbox, temporal hasta que se prueben todos las colisiones
		glTranslated(equipo1.pos_arena.x, equipo1.pos_arena.y, 0);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3ub(0, 255, 255);
		glVertex3d(-equipo1.Hitbox.x, -equipo1.Hitbox.y, 0);
		glVertex3d(-equipo1.Hitbox.x, equipo1.Hitbox.y, 0);
		glColor3ub(0, 255, 255);
		glVertex3d(equipo1.Hitbox.x, equipo1.Hitbox.y, 0);
		glVertex3d(equipo1.Hitbox.x, -equipo1.Hitbox.y, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glTranslated(-equipo1.pos_arena.x, -equipo1.pos_arena.y, 0);

		// Personaje real, placeholder, hay que cambiarlo
		glColor3ub(255, 255, 0);
		glTranslated(equipo1.pos_arena.x, equipo1.pos_arena.y, 0);
		glutSolidSphere(1, 20, 20);
		glTranslated(-equipo1.pos_arena.x, -equipo1.pos_arena.y, 0);
	}

	if(equipo2.vida_actual > 0)
	{
		// Para probar hitbox, temporal hasta que se prueben todos las colisiones
		glTranslated(equipo2.pos_arena.x, equipo2.pos_arena.y, 0);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3ub(0, 255, 255);
		glVertex3d(-equipo2.Hitbox.x, -equipo2.Hitbox.y, 0);
		glVertex3d(-equipo2.Hitbox.x, equipo2.Hitbox.y, 0);
		glColor3ub(0, 255, 255);
		glVertex3d(equipo2.Hitbox.x, equipo2.Hitbox.y, 0);
		glVertex3d(equipo2.Hitbox.x, -equipo2.Hitbox.y, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glTranslated(-equipo2.pos_arena.x, -equipo2.pos_arena.y, 0);

		// Personaje real, placeholder, hay que cambiarlo
		glColor3ub(0, 255, 0);
		glTranslated(equipo2.pos_arena.x, equipo2.pos_arena.y, 0);
		glutSolidSphere(1, 20, 20);
		glTranslated(-equipo2.pos_arena.x, -equipo2.pos_arena.y, 0);
		
	}

}



void ArenaCombate::dibuja_BarrasVida()
{
	//Dibujar barras de vida 

	//Barra de vida del equipo 1

	if (equipo1.vida_actual >= 0)
	{
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3ub(255, 0, 0);
		glVertex3d(-dimensiones_arena.x - 4, -equipo1.vida_actual / 10, 0);
		glVertex3d(-dimensiones_arena.x - 4, equipo1.vida_actual / 10, 0);
		glColor3ub(255, 0, 0);
		glVertex3d(-dimensiones_arena.x - 2, equipo1.vida_actual / 10, 0);
		glVertex3d(-dimensiones_arena.x - 2, -equipo1.vida_actual / 10, 0);
		glEnd();
		glEnable(GL_LIGHTING);
	}

	//Contenedor de Barra de vida del equipo 1

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex3d(-dimensiones_arena.x - 4, -dimensiones_arena.y - 1, 0);
	glVertex3d(-dimensiones_arena.x - 4, dimensiones_arena.y + 1, 0);
	glColor3ub(255, 255, 255);
	glVertex3d(-dimensiones_arena.x - 2, dimensiones_arena.y + 1, 0);
	glVertex3d(-dimensiones_arena.x - 2, -dimensiones_arena.y - 1, 0);
	glEnd();
	glEnable(GL_LIGHTING);

	//Barra de vida del equipo 2

	if (equipo2.vida_actual >= 0)
	{
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3ub(255, 0, 0);
		glVertex3d(dimensiones_arena.x + 4, -equipo2.vida_actual / 10, 0);
		glVertex3d(dimensiones_arena.x + 4, equipo2.vida_actual / 10, 0);
		glColor3ub(255, 0, 0);
		glVertex3d(dimensiones_arena.x + 2, equipo2.vida_actual / 10, 0);
		glVertex3d(dimensiones_arena.x + 2, -equipo2.vida_actual / 10, 0);
		glEnd();
		glEnable(GL_LIGHTING);
	}

	//Contenedor de Barra de vida del equipo 2

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex3d(dimensiones_arena.x + 4, -dimensiones_arena.y - 1, 0);
	glVertex3d(dimensiones_arena.x + 4, dimensiones_arena.y + 1, 0);
	glColor3ub(255, 255, 255);
	glVertex3d(dimensiones_arena.x + 2, dimensiones_arena.y + 1, 0);
	glVertex3d(dimensiones_arena.x + 2, -dimensiones_arena.y - 1, 0);
	glEnd();
	glEnable(GL_LIGHTING);
}

void ArenaCombate::dibuja_Ataques()
{
	if (atk1)
	{
		equipo1.ataque->atacar_dibujar();
	}
	if (atk2)
	{
		equipo2.ataque->atacar_dibujar();
	}
}

void ArenaCombate::dibuja_Obstaculos()
{
	obstaculo1.dibujar();
}

//Metodos de movimiento y ataque

void ArenaCombate::arena_combate()
{ 

	if (atk1_ini)
	{
		atk1 = true;
		equipo1.ataque->atacar(equipo1.pos_arena, equipo1.dir_mov);
		cd1 = equipo1.cooldown;
		atk1_ini = false;
	}
	if (atk2_ini)
	{
		atk2 = true;
		equipo2.ataque->atacar(equipo2.pos_arena, equipo2.dir_mov);
		cd2 = equipo2.cooldown;
		atk2_ini = false;
	}

	if (atk1)
	{
		equipo1.ataque->mueve_ataque();
		atk1 = !equipo1.ataque->colision_ataque(equipo2);
	}

	if (atk2)
	{
		equipo2.ataque->mueve_ataque();
		atk2 = !(equipo2.ataque->colision_ataque(equipo1));
	}

	// Cooldown para pruebas, hay que cambiarlo 
	if (cd1 > 0) cd1 -= 1;
	if (cd2 > 0) cd2 -= 1;
}

void ArenaCombate::interaccion_obstaculos()
{
	static bool team1_inter = false, team2_inter = false;

	obstaculo1.interrumpir(equipo1);
	obstaculo1.interrumpir(equipo2);

}

void ArenaCombate::limita_movimiento()
{

	if (equipo1.pos_arena.x >= dimensiones_arena.x) equipo1.pos_arena.x = dimensiones_arena.x;
	if (equipo1.pos_arena.x <= -dimensiones_arena.x) equipo1.pos_arena.x = -dimensiones_arena.x;
	if (equipo1.pos_arena.y >= dimensiones_arena.y) equipo1.pos_arena.y = dimensiones_arena.y;
	if (equipo1.pos_arena.y <= -dimensiones_arena.y) equipo1.pos_arena.y = -dimensiones_arena.y;

	if (equipo2.pos_arena.x >= dimensiones_arena.x) equipo2.pos_arena.x = dimensiones_arena.x;
	if (equipo2.pos_arena.x <= -dimensiones_arena.x) equipo2.pos_arena.x = -dimensiones_arena.x;
	if (equipo2.pos_arena.y >= dimensiones_arena.y) equipo2.pos_arena.y = dimensiones_arena.y;
	if (equipo2.pos_arena.y <= -dimensiones_arena.y) equipo2.pos_arena.y = -dimensiones_arena.y;
}

void ArenaCombate::mueve_personaje(bool key[])
{

	if ((key['w']|| key['W']) && !(key['d'] || key['D']) && !(key['a'] || key['A']))
	{
		equipo1.dir_mov = { 0.0, 1.0 };
		equipo1.pos_arena = equipo1.pos_arena + equipo1.dir_mov * equipo1.velocidad;
	}
	if ((key['s'] || key['S']) && !(key['d'] || key['D']) && !(key['a'] || key['A']))
	{
		equipo1.dir_mov = { 0.0, -1.0 };
		equipo1.pos_arena = equipo1.pos_arena + equipo1.dir_mov * equipo1.velocidad;
	}
	if ((key['d'] || key['D']) && !(key['w'] || key['W']) && !(key['s'] || key['S']))
	{
		equipo1.dir_mov = { 1.0, 0.0 };
		equipo1.pos_arena = equipo1.pos_arena + equipo1.dir_mov * equipo1.velocidad;
	}
	if ((key['a'] || key['A']) && !(key['w'] || key['W']) && !(key['s'] || key['S']))
	{
		equipo1.dir_mov = { -1.0, 0.0 };
		equipo1.pos_arena = equipo1.pos_arena + equipo1.dir_mov * equipo1.velocidad;
	}
	if ((key['w'] || key['W']) && (key['d'] || key['D']))
	{
		equipo1.dir_mov = { sqrt(2) / 2, sqrt(2) / 2 };
		equipo1.pos_arena = equipo1.pos_arena + equipo1.dir_mov * equipo1.velocidad;
	}
	if ((key['w'] || key['W']) && (key['a'] || key['A']))
	{
		equipo1.dir_mov = { -sqrt(2) / 2, sqrt(2) / 2 };
		equipo1.pos_arena = equipo1.pos_arena + equipo1.dir_mov * equipo1.velocidad;
	}
	if ((key['s'] || key['S']) && (key['d'] || key['D']))
	{
		equipo1.dir_mov = { sqrt(2) / 2, -sqrt(2) / 2 };
		equipo1.pos_arena = equipo1.pos_arena + equipo1.dir_mov * equipo1.velocidad;
	}
	if ((key['s'] || key['S']) && (key['a'] || key['A']))
	{
		equipo1.dir_mov = { -sqrt(2) / 2, -sqrt(2) / 2 };
		equipo1.pos_arena = equipo1.pos_arena + equipo1.dir_mov * equipo1.velocidad;
	}
	if ((key['f'] || key['F']) && cd1 <= 0) atk1_ini = true;


	if ((key['i'] || key['I']) && !(key['l'] || key['L']) && !(key['j'] || key['J']))
	{
		equipo2.dir_mov = { 0.0, 1.0 };
		equipo2.pos_arena = equipo2.pos_arena + equipo2.dir_mov * equipo2.velocidad;
	}
	if ((key['k'] || key['K']) && !(key['l'] || key['L']) && !(key['j'] || key['J']))
	{
		equipo2.dir_mov = { 0.0, -1.0 };
		equipo2.pos_arena = equipo2.pos_arena + equipo2.dir_mov * equipo2.velocidad;
	}
	if ((key['l'] || key['L']) && !(key['i'] || key['I']) && !(key['k'] || key['K']))
	{
		equipo2.dir_mov = { 1.0, 0.0 };
		equipo2.pos_arena = equipo2.pos_arena + equipo2.dir_mov * equipo2.velocidad;
	}
	if ((key['j'] || key['J']) && !(key['i'] || key['I']) && !(key['k'] || key['K']))
	{
		equipo2.dir_mov = { -1.0, 0.0 };
		equipo2.pos_arena = equipo2.pos_arena + equipo2.dir_mov * equipo2.velocidad;
	}
	if ((key['i'] || key['I']) && (key['l'] || key['L']))
	{
		equipo2.dir_mov = { sqrt(2) / 2, sqrt(2) / 2 };
		equipo2.pos_arena = equipo2.pos_arena + equipo2.dir_mov * equipo2.velocidad;
	}
	if ((key['i'] || key['I']) && (key['j'] || key['J']))
	{
		equipo2.dir_mov = { -sqrt(2) / 2, sqrt(2) / 2 };
		equipo2.pos_arena = equipo2.pos_arena + equipo2.dir_mov * equipo2.velocidad;
	}
	if ((key['k'] || key['K']) && (key['l'] || key['L']))
	{
		equipo2.dir_mov = { sqrt(2) / 2, -sqrt(2) / 2 };
		equipo2.pos_arena = equipo2.pos_arena + equipo2.dir_mov * equipo2.velocidad;
	}
	if ((key['k'] || key['K']) && (key['j'] || key['J']))
	{
		equipo2.dir_mov = { -sqrt(2) / 2, -sqrt(2) / 2 };
		equipo2.pos_arena = equipo2.pos_arena + equipo2.dir_mov * equipo2.velocidad;
	}	
	if ((key['h'] || key['H']) && cd2 <= 0) atk2_ini = true;
}
 