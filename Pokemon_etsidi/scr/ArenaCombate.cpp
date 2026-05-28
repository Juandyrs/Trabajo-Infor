#include "ArenaCombate.h"
#include <freeglut.h>
#include "Colisiones.h"
#include "InteraccionArena.h"

bool atk1_ini = false, atk2_ini = false;
double cd1 = 0.0, cd2 = 0.0;
Ataque *ataque1, *Ataque2;

//Metodos de dibujo

void ArenaCombate::dibuja_Arena()
{
	dibuja_Obstaculos();
	dibuja_Personajes();
	dibuja_Ataques();
	dibuja_suelo();
	dibuja_BarrasVida();
}

void ArenaCombate::dibuja_suelo()
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
	if (equipo1->vida_actual > 0)
	{
		// Para probar hitbox, temporal hasta que se prueben todos las colisiones
		glColor3ub(0, 255, 255);
		equipo1->hitbox->dibujar();

		// Personaje real, placeholder, hay que cambiarlo
		glColor3ub(255, 255, 0);
		glTranslated(equipo1->hitbox->pos.x, equipo1->hitbox->pos.y, 0);
		glutSolidSphere(0.5, 20, 20);
		glTranslated(-equipo1->hitbox->pos.x, -equipo1->hitbox->pos.y, 0);
	}

	if(equipo2->vida_actual > 0)
	{
		// Para probar hitbox, temporal hasta que se prueben todos las colisiones
		glColor3ub(0, 255, 255);
		equipo2->hitbox->dibujar();

		// Personaje real, placeholder, hay que cambiarlo
		glColor3ub(0, 255, 0);
		glTranslated(equipo2->hitbox->pos.x, equipo2->hitbox->pos.y, 0);
		glutSolidSphere(0.5, 20, 20);
		glTranslated(-equipo2->hitbox->pos.x, -equipo2->hitbox->pos.y, 0);
		
	}

}

void ArenaCombate::dibuja_BarrasVida()
{
	//Dibujar barras de vida 

	double a{ 2.0 }, b{ 1.0 }, c{ 20.0 }, d{ 0.5 }; //Parametros de ajuste

	//Barra de vida del equipo 1

	if (equipo1->vida_actual >= 0)
	{
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3ub(255, 0, 0);
		glVertex3d(-dimensiones_arena.x - a, -equipo1->vida_actual / c, 0);
		glVertex3d(-dimensiones_arena.x - a, equipo1->vida_actual / c, 0);
		glColor3ub(255, 0, 0);
		glVertex3d(-dimensiones_arena.x - b, equipo1->vida_actual / c, 0);
		glVertex3d(-dimensiones_arena.x - b, -equipo1->vida_actual / c, 0);
		glEnd();
		glEnable(GL_LIGHTING);
	}

	//Contenedor de Barra de vida del equipo 1

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex3d(-dimensiones_arena.x - a, -dimensiones_arena.y - d, 0);
	glVertex3d(-dimensiones_arena.x - a, dimensiones_arena.y + d, 0);
	glColor3ub(255, 255, 255);
	glVertex3d(-dimensiones_arena.x - b, dimensiones_arena.y + d, 0);
	glVertex3d(-dimensiones_arena.x - b, -dimensiones_arena.y - d, 0);
	glEnd();
	glEnable(GL_LIGHTING);

	//Barra de vida del equipo 2

	if (equipo2->vida_actual >= 0)
	{
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3ub(255, 0, 0);
		glVertex3d(dimensiones_arena.x + a, -equipo2->vida_actual / c, 0);
		glVertex3d(dimensiones_arena.x + a, equipo2->vida_actual / c, 0);
		glColor3ub(255, 0, 0);
		glVertex3d(dimensiones_arena.x + b, equipo2->vida_actual / c, 0);
		glVertex3d(dimensiones_arena.x + b, -equipo2->vida_actual / c, 0);
		glEnd();
		glEnable(GL_LIGHTING);
	}

	//Contenedor de Barra de vida del equipo 2

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex3d(dimensiones_arena.x + a, -dimensiones_arena.y - d, 0);
	glVertex3d(dimensiones_arena.x + a, dimensiones_arena.y + d, 0);
	glColor3ub(255, 255, 255);
	glVertex3d(dimensiones_arena.x + b, dimensiones_arena.y + d, 0);
	glVertex3d(dimensiones_arena.x + b, -dimensiones_arena.y - d, 0);
	glEnd();
	glEnable(GL_LIGHTING);
}

void ArenaCombate::dibuja_Ataques()
{
	if (equipo1->atacando)
	{
		equipo1->ataque->atacar_dibujar();
	}
	if (equipo2->atacando)
	{
		equipo2->ataque->atacar_dibujar();
	}
}

void ArenaCombate::dibuja_Obstaculos()
{
	obstaculos.dibujar_Obstaculos();
}

//Metodos de movimiento y ataque

void ArenaCombate::arena_combate()
{ 
	InteraccionArena::aplicar_Efectos(*equipo1);
	InteraccionArena::aplicar_Efectos(*equipo2);

	if (atk1_ini)
	{
		equipo1->atacando = true;
		equipo1->ataque->iniciar_ataque(equipo1->hitbox->pos, equipo1->dir_mov);
		cd1 = equipo1->cooldown;
		atk1_ini = false;
	}
	if (atk2_ini)
	{
		equipo2->atacando = true;
		equipo2->ataque->iniciar_ataque(equipo2->hitbox->pos, equipo2->dir_mov);
		cd2 = equipo2->cooldown;
		atk2_ini = false;
	}

	if (equipo1->atacando) equipo1->atacando = !InteraccionArena::colisiona_ataques_obst(obstaculos, *equipo1->consultar_ataque());
	if (equipo1->atacando) equipo1->atacando = !InteraccionArena::colision_ataques_arena(*this, *equipo1->consultar_ataque());

	if (equipo2->atacando) equipo2->atacando = !InteraccionArena::colisiona_ataques_obst(obstaculos, *equipo2->consultar_ataque());
	if (equipo2->atacando) equipo2->atacando = !InteraccionArena::colision_ataques_arena(*this, *equipo2->consultar_ataque());

	equipo1->atacar(*equipo2);
	equipo2->atacar(*equipo1);

	// Cooldown para pruebas, hay que cambiarlo 
	if (cd1 > 0) cd1 -= 1;
	if (cd2 > 0) cd2 -= 1;

}

void ArenaCombate::interaccion_obstaculos()
{
	static bool team1_inter = false, team2_inter = false;

	obstaculos.interrumpir_Obstaculos(*equipo1);
	obstaculos.interrumpir_Obstaculos(*equipo2);
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

		pos.x = rand() % (2*((int)dimensiones_arena.x - 1) + 1) - ((int)dimensiones_arena.x - 1);
		pos.y = rand() % (2*((int)dimensiones_arena.y - 1) + 1) - ((int)dimensiones_arena.y - 1);
		temporal.hitbox->pos = pos;

		//Para evitar que un obstaculo se genere encima de un personaje
		if (Colisiones::colision(temporal.consultar_hitbox(), equipo1->consultar_hitbox()) || Colisiones::colision(temporal.consultar_hitbox(), equipo2->consultar_hitbox()))
		{
			continue;
		}

		//Para evitar que un obstaculo se genere encima de otro obstaculo
		for (int j = 0; j < obstaculos.size(); j++)
		{
			if (Colisiones::colision(temporal.consultar_hitbox(), obstaculos.obtener_Obstaculo(j).consultar_hitbox()))
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

	if (equipo1->hitbox->pos.x >= dimensiones_arena.x) equipo1->hitbox->pos.x = dimensiones_arena.x;
	if (equipo1->hitbox->pos.x <= -dimensiones_arena.x) equipo1->hitbox->pos.x = -dimensiones_arena.x;
	if (equipo1->hitbox->pos.y >= dimensiones_arena.y) equipo1->hitbox->pos.y = dimensiones_arena.y;
	if (equipo1->hitbox->pos.y <= -dimensiones_arena.y) equipo1->hitbox->pos.y = -dimensiones_arena.y;

	if (equipo2->hitbox->pos.x >= dimensiones_arena.x) equipo2->hitbox->pos.x = dimensiones_arena.x;
	if (equipo2->hitbox->pos.x <= -dimensiones_arena.x) equipo2->hitbox->pos.x = -dimensiones_arena.x;
	if (equipo2->hitbox->pos.y >= dimensiones_arena.y) equipo2->hitbox->pos.y = dimensiones_arena.y;
	if (equipo2->hitbox->pos.y <= -dimensiones_arena.y) equipo2->hitbox->pos.y = -dimensiones_arena.y;
}

void ArenaCombate::inicializa_Arena(Pokemon *t1, Pokemon *t2, bool ia)
{
	IA_activa = ia;

	equipo1 = t1;
	equipo2 = t2;

	equipo1->hitbox->pos = { -dimensiones_arena.x + 2, 0 };
	equipo2->hitbox->pos = { dimensiones_arena.x - 2, 0 };

	inicializa_obstaculos();
}

Pokemon* ArenaCombate::devolver_ganador()
{
	if (equipo1->vida_actual == 0)
	{
		equipo1->estado = Estado::Muerto;
		return equipo2;
	}
	if (equipo2->vida_actual == 0)
	{
		equipo2->estado = Estado::Muerto;
		return equipo1;
	}
	return nullptr;
}

void ArenaCombate::mueve_personaje(bool key[])
{
	Vector2D dir1{ 0,0 };

	if (key['w']|| key['W']) dir1 += { 0.0, 1.0 };
	if (key['s'] || key['S']) dir1 += { 0.0, -1.0 };
	if (key['d'] || key['D']) dir1 += { 1.0, 0.0 };
	if (key['a'] || key['A']) dir1 += { -1.0, 0.0 };
	if ((key['f'] || key['F']) && cd1 <= 0) atk1_ini = true;
	if (dir1.modulo() != 0) equipo1->mover_arena(dir1.unitario());

	if (IA_activa) return;

	Vector2D dir2{ 0,0 };

	if (key['i'] || key['I']) dir2 += { 0.0, 1.0 };
	if (key['k'] || key['K']) dir2 += { 0.0, -1.0 };
	if (key['l'] || key['L']) dir2 += { 1.0, 0.0 };
	if (key['j'] || key['J']) dir2 += { -1.0, 0.0 };
	if ((key['h'] || key['H']) && cd2 <= 0) atk2_ini = true;
	if (dir2.modulo() != 0) equipo2->mover_arena(dir2.unitario());

}
 
void ArenaCombate::resetear_Arena()
{
	//Reinicio los obstaculos
	obstaculos.eliminar_Contenido();

	//Reinicio variables internas
	atk1_ini = false;
	atk2_ini = false;
	cd1 = 0.0;
	cd2 = 0.0;

	//Reinicio ataque de pokemons y algunas estadisticas
	equipo1->atacando = false;
	equipo2->atacando = false;
	equipo1->ataque->dano = equipo1->dano;
	equipo2->ataque->dano = equipo2->dano;
	equipo1->efecto_estado = EfectoEstado::Ninguno;
	equipo2->efecto_estado = EfectoEstado::Ninguno;
	equipo1->duracion_efecto = 0;
	equipo2->duracion_efecto = 0;
	equipo1->dir_mov = Vector2D{ 0.0,0.0 };
	equipo2->dir_mov = Vector2D{ 0.0,0.0 };
}