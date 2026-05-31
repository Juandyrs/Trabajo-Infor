#include "Hechizo.h"
#include "Pokemon.h"

bool Hechizo::llamar_curar(Pokemon* objetivo) {
	if (Curar && objetivo != nullptr) {
		objetivo->cura_max();
		Curar = false; //gastamos el hechizo
		return true;   //ha ido todo bien
	}
    mensaje_error = 1;   
    t_error = 3.0f;  
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

    mensaje_error = 1;
    t_error = 3.0f;
    
    return false;
}


bool Hechizo::llamar_intercambio(Pokemon* p) {

    if (Intercambio && p != nullptr) {

        //GUARDAR LOS INICIALES PARA INTERCAMBIO
        movoriginal = p->obtenertipomovimiento();
        casillasoriginal = p->obtenerncasillas();

      //MODO TELETRANSPORTE PARA PODER MOVERTE BIEN
        p->cambio();

        std::cout << "¡Hechizo de intercambio activado!" << std::endl;
        Intercambio = false;
        return true;
    }

    mensaje_error = 1;
    t_error = 3.0f;
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

    mensaje_error = 1;
    t_error = 3.0f;
    return false;
}

bool Hechizo::llamar_revivir() {
	if (Revivir) {
		std::cout << "¡Hechizo de revivir aplicado!" << std::endl;
		Revivir = false; 
		return true;
	}
    mensaje_error = 1;
    t_error = 3.0f;
    return false;
}


void Hechizo::actualiza_t(float t) {
    if (t_error > 0.0f) {
        t_error=t_error - t;
        if (t_error <= 0.0f) {
            mensaje_error = 0; 
        }
    }
}

void Hechizo::dibuja_errores() {
    if (t_error > 0.0f) {
        glDisable(GL_LIGHTING);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_TEXTURE_2D);

        if (mensaje_error == 1) {
            glColor3f(1.0f, 0.0f, 0.0f);
            Textos::escribirCadena2DPequena(2.0f, 48.0f, "HECHIZO YA UTILIZADO O NO DISPONIBLE");
        }
        else if (mensaje_error == 2) {
            glColor3f(1.0f, 0.0f, 0.0f);
            Textos::escribirCadena2DPequena(2.0f, 48.0f, "HECHIZO NO DISPONIBLE (SIN IMPLEMENTAR)");
        }

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
    }
}