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

    //calculamos la esquina superior izquierda y de ahi dibujamos el cuadrado

    float x = columna * lado;
    float y = (8 - fila) * lado;



    //seleccionamos el color en funcion del estado de la casilla

    switch (tipo) {
    case TipoCasilla::clara:
        glColor3ub(235, 235, 225); // Gris muy claro
        break;
    case TipoCasilla::oscura:
        glColor3ub(65, 65, 75);    // Gris oscuro 
        break;
    case TipoCasilla::neutr:
        glColor3ub(140, 150, 160); // Gris medio
        break;
    case TipoCasilla::poder:
        glColor3ub(255, 215, 0);   // Dorado 
        break;
    case TipoCasilla::aviso_claro:
        glColor3ub(240, 170, 90);  // Naranja 
        break;
    case TipoCasilla::aviso_oscuro:
        glColor3ub(240, 170, 90);   // Rojo apagado 
        break;
    case TipoCasilla::aviso_neutro:
        glColor3ub(240, 170, 90); // Verde apagado 
        break;
    }

    //dibujamos el cuadrado indicando los vertices

    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + lado, y);
    glVertex2f(x + lado, y + lado);
    glVertex2f(x, y + lado);
    glEnd();

    //dibujamos el marco de la casilla
    glLineWidth(1.5f);
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + lado, y);
    glVertex2f(x + lado, y + lado);
    glVertex2f(x, y + lado);
    glEnd();
    
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
        ETSIDI::GLTexture tex = ETSIDI::getTexture(p->obtenersprite().c_str());

            float cx = x + lado * 0.5f;   
            float cy = y + lado * 0.5f;   

            float escala = 0.45f;         //ESCALA, VA DE 0 a 1
            float tamano = lado * escala;   

            glPushMatrix();

            glDisable(GL_LIGHTING);

            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, tex.id);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            glColor3f(1.0f, 1.0f, 1.0f); 

            glPushMatrix();



            glTranslatef(cx, cy, 0.53f);

            glBegin(GL_QUADS);
            glTexCoord2f(0, 1); glVertex3f(-tamano, -tamano, 0); 
            glTexCoord2f(1, 1); glVertex3f(tamano, -tamano, 0);  
            glTexCoord2f(1, 0); glVertex3f(tamano, tamano, 0);   
            glTexCoord2f(0, 0); glVertex3f(-tamano, tamano, 0);  
            glEnd();

            glPopMatrix();

            glDisable(GL_BLEND);
            glDisable(GL_TEXTURE_2D);
            glEnable(GL_DEPTH_TEST);
        }
}

