#include "Volador.h"
#include <freeglut.h>

void Volador::atacar(Vector2D posicion, Vector2D dir)
{
	// No es necesario el uso de la direccion
	ataque.pos_atk = posicion;
}

void Volador::atacar_dibujar()
{
	glColor3ub(255, 0, 0);
	glTranslated(ataque.pos_atk.x, ataque.pos_atk.y, 0);
	glutSolidSphere(ataque.radio_ataque, 20, 20);
	glTranslated(-ataque.pos_atk.x, -ataque.pos_atk.y, 0);
}

bool Volador::colision_ataque(Pokemon &objetivo)
{
	static double frame_ataque = ataque.frame_ataque;
	static int contador{ 10 }; // Es para que no haga daño en todo los frames (Si no, estaría desbalanceado)

	double distancia_x = abs(ataque.pos_atk.x - objetivo.consultar_posicion().x);
	double distancia_y = abs(ataque.pos_atk.y - objetivo.consultar_posicion().y);

	if (distancia_x < (ataque.radio_ataque + objetivo.consultar_hitbox().x) && distancia_y < (ataque.radio_ataque + objetivo.consultar_hitbox().y) 
		&& (contador == 10))
	{
		objetivo.recibir_dano(ataque.dano);
		contador = 0;
	}

	if (frame_ataque <= 0)
	{
		frame_ataque = ataque.frame_ataque;
		contador = 10;
		return true;
	}

	pos_arena = ataque.pos_atk; // Mantiene al volador inmovil mientras dure el ataque
	frame_ataque -= 0.1;
	contador++;

	return false;
	return false;
}