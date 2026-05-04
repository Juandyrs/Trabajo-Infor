#include "Fenix.h"
#include <freeglut.h>

void Fenix::atacar(Vector2D posicion, Vector2D dir)
{
	// No es necesario el uso de la direccion

	ataque.pos_atk = posicion;
}

void Fenix::atacar_dibujar()
{
	glColor3ub(255, 0, 0);
	glTranslated(ataque.pos_atk.x, ataque.pos_atk.y, 0);
	glutSolidSphere(ataque.radio_ataque, 20, 20);
	glTranslated(-ataque.pos_atk.x, -ataque.pos_atk.y, 0);
}

bool Fenix::colision_ataque(Pokemon &objetivo)
{
	static double frame_ataque{ ataque.frame_ataque };
	static double vida_antes{};
	static int contador{ 10 }; // Es para que no haga daño en todo los frames (Si no, estaría desbalanceado) 

	if (frame_ataque == ataque.frame_ataque)
	{
		vida_antes = vida_actual;
	}

	double distancia_x = abs(ataque.pos_atk.x - objetivo.pos_arena.x);
	double distancia_y = abs(ataque.pos_atk.y - objetivo.pos_arena.y);

	if ((distancia_x < (ataque.radio_ataque + objetivo.Hitbox.x) && distancia_y < (ataque.radio_ataque + objetivo.Hitbox.y)) 
		&& (contador == 10))
	{
		objetivo.vida_actual -= ataque.dano;
		contador = 0;
	}

	if (frame_ataque <= 0)
	{
		frame_ataque = ataque.frame_ataque;
		contador = 10;
		return true;
	}

	pos_arena = ataque.pos_atk; // Mantiene al fenix inmovil mientras dure el ataque
	vida_actual = vida_antes; // El fenix no recibe daño mientras ataca
	frame_ataque -= 0.1;

	if (contador < 10) contador++;

	return false;
}
