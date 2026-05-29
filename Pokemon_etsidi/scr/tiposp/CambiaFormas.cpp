#include "CambiaFormas.h"
#include "Fenix.h"

void CambiaFormas::cambiar_forma(Pokemon &enemigo)
{
	nombre = enemigo.consultar_nombre();
	velocidad = enemigo.consultar_vel();
	dano = enemigo.consultar_dano();
	cooldown = enemigo.consultar_cd();
	hitbox = new HitboxRectangular(enemigo.consultar_dim_hitbox());

	ataque = enemigo.consultar_ataque()->clonar();

	std::cout << enemigo.consultar_ataque()->consultar_hitbox() << '\n';
	std::cout << ataque->consultar_hitbox() << '\n';
}

void CambiaFormas::forma_original()
{
	nombre = nombre_original;
	delete ataque;
	delete hitbox;
}

void CambiaFormas::atacar(Pokemon &objetivo)
{

	if (typeid(objetivo) == typeid(Fenix)) 
	{
		Fenix aux(1); //Para saber la velocidad inicial del personaje
		double vida_inicial = vida_actual;

		if (!atacando)
		{
			velocidad = aux.consultar_vel();
			if (efecto_estado == EfectoEstado::Invulnerable) efecto_estado = EfectoEstado::Ninguno;
			return;
		}

		velocidad = 0.0;
		efecto_estado = EfectoEstado::Invulnerable;
	}

	Pokemon::atacar(objetivo);
}
