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

bool Rango::colision_ataque(Pokemon &objetivo)
{
	if (dir_atk.modulo() == 0) return false; // Si la dirección es un vector nulo, no se detecta colisión

	if (Colisiones::colision(hitbox, objetivo.consultar_hitbox())
		&& (objetivo.consultar_efecto_estado() != EfectoEstado::Invulnerable))
	{
		// Colisión detectada, aplicar daño al objetivo
		objetivo.recibir_dano(dano);
		return true;
	}

	return false;
}
Ataque* Rango::clonar() const
{
	Rango* copia = new Rango();
	copia->hitbox = hitbox->clonar();
	copia->vel_proyectil = vel_proyectil;
	copia->dano = dano;
	return copia;
}
//Metodos de ataque melee

void Melee::iniciar_ataque(Vector2D posicion, Vector2D dir)
{
	double ang_ataque = dir.argumento();
	HitboxRectangular* h = dynamic_cast<HitboxRectangular*>(hitbox);
	HitboxRectangular* aux = new HitboxRectangular(*h);
	Vector2D ataque_centro = posicion + Vector2D{ aux->rectangulo.x * cos(ang_ataque),  aux->rectangulo.y * sin(ang_ataque) };

	hitbox->pos = ataque_centro;
	dir_atk = dir;
}

void Melee::atacar_dibujar()
{
	if (dir_atk.modulo() == 0) return; // Si la dirección es un vector nulo, no se dibuja el ataque

	double ang_ataque = dir_atk.argumento();

	//Placeholder, hay que cambiarlo

	HitboxRectangular* aux = dynamic_cast<HitboxRectangular*>(hitbox);

	glTranslated(hitbox->pos.x, hitbox->pos.y, 0);
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
	glTranslated(-hitbox->pos.x, -hitbox->pos.y, 0);
}

bool Melee::colision_ataque(Pokemon &objetivo)
{
	if (dir_atk.modulo() == 0) return false; // Si la dirección es un vector nulo, no se dibuja el ataque

	static int frame = frame_ataque;
	HitboxRectangular *h = dynamic_cast<HitboxRectangular*>(hitbox);
	HitboxRectangular *aux = new HitboxRectangular(*h);

	//Debido a que el ataque melee puede estar rotado hay ligeros errores en la colision, por mientras se deja como si no lo estuviera. Es suficientemente aceptable
	if (Colisiones::colision(aux, objetivo.consultar_hitbox())
		&& (objetivo.consultar_efecto_estado() != EfectoEstado::Invulnerable))
	{
		objetivo.recibir_dano(dano);
		delete aux;
		return true;
	}

	if (frame > 0)
	{
		frame -= 1;
		delete aux;
		return false;
	}
	else
	{
		frame = frame_ataque;
		delete aux;
		return true;
	}
	delete aux;
	return false;
}

Ataque* Melee::clonar() const
{
	Melee* copia = new Melee();
	copia->hitbox = hitbox->clonar();
	copia->frame_ataque = frame_ataque;
	copia->dano = dano;
	return copia;
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

bool Area::colision_ataque(Pokemon& objetivo)
{
	static int frame = frame_ataque;

	if (Colisiones::colision(hitbox, objetivo.consultar_hitbox())
		&& (frame % 10 == 0) && (objetivo.consultar_efecto_estado() != EfectoEstado::Invulnerable))
	{
		objetivo.recibir_dano(dano);
	}

	if (frame <= 0)
	{
		frame = frame_ataque;
		return true;
	}

	// Hay que agregar que Mantiene al fenix inmovil mientras dure el ataque
	// Hay que agregar que el fenix no recibe daño mientras ataca

	frame -= 1;

	return false;
}

Ataque* Area::clonar() const
{
	Area* copia = new Area();
	copia->hitbox = hitbox->clonar();
	copia->frame_ataque = frame_ataque;
	copia->dano = dano;
	return copia;
}
