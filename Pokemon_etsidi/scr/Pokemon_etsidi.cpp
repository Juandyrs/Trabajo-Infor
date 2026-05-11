// Pokemon_etsidi.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.


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
#include "Juego.h"
#include <vector>

using std::vector;

void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion 
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void OnKeyboardUp(unsigned char key, int x, int y);

Juego MiJuego;

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
	


	//Hechiceros
	Hechicero Alakazam{ "Alakazam",Bando::Entrenador,Tipo::Psiquico,Tipo::Ninguno, {4,0} };
	Hechicero Gengar{ "Gengar",Bando::Team_Rocket,Tipo::Fantasma,Tipo::Veneno, {4,8} };

	
	//Voladores

	Volador Charizard[2]{ 
		Volador("Charizard",Bando::Entrenador,Tipo::Fuego, Tipo::Volador,{2,0}),
		Volador("Charizard",Bando::Entrenador,Tipo::Fuego, Tipo::Volador,{6,0})
	};

	Volador Crobat[2]{
		Volador("Crobat",Bando::Team_Rocket,Tipo::Volador, Tipo::Veneno,{2,8}),
		Volador("Crobat",Bando::Team_Rocket,Tipo::Volador, Tipo::Veneno,{6,8})
	};
	
	//Tanques 
	Tanque Snorlax[2]{
		Tanque("Snorlax",Bando::Entrenador,Tipo::Normal,Tipo::Ninguno,{0,0}),
		Tanque("Snorlax",Bando::Entrenador,Tipo::Normal,Tipo::Ninguno,{8,0}),
	};
	Tanque Tyranitar[2]{
		Tanque("Tyranitar",Bando::Team_Rocket,Tipo::Tierra,Tipo::Siniestro,{0,8}),
		Tanque("Tyranitar",Bando::Team_Rocket,Tipo::Tierra,Tipo::Siniestro,{8,8}),
	};

	//Distancia
	Distancia Grovile[4] = { 
		Distancia("Grovile",Bando::Entrenador,Tipo::Planta,Tipo::Ninguno,{0,1}),
		Distancia("Grovile",Bando::Entrenador,Tipo::Planta,Tipo::Ninguno,{1,0}),
		Distancia("Grovile",Bando::Entrenador,Tipo::Planta,Tipo::Ninguno,{7,0}),
		Distancia("Grovile",Bando::Entrenador,Tipo::Planta,Tipo::Ninguno,{8,1})
	
	};

	Distancia Umbreon[4] = {
		Distancia("Umbreon",Bando::Team_Rocket,Tipo::Siniestro,Tipo::Ninguno,{0,7}),
		Distancia("Umbreon",Bando::Team_Rocket,Tipo::Siniestro,Tipo::Ninguno,{1,8}),
		Distancia("Umbreon",Bando::Team_Rocket,Tipo::Siniestro,Tipo::Ninguno,{7,8}),
		Distancia("Umbreon",Bando::Team_Rocket,Tipo::Siniestro,Tipo::Ninguno,{8,7})

	};

	//Basico
	Basico Machomp[7] = {
		Basico("Machomp", Bando::Entrenador, Tipo::Lucha, Tipo::Ninguno,{1,1}),
		Basico("Machomp", Bando::Entrenador, Tipo::Lucha, Tipo::Ninguno,{2,1}),
		Basico("Machomp", Bando::Entrenador, Tipo::Lucha, Tipo::Ninguno,{3,1}),
		Basico("Machomp", Bando::Entrenador, Tipo::Lucha, Tipo::Ninguno,{4,1}),
		Basico("Machomp", Bando::Entrenador, Tipo::Lucha, Tipo::Ninguno,{5,1}),
		Basico("Machomp", Bando::Entrenador, Tipo::Lucha, Tipo::Ninguno,{6,1}),
		Basico("Machomp", Bando::Entrenador, Tipo::Lucha, Tipo::Ninguno,{7,1})
	};

	Basico Scraggy[7] = {
		Basico("Scraggy", Bando::Team_Rocket, Tipo::Lucha, Tipo::Siniestro,{1,7}),
		Basico("Scraggy", Bando::Team_Rocket, Tipo::Lucha, Tipo::Siniestro,{2,7}),
		Basico("Scraggy", Bando::Team_Rocket, Tipo::Lucha, Tipo::Siniestro,{3,7}),
		Basico("Scraggy", Bando::Team_Rocket, Tipo::Lucha, Tipo::Siniestro,{4,7}),
		Basico("Scraggy", Bando::Team_Rocket, Tipo::Lucha, Tipo::Siniestro,{5,7}),
		Basico("Scraggy", Bando::Team_Rocket, Tipo::Lucha, Tipo::Siniestro,{6,7}),
		Basico("Scraggy", Bando::Team_Rocket, Tipo::Lucha, Tipo::Siniestro,{7,7})
	};

	//Cambiaforma
	CambiaFormas Ditto[2]{ CambiaFormas("Ditto",Bando::Team_Rocket,Tipo::Normal,Tipo::Ninguno,{3,8}),CambiaFormas("Ditto",Bando::Team_Rocket,Tipo::Normal,Tipo::Ninguno,{5,8}) };

	//Fenix
	Fenix Moltres[2] = { Fenix("Moltres", Bando::Entrenador, Tipo::Fuego, Tipo::Volador,{5,0}),Fenix("Moltres", Bando::Entrenador, Tipo::Fuego, Tipo::Volador,{3,0})};

	

	//Colocacion en tablero
	
	//Posicion Hechicero
	Mitablerito.colocar_pokemon(Alakazam.pos_tab.x,Alakazam.pos_tab.y, &Alakazam);
	Mitablerito.colocar_pokemon(Gengar.pos_tab.x,Gengar.pos_tab.y, &Gengar);

	//Posicion Volador
	Mitablerito.colocar_pokemon(Charizard[0].pos_tab.x, Charizard[0].pos_tab.y, &Charizard[0]);
	Mitablerito.colocar_pokemon(Charizard[1].pos_tab.x, Charizard[1].pos_tab.y, &Charizard[1]);
	Mitablerito.colocar_pokemon(Crobat[0].pos_tab.x, Crobat[0].pos_tab.y, &Crobat[0]);
	Mitablerito.colocar_pokemon(Crobat[1].pos_tab.x, Crobat[1].pos_tab.y, &Crobat[1]);

	//Posicion Tanque
	Mitablerito.colocar_pokemon(Snorlax[0].pos_tab.x, Snorlax[0].pos_tab.y, &Snorlax[0]);
	Mitablerito.colocar_pokemon(Snorlax[1].pos_tab.x, Snorlax[1].pos_tab.y, &Snorlax[1]);
	Mitablerito.colocar_pokemon(Tyranitar[0].pos_tab.x, Tyranitar[0].pos_tab.y, &Tyranitar[0]);
	Mitablerito.colocar_pokemon(Tyranitar[1].pos_tab.x, Tyranitar[1].pos_tab.y, &Tyranitar[1]);

	
	//Posicion Distancia
	for (int i = 0; i < 4; i++) Mitablerito.colocar_pokemon(Grovile[i].pos_tab.x, Grovile[i].pos_tab.y, &Grovile[i]);
	for (int i = 0; i < 4; i++) Mitablerito.colocar_pokemon(Umbreon[i].pos_tab.x, Umbreon[i].pos_tab.y, &Umbreon[i]);

	//Posicion Basico
	for (int i = 0; i < 7; i++) Mitablerito.colocar_pokemon(Machomp[i].pos_tab.x, Machomp[i].pos_tab.y, &Machomp[i]);
	for (int i = 0; i < 7; i++) Mitablerito.colocar_pokemon(Scraggy[i].pos_tab.x, Scraggy[i].pos_tab.y, &Scraggy[i]);

	//Posicion Cambiaforma
	Mitablerito.colocar_pokemon(Ditto[0].pos_tab.x, Ditto[0].pos_tab.y, &Ditto[0]);
	Mitablerito.colocar_pokemon(Ditto[1].pos_tab.x, Ditto[1].pos_tab.y, &Ditto[1]);

	//Posicion Fenix
	Mitablerito.colocar_pokemon(Moltres[0].pos_tab.x, Moltres[0].pos_tab.y, &Moltres[0]);
	Mitablerito.colocar_pokemon(Moltres[1].pos_tab.x, Moltres[1].pos_tab.y, &Moltres[1]);

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
	
	MiJuego.dibujar_Juego();
	
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//codigo de gestion de teclado
	
	keys[key] = true;

	MiJuego.mover_Juego(keys);


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
	
	MiJuego.jugar();

	//no borrar estas lineas
	//indicamos que se vuelva a dibujar la pantalla, para que se vean los cambios
	glutPostRedisplay();
	//recurivamente, le decimos que dentro de 25ms vuelva a llamar a esta funcion, para que se siga animando
	glutTimerFunc(25, OnTimer, 0);
}
