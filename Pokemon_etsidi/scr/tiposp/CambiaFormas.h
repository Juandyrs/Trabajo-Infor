#pragma once

#include "Pokemon.h"

class CambiaFormas :
    public Pokemon
{
	Pokemon *forma; //Prueba

public:

    CambiaFormas() = default;

    CambiaFormas(string n, Bando b, Tipo tipo1, Tipo tipo2, Vector2D pos_t)
		: forma(nullptr)
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

    

};

