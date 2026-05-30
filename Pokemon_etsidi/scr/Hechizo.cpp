#include "Hechizo.h"

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