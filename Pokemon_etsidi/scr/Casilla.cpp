#include "Casilla.h"

void Casilla::inicializar(int f, int c) {

	fila = f;
	columna = c;

	if ((f == 0 && c == 4) ||
		(f == 4 && c == 4) ||
		(f == 4 && c == 0) ||
		(f == 8 && c == 4) ||
		(f == 4 && c == 8))
	{

		tipo = TipoCasilla::poder;
		cambio = -1;

	}

	//ponemos por ejemplo que aprx un tercio de las casillas son cambiantes 

	else if ((f + c) % 3 == 0)
	{
		
		cambio = (f * 2 + c) % 6; // asignamos un estado para que no empiecen todas en el mismo;

		// le ponemos a la casilla el tipo que e haya tocado

		if (cambio == 0) tipo = TipoCasilla::neutr;
		else if (cambio == 1) tipo = TipoCasilla::aviso_claro;
		else if (cambio == 2) tipo = TipoCasilla::clara;
		else if (cambio == 3) tipo = TipoCasilla::aviso_oscuro;
		else if (cambio == 4) tipo = TipoCasilla::oscura;
		else if (cambio == 5) tipo = TipoCasilla::aviso_neutro;
	}

	else if ((f + c) % 2 == 0) {

		tipo = TipoCasilla::clara;
		cambio = -1;

	}

	else {
		tipo = TipoCasilla::oscura;
		cambio = -1;

	}

}

void Casilla::avanzar_ciclo() {

	if (cambio < 0) return;

	// Ciclo de 6 fases
	cambio = (cambio + 1) % 6;


	if(cambio == 0) tipo = TipoCasilla::neutr;
	else if (cambio == 1) tipo = TipoCasilla::aviso_claro; 
	else if (cambio == 2) tipo = TipoCasilla::clara;
	else if (cambio == 3) tipo = TipoCasilla::aviso_oscuro; 
	else if (cambio == 4) tipo = TipoCasilla::oscura;
	else if (cambio == 5) tipo = TipoCasilla::aviso_neutro;  

}
