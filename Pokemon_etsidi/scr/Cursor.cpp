#include "Cursor.h"
#include "Tablero.h"
#include "Pokemon.h"
#include <ETSIDI.h>
#include "cmath"


using namespace std;

void Cursor::inicializarcursor(int f, int c) {
    fila = f;
    columna = c;
}

void Cursor::dibujarcursor() {

    float lado = 5.0f;
    float x = columna * lado; //ESTAN AL REVES POR QUE SI NO EL MOVIMIENTO SALE INVERTIDO :p
    float y = fila * lado;

    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4ub(255, 255, 0, 100);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + lado, y);
    glVertex2f(x + lado, y + lado);
    glVertex2f(x, y + lado);
    glEnd();
    glDisable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);

  //  glEnable(GL_TEXTURE_2D);
   // glEnable(GL_BLEND);
   // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

   // glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/sprites/pokeball.png"));

    //glPushMatrix();
    //glTranslatef(x, y, 0.53f);

   // glBegin(GL_QUADS);
   // glTexCoord2f(0, 0); glVertex3f(-lado, -lado, 0);
   // glTexCoord2f(1, 0); glVertex3f(lado, -lado, 0);
   // glTexCoord2f(1, 1); glVertex3f(lado, lado, 0);
//glTexCoord2f(0, 1); glVertex3f(-lado, lado, 0);
   // glEnd();


    if (fichaencursor != nullptr && Tipomov != TipoMovimiento::Teletransporte ) { //EL PSIQUICO SE TELETRANSPORTA O LO QUE ES LO MISMO, NO SE DIBUJA CON EL CURSOR

        float cx = x + lado * 0.5f;
        float cy = y + lado * 0.5f;

        float escala = 0.45f;         //ESCALA, VA DE 0 a 1
        float tamano = lado * escala;

        glPushMatrix();

        // Plano base
        glPushMatrix();
        glTranslatef(cx, cy, 0.52f);
        glBegin(GL_QUADS);
        glVertex3f(-tamano, -tamano, 0);
        glVertex3f(tamano, -tamano, 0);
        glVertex3f(tamano, tamano, 0);
        glVertex3f(-tamano, tamano, 0);
        glEnd();
        glPopMatrix();

        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(fichaencursor->obtenersprite().c_str()).id);

        glPushMatrix();
        glTranslatef(cx, cy, 0.53f);

        glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-tamano, -tamano, 0);
        glTexCoord2f(1, 0); glVertex3f(tamano, -tamano, 0);
        glTexCoord2f(1, 1); glVertex3f(tamano, tamano, 0);
        glTexCoord2f(0, 1); glVertex3f(-tamano, tamano, 0);
        glEnd();

        glPopMatrix();

        glDisable(GL_BLEND);
        glDisable(GL_TEXTURE_2D);

        glPopMatrix();
    }
}

void Cursor::cursorpillaficha(Pokemon* p) {


    llevaficha = true;
    fichaencursor = p;

    fi = fila;
    ci = columna;

    maxdistancia = p->obtenerncasillas();
    Tipomov = p->obtenertipomovimiento();

}

void Cursor::cursorsueltaficha() {
    llevaficha = false;
    fichaencursor = nullptr;
    maxdistancia = 0;
}

void Cursor::Cursormover(bool key[], Pokemon* matriz[9][9], int hechizo) {

    int absfila = fila;
    int abscolumna = columna;

    if (key['a'] || key['A']) columna--;

    else if (key['d'] || key['D']) columna++;
    else if (key['w'] || key['W']) fila++;
    else if (key['s'] || key['S']) fila--;

    if (columna < 0) columna = 0;
    if (columna > 8) columna = 8;

    if (fila < 0) fila = 0;
    if (fila > 8) fila = 8;

 
    if (llevaficha == false) return;
   

    //PARA MOVIMIENTOS TERRESTRES

    if (llevaficha == true){
        
        actualdistancia = abs(fi - fila) + abs(ci - columna);
        if (hechizo != 1) {
        if (actualdistancia > maxdistancia) {
            fila = absfila;
            columna = abscolumna;
        }

        
        if (Tipomov == TipoMovimiento::Tierra) {
            if (matriz[fila][columna] != nullptr) {
                fila = absfila;
                columna = abscolumna;
            }
            }
        }
    }



}



void Cursor::distancialactual() {

    actualdistancia = fi + fila;
}