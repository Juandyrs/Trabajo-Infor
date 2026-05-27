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

void Pokemon::mover_arena(Vector2D dir)
{
	dir_mov = dir;
	hitbox->pos += dir_mov * velocidad;
}

void Pokemon::pokemondibuja(int f, int c) {
	//NO HACE FALTA PASARLE EL PUNTERO DE POKEMON PARA SABER SI HAY ALGO POR QUE YA LO HACE LA FUNCION DE DIBUJADO DE TABLERO

	glPushMatrix();

	//TODO ESTO ES PARA LAS PANOS

		//COLOCAR LOS PLANOS EN EL CENTRO DE LA CASILLA CORRESPONDIENTE
	glPushMatrix();
	glTranslatef(c + 0.5f, f + 0.5f, 0.51f); // justo encima de la casilla
	glBegin(GL_QUADS);
	glVertex3f(-0.45f, -0.45f, 0);
	glVertex3f(0.45f, -0.45f, 0);
	glVertex3f(0.45f, 0.45f, 0);
	glVertex3f(-0.45f, 0.45f, 0);
	glEnd();

	glPopMatrix();


	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(obtenersprite().c_str()).id);
	glPushMatrix();
	glTranslatef(c + 0.5f, f + 0.5f, 0.5f);  // encima del plano

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-0.45f, -0.45f, 0);
	glTexCoord2f(1, 0); glVertex3f(0.45f, -0.45f, 0);
	glTexCoord2f(1, 1); glVertex3f(0.45f, 0.45f, 0);
	glTexCoord2f(0, 1); glVertex3f(-0.45f, 0.45f, 0);
	glEnd();

	glPopMatrix();

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);

}

Vector2D Pokemon::consultar_dim_hitbox() const
{
	HitboxRectangular *h = dynamic_cast<HitboxRectangular*>(hitbox);

	return h->rectangulo;
}