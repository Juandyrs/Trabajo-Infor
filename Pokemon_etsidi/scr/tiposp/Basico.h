#pragma once

#include "Pokemon.h"
#include "Ataque.h"

class Basico :
    public Pokemon
{

public:
    Basico() = default;
    Basico(string n, Bando b, Tipo tipo1, Tipo tipo2, Vector2D pos_t)
    {
        //Arena
		ataque = new Melee(10.0, Vector2D{ 1.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 2.0, 2.5, 5);
        vida_max = 60.0;
        vida_actual = 60.0;
        velocidad = 0.5;
        Hitbox = { 1.0 , 1.0 };

        //Tablero

        nombre = n;
        simbolo = 'B';
        equipo = b;
        tip1 = tipo1;
        tip2 = tipo2;
        pos_tab = pos_t;
        
    }

    void preparar(string n, char s, Bando b, Tipo t1, Tipo t2) {


        inicializa_datos(n, s, b, t1, t2); //Paso los datos recibidos del main
        inicializa_stats(200.0, 200.0, 50.0); //Paso las estadísticas
        inicializa_mov(TipoMovimiento::Tierra, 5);//Paso el tipo de transporte
    }


    // Metodos de la arena
};

