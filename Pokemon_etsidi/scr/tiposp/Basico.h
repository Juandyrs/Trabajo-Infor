#pragma once

#include "Pokemon.h"
#include "Ataque.h"

class Basico :
    public Pokemon
{

public:

    Basico() = default;

    //Constructo para pruebas en la Arena
    Basico(int a)
    {
        //Arena
        ataque = new Melee(10.0, Vector2D{ 1.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 1.0, 0.75, 5);
        dano = 10.0;
        vida_max = 60.0;
        vida_actual = 60.0;
        velocidad = 0.5;
        hitbox = new HitboxRectangular({ 0.5,  0.5 });
        cooldown = 5.0;
    }
    
    Basico(string n, Bando b, Tipo tipo1, Tipo tipo2, Vector2D pos_t, string s)
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
            , 0.5     //Velocidad
            , 10.0    //Dano
            , 5.0     //Cooldown
            , s        //Ruta de imagen
        )
    {
        ataque = new Melee(10.0, Vector2D{ 1.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 1.0, 1.5, 5);
        hitbox = new HitboxRectangular({ 0.5,  0.5 });
    }

    


    // Metodos de la arena
};

