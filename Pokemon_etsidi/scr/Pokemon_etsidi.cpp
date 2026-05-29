// Pokemon_etsidi.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.


#include <iostream>
#include <freeglut.h>
#include "Juego.h"
#include <chrono>

using namespace std::chrono;

using std::vector;

void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion 
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void OnKeyboardUp(unsigned char key, int x, int y);

Juego Archon;

bool keys[256]{false};

// Para poder detectar el pulsado de dos teclas simultaneas

int main(int argc, char* argv[])
{

	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("POKETSIDI");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown); // Registra cuando se pulsa una de las teclas
	glutKeyboardUpFunc(OnKeyboardUp); // Registra cuando se deja de pulsar una tecla

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();
	return 0;
}

void OnDraw(void)
{
	//Codigo de Dibujo del Juego
	Archon.dibujar_Juego();
	
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//codigo de gestion de teclado
	
	keys[key] = true;

	Archon.mover_Juego(keys);


	//indicamos que se vuelva a dibujar la pantalla, para que se vean los cambios
	glutPostRedisplay();
}

void OnKeyboardUp(unsigned char key, int x_t, int y_t)
{
	//codigo de gestion de teclado

	keys[key] = false;

	Archon.mover_Juego(keys);

	//indicamos que se vuelva a dibujar la pantalla, para que se vean los cambios
	glutPostRedisplay();
}

void OnTimer(int value)
{
	// calcular dt real entre llamadas usando std::chrono
	static auto last = high_resolution_clock::now();
	auto now = high_resolution_clock::now();
	duration<double> elapsed = now - last;
	double dt = elapsed.count();
	last = now;

	//código de animacion

	Archon.jugar();
	Archon.animar();
	Archon.actualizar_juego(dt);

	//no borrar estas lineas
	//indicamos que se vuelva a dibujar la pantalla, para que se vean los cambios
	glutPostRedisplay();
	//recurivamente, le decimos que dentro de 25ms vuelva a llamar a esta funcion, para que se siga animando
	glutTimerFunc(25, OnTimer, 0);
}
