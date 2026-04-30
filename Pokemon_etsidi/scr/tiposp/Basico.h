#pragma once

#include "Pokemon.h"

class Basico :
    public Pokemon
{
public:

    Basico()    
    {
        vida_max = 60.0;
        vida_actual = 60.0;
        velocidad = 2.0;
        Hitbox = { 0.5, 0.5 };
	}

    void preparar(string n, char s, Bando b, Tipo t1, Tipo t2) {


        inicializa_datos(n, s, b, t1, t2); //Paso los datos recibidos del main
        inicializa_stats(200.0, 200.0, 50.0); //Paso las estadísticas
        inicializa_mov(TipoMovimiento::Tierra, 5);//Paso el tipo de transporte
    }

};

