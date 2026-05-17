#include "IA.h"
#include "ArenaCombate.h"
#include <typeinfo>
#include "tiposp/Distancia.h"
#include "Colisiones.h"
#include "Basico.h"
#include <vector>

using std::vector;
using std::max_element;

extern bool atk2_ini;
extern double cd2;

void IA::IA_Tablero(Tablero& tablero)
{

}

void IA::IA_Combate_Arena(ArenaCombate &arena)
{
	srand(time(NULL));

	int decision = rand() % (8 - 1 + 1) + 1;
	static int frame{100};
	Vector2D distancia = arena.equipo1.consultar_posicion() - arena.equipo2.consultar_posicion();

	if (typeid(arena.equipo2) != typeid(Distancia) && frame%10 == 0)
	{
		switch (estado_arena)
		{
			case Estado_Arena::Buscar:


				if (IA::buscar_camino_arena(arena)) estado_arena = Estado_Arena::Atacar; 

				break;
			
			case Estado_Arena::Atacar:

				arena.equipo2.dir_mov = distancia.unitario();

				if (typeid(arena.equipo2) != typeid(Distancia))
				{
					auto& aux = arena.equipo2;

					if (distancia.modulo() > aux.ataque->consultar_rango())	estado_arena = Estado_Arena::Buscar;
				}

				if (cd2 <= 0)
				{
					atk2_ini = true;
				}

				break;

			case Estado_Arena::Esquivar:

				break;

			case Estado_Arena::Defensivo:

				break;
		}
	}



	/* switch (decision)
	{
		case 1:
			if(frame%10 == 0) arena.equipo2.mover_arena({ 0, 1 });
			break;

		case 2:
			if(frame%10 == 0) arena.equipo2.mover_arena({ 0, -1 });
			break;

		case 3:
			if(frame%10 == 0) arena.equipo2.mover_arena({ 1, 0 });
			break;

		case 4:
			if(frame%10 == 0) arena.equipo2.mover_arena({ -1, 0 });
			break;

		case 5:
			if (frame % 10 == 0) arena.equipo2.mover_arena({ sqrt(2) / 2, sqrt(2) / 2 });
			break;

		case 6:
			if (frame % 10 == 0) arena.equipo2.mover_arena({ -sqrt(2) / 2, sqrt(2) / 2 });
			break;

		case 7:
			if (frame % 10 == 0) arena.equipo2.mover_arena({ sqrt(2) / 2, -sqrt(2) / 2 });
			break;

		case 8:
			if (frame % 10 == 0) arena.equipo2.mover_arena({ -sqrt(2) / 2, -sqrt(2) / 2 });
			break;
	}*/

	frame--;
	if (frame <= 0) frame = 100;
}

bool IA::buscar_camino_arena(ArenaCombate &arena)
{
	Vector2D distancia = arena.equipo1.consultar_posicion() - arena.equipo2.consultar_posicion();
	Vector2D d_aux{};
	vector <int> pesos(8);
	vector <Vector2D> movimientos = { {0,1}, {0,-1}, {1,0}, {-1,0},
		{sqrt(2) / 2, sqrt(2) / 2}, {-sqrt(2) / 2, sqrt(2) / 2}, {sqrt(2) / 2, -sqrt(2) / 2}, {-sqrt(2) / 2, -sqrt(2) / 2} };
	vector <Vector2D> puntos(8);
	Vector2D mejor_movimiento{ 0,0 };

	//Los personajes a distancia se comportan de manera distinta.
	if (typeid(arena.equipo2) != typeid(Distancia))
	{
		auto aux = arena.equipo2;

		for (int i = 0; i < 8; i++)
		{
			puntos[i] = arena.equipo2.siguiente_posicion(movimientos[i]);

			aux.pos_arena = puntos[i];
			d_aux = arena.equipo1.consultar_posicion() - aux.pos_arena;

			if (arena.obstaculos.interrumpir_Obstaculos(aux)) pesos[i] = 0;
			else pesos[i] = 100 - d_aux.modulo()*10;
		}

		auto mayor_peso = max_element(pesos.begin(), pesos.end()); //Devuelve el iterador del mayor elemento
		auto indice = std::distance(pesos.begin(), mayor_peso); //Calcula la distancia entre el iterador y el inicio

		mejor_movimiento = movimientos[indice];

		arena.equipo2.mover_arena(mejor_movimiento.unitario());

		if (distancia.modulo() < aux.ataque->consultar_rango())	return true;
	}
	
	return false;
}
 