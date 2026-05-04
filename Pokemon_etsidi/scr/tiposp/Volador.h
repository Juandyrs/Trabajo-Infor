#pragma once

#include "Pokemon.h"

class Volador :
    public Pokemon
{
    
    Area ataque;

public:

    Volador()
        : ataque(5.0, Vector2D{ 0.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 1.5, 2.0)
    {
        vida_max = 60.0;
        vida_actual = 60.0;
        velocidad = 0.2;
        Hitbox = { 1.0, 1.0 };
    }

    void preparar(string n, char s, Bando b, Tipo t1, Tipo t2)
    {
        inicializa_datos(n, s, b, t1, t2); //Paso los datos recibidos del main
        inicializa_stats(200.0, 200.0, 50.0); //Paso las estadísticas
        inicializa_mov(TipoMovimiento::Vuelo, 5);//Paso el tipo de transporte
    }
  
    void atacar(Vector2D posicion, Vector2D dir) override;
    void atacar_dibujar() override;
    void mueve_ataque() override {}
    bool colision_ataque(Pokemon& objetivo) override;
};

