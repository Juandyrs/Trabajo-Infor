#pragma once

#include "Pokemon.h"

class Volador :
    public Pokemon
{

public:
    Volador() = default;


    Volador(int a) //Constructor para pruebas en la arena
    {
        ataque = new Rango(20.0, Vector2D{ 0.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 1.5, 0.25);
        dano = 30;
        vida_max = 60.0;
        vida_actual = 60.0;
        velocidad = 0.2;
        hitbox = new HitboxRectangular({ 0.5,  0.5 });
    }

    Volador(string n, Bando b, Tipo tipo1, Tipo tipo2, Vector2D pos_t, string s)
        : Pokemon(
            n        //Nombre
            , tipo1
            , tipo2
            , b        //Bando
            , 'V'
            , TipoMovimiento::Vuelo
            , pos_t
            , 3        //Numero de casilla
            , 60.0    //Vida
            , 0.2     //Velocidad
            , 30.0    //Dano
            , 5.0     //Cooldown
            , s        //Ruta de imagen
        )
    {
        //Arena
		ataque = new Rango(20.0, Vector2D{ 0.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 1.5, 0.25);
        dano = 30;
        vida_max = 60.0;
        vida_actual = 60.0;
        velocidad = 0.2;
        hitbox = new HitboxRectangular({ 0.5,  0.5 });

        //Tablero
        nombre = n;
        equipo = b;
        tip1 = tipo1;
        tip2 = tipo2;
        pos_tab = pos_t;
        simbolo = 'V';
        sprite = s;
        numero_casillas = 3;
        movimiento = TipoMovimiento::Vuelo;
    }
  
};

