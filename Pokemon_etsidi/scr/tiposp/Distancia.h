#pragma once

#include "Pokemon.h"
#include "Ataque.h"

class Distancia :
    public Pokemon
{

public:

	Distancia() = default;

	//Constructor para la clase Distancia, que inicializa la clase
	Distancia(int a) //Este constructor es para pruebas de la arena se debera quitar
	{
		ataque = new Rango(20.0, Vector2D{ 1.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 0.5, 0.25);
		vida_max = 60.0;
		vida_actual = 60.0;
		velocidad = 2.0;
		dano = 20.0;
		cooldown = 5;
		hitbox = new HitboxRectangular({ 0.4,  0.4 });


	}

	Distancia(string n, Bando b, Tipo tipo1, Tipo tipo2, Vector2D pos_t, string s, Vector2D centro = { 0,0 }, Vector2D set = { 0,0 }, Vector2D hit = { 0,0 })
		: Pokemon(
			  n        //Nombre
			, tipo1
			, tipo2
			, b        //Bando
			, 'D'
			, TipoMovimiento::Tierra
			, pos_t
			, 3        //Numero de casilla
			, 60.0    //Vida
			, 2.0     //Velocidad
			, 20.0    //Dano
			, 5.0     //Cooldown
			, s       //Ruta de imagen
		)
	{
		ataque = new Rango(20.0, Vector2D{ 1.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 0.5, 0.5);
		hitbox = new HitboxRectangular(hit);

		sprites->setSize(set.x, set.y);
		sprites->setCenter(centro.x, centro.y);

		centro_s = centro;
		set_s = set;
	}

};

