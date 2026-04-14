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
void Pokemon::inicializa_stats(double v_max, double v_act, double vel, double timp, double da, double vel_proy) {
	vida_max = v_max;
	vida_actual = v_act;
	velocidad = vel;
	tiempo_recarga = timp;
	daño = da;
	velocidad_proyectil = vel_proy;

}
void Pokemon::inicializa_mov(TipoMovimiento mov, int nu_ca) {
	movimiento = mov;
	numero_casillas = nu_ca;

}
