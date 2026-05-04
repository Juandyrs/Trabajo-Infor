#pragma once

#include "Pokemon.h"
#include "Ataque.h"

class Distancia :
    public Pokemon
{

	Rango ataque;

public:

	//Constructor para la clase Distancia, que inicializa la clase

	Distancia()
		: ataque(20.0, Vector2D{ 1.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 0.5, 0.5)
	{
		// No se pueden inicializar miembros heredados en la lista de inicialización
		vida_max = 60.0;
		vida_actual = 60.0;
		velocidad = 0.2;
		dano = 20.0;
		cooldown = 5;
		Hitbox = { 2, 2 }; // Hitbox para prueba, hay que cambiarlo
	}

    void preparar(string n, char s, Bando b, Tipo t1, Tipo t2) {

        inicializa_datos(n, s, b, t1, t2); //Paso los datos recibidos del main
        inicializa_stats(200.0, 200.0, 50.0); //Paso las estadísticas
        inicializa_mov(TipoMovimiento::Tierra, 5);//Paso el tipo de transporte
    }

	void atacar( Vector2D posicion, Vector2D dir) override;
	void atacar_dibujar() override;
	void mueve_ataque() override { ataque.pos_atk = ataque.pos_atk + ataque.vel_proyectil; }
	bool colision_ataque(Pokemon &objetivo) override;
};

