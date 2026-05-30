#include "Textos.h"

void Textos::escribirCadena2D(float x, float y, const char* cadena) {
    glRasterPos3d(x, y, 1);
    for (const char* c = cadena; *c != '\0'; c++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
}

void Textos::escribirChar2D(float x, float y, char letra) {
    glRasterPos3d(x, y, 1);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letra);
}

void Textos::escribirCadena2DPequena(float x, float y, const char* cadena) {
    glRasterPos3d(x, y, 1);
    for (const char* c = cadena; *c != '\0'; c++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); 
}