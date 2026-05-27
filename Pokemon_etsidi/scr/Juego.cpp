#include "Juego.h"
#include "Pokemon.h"
#include "IA.h"
#include <freeglut.h>
#include "tiposp/CambiaFormas.h"
#include "tiposp/Fenix.h"
#include <ETSIDI.h>
using namespace std; 

//funciones para escribir en 2D freeglut
void escribirCadena2D(float x, float y, const char* cadena) {
	glRasterPos3d(x, y, 1);
	for (const char* c = cadena; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}

void escribirChar2D(float x, float y, char letra) {
	glRasterPos3d(x, y, 1);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letra);
}

void Juego::dibujar_Juego()
{

	switch (pantallaActual)
	{
	case MENU: {


		glDisable(GL_LIGHTING);
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, 9.0, 0.0, 9.0);

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



		static ETSIDI::Sprite titulo("bin/fondos/letras_poketsidi.png", 4.5f, 7.0f, 6.5f, 2.5f);
		titulo.draw();

		static ETSIDI::Sprite fondoPlaya("bin/fondos/fondo_menu.png", 4.5f, 4.5f, 9.0f, 9.0f);
		fondoPlaya.draw();



		glDisable(GL_BLEND);

		glColor3f(1.0f, 1.0f, 1.0f);
		escribirCadena2D(2.5f, 4.5f, "Pulsa [1] -> Jugador vs Jugador");
		escribirCadena2D(2.5f, 3.5f, "Pulsa [2] -> Jugador vs IA");

		glColor3f(0.5f, 0.7f, 1.0f);
		escribirCadena2D(2.1f, 1.5f, "Selecciona una opcion en el teclado");


		break;
	}

	case TABLERO:



		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDisable(GL_LIGHTING);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
	
		gluOrtho2D(-5.0, 65.0, -5.0, 65.0);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Fondo gris oscuro para el tablero
		
	
		Mitablerito.dibujar_casillas();
		
		// --- LEYENDA DEL TABLERO ---
		
		glColor3f(1.0f, 1.0f, 1.0f); // Texto blanco
		escribirCadena2D(47.0f, 40.0f, "LEYENDA:");

		// Casilla Clara
		glColor3ub(235, 235, 225);
		glBegin(GL_QUADS); glVertex2f(47.0f, 36.0f); glVertex2f(49.0f, 36.0f); glVertex2f(49.0f, 38.0f); glVertex2f(47.0f, 38.0f); glEnd();
		glColor3f(1.0f, 1.0f, 1.0f); escribirCadena2D(50.0f, 36.5f, "Clara");

		// Casilla Oscura
		glColor3ub(65, 65, 75);
		glBegin(GL_QUADS); glVertex2f(47.0f, 32.0f); glVertex2f(49.0f, 32.0f); glVertex2f(49.0f, 34.0f); glVertex2f(47.0f, 34.0f); glEnd();
		glColor3f(1.0f, 1.0f, 1.0f); escribirCadena2D(50.0f, 32.5f, "Oscura");

		// Casilla Neutra
		glColor3ub(140, 150, 160);
		glBegin(GL_QUADS); glVertex2f(47.0f, 28.0f); glVertex2f(49.0f, 28.0f); glVertex2f(49.0f, 30.0f); glVertex2f(47.0f, 30.0f); glEnd();
		glColor3f(1.0f, 1.0f, 1.0f); escribirCadena2D(50.0f, 28.5f, "Neutra");

		// Casilla de Poder
		glColor3ub(255, 215, 0);
		glBegin(GL_QUADS); glVertex2f(47.0f, 24.0f); glVertex2f(49.0f, 24.0f); glVertex2f(49.0f, 26.0f); glVertex2f(47.0f, 26.0f); glEnd();
		glColor3f(1.0f, 1.0f, 1.0f); escribirCadena2D(50.0f, 24.5f, "Poder");

		
		glColor3ub(240, 170, 90); // Color aviso
		glBegin(GL_QUADS); glVertex2f(47.0f, 20.0f); glVertex2f(49.0f, 20.0f); glVertex2f(49.0f, 22.0f); glVertex2f(47.0f, 22.0f); glEnd();
		glColor3f(1.0f, 1.0f, 1.0f); escribirCadena2D(50.0f, 20.5f, "Aviso (Cambio inminente)");


		


		break;

	case ARENA:

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 0, 15,
			0.0, 0, 0.0,
			0.0, 1, 0.0);

		Arena.dibuja_Personajes();
		Arena.dibuja_Ataques();
		Arena.dibuja_Obstaculos();
		Arena.dibuja_Arena();
		Arena.dibuja_BarrasVida();

		break;
	}

}

void Juego::mover_Juego(bool key[])
{
	//MENU

	switch (pantallaActual)
	{
	case MENU:

		if (key['1']) {
			IA_activa = false;
			pantallaActual = TABLERO;
			Mitablerito.inicializar_tablero();
		}
		else if (key['2']) {
			IA_activa = true;
			pantallaActual = TABLERO;
			Mitablerito.inicializar_tablero();
		}

		break;

	case TABLERO:

		Mitablerito.imprimir(); //CADA VEZ QUE SALE DE LA ARENA REESCRIBE EL TABLERO

		// movimiento cursor del tablero 

		// Movimiento cursor
		if (key['w'] || key['W']) { Mitablerito.mover_cursor(1, 0); key['w'] = key['W'] = false; }
		if (key['s'] || key['S']) { Mitablerito.mover_cursor(-1, 0);  key['s'] = key['S'] = false; }
		if (key['a'] || key['A']) { Mitablerito.mover_cursor(0, -1); key['a'] = key['A'] = false; }
		if (key['d'] || key['D']) { Mitablerito.mover_cursor(0, 1);  key['d'] = key['D'] = false; }

		// Seleccionamos con enter

		if (key[13]) {
			Pokemon* p = Mitablerito.seleccionar_cursor();
			if (p != nullptr)
				cout << "Pokemon: " << p->consultar_nombre() << "\n";
			else
				cout << "Casilla vacía\n";
			key[13] = false;
		}

		//Para Probar la Arena
		if (key['p'] || key['P'])
		{
			pantallaActual = ARENA;
		}

		break;

	case ARENA:

		Arena.mueve_personaje(key);

		if (key['t'] || key['T']) pantallaActual = TABLERO;

		break;

	}
}


void Juego::logica_Juego()
{

}

void Juego::jugar()
{
	// Todo el codigo necesario para jugar 

	switch (pantallaActual)
	{
	case TABLERO:

		logica_Juego();

		break;

	case ARENA:

		arena_combate(*new Distancia(1),
			*new Distancia(1));

		break;
	}

}

void Juego::arena_combate(Pokemon &equipo1, Pokemon &equipo2)
{
	static bool primera_vez = true;

	if(primera_vez) 
	{
		//Solo uno de los dos equipos puede tener un cambia formas
		//Se identifica si uno de los dos es un cambiaformas
		if (typeid(equipo1) == typeid(CambiaFormas))
		{
			//Se accede al pokemon como cambiaformas
			CambiaFormas &p = dynamic_cast<CambiaFormas&>(equipo1);
			p.cambiar_forma(equipo2);
		}  
		 
		if (typeid(equipo2) == typeid(CambiaFormas))
		{
			CambiaFormas &p = dynamic_cast<CambiaFormas&>(equipo2);
			p.cambiar_forma(equipo1);
		}

		Arena.inicializa_Arena(&equipo1, &equipo2, IA_activa);
		IA::estado_arena = Estado_Arena::Buscar;
		primera_vez = false;
	}

	Arena.arena_combate();
	Arena.interaccion_obstaculos();
	Arena.limita_movimiento();

	if (IA_activa) 
	{
		IA::IA_Combate_Arena(Arena);
	}

	auto ganador = Arena.devolver_ganador();
	if(ganador != nullptr) pantallaActual = TABLERO;
}