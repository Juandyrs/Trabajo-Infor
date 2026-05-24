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
        Hitbox = { 0.5, 0.5 };
    }

    CambiaFormas(string n, Bando b, Tipo tipo1, Tipo tipo2, Vector2D pos_t)
        : nombre_original(n)
    {
        //Arena
        vida_max = 60.0;
        vida_actual = 60.0;
        Hitbox = { 0.5, 0.5 };

        //Tablero
        nombre = n;
        equipo = b; 
        tip1 = tipo1;
        tip2 = tipo2;
        pos_tab = pos_t;
        simbolo = 'C';
    }

    void cambiar_forma(Pokemon &enemigo);
    void forma_original() { nombre = nombre_original; }
    void atacar(Pokemon &objetivo) override;
};

