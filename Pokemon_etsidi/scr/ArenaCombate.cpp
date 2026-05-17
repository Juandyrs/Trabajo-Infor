#include "ArenaCombate.h"
#include <freeglut.h>
#include "Colisiones.h"
#include "InteraccionArena.h"

bool atk1_ini = false, atk2_ini = false;
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
	if (equipo1.atacando)
	{
		equipo1.ataque->atacar_dibujar();
	}
	if (equipo2.atacando)
	{
		equipo2.ataque->atacar_dibujar();
	}
}

void ArenaCombate::dibuja_Obstaculos()
{
	obstaculos.dibujar_Obstaculos();
}

//Metodos de movimiento y ataque

void ArenaCombate::arena_combate()
{ 
	InteraccionArena::aplicar_Efectos(equipo1);
	InteraccionArena::aplicar_Efectos(equipo2);

	if (atk1_ini)
	{
		equipo1.atacando = true;
		equipo1.ataque->iniciar_ataque(equipo1.pos_arena, equipo1.dir_mov);
		cd1 = equipo1.cooldown;
		atk1_ini = false;
	}
	if (atk2_ini)
	{
		equipo2.atacando = true;
		equipo2.ataque->iniciar_ataque(equipo2.pos_arena, equipo2.dir_mov);
		cd2 = equipo2.cooldown;
		atk2_ini = false;
	}

	equipo1.atacar(equipo2);

	equipo2.atacar(equipo1);

	// Cooldown para pruebas, hay que cambiarlo 
	if (cd1 > 0) cd1 -= 1;
	if (cd2 > 0) cd2 -= 0.1;
}

void ArenaCombate::interaccion_obstaculos()
{
	static bool team1_inter = false, team2_inter = false;

	obstaculos.interrumpir_Obstaculos(equipo1);
	obstaculos.interrumpir_Obstaculos(equipo2);
}

void ArenaCombate::inicializa_obstaculos()
{
	int cantidad_max_obtaculos{10};
	int cantidad_min_obstaculos{4};
	Vector2D pos{0, 0};
	Obs_Piedra temporal({0,0});

	srand(time(NULL));
	
	int cantidad_obstaculos = rand() % (cantidad_max_obtaculos - cantidad_min_obstaculos + 1) + cantidad_min_obstaculos;
	int i{};
	bool salir{ false };

	while (i < cantidad_obstaculos)
	{
		salir = false;

		pos.x = rand() % (2*((int)dimensiones_arena.x - 2) + 1) - ((int)dimensiones_arena.x - 2);
		pos.y = rand() % (2*((int)dimensiones_arena.y - 2) + 1) - ((int)dimensiones_arena.y - 2);

		//Para evitar que un obstaculo se genere encima de un personaje
		if (Colisiones::colision(temporal.consultar_hitbox(), pos, equipo1.consultar_hitbox(), equipo1.pos_arena) || Colisiones::colision(temporal.consultar_hitbox(), pos, equipo2.consultar_hitbox(), equipo2.pos_arena))
		{
			continue;
		}

		//Para evitar que un obstaculo se genere encima de otro obstaculo
		for (int j = 0; j < obstaculos.obtener_Tamano(); j++)
		{
			if (Colisiones::colision(temporal.consultar_hitbox(), pos, obstaculos.obtener_Obstaculo(j).consultar_hitbox(), obstaculos.obtener_Obstaculo(j).consultar_posicion()))
			{
				salir = true;
				break;
			}
		}

		if (salir) continue;

		obstaculos.agregar_Obstaculo(new Obs_Piedra(pos));
		i++;
	}	
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

void ArenaCombate::inicializa_Arena(Pokemon &t1, Pokemon &t2, bool ia)
{
	IA_activa = ia;

	equipo1 = t1;
	equipo2 = t2;

	equipo1.pos_arena = { -dimensiones_arena.x + 2, 0 };
	equipo2.pos_arena = { dimensiones_arena.x - 2, 0 };
}

void ArenaCombate::mueve_personaje(bool key[])
{

	if ((key['w']|| key['W']) && !(key['d'] || key['D']) && !(key['a'] || key['A'])) equipo1.mover_arena({ 0.0, 1.0 });
	if ((key['s'] || key['S']) && !(key['d'] || key['D']) && !(key['a'] || key['A'])) equipo1.mover_arena({ 0.0, -1.0 });
	if ((key['d'] || key['D']) && !(key['w'] || key['W']) && !(key['s'] || key['S'])) equipo1.mover_arena({ 1.0, 0.0 });
	if ((key['a'] || key['A']) && !(key['w'] || key['W']) && !(key['s'] || key['S'])) equipo1.mover_arena({ -1.0, 0.0 });
	if ((key['w'] || key['W']) && (key['d'] || key['D'])) equipo1.mover_arena({ sqrt(2) / 2, sqrt(2) / 2 });
	if ((key['w'] || key['W']) && (key['a'] || key['A'])) equipo1.mover_arena({ -sqrt(2) / 2, sqrt(2) / 2 });
	if ((key['s'] || key['S']) && (key['d'] || key['D'])) equipo1.mover_arena({ sqrt(2) / 2, -sqrt(2) / 2 });
	if ((key['s'] || key['S']) && (key['a'] || key['A'])) equipo1.mover_arena({ -sqrt(2) / 2, -sqrt(2) / 2 });
	if ((key['f'] || key['F']) && cd1 <= 0) atk1_ini = true;
		
	if (IA_activa) return;

	if ((key['i'] || key['I']) && !(key['l'] || key['L']) && !(key['j'] || key['J'])) equipo2.mover_arena({ 0.0, 1.0 });
	if ((key['k'] || key['K']) && !(key['l'] || key['L']) && !(key['j'] || key['J'])) equipo2.mover_arena({ 0.0, -1.0 });
	if ((key['l'] || key['L']) && !(key['i'] || key['I']) && !(key['k'] || key['K'])) equipo2.mover_arena({ 1.0, 0.0 });
	if ((key['j'] || key['J']) && !(key['i'] || key['I']) && !(key['k'] || key['K'])) equipo2.mover_arena({ -1.0, 0.0 });
	if ((key['i'] || key['I']) && (key['l'] || key['L'])) equipo2.mover_arena({ sqrt(2) / 2, sqrt(2) / 2 });
	if ((key['i'] || key['I']) && (key['j'] || key['J'])) equipo2.mover_arena({ -sqrt(2) / 2, sqrt(2) / 2 });
	if ((key['k'] || key['K']) && (key['l'] || key['L'])) equipo2.mover_arena({ sqrt(2) / 2, -sqrt(2) / 2 });
	if ((key['k'] || key['K']) && (key['j'] || key['J'])) equipo2.mover_arena({ -sqrt(2) / 2, -sqrt(2) / 2 });
	if ((key['h'] || key['H']) && cd2 <= 0) atk2_ini = true;
}
 