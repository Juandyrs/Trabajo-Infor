#pragma once

#include "Pokemon.h"
#include "Ataque.h"

class Hechicero :
    public Pokemon
{

public:

	Hechicero() = default;

	Hechicero(int a) // Constructor para pruebas en la arena
	{
		ataque = new Rango(20.0, Vector2D{ 1.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 0.5, 0.5);
		vida_max = 60.0;
		vida_actual = 60.0;
		velocidad = 0.2;
		dano = 20.0;
		cooldown = 5;
		hitbox = new HitboxRectangular({ 0.5,  0.5 });
	}

	Hechicero(string n, Bando b, Tipo tipo1, Tipo tipo2, Vector2D pos_t, string s)
<<<<<<< Updated upstream
=======
		: Pokemon(
			n        //Nombre
			, tipo1
			, tipo2
			, b        //Bando
			, 'H'
			, TipoMovimiento::Teletransporte
			, pos_t
			, 3        //Numero de casilla
			, 60.0    //Vida
			, 0.5     //Velocidad
			, 10.0    //Dano
			, 5.0     //Cooldown
			, s       //Ruta de imagen
		)
>>>>>>> Stashed changes
	{
		// No se pueden inicializar miembros heredados en la lista de inicialización
		//Arena
		ataque = new Rango(20.0, Vector2D{ 1.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 0.5, 0.5);
		vida_max = 60.0;
		vida_actual = 60.0;
		velocidad = 0.2;
		dano = 20.0;
		cooldown = 5;
		hitbox = new HitboxRectangular({ 0.5,  0.5 });

		//Tablero
		nombre = n;
		equipo = b;
		tip1 = tipo1;
		tip2 = tipo2;
		pos_tab = pos_t;
		simbolo = 'H';
		sprite = s;
		numero_casillas = 3;
		movimiento = TipoMovimiento::Teletransporte;


	}


	Hechizo& modificarHechizos() { return hechizos; } //PARA MODIFICAR SU VALOR
	const Hechizo& verHechizos() const { return hechizos; } //PARA LEERLO SI ES TruE O FALSE h->getHechizos().gastacurar() se ve asi en tablero es la gracia de esto


};

