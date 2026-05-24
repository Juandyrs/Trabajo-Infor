#include "CambiaFormas.h"
#include "Fenix.h"

void CambiaFormas::cambiar_forma(Pokemon &enemigo)
{
	nombre = enemigo.consultar_nombre();
	velocidad = enemigo.consultar_vel();
	dano = enemigo.consultar_dano();
	cooldown = enemigo.consultar_cd();
	Hitbox = enemigo.consultar_hitbox();

	Rango *aux0 = dynamic_cast<Rango*>(enemigo.consultar_ataque());
	Melee *aux1 = dynamic_cast<Melee*>(enemigo.consultar_ataque());
	Area *aux2 = dynamic_cast<Area*>(enemigo.consultar_ataque());

	if (aux0 != nullptr)
	{
		Rango *aux = new Rango(*aux0);
		ataque = aux;
		cout << "rango";
	}

	if (aux1 != nullptr)
	{
		Melee *aux = new Melee(*aux1);
		ataque = aux;
		cout << "melee";
	}

	if (aux2 != nullptr)
	{
		Area *aux = new Area(*aux2);
		ataque = aux;
		cout << "area";
	}
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
