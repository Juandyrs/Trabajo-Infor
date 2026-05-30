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

    Fenix(string n, Bando b, Tipo tipo1, Tipo tipo2, Vector2D pos_t, string s, Vector2D centro = { 0,0 }, Vector2D set = { 0,0 }, Vector2D hit = { 0,0 })
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
            , 0.8     //Velocidad
            , 5    //Dano
            , 5.0     //Cooldown
            , s        //Ruta de imagen
        )
    {
		ataque = new Area(5.0, Vector2D{ 0.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 0.5, 60);
        hitbox = new HitboxRectangular({ 0.5,  0.5 });

        sprites->setSize(set.x, set.y);
        sprites->setCenter(centro.x, centro.y);

        centro_s = centro;
        set_s = set;
	}


    //Arena
    void atacar(Pokemon &objetivo) override;
};

