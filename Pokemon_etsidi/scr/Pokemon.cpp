#include "Pokemon.h"
#include <string>
#include <freeglut.h>
#include <ETSIDI.h>
#include "Vector2D.h"
#include "Tablero.h"
#include <cmath>

using namespace std;
using std::vector;

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

	hitbox->pos += dir_mov * velocidad * mult_vel * dt;
}

//void Pokemon::pokemondibuja(int f, int c) {}

vector<Vector2D> Pokemon::movimiento_valido(const Tablero *tablero)
{
	vector<Vector2D> movimientos_posibles{};

	bool salir{ false };
	int total_mov{};
	int n_casillas = this->numero_casillas;
	int f_actual = tablero->consultar_fila_seleccionada(), c_actual = tablero->consultar_columna_seleccionada();
	
	if (this->movimiento != TipoMovimiento::Tierra)
	{

		//Se calcula los movimientos posibles considerando un movimiento en rombo para las piezas que no sean de tierra
		for (int df = -n_casillas; df <= n_casillas; df++)
		{
			int destino_f = f_actual + df;

			if (destino_f < 0 || destino_f >= 9) continue;

			int alcance_horizontal = n_casillas - abs(df);

			for (int dc = -alcance_horizontal; dc <= alcance_horizontal; dc++)
			{
				int destino_c = c_actual + dc;

				if (destino_c < 0 || destino_c >= 9) continue;
				if (df == 0 && dc == 0) continue;

				//Si la casilla no esta ocupada, es posible el movimiento o si el pokemon es de un equipo enemigo

				auto p = tablero->consultar_pok(destino_f, destino_c);

				if (p == nullptr || p->equipo != this->equipo) movimientos_posibles.push_back(Vector2D(destino_f, destino_c));
			}
		}
	}
	else
	{
		//Para las unidades de tierra es necesario calcular todas las direcciones para saber a donde se pueden mover
		struct Nodo
		{
			int f, c;
			int mov_dados;
		};

		vector<Nodo> nodos;
		bool pasados[9][9]{ false }; // Guarda las posiciones que se ha pasado 

		pasados[f_actual][c_actual] = true;
		int movimientos_f[4] = { -1,1,0,0 }; // Movimientos 
		int movimientos_c[4] = { 0,0,-1,1 }; // Movimientos 

		nodos.push_back(Nodo(f_actual, c_actual, 0));

		while (!nodos.empty())
		{
			Nodo nodo = nodos.front();
			nodos.erase(nodos.begin());

			if (nodo.mov_dados >= n_casillas) continue;

			for (int i = 0; i < 4; i++)
			{
				int f_adyacente = nodo.f + movimientos_f[i];
				int c_adyacente = nodo.c + movimientos_c[i];

				if (f_adyacente < 0 || f_adyacente >= 9 || c_adyacente < 0 || c_adyacente >= 9) continue; //Limites
				if (pasados[f_adyacente][c_adyacente]) continue; // Si ya he pasado

				if (tablero->consultar_pok(f_adyacente, c_adyacente) == nullptr)
				{
					movimientos_posibles.push_back(Vector2D(f_adyacente, c_adyacente));
					pasados[f_adyacente][c_adyacente] = true;
					nodos.push_back(Nodo(f_adyacente, c_adyacente, nodo.mov_dados + 1));
				}
				else if (tablero->consultar_pok(f_adyacente, c_adyacente)->equipo != this->equipo)
				{
					movimientos_posibles.push_back(Vector2D(f_adyacente, c_adyacente));
					pasados[f_adyacente][c_adyacente] = true;
				}
			}

		}
	}
		return movimientos_posibles;
}


void Pokemon::dibujar_pokemon(int a)
{
	sprites->setSize(set_s.x * 5, set_s.y * 5);
	sprites->setCenter(centro_s.x * 5, centro_s.y * 5);

	glPushMatrix();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	sprites->draw();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glPopMatrix();
}

void Pokemon::dibujar_pokemon()
{
	int fila{ 0 };
	int columna_spr{ 3 };

	sprites->setSize(set_s.x, set_s.y);
	sprites->setCenter(centro_s.x, centro_s.y);

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
		sprites->setState(1);
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
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
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