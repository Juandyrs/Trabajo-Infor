// Pokemon_etsidi.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "tablero.h"
#include "Pokemon.h"
#include "Tipos_Pokemon.h"
#include <freeglut.h>

void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion 
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	

int main(int argc, char* argv[])
{

	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("PANGSIDI");

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
	glutKeyboardFunc(OnKeyboardDown);















	Tablero Mitablerito;
	Hechicero Alakazam,Gengar;
	Volador Charizard, Crobat;
	Tanque Snorlax, Tyranitar;
	Distancia Grovile, Umbreon;
	Basico Machop, Scraggy;


	//Hechiceros
	Alakazam.preparar("Hechicero", 'H', Bando::Entrenador, Tipo::Psiquico, Tipo::Ninguno);
	Gengar.preparar("Hechicero", 'H', Bando::Team_Rocket, Tipo::Fantasma, Tipo::Veneno);
	
	//Voladores
	Charizard.preparar("Volador", 'V', Bando::Entrenador, Tipo::Fuego, Tipo::Volador);
	Crobat.preparar("Volador", 'V', Bando::Team_Rocket, Tipo::Veneno, Tipo::Volador);

	//Tanques 
	Snorlax.preparar("Tanque", 'T', Bando::Entrenador, Tipo::Normal, Tipo::Ninguno);
	Tyranitar.preparar("Tanque", 'T', Bando::Team Rocket, Tipo::Tierra, Tipo::Siniestro);

	//Distancia
	Grovile.preparar("Distancia", 'D', Bando::Entrenador, Tipo::Planta, Tipo::Ninguno);
	Umbreon.preparar("Distancia", 'D', Bando::Team_Rocket, Tipo::Siniestro, Tipo::Ninguno);

	//Basico
	Machop.preparar("Basico", 'B', Bando::Entrenador, Tipo::Lucha, Tipo::Ninguno);
	Machop.preparar("Basico", 'B', Bando::Team_Rocket, Tipo::Lucha, Tipo::Siniestro);


	//Colocacion en tablero
	
	//Posicion Hechicero
	Mitablerito.colocar_pokemon(4, 0, &Alakazam);
	Mitablerito.colocar_pokemon(4, 8, &Gengar);
	//Posicion Volador
	Mitablerito.colocar_pokemon(2, 0, &Charizard);
	Mitablerito.colocar_pokemon(6, 0, &Charizard);
	Mitablerito.colocar_pokemon(2, 8, &Crobat);
	Mitablerito.colocar_pokemon(6, 8, &Crobat);
	//Posicion Tanque
	Mitablerito.colocar_pokemon(0, 0, &Snorlax);
	Mitablerito.colocar_pokemon(8, 0, &Snorlax);
	Mitablerito.colocar_pokemon(0, 8, &Tyranitar);
	Mitablerito.colocar_pokemon(8, 8, &Tyranitar);
	//Posicion Distancia
	Mitablerito.colocar_pokemon(0, 1, &Grovile);
	Mitablerito.colocar_pokemon(1, 0, &Grovile);
	Mitablerito.colocar_pokemon(7, 0, &Grovile);
	Mitablerito.colocar_pokemon(8, 1, &Grovile);
	Mitablerito.colocar_pokemon(0, 7, &Umbreon);
	Mitablerito.colocar_pokemon(1, 8, &Umbreon);
	Mitablerito.colocar_pokemon(8, 7, &Umbreon);
	Mitablerito.colocar_pokemon(7, 8, &Umbreon);

	//Posicion Basico
	for (i = 1; i < 8; i++) Mitablerito.colocar_pokemon(i, 1, &Machop);
	for (i = 1; i < 8; i++) Mitablerito.colocar_pokemon(i, 7, &Scraggy);









	

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

	gluLookAt(0, 10, 20,  // posicion del ojo
		0.0, 0, 0.0,				// hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);				// definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo

	//dibujo del suelo inicial que BORRAREMOS
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 0, 0);
	glVertex3d(-5.0, 0, -5.0);
	glVertex3d(-5.0, 0, 5.0);
	glColor3ub(255, 255, 0);
	glVertex3d(5.0, 0, 5.0);
	glVertex3d(5.0, 0, -5.0);
	glEnd();
	glEnable(GL_LIGHTING);
	
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//codigo de gestion de teclado
	

	//indicamos que se vuelva a dibujar la pantalla, para que se vean los cambios
	glutPostRedisplay();
}


void OnTimer(int value)
{
	//código de animacion
	

	//no borrar estas lineas
	//indicamos que se vuelva a dibujar la pantalla, para que se vean los cambios
	glutPostRedisplay();
	//recurivamente, le decimos que dentro de 25ms vuelva a llamar a esta funcion, para que se siga animando
	glutTimerFunc(25, OnTimer, 0);
}
