#include "Tanque.h"
#include <freeglut.h>

void Tanque::atacar(Vector2D posicion, Vector2D dir)
{
	double velocidad_ataque = 0.1;

	ataque.pos_atk = posicion;
	ataque.dir_atk = dir;
	ataque.vel_proyectil = velocidad_ataque * dir;

}

void Tanque::atacar_dibujar()
{
	glColor3ub(255, 0, 0);
	glTranslated(ataque.pos_atk.x, ataque.pos_atk.y, 0);
	glutSolidSphere(ataque.radio_proyectil, 20, 20);
	glTranslated(-ataque.pos_atk.x, -ataque.pos_atk.y, 0);
}

bool Tanque::colision_ataque(Pokemon &objetivo)
{
	//Calculo de la distancia entre el ataque y el objetivo
	double distancia_x = abs(ataque.pos_atk.x - objetivo.consultar_posicion().x);
	double distancia_y = abs(ataque.pos_atk.y - objetivo.consultar_posicion().y);

	if (distancia_x < (ataque.radio_proyectil + objetivo.consultar_hitbox().x) && distancia_y < (ataque.radio_proyectil + objetivo.consultar_hitbox().y))
	{

		// Colisión detectada, aplicar daño al objetivo
		objetivo.recibir_dano(ataque.dano);
		return true;
	}

	return false;

}