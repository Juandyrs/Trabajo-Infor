#include "Ataque.h"
#include <freeglut.h>
#include <numbers>
#include "Pokemon.h"

// Metodos de ataque rango

void Rango::atacar(Vector2D posicion, Vector2D dir)
{
	double velocidad_ataque = 0.1;

	pos_atk = posicion;
	dir_atk = dir;
	vel_proyectil = velocidad_ataque * dir;
}

void Rango::atacar_dibujar()
{
	glColor3ub(255, 0, 0);
	glTranslated(pos_atk.x, pos_atk.y, 0);
	glutSolidSphere(radio_proyectil, 20, 20);
	glTranslated(-pos_atk.x, -pos_atk.y, 0);
}

bool Rango::colision_ataque(Pokemon &objetivo)
{
	//Calculo de la distancia entre el ataque y el objetivo
	double distancia_x = abs(pos_atk.x - objetivo.consultar_posicion().x);
	double distancia_y = abs(pos_atk.y - objetivo.consultar_posicion().y);

	if (distancia_x < (radio_proyectil + objetivo.consultar_hitbox().x) && distancia_y < (radio_proyectil + objetivo.consultar_hitbox().y))
	{
		// Colisión detectada, aplicar daño al objetivo
		objetivo.recibir_dano(dano);
		return true;
	}

	return false;
}

//Metodos de ataque melee

void Melee::atacar(Vector2D posicion, Vector2D dir)
{
	pos_atk = posicion;
	dir_atk = dir;
}

void Melee::atacar_dibujar()
{
	double ang_ataque = dir_atk.argumento();

	//Placeholder, hay que cambiarlo

	glTranslated(pos_atk.x, pos_atk.y, 0);
	glRotated(ang_ataque * 180 / std::numbers::pi, 0, 0, 1);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 0, 0);
	glVertex3d(0, ancho_ataque, 0);
	glVertex3d(rango_ataque, ancho_ataque, 0);
	glColor3ub(255, 0, 0);
	glVertex3d(rango_ataque, -ancho_ataque, 0);
	glVertex3d(0, -ancho_ataque, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glRotated(-ang_ataque * 180 / std::numbers::pi, 0, 0, 1);
	glTranslated(-pos_atk.x, -pos_atk.y, 0);
}

bool Melee::colision_ataque(Pokemon &objetivo)
{
	double ang_ataque = dir_atk.argumento();
	Vector2D ataque_centro = pos_atk + Vector2D{ rango_ataque / 2 * cos(ang_ataque), ancho_ataque / 2 * sin(ang_ataque) };
	double distancia_x = abs(ataque_centro.x - objetivo.consultar_posicion().x);
	double distancia_y = abs(ataque_centro.y - objetivo.consultar_posicion().y);
	static double frame = frame_ataque;

	//Debido a que el ataque melee puede estar rotado hay ligeros errores en la colision, por mientras se deja como si no lo estuviera. Es suficientemente aceptable
	if (distancia_x < ((rango_ataque / 2 + objetivo.consultar_hitbox().x))
		&& distancia_y < ((ancho_ataque / 2 + objetivo.consultar_hitbox().y)))
	{
		objetivo.recibir_dano(dano);
		return true;
	}

	if (frame > 0)
	{
		frame -= 0.1;
		return false;
	}                    
	else
	{
		frame = frame_ataque;
		return true;
	}

	return false;
}

//Metodos de ataque area

void Area::atacar(Vector2D posicion, Vector2D dir)
{
	// No es necesario el uso de la direccion

	pos_atk = posicion;
}

void Area::atacar_dibujar()
{
	glColor3ub(255, 0, 0);
	glTranslated(pos_atk.x, pos_atk.y, 0);
	glutSolidSphere(radio_ataque, 20, 20);
	glTranslated(-pos_atk.x, -pos_atk.y, 0);
}

bool Area::colision_ataque(Pokemon &objetivo)
{
	static double frame = frame_ataque;
	static double vida_antes{};
	static int contador{ 10 }; // Es para que no haga daño en todo los frames (Si no, estaría desbalanceado) 

	if (frame == frame_ataque)
	{
		vida_antes = objetivo.consultar_vida();
	}

	double distancia_x = abs(pos_atk.x - objetivo.consultar_posicion().x);
	double distancia_y = abs(pos_atk.y - objetivo.consultar_posicion().y);

	if ((distancia_x < (radio_ataque + objetivo.consultar_hitbox().x) && distancia_y < (radio_ataque + objetivo.consultar_hitbox().y))
		&& (contador == 10))
	{
		objetivo.recibir_dano(dano);
		contador = 0;
	}

	if (frame <= 0)
	{
		frame = frame_ataque;
		contador = 10;
		return true;
	}

	// Hay que agregar que el se Mantiene al fenix inmovil mientras dure el ataque
	// Hay que agregar que el se Mantiene El fenix no recibe daño mientras ataca

	frame -= 0.1;

	if (contador < 10) contador++;

	return false;
}
