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
    {
        //Arena
		ataque = new Melee(10.0, Vector2D{ 1.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 1.0, 1.5, 5);
        dano = 10.0;
        vida_max = 60.0;
        vida_actual = 60.0;
        velocidad = 0.5;
        hitbox = new HitboxRectangular({ 0.5,  0.5 });
		cooldown = 5.0;

        //Tablero

        nombre = n;
        simbolo = 'B';
        equipo = b;
        tip1 = tipo1;
        tip2 = tipo2;
        pos_tab = pos_t;
        sprite = s;
        
    }

    


    // Metodos de la arena
};

