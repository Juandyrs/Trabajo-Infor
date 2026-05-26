#include "IA.h"
#include "ArenaCombate.h"
#include <typeinfo>
#include "tiposp/Distancia.h"
#include "Colisiones.h"
#include "Ataque.h"
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
	Vector2D distancia = arena.equipo1->consultar_posicion() - arena.equipo2->consultar_posicion();

	if (typeid(arena.equipo2) != typeid(Distancia) && frame%10 == 0)
	{
		switch (estado_arena)
		{
			case Estado_Arena::Buscar:


				if (IA::buscar_camino_arena(arena)) estado_arena = Estado_Arena::Atacar; 

				break;
			
			case Estado_Arena::Atacar:

				if (typeid(*arena.equipo2->ataque) == typeid(Melee) || typeid(*arena.equipo2->ataque) == typeid(Area))
				{
					arena.equipo2->dir_mov = distancia.unitario();
				//	if (distancia.modulo() > arena.equipo2->ataque->consultar_hitbox()) estado_arena = Estado_Arena::Buscar; IMPORTANTE VER
				}

				else if (typeid(*arena.equipo2->ataque) == typeid(Rango))
				{
					if (!Colisiones::colision(arena.equipo1->hitbox, arena.equipo2->dir_mov, arena.equipo2->hitbox->pos)) estado_arena = Estado_Arena::Buscar;
				}

				if (cd2 <= 0 /* && !arena.equipo2->atacando*/ ) atk2_ini = true; // IMPORTANTE VER

				break;

			case Estado_Arena::Esquivar:

				break;

			case Estado_Arena::Defensivo:

				break;
		}
	}

	frame--;
	if (frame <= 0) frame = 100;
}

bool IA::buscar_camino_arena(ArenaCombate &arena)
{
	Vector2D distancia = arena.equipo1->consultar_posicion() - arena.equipo2->consultar_posicion();
	Vector2D d_aux{};
	vector <int> pesos(8);
	vector <Vector2D> movimientos = { {0,1}, {0,-1}, {1,0}, {-1,0},
		{sqrt(2) / 2, sqrt(2) / 2}, {-sqrt(2) / 2, sqrt(2) / 2}, {sqrt(2) / 2, -sqrt(2) / 2}, {-sqrt(2) / 2, -sqrt(2) / 2} };
	vector <Vector2D> puntos(8), mejor_ruta;
	Vector2D mejor_movimiento{ 0,0 };
	static vector <Vector2D>  posiciones_anterior(20);

	//Los personajes cuerpo a cuerpo y los de ataque en area  se comportan de manera similar.
	if (typeid(*arena.equipo2->ataque) == typeid(Melee) || typeid(*arena.equipo2->ataque) == typeid(Area))
	{
		//El personaje cuerpo a cuerpo intenta estar lo mas cerca del jugador para atacar
		auto aux = *arena.equipo2;

		for (int i = 0; i < 8; i++)
		{
			puntos[i] = arena.equipo2->siguiente_posicion(movimientos[i]);
			aux.hitbox->pos = puntos[i];
			d_aux = arena.equipo1->consultar_posicion() - aux.hitbox->pos;

			pesos[i] = 100; // Valor base del peso

			pesos[i] -= d_aux.modulo() * 10; //Premia el movimiento que se acerca al enemigo

			for (auto e : posiciones_anterior) if (puntos[i] == e) pesos[i] -= 50; //Penaliza volver a alguna posicion anterior

			if (arena.obstaculos.distancia_obstaculo_cercano(aux) <= 0.01) pesos[i] -= 100; //Penaliza estar cerca de obstaculos

			pesos[i] += rand() % (5 - 1 + 1) + 1; // Un poco de aleatoriedad para intentar evitar que se trabe

			//Para poder ver cuales son los pesos de los movimientos
			//cout << "Pos siguiente:" << puntos[i] << endl;
			//cout << pesos[i]<< movimientos[i] << endl;
		}

		auto mayor_peso = max_element(pesos.begin(), pesos.end()); //Devuelve el iterador del mayor elemento
		auto indice = std::distance(pesos.begin(), mayor_peso); //Calcula la distancia entre el iterador y el inicio

		mejor_movimiento = movimientos[indice];

		for (int i = 19; i >= 1; i--)
		{
			//cout << posiciones_anterior[i] << endl;
			//Guarda las posiciones anteriores y se pierde la posicion que se estuvo hace 20 movimientos 
			posiciones_anterior[i] = posiciones_anterior[i - 1];
		}

		posiciones_anterior[0] = arena.equipo2->hitbox->pos;
		arena.equipo2->mover_arena(mejor_movimiento.unitario());

		//if (distancia.modulo() < aux.ataque->consultar_rango())	return true; IMPORTANTE VER
	}
	
	else if (typeid(*arena.equipo2->ataque) == typeid(Rango))
	{
		//El personaje a distancia intenta estar lejos del jugador y moverse para atacar a distancia
		auto aux = *arena.equipo2;

		for (int i = 0; i < 8; i++)
		{
			puntos[i] = arena.equipo2->siguiente_posicion(movimientos[i]);
			aux.hitbox->pos = puntos[i];
			d_aux = arena.equipo1->consultar_posicion() - aux.hitbox->pos;

			pesos[i] = 100; // Valor base del peso

			if (1.0 <= d_aux.modulo() && d_aux.modulo() <= 1.5) pesos[i] += 20; //Premia el movimiento que se mantenga a una distancia del enemigo

			for (int i = 0; i < 8; i++) 
				if (Colisiones::colision(arena.equipo1->hitbox, movimientos[i], aux.hitbox->pos)) pesos[i] += 50; // Premia movimientos en los que se pueda acertar

			for (auto e : posiciones_anterior) if (puntos[i] == e) pesos[i] -= 50; //Penaliza volver a alguna posicion anterior

			if (arena.obstaculos.distancia_obstaculo_cercano(aux) <= 0.01) pesos[i] -= 2000; //Penaliza estar cerca de obstaculos

			pesos[i] += rand() % (5 - 1 + 1) + 1; // Un poco de aleatoriedad para intentar evitar que se trabe
		}

		auto mayor_peso = max_element(pesos.begin(), pesos.end()); //Devuelve el iterador del mayor elemento
		auto indice = std::distance(pesos.begin(), mayor_peso); //Calcula la distancia entre el iterador y el inicio

		mejor_movimiento = movimientos[indice];

		for (int i = 19; i >= 1; i--) posiciones_anterior[i] = posiciones_anterior[i - 1];

		posiciones_anterior[0] = arena.equipo2->hitbox->pos;
		arena.equipo2->mover_arena(mejor_movimiento.unitario());

		if (Colisiones::colision(arena.equipo1->hitbox, mejor_movimiento, arena.equipo2->hitbox->pos)) return true;
	}

	return false;
}
 