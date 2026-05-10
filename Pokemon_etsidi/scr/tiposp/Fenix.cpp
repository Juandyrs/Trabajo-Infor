#include "Fenix.h"
#include <freeglut.h>

void Fenix::atacar(Pokemon &objetivo) 
{
    Fenix aux; //Para saber la velocidad inicial del personaje
	double vida_inicial = vida_actual;

	if (!atacando)
	{
		velocidad = aux.velocidad;
		if(efecto_estado == EfectoEstado::Invulnerable) efecto_estado = EfectoEstado::Ninguno;
		return;
	}

	Pokemon::atacar(objetivo);

	velocidad = 0.0;
	efecto_estado = EfectoEstado::Invulnerable;
}
