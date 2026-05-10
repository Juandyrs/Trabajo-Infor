#pragma once

#include "Pokemon.h"
#include "Ataque.h"

class Fenix :
    public Pokemon
{

public:

    Fenix()
    {
		ataque = new Area(5.0, Vector2D{ 0.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 1.5, 60);
        vida_max = 60.0;
        vida_actual = 60.0;
        velocidad = 0.2;
        Hitbox = { 1.0, 1.0 };
	}

    void preparar(string n, char s, Bando b, Tipo t1, Tipo t2) {


        inicializa_datos(n, s, b, t1, t2); //Paso los datos recibidos del main
        inicializa_stats(200.0, 200.0, 50.0); //Paso las estadísticas
        inicializa_mov(TipoMovimiento::Teletransporte, 9);//Paso el tipo de transporte
    }

    void atacar(Pokemon &objetivo) override;
};

