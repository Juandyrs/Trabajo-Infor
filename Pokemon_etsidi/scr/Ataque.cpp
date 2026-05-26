#include "Ataque.h"
#include <freeglut.h>
#include <numbers>
#include "Pokemon.h"
#include "Colisiones.h"

// Metodos de ataque rango

void Rango::iniciar_ataque(Vector2D posicion, Vector2D dir)
{
	double velocidad_ataque = 0.1;

	hitbox->pos = posicion;
	dir_atk = dir;
	vel_proyectil = velocidad_ataque * dir;
}

void Rango::atacar_dibujar()
{
	if (dir_atk.modulo() == 0) return; // Si la dirección es un vector nulo, no se dibuja el ataque
	
	glColor3ub(255, 0, 0);
	hitbox->dibujar();
}

//Metodos de ataque melee

void Melee::iniciar_ataque(Vector2D posicion, Vector2D dir)
{
	hitbox->pos = posicion;
	dir_atk = dir;
}

void Melee::atacar_dibujar()
{
	double ang_ataque = dir_atk.argumento();

	//Placeholder, hay que cambiarlo

	HitboxRectangular* aux = dynamic_cast<HitboxRectangular*>(hitbox);

	glTranslated(hitbox->pos.x + cos(ang_ataque)*aux->rectangulo.x, hitbox->pos.y + sin(ang_ataque) * aux->rectangulo.y, 0);
	glRotated(ang_ataque * 180 / std::numbers::pi, 0, 0, 1);
	glDisable(GL_LIGHTING);
	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(-aux->rectangulo.x, aux->rectangulo.y, 0);
	glVertex3d(aux->rectangulo.x, aux->rectangulo.y, 0);
	glVertex3d(aux->rectangulo.x, -aux->rectangulo.y, 0);
	glVertex3d(-aux->rectangulo.x, -aux->rectangulo.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glRotated(-ang_ataque * 180 / std::numbers::pi, 0, 0, 1);
	glTranslated(-(hitbox->pos.x + cos(ang_ataque) * aux->rectangulo.x), -(hitbox->pos.y + sin(ang_ataque) * aux->rectangulo.y), 0);
}

//Metodos de ataque area

void Area::iniciar_ataque(Vector2D posicion, Vector2D dir)
{
	// No es necesario el uso de la direccion
	hitbox->pos = posicion;
}

void Area::atacar_dibujar()
{
	glColor3ub(255, 0, 0);
	hitbox->dibujar();
}