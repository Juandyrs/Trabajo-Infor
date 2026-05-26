#include "Ataque.h"
#include <freeglut.h>
#include <numbers>
#include "Pokemon.h"
#include "Colisiones.h"

// Metodos de ataque rango

void Rango::iniciar_ataque(Vector2D posicion, Vector2D dir)
{
	double velocidad_ataque = 0.1;

	pos_atk = posicion;
	dir_atk = dir;
	vel_proyectil = velocidad_ataque * dir;
}

void Rango::atacar_dibujar()
{
	if (dir_atk.modulo() == 0) return; // Si la dirección es un vector nulo, no se dibuja el ataque
	
	glColor3ub(255, 0, 0);
	glTranslated(pos_atk.x, pos_atk.y, 0);
	hitbox->dibujar();
	glTranslated(-pos_atk.x, -pos_atk.y, 0);
}

//Metodos de ataque melee

void Melee::iniciar_ataque(Vector2D posicion, Vector2D dir)
{
	pos_atk = posicion;
	dir_atk = dir;
}

void Melee::atacar_dibujar()
{
	double ang_ataque = dir_atk.argumento();

	//Placeholder, hay que cambiarlo

	HitboxRectangular* aux = dynamic_cast<HitboxRectangular*>(hitbox);

	glTranslated(pos_atk.x + cos(ang_ataque)*aux->rectangulo.x, pos_atk.y + sin(ang_ataque) * aux->rectangulo.y, 0);
	glRotated(ang_ataque * 180 / std::numbers::pi, 0, 0, 1);
	glDisable(GL_LIGHTING);
	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	hitbox->dibujar();
	glEnd();
	glEnable(GL_LIGHTING);
	glRotated(-ang_ataque * 180 / std::numbers::pi, 0, 0, 1);
	glTranslated(-(pos_atk.x + cos(ang_ataque) * aux->rectangulo.x), -(pos_atk.y + sin(ang_ataque) * aux->rectangulo.y), 0);
}

//Metodos de ataque area

void Area::iniciar_ataque(Vector2D posicion, Vector2D dir)
{
	// No es necesario el uso de la direccion
	pos_atk = posicion;
}

void Area::atacar_dibujar()
{
	glColor3ub(255, 0, 0);
	glTranslated(pos_atk.x, pos_atk.y, 0);
	hitbox->dibujar();
	glTranslated(-pos_atk.x, -pos_atk.y, 0);
}