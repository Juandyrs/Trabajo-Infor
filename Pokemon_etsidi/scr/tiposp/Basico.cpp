#include "Basico.h"
#include <freeglut.h>
#include <numbers>

void Basico::atacar(Vector2D posicion, Vector2D dir)
{
	ataque.pos_atk = posicion;
	ataque.dir_atk = dir;
}

void Basico::atacar_dibujar()
{
	double ang_ataque = ataque.dir_atk.argumento();

	//Placeholder, hay que cambiarlo

	glTranslated(ataque.pos_atk.x, ataque.pos_atk.y, 0);
	glRotated(ang_ataque * 180 / std::numbers::pi, 0, 0, 1);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 0, 0);
	glVertex3d(0, ataque.ancho_ataque, 0);
	glVertex3d(ataque.rango_ataque, ataque.ancho_ataque, 0);
	glColor3ub(255, 0, 0);
	glVertex3d(ataque.rango_ataque, -ataque.ancho_ataque, 0);
	glVertex3d(0, -ataque.ancho_ataque, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glRotated(-ang_ataque * 180 / std::numbers::pi, 0, 0, 1);
	glTranslated(-ataque.pos_atk.x, -ataque.pos_atk.y, 0);
}

bool Basico::colision_ataque(Pokemon &objetivo)
{
	double ang_ataque = ataque.dir_atk.argumento();
	Vector2D ataque_centro = ataque.pos_atk + Vector2D{ ataque.rango_ataque/2 * cos(ang_ataque), ataque.ancho_ataque/2 * sin(ang_ataque) };
	double distancia_x = abs(ataque_centro.x - objetivo.consultar_posicion().x);
	double distancia_y = abs(ataque_centro.y - objetivo.consultar_posicion().y);
	static double frame_ataque = ataque.frame_ataque;


	//Debido a que el ataque melee puede estar rotado hay ligeros errores en la colision, por mientras se deja como si no lo estuviera. Es suficientemente aceptable
	if (distancia_x < ((ataque.rango_ataque/2 + objetivo.consultar_hitbox().x))
		&& distancia_y < ((ataque.ancho_ataque + objetivo.consultar_hitbox().y)))
	{
		objetivo.recibir_dano(ataque.dano);
		return true;
	}

	if (frame_ataque > 0)
	{
		frame_ataque -= 0.1;
		return false;
	}
	else
	{
		frame_ataque = ataque.frame_ataque;
		return true;
	}

	return false;
}

