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
    float y = (8 - fila) * lado;

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

    if (fichaencursor != nullptr && Tipomov != TipoMovimiento::Teletransporte ) { //EL PSIQUICO SE TELETRANSPORTA O LO QUE ES LO MISMO, NO SE DIBUJA CON EL CURSOR

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

        fichaencursor->dibujar_pokemon(0);

        glPopMatrix();

        glDisable(GL_BLEND);
        glDisable(GL_TEXTURE_2D);
        glEnable(GL_DEPTH_TEST);
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

void Cursor::Cursormover(bool key[], Pokemon* matriz[9][9]) {

    int absfila = fila;
    int abscolumna = columna;

    if (key['a'] || key['A']) columna--;
    else if (key['d'] || key['D']) columna++;
    else if (key['s'] || key['S']) fila++;
    else if (key['w'] || key['W']) fila--;

    if (columna < 0) columna = 0;
    if (columna > 8) columna = 8;

    if (fila < 0) fila = 0;
    if (fila > 8) fila = 8;

    if (llevaficha == false) return;

    //PARA MOVIMIENTOS TERRESTRES

    if (llevaficha == true) {

        actualdistancia = abs(fi - fila) + abs(ci - columna);

        if (actualdistancia > maxdistancia) {
            fila = absfila;
            columna = abscolumna;
        }


        if (Tipomov == TipoMovimiento::Tierra) {

            Pokemon* destino = matriz[fila][columna];


            if (destino == nullptr) //VACIO SE PERMITE PASAR, LO QUE TENIAMOS PUEstO ANTES
                return;


            if (destino->obtener_bando() == fichaencursor->obtener_bando()) { //ALIADO NO TE DEJA PASAR, ES LO QUE TENIAMOS ANTES
                fila = absfila;
                columna = abscolumna;
                return;
            }


            if (destino->obtener_bando() != fichaencursor->obtener_bando()) { //SI ES ENEMIGA SE QUEDA PARA PELEAR; LAS FICHAN NO PUEDEN HUIR NO SON COBARDES JAJAJ, SOLO SI SON TERRESTRES LAS OTAS PASAN POR ENCIMA, ADEMAS SE LE PERMITE VOLVER A LA DE PARTIDA SI ESTA AL LADO

                maxdistancia = 0; //BLOQUEAR EN LA CASILLA (DEJARIA VOLVER A LA DE SALIDA SI ESTA AL LADO)


                return;
            }
        }

    }
}

void Cursor::mod_fila(bool sumar)
{
    if (sumar) fila++;
    else fila--;

    if (fila < 0) fila = 0;
    if (fila > 8) fila = 8;
}

void Cursor::mod_columna(bool sumar)
{
    if (sumar) columna++;
    else columna--;

    if (columna < 0) columna = 0;
    if (columna > 8) columna = 8;
}

void Cursor::resetear_cursor()
{
    llevaficha = false;
    fichaencursor = nullptr;
    llevaficha = false;
    actualdistancia = 0;
    actualmaxdistancia = 0;
}


