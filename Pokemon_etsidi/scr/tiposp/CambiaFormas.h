#pragma once

#include "Pokemon.h"

class CambiaFormas :
    public Pokemon
{

public:

    void preparar(string n, char s, Bando b, Tipo t1, Tipo t2) {


        inicializa_datos(n, s, b, t1, t2); //Paso los datos recibidos del main
        inicializa_stats(200.0, 200.0, 50.0); //Paso las estadísticas
        inicializa_mov(TipoMovimiento::Teletransporte, 9);//Paso el tipo de transporte
    }

    void atacar(Vector2D posicion, Vector2D dir) override;
    void atacar_dibujar() override;
    void mueve_ataque() override {}
    bool colision_ataque(Pokemon &objetivo) override;
};

