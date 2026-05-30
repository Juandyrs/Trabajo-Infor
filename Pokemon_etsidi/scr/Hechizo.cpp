#include "Hechizo.h"
#include "Pokemon.h"

bool Hechizo::llamar_curar(Pokemon* objetivo) {
	if (Curar && objetivo != nullptr) {
		objetivo->cura_max();
		std::cout << "¡Hechizo de curacion aplicado!" << std::endl;
		Curar = false; //gastamos el hechizo
		return true;   //ha ido todo bien
	}
	std::cout << "¡Hechizo de curacion NO aplicado!" << std::endl;
	return false;    //este no se aplica si no queda de ese hechizo o no se ha apuntado a ningun pokemon 

}


bool Hechizo::llamar_teletransporte(Pokemon* p) {
    if (Teletransporte && p != nullptr) {
        

        //DATOS PARA RESTABLECER MAS TARDE
        movoriginal = p->obtenertipomovimiento();
        casillasoriginal = p->obtenerncasillas();

        //CAMBIAR EL TIPO
        p->teletransporte();

        std::cout << "¡Hechizo de teletransporte activado!" << std::endl;
        Teletransporte = false;
        return true;
    }

    std::cout << "¡Hechizo de teletransporte NO aplicado!" << std::endl;
    return false;
}


bool Hechizo::llamar_intercambio(Pokemon* p) {

    if (Intercambio && p != nullptr) {

        //GUARDAR LOS INICIALES PARA INTERCAMBIO
        movoriginal = p->obtenertipomovimiento();
        casillasoriginal = p->obtenerncasillas();

      //MODO TELETRANSPORTE PARA PODER MOVERTE BIEN
        p->teletransporte();

        std::cout << "¡Hechizo de intercambio activado!" << std::endl;
        Intercambio = false;
        return true;
    }

    std::cout << "¡Hechizo de intercambio NO aplicado!" << std::endl;
    return false;
}

bool Hechizo::llamar_bloqueo(Pokemon* p) {
    if (Bloquear && p != nullptr) {

        //DATOS PARA RESTABLECER MAS TARDE
        movoriginal = p->obtenertipomovimiento();
        casillasoriginal = p->obtenerncasillas();

    //CAMBIAR SU MOVIMIENTO A 0, TIERRA DA IGUAL LUEGO SE REINICIA
        p->restablecermovimiento(TipoMovimiento::Tierra, 0);

        std::cout << "¡Hechizo de bloqueo aplicado!" << std::endl;
        Bloquear = false;
        return true;
    }

    std::cout << "¡Hechizo de bloqueo NO aplicado!" << std::endl;
    return false;
}
}

bool Hechizo::llamar_revivir() {
	if (Revivir) {
		std::cout << "¡Hechizo de revivir aplicado!" << std::endl;
		Revivir = false; 
		return true;
	}
	std::cout << "¡Hechizo de revivir NO aplicado!" << std::endl;
	return false;
}