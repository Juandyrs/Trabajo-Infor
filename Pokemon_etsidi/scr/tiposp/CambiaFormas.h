#pragma once

#include "Pokemon.h"

class CambiaFormas :
    public Pokemon
{
    ETSIDI::SpriteSequence* sprite_original;

public:

    CambiaFormas() = default;

    CambiaFormas(int a)
    {
        vida_max = 60.0;
        vida_actual = 60.0;
        hitbox = new HitboxRectangular({ 0.4,  0.4 });
 

    }

    CambiaFormas(string n, Bando b, Tipo tipo1, Tipo tipo2, Vector2D pos_t, string s, Vector2D centro = { 0,0 }, Vector2D set = { 0,0 }, Vector2D hit = { 0,0 })
        : Pokemon(
              n        //Nombre
            , tipo1
            , tipo2
            , b        //Bando
            , 'C'
            , TipoMovimiento::Vuelo
            , pos_t
            , 4        //Numero de casilla
            , 60.0    //Vida
            , 2.0     //Velocidad
            , 10.0    //Dano
            , 5.0     //Cooldown
            , s        //Ruta de imagen
        )
        , sprite_original(new ETSIDI::SpriteSequence(s.c_str(), 3, 5))
    {
        hitbox = new HitboxRectangular(hit);

        sprites->setSize(set.x, set.y);
        sprites->setCenter(centro.x, centro.y);

        centro_s = centro;
        set_s = set;
    }

    void cambiar_forma(Pokemon &enemigo);
    void forma_original();
    void atacar(Pokemon &objetivo) override;
};

