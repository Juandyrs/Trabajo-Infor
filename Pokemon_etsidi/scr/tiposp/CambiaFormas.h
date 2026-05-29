#pragma once

#include "Pokemon.h"

class CambiaFormas :
    public Pokemon
{
    string nombre_original;

public:

    CambiaFormas() = default;

    CambiaFormas(int a)
    {
        vida_max = 60.0;
        vida_actual = 60.0;
        hitbox = new HitboxRectangular({ 0.5,  0.5 });
 

    }

    CambiaFormas(string n, Bando b, Tipo tipo1, Tipo tipo2, Vector2D pos_t, string s)
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
            , 0.5     //Velocidad
            , 10.0    //Dano
            , 5.0     //Cooldown
            , s        //Ruta de imagen
        )
        , nombre_original(n)
    {
        //Arena
        vida_max = 60.0;
        vida_actual = 60.0;
        hitbox = new HitboxRectangular({ 0.5,  0.5 });

        //Tablero
        nombre = n;
        equipo = b; 
        tip1 = tipo1;
        tip2 = tipo2;
        pos_tab = pos_t;
        simbolo = 'C';
        sprite = s;
        numero_casillas = 5;
        movimiento = TipoMovimiento::Tierra;
    }

    void cambiar_forma(Pokemon &enemigo);
    void forma_original();
    void atacar(Pokemon &objetivo) override;
};

