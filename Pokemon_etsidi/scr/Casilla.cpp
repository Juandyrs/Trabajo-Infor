#include "Casilla.h"
#include "Pokemon.h"
#include "Tablero.h"

void Casilla::inicializar(int f, int c) {

	fila = f;
	columna = c;

	if ((f == 0 && c == 4) ||
		(f == 4 && c == 4) ||
		(f == 4 && c == 0) ||
		(f == 8 && c == 4) ||
		(f == 4 && c == 8))
	{

		tipo = TipoCasilla::poder;
		cambio = -1;

	}

	//ponemos por ejemplo que aprx un cuarto de las casillas son cambiantes 

	else if (rand() % 4 == 0)
	{
		
		cambio = 0; // asignamos un estado para que no empiecen todas en el mismo;

		// le ponemos a la casilla el tipo neutro 

		if (cambio == 0) tipo = TipoCasilla::neutr;
		
	}

	else if ((f + c) % 2 == 0) {

		tipo = TipoCasilla::clara;
		cambio = -1;

	}

	else {
		tipo = TipoCasilla::oscura;
		cambio = -1;

	}

}



void Casilla::avanzar_ciclo() {

	if (cambio < 0) return;

	// Ciclo de 6 fases

	cambio = (cambio + 1) % 6;

	

	if(cambio == 0) tipo = TipoCasilla::neutr;
	else if (cambio == 1) tipo = TipoCasilla::aviso_claro; 
	else if (cambio == 2) tipo = TipoCasilla::clara;
	else if (cambio == 3) tipo = TipoCasilla::aviso_oscuro; 
	else if (cambio == 4) tipo = TipoCasilla::oscura;
	else if (cambio == 5) tipo = TipoCasilla::aviso_neutro;  

}

void Casilla::dibujarcasilla(Pokemon* p){

    float lado = 5.0f; //tamano del lado del cuadrado
    float margen = 0.00f;

    //calculamos la esquina superior izquierda y de ahi dibujamos el cuadrado

    float x = columna * lado;
    float y = (8 - fila) * lado;



    switch (tipo)
    {
    case TipoCasilla::clara:          //BLANCO
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/casillas/blanca.png").id);
        break;

    case TipoCasilla::oscura:         //NEGRO
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/casillas/negra.png").id);
        break;

    case TipoCasilla::neutr:         //GRIS
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/casillas/gris.png").id);
        break;

    case TipoCasilla::poder:          //PODER
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/casillas/morada.png").id);
        break;

    case TipoCasilla::aviso_claro:    //AMARILLO
    case TipoCasilla::aviso_oscuro:
    case TipoCasilla::aviso_neutro:
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/casillas/amarilla.png").id);
        break;
    }



    glDisable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor3ub(255, 255, 255);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 1); glVertex2f(x + margen, y + margen);
    glTexCoord2f(1, 1); glVertex2f(x + lado - margen, y + margen);
    glTexCoord2f(1, 0); glVertex2f(x + lado - margen, y + lado - margen);
    glTexCoord2f(0, 0); glVertex2f(x + margen, y + lado - margen);
    glEnd();

    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);

 
    


    // Dibujar pokeball morada
    if (tipo == TipoCasilla::poder && p == nullptr) {
        ETSIDI::GLTexture tex = ETSIDI::getTexture("bin/sprites/masterball.png"); 

        if (tex.id != 0) {
            float margen = 1.0f; 

            glDisable(GL_DEPTH_TEST);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, tex.id);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glColor3ub(255, 255, 255);

            glBegin(GL_QUADS);
            glTexCoord2f(0, 1); glVertex2f(x + margen, y + margen);
            glTexCoord2f(1, 1); glVertex2f(x + lado - margen, y + margen);
            glTexCoord2f(1, 0); glVertex2f(x + lado - margen, y + lado - margen);
            glTexCoord2f(0, 0); glVertex2f(x + margen, y + lado - margen);
            glEnd();

            glDisable(GL_BLEND);
            glDisable(GL_TEXTURE_2D);
            glEnable(GL_DEPTH_TEST);
        }
    }


    //DESDE AQUI ES PARA LOS POKEMONs
        if (p != nullptr) {

            float cx = x + lado * 0.5f;   
            float cy = y + lado * 0.5f;   

            float escala = 0.45f;         //ESCALA, VA DE 0 a 1
            float tamano = lado * escala;   

            glPushMatrix();

            glDisable(GL_LIGHTING);

            glEnable(GL_TEXTURE_2D);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            glColor3f(1.0f, 1.0f, 1.0f); 

            glPushMatrix();



            glTranslatef(cx, cy, 0.53f);

            p->dibujar_pokemon(0);

            glPopMatrix();

            glDisable(GL_BLEND);
            glDisable(GL_TEXTURE_2D);
            glEnable(GL_DEPTH_TEST);
        }
}

