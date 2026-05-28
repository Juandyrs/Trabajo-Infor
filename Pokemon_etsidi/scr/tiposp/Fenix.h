#pragma once

#include "Pokemon.h"
#include "Ataque.h"

class Fenix :
    public Pokemon
{
  
public:

    Fenix() = default;

    //Constructor necesario para la arena
    Fenix(int a)
    {
        ataque = new Area(5.0, Vector2D{ 0.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 0.75, 60);
        dano = 5.0;
        vida_max = 60.0;
        vida_actual = 60.0;
        velocidad = 0.2;
        hitbox = new HitboxRectangular({ 0.5,  0.5 });
    }

    Fenix(string n, Bando b, Tipo tipo1, Tipo tipo2, Vector2D pos_t, string s)
        : Pokemon(
              n        //Nombre
            , tipo1
            , tipo2
            , b        //Bando
            , 'F'
            , TipoMovimiento::Vuelo
            , pos_t
            , 3        //Numero de casilla
            , 60.0    //Vida
            , 0.2     //Velocidad
            , 5    //Dano
            , 5.0     //Cooldown
            , s        //Ruta de imagen
        )
    {
        //Atributos arena
		ataque = new Area(5.0, Vector2D{ 0.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 1.5, 60);
        hitbox = new HitboxRectangular({ 0.5,  0.5 });
	}


    //Arena
    void atacar(Pokemon &objetivo) override;
};

