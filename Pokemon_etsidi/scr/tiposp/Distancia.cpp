#include "Distancia.h"
#include <Ataque.h>
#include <freeglut.h>
#include "cmath"

void Distancia::atacar(Vector2D posicion, Vector2D dir)
{	
	double velocidad_ataque = 0.1;

	ataque.pos_atk = posicion;
	ataque.dir_atk = dir;
	ataque.vel_proyectil = velocidad_ataque * dir;

}

void Distancia::atacar_dibujar()
{
	glColor3ub(255, 0, 0);
	glTranslated(ataque.pos_atk.x, ataque.pos_atk.y, 0);
	glutSolidSphere(static_cast<Rango&>(ataque).radio_proyectil, 20, 20);
	glTranslated(-ataque.pos_atk.x, -ataque.pos_atk.y, 0);
}

bool Distancia::colision_ataque(Pokemon &objetivo)
{
	//Calculo de la distancia entre el ataque y el objetivo
	double distancia_x = abs(ataque.pos_atk.x - objetivo.pos_arena.x);
	double distancia_y = abs(ataque.pos_atk.y - objetivo.pos_arena.y);

	if (distancia_x < (ataque.radio_proyectil + objetivo.Hitbox.x) && distancia_y < (ataque.radio_proyectil + objetivo.Hitbox.y)) 
	{

		// Colisión detectada, aplicar daño al objetivo
		objetivo.vida_actual -= ataque.dano;
		return true;
	}

	return false;

}