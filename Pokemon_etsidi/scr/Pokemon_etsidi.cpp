// Pokemon_etsidi.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "tablero.h"
#include "Pokemon.h"
#include "Hechicero.h"
#include "Volador.h"
#include "Tanque.h"
#include "Distancia.h"
#include "Basico.h"
#include "Fenix.h"
#include "CambiaFormas.h"
#include "ArenaCombate.h"
#include <freeglut.h>

void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion 
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void OnKeyboardUp(unsigned char key, int x, int y);

Fenix &p1 = *new Fenix();
Distancia &p2 = *new Distancia();
ArenaCombate Arena(p1, p2);
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

	Tablero Mitablerito;
	Hechicero Alakazam,Gengar;
	Volador Charizard[2], Crobat[2];
	Tanque Snorlax[2], Tyranitar[2];
	Distancia Grovile[4], Umbreon[4];
	Basico Machop[7], Scraggy[7];
	CambiaFormas Ditto[2];
	Fenix Moltres[2];

	//Hechiceros
	Alakazam.preparar("Hechicero", 'H', Bando::Entrenador, Tipo::Psiquico, Tipo::Ninguno);
	Gengar.preparar("Hechicero", 'H', Bando::Team_Rocket, Tipo::Fantasma, Tipo::Veneno);
	
	//Voladores
	for(int i=0;i<2;i++) Charizard[i].preparar("Volador", 'V', Bando::Entrenador, Tipo::Fuego, Tipo::Volador);
	for(int i=0; i<2;i++) Crobat[i].preparar("Volador", 'V', Bando::Team_Rocket, Tipo::Veneno, Tipo::Volador);

	//Tanques 
	for (int i = 0; i < 2; i++) Snorlax[i].preparar("Tanque", 'T', Bando::Entrenador, Tipo::Normal, Tipo::Ninguno);
	for (int i = 0; i < 2; i++) Tyranitar[i].preparar("Tanque", 'T', Bando::Team_Rocket, Tipo::Tierra, Tipo::Siniestro);

	//Distancia
	for (int i = 0; i < 4; i++) Grovile[i].preparar("Distancia", 'D', Bando::Entrenador, Tipo::Planta, Tipo::Ninguno);
	for (int i = 0; i < 4; i++) Umbreon[i].preparar("Distancia", 'D', Bando::Team_Rocket, Tipo::Siniestro, Tipo::Ninguno);

	//Basico
	for (int i = 1; i < 8; i++) Machop[i-1].preparar("Basico", 'B', Bando::Entrenador, Tipo::Lucha, Tipo::Ninguno);
	for (int i = 1; i < 8; i++) Scraggy[i - 1].preparar("Basico", 'B', Bando::Team_Rocket, Tipo::Lucha, Tipo::Siniestro);
	
	//Cambiaforma
	for (int i = 0; i < 2; i++) Ditto[i].preparar("Cambiaforma", 'C', Bando::Team_Rocket, Tipo::Normal, Tipo::Ninguno);
	
	//Fenix
	for (int i = 0; i < 2; i++) Moltres[i].preparar("Fenix", 'F', Bando::Entrenador, Tipo::Fuego, Tipo::Volador);
	

	//Colocacion en tablero
	
	//Posicion Hechicero
	Mitablerito.colocar_pokemon(4, 0, &Alakazam);
	Mitablerito.colocar_pokemon(4, 8, &Gengar);
	//Posicion Volador
	Mitablerito.colocar_pokemon(2, 0, &Charizard[0]);
	Mitablerito.colocar_pokemon(6, 0, &Charizard[1]);
	Mitablerito.colocar_pokemon(2, 8, &Crobat[0]);
	Mitablerito.colocar_pokemon(6, 8, &Crobat[1]);
	//Posicion Tanque
	Mitablerito.colocar_pokemon(0, 0, &Snorlax[0]);
	Mitablerito.colocar_pokemon(8, 0, &Snorlax[1]);
	Mitablerito.colocar_pokemon(0, 8, &Tyranitar[0]);
	Mitablerito.colocar_pokemon(8, 8, &Tyranitar[1]);
	//Posicion Distancia
	Mitablerito.colocar_pokemon(0, 1, &Grovile[0]);
	Mitablerito.colocar_pokemon(1, 0, &Grovile[1]);
	Mitablerito.colocar_pokemon(7, 0, &Grovile[2]);
	Mitablerito.colocar_pokemon(8, 1, &Grovile[3]);
	Mitablerito.colocar_pokemon(0, 7, &Umbreon[0]);
	Mitablerito.colocar_pokemon(1, 8, &Umbreon[1]);
	Mitablerito.colocar_pokemon(8, 7, &Umbreon[2]);
	Mitablerito.colocar_pokemon(7, 8, &Umbreon[3]);
	//Posicion Basico
	for (int i = 1; i < 8; i++) Mitablerito.colocar_pokemon(i, 1, &Machop[i-1]);
	for (int i = 1; i < 8; i++) Mitablerito.colocar_pokemon(i, 7, &Scraggy[i-1]);
	//Posicion Cambiaforma
	Mitablerito.colocar_pokemon(3, 8,&Ditto[0]);
	Mitablerito.colocar_pokemon(5, 8, &Ditto[1]);
	//Posicion Fenix
	Mitablerito.colocar_pokemon(3, 0, &Moltres[0]);
	Mitablerito.colocar_pokemon(5, 0, &Moltres[1]);

	Mitablerito.imprimir();
	//Dibujar el tablero


	

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();
	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla y reseteo de la matriz de transformacion	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 0, 30,  // posicion del ojo
		0.0, 0, 0.0,				// hacia que punto mira  (0,0,0) 
		0.0, 1, 0.0);				// definimos hacia arriba (eje Z)    

	//aqui es donde hay que poner el codigo de dibujo
	
	Arena.dibuja_Ataques();
	Arena.dibuja_Obstaculos();
	Arena.dibuja_BarrasVida();
	Arena.dibuja_Personajes();
	Arena.dibuja_Arena();

	
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//codigo de gestion de teclado
	
	keys[key] = true;

	Arena.mueve_personaje(keys);


	//indicamos que se vuelva a dibujar la pantalla, para que se vean los cambios
	glutPostRedisplay();
}

void OnKeyboardUp(unsigned char key, int x_t, int y_t)
{
	//codigo de gestion de teclado

	keys[key] = false;

}

void OnTimer(int value)
{
	//código de animacion
	
	Arena.arena_combate();
	Arena.interaccion_obstaculos();
	Arena.limita_movimiento();

	//no borrar estas lineas
	//indicamos que se vuelva a dibujar la pantalla, para que se vean los cambios
	glutPostRedisplay();
	//recurivamente, le decimos que dentro de 25ms vuelva a llamar a esta funcion, para que se siga animando
	glutTimerFunc(25, OnTimer, 0);
}
