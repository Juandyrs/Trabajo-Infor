#include "Pokemon.h"
#include <string>
#include <freeglut.h>
#include <ETSIDI.h>


using namespace std;

void Pokemon::inicializa_datos(string n, char s, Bando b, Tipo tipo1, Tipo tipo2) {
nombre = n;
simbolo = s;
equipo = b;
tip1 = tipo1;
tip2 = tipo2;

}
void Pokemon::inicializa_stats(double v_max, double v_act, double vel) {
	vida_max = v_max;
	vida_actual = v_act;
	velocidad = vel;
}
void Pokemon::inicializa_mov(TipoMovimiento mov, int nu_ca) {
	movimiento = mov;
	numero_casillas = nu_ca;

}

//Metodos relacionados con la arena

void Pokemon::recibir_dano(double cantidad)
{
	vida_actual -= cantidad;

	if (vida_actual < 0) 
	{
		vida_actual = 0;
	}
}

void Pokemon::atacar(Pokemon& objetivo)
{
	if (!atacando) return;
	ataque->mueve_ataque();
	atacando = !ataque->colision_ataque(objetivo);

}

void Pokemon::mover_arena(double dt)
{
	if (dir_mov == Vector2D(0.0, 0.0)) return;

	hitbox->pos += dir_mov * velocidad * dt;
}

//void Pokemon::pokemondibuja(int f, int c) {}

void Pokemon::dibujar_pokemon()
{
	int fila{ 0 };
	int columna_spr{ 3 };

	//Logica del estado del sprite

	if (dir_mov == Vector2D(0.0, -1.0)) fila = 0;
	if (dir_mov == Vector2D(0.0, 1.0)) fila = 1;
	if (dir_mov == Vector2D(-1.0, 0.0)) fila = 2;
	if (dir_mov == Vector2D(1.0, 0.0)) fila = -2;
	if (dir_mov == Vector2D(-sqrt(2) / 2, -sqrt(2) / 2)) fila = 3;
	if (dir_mov == Vector2D(sqrt(2) / 2, -sqrt(2) / 2)) fila = -3;
	if (dir_mov == Vector2D(-sqrt(2) / 2, sqrt(2) / 2)) fila = 4;
	if (dir_mov == Vector2D(sqrt(2) / 2, sqrt(2) / 2)) fila = -4;

	if (fila > 0) sprites->flip(false, false);
	if (fila < 0) sprites->flip(true, false);

	//Para mantener la animacion de la direccion de movimiento
	unsigned int estado = 3 * abs(fila);

	if (dir_mov == Vector2D(0.0, 0.0))
	{
		if (moviendo) moviendo = false;
		sprites->setState(0);
	}
	else
	{
		if (!moviendo || (sprites->getState() < estado || sprites->getState() >= estado + columna_spr))
		{
			moviendo = true;
			sprites->setState(estado);
			sprites->setState(estado, false);
		}

		int ultimo_frame = estado + columna_spr;
		if (sprites->getState() >= ultimo_frame) sprites->setState(estado, false);
	}

	//Dibujo del sprite
	glPushMatrix();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTranslated(hitbox->pos.x, hitbox->pos.y, 0.0);
	sprites->draw();
	glPopMatrix();
}

void Pokemon::animar_pokemon()
{
	sprites->loop();
}

Vector2D Pokemon::consultar_dim_hitbox() const
{
	HitboxRectangular *h = dynamic_cast<HitboxRectangular*>(hitbox);

	return h->rectangulo;
}