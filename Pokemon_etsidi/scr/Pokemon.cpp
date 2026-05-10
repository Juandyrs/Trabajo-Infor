#include "Pokemon.h"
#include <string>

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
	pos_arena += dir_mov * velocidad;
}
