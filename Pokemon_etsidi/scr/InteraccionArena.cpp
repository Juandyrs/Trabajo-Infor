#include "InteraccionArena.h"

void InteraccionArena::aplicar_Efectos(Pokemon &personaje)
{
	switch (personaje.efecto_estado)
	{
	case EfectoEstado::Quemadura:

		if (personaje.consultar_duracion_estado() % 10 == 0)
		{
			personaje.recibir_dano(1.0);
		}

		if (personaje.consultar_duracion_estado() <= 0) personaje.modificar_estado(EfectoEstado::Ninguno, 0);

		personaje.duracion_efecto--;

		break;
	default:
		break;
	}
}
