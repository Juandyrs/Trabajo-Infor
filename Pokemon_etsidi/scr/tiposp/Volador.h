#pragma once

#include "Pokemon.h"

class Volador :
    public Pokemon
{

public:
    Volador() = default;


    Volador(int a) //Constructor para pruebas en la arena
    {
        ataque = new Rango(5.0, Vector2D{ 0.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 1.5, 3);
        vida_max = 60.0;
        vida_actual = 60.0;
        velocidad = 0.2;
        Hitbox = { 0.5, 0.5 };
    }

    Volador(string n, Bando b, Tipo tipo1, Tipo tipo2, Vector2D pos_t)
    {
        //Arena
		ataque = new Rango(5.0, Vector2D{ 0.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 1.5, 3);
        vida_max = 60.0;
        vida_actual = 60.0;
        velocidad = 0.2;
        Hitbox = { 0.5, 0.5 };

        //Tablero
        nombre = n;
        equipo = b;
        tip1 = tipo1;
        tip2 = tipo2;
        pos_tab = pos_t;
        simbolo = 'V';
    }

   
  
};

