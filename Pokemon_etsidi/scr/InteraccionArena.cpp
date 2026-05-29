#include "InteraccionArena.h"
#include "Colisiones.h"

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

bool InteraccionArena::colision_ataques_arena(ArenaCombate &obj, Ataque &p)
{

	Vector2D esq1, esq2, esq3, esq4;

	esq1 = Vector2D(obj.dimensiones_arena.x, obj.dimensiones_arena.y);
	esq2 = Vector2D(-obj.dimensiones_arena.x, obj.dimensiones_arena.y);
	esq3 = Vector2D(-obj.dimensiones_arena.x, -obj.dimensiones_arena.y);
	esq4 = Vector2D(obj.dimensiones_arena.x, -obj.dimensiones_arena.y);

	if (typeid(p) == typeid(Rango))
	{
		if (Colisiones::colision(p.hitbox, Vector2D(0, -1), esq1)) return true;
		if (Colisiones::colision(p.hitbox, Vector2D(1, 0), esq2)) return true;
		if (Colisiones::colision(p.hitbox, Vector2D(0, 1), esq3)) return true;
		if (Colisiones::colision(p.hitbox, Vector2D(-1, 0), esq4)) return true;
	}

	return false;
}

bool InteraccionArena::colisiona_ataques_obst(ListaObstaculos &obs, Ataque &p)
{

	for (auto i = obs.begin(); i != obs.end(); )
	{
		auto e = *i;
		bool borrado{ false };

		if (!e->es_destruible())
		{
			i++;
			continue;
		}

		if (Colisiones::colision(e->hitbox, p.hitbox))
		{
			e->vida -= 1;

			if (e->vida == 0)
			{
				delete e;
				i = obs.lista.erase(i);// Para evitar romper el programa
				borrado = true;
			}

			if (typeid(p) != typeid(Area)) //El ataque a rango se desaparece despues de colisionar con un objeto destruible
			{
				return true;
			}
		}

		if(!borrado) i++; // Para evitar romper el programa
	}

	return false;
}