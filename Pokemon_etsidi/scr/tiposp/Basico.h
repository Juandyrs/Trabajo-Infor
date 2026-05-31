#pragma once

#include "Pokemon.h"
#include "Ataque.h"

class Basico :
    public Pokemon
{
    
public:

    Basico() = default;

    //Constructo para pruebas en la Arena

    
    Basico(string n, Bando b, Tipo tipo1, Tipo tipo2, Vector2D pos_t, string s, Vector2D centro = {0,0}, Vector2D set = { 0,0 }, Vector2D hit = { 0,0 })
        : Pokemon(
              n        //Nombre
            , tipo1    
            , tipo2
            , b        //Bando
            ,'B'
            , TipoMovimiento::Tierra
            , pos_t
            , 3        //Numero de casilla
            , 60.0    //Vida
            , 2.0     //Velocidad
            , 10.0    //Dano
            , 5.0     //Cooldown
            , s        //Ruta de imagen
        )
    {
        //Arena
		ataque = new Melee(10.0, Vector2D{ 1.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 0.5, 0.75, 2);
        hitbox = new HitboxRectangular(hit);

        sprites->setSize(set.x, set.y);
        sprites->setCenter(centro.x, centro.y);

        centro_s = centro;
        set_s = set;
    }

};

