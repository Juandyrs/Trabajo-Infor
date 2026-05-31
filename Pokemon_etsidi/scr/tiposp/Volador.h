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
        velocidad = 2.0;
        hitbox = new HitboxRectangular({ 0.4,  0.4 });
    }

    Volador(string n, Bando b, Tipo tipo1, Tipo tipo2, Vector2D pos_t, string s, Vector2D centro = { 0,0 }, Vector2D set = { 0,0 }, Vector2D hit = { 0,0 })
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
            , 2.0     //Velocidad
            , 30.0    //Dano
            , 5.0     //Cooldown
            , s        //Ruta de imagen
        )
    {
		ataque = new Rango(20.0, Vector2D{ 0.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 1.5, 0.25);
        hitbox = new HitboxRectangular({ 0.4,  0.4 });

        sprites->setSize(set.x, set.y);
        sprites->setCenter(centro.x, centro.y);

        centro_s = centro;
        set_s = set;
    }
  
};

