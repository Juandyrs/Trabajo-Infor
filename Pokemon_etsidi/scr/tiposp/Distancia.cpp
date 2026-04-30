#include "Distancia.h"
#include <Ataque.h>
#include <freeglut.h>

void Distancia::atacar(Vector2D posicion, Vector2D dir)
{	
	//Calculo la distancia entre el ataque y el enemigo
	
	static bool flag = false;
	double velocidad_ataque = 0.1;

	if (!flag) 
	{
		ataque.pos_atk = posicion;
		ataque.dir_atk = dir;
		ataque.vel_proyectil = velocidad_ataque * dir;
		flag = true;
	}

	mueve_ataque();

}

void Distancia::atacar_dibujar()
{
	glColor3ub(255, 0, 0);
	glTranslated(ataque.pos_atk.x, ataque.pos_atk.y, 0);
	glutSolidSphere(static_cast<Rango&>(ataque).radio_proyectil, 20, 20);
	glTranslated(-ataque.pos_atk.x, -ataque.pos_atk.y, 0);
}