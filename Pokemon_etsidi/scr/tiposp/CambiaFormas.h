#pragma once

#include "Pokemon.h"

class CambiaFormas :
    public Pokemon
{
	Pokemon *forma; //Prueba

public:

    CambiaFormas()
		: forma(nullptr)
    {
        vida_max = 60.0;
        vida_actual = 60.0;
        Hitbox = { 0.5, 0.5 };
    }

    void preparar(string n, char s, Bando b, Tipo t1, Tipo t2) {


        inicializa_datos(n, s, b, t1, t2); //Paso los datos recibidos del main
        inicializa_stats(200.0, 200.0, 50.0); //Paso las estadísticas
        inicializa_mov(TipoMovimiento::Teletransporte, 9);//Paso el tipo de transporte
    }

};

