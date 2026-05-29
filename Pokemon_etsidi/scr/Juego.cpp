#include "Juego.h"
#include "Pokemon.h"
#include "IA.h"
#include <freeglut.h>
#include "tiposp/CambiaFormas.h"
#include "tiposp/Fenix.h"
#include "tiposp/Hechicero.h"
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


		
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D); 
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-5.0, 50.0, -5.0, 50.0);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		Mitablerito.tablerodibuja();
		
		
		/*
		// leyenda
		
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
		glColor3f(1.0f, 1.0f, 1.0f); escribirCadena2D(50.0f, 20.5f, "Aviso (Cambio pronto)");

		*/

		


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


		Arena.dibuja_Arena();
		Arena.dibuja_BarrasVida();

		break;

	case FIN:

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDisable(GL_LIGHTING);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0.0, 9.0, 0.0, 9.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		if (resultado == ResultadoJuego::GANADORENTRENADOR) {
			static ETSIDI::Sprite fondoENT("bin/fondos/fondo_victoria_ENT.png", 4.5f, 4.5f, 9.0f, 9.0f); 
			fondoENT.draw();
	}
		else {
			static ETSIDI::Sprite fondoTR("bin/fondos/fondo_victoria_TR.png", 4.5f, 4.5f, 9.0f, 9.0f);
			fondoTR.draw();
		}

		glDisable(GL_BLEND);

	
		

		
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0.0f, 0.0f, 0.0f, 0.6f);
		glBegin(GL_QUADS);
		glVertex2f(1.5f, 8.5f);
		glVertex2f(7.5f, 8.5f);
		glVertex2f(7.5f, 9.0f);
		glVertex2f(1.5f, 9.0f);
		glEnd();
		glDisable(GL_BLEND);

		glColor3f(1.0f, 1.0f, 0.0f);
		escribirCadena2D(1.8f, 8.6f, "Pulsa [R] para volver al menu");

		break;


	case HECHIZOS:
	{
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glDisable(GL_LIGHTING);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-5.0, 50.0, -5.0, 50.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		Mitablerito.tablerodibuja();

		glDisable(GL_DEPTH_TEST);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glDisable(GL_TEXTURE_2D);
		glColor4f(0.0f, 0.0f, 0.0f, 0.7f);
		glBegin(GL_QUADS);
		glVertex2f(-5.0f, -5.0f); glVertex2f(65.0f, -5.0f);
		glVertex2f(65.0f, 65.0f); glVertex2f(-5.0f, 65.0f);
		glEnd();

		glDisable(GL_BLEND);
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
		glVertex2f(4.5f, 1.5f); glVertex2f(40.5f, 1.5f);
		glVertex2f(40.5f, 43.5f); glVertex2f(4.5f, 43.5f);
		glEnd();

		glLineWidth(3.0f);
		glColor3f(1.0f, 0.8f, 0.0f);
		glBegin(GL_LINE_LOOP);
		glVertex2f(4.5f, 1.5f); glVertex2f(40.5f, 1.5f);
		glVertex2f(40.5f, 43.5f); glVertex2f(4.5f, 43.5f);
		glEnd();

		
		glDisable(GL_TEXTURE_2D);
		glColor3f(1.0f, 0.8f, 0.0f);
		escribirCadena2D(10.0f, 40.0f, "LIBRO DE HECHIZOS (Selecciona 1-7)");

		
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor3f(1.0f, 1.0f, 1.0f);

		static ETSIDI::Sprite ico1("bin/sprites/Iconos/teleport.png", 9.0f, 35.0f, 3.5f, 3.5f); ico1.draw();
		static ETSIDI::Sprite ico2("bin/sprites/Iconos/curar.png", 9.0f, 30.0f, 3.5f, 3.5f); ico2.draw();
		static ETSIDI::Sprite ico3("bin/sprites/Iconos/shiftime.png", 9.0f, 25.0f, 3.5f, 3.5f); ico3.draw();
		static ETSIDI::Sprite ico4("bin/sprites/Iconos/exchange.png", 9.0f, 20.0f, 3.5f, 3.5f); ico4.draw();
		static ETSIDI::Sprite ico5("bin/sprites/Iconos/elemental.png", 9.0f, 15.0f, 3.5f, 3.5f); ico5.draw();
		static ETSIDI::Sprite ico6("bin/sprites/Iconos/revivir.png", 9.0f, 10.0f, 3.5f, 3.5f); ico6.draw();
		static ETSIDI::Sprite ico7("bin/sprites/Iconos/imprison.png", 9.0f, 5.0f, 3.5f, 3.5f); ico7.draw();

		glDisable(GL_BLEND);
		glDisable(GL_TEXTURE_2D);

		glColor3f(1.0f, 1.0f, 1.0f);
		escribirCadena2D(12.5f, 34.5f, "1. Teletransporte - Mover aliado");
		escribirCadena2D(12.5f, 29.5f, "2. Curar - Sanar vida completa");
		escribirCadena2D(12.5f, 24.5f, "3. Cambiar Tiempo - Altera casillas");
		escribirCadena2D(12.5f, 19.5f, "4. Intercambiar - Cambiar 2 piezas");
		escribirCadena2D(12.5f, 14.5f, "5. Invocar Elemental");
		escribirCadena2D(12.5f, 9.5f, "6. Resucitar - Revivir aliado");
		escribirCadena2D(12.5f, 4.5f, "7. Encarcelar - Bloquear enemigo");

		glColor3f(0.7f, 0.7f, 0.7f);
		escribirCadena2D(34.0f, 3.0f, "[H] Volver");

		glEnable(GL_DEPTH_TEST);

		break;
	}


}

}

void Juego::mover_Juego(bool key[])
{
	//esto luego hay que quitarlo, ahora es para comprobar la pantalla de fin
	if (key['v'] ) {
		resultado = ResultadoJuego::GANADORROCKET; 
		pantallaActual = EstadoPantalla::FIN;
		key['v'] = false;
	}

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

		//Mitablerito.imprimir(); //CADA VEZ QUE SALE DE LA ARENA REESCRIBE EL TABLERO
		Mitablerito.tableromueve(key);

		//Para Probar la Arena
		if (key['p'] || key['P'])
		{
			pantallaActual = ARENA;
		}


		//para probar el menu de hechizos 

		if (key['h'] || key['H']) {

			Pokemon* p = Mitablerito.get_pokemon(Mitablerito.cursor.fila, Mitablerito.cursor.columna);
			if (p != nullptr) {
				string nombre = p->consultar_nombre();
				if (nombre == "Alakazam" || nombre == "Gengar") {
					pantallaActual = HECHIZOS;
				}
				else {
					cout << "El Pokemon " << nombre << " no puede usar hechizos." << endl;
				}
			}
			key['h'] = key['H'] = false;
		}

		break;

	case ARENA:

		Arena.mueve_personaje(key);

		if (key['t'] || key['T']) pantallaActual = TABLERO;
		break;

	case FIN:
		if (key['r']) {
			pantallaActual = MENU;
			resultado = ResultadoJuego::NOGANADOR;
			key['r'] = false;
		}
		break;

	case HECHIZOS:
		
		if (key['h']) {
			pantallaActual = TABLERO;
			key['h'] = false;
		}
		break;




	}
}


void Juego::logica_Juego()
{
	comprobar_victoria();
	//aqui hay que meter el avance de los turnos 
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

		arena_combate(*new Hechicero("Alakazam", Bando::Entrenador, Tipo::Psiquico, Tipo::Ninguno, { 4,0 }, "bin/sprites/Blanca/AlakazamS.png"),
			*new Hechicero("Alakazam", Bando::Entrenador, Tipo::Psiquico, Tipo::Ninguno, { 4,0 }, "bin/sprites/Blanca/AlakazamS.png"));

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

//para comprobaciones de victoria 

void Juego::comprobar_victoria() {

	// perder por quedarte sin pokemons
	if (Mitablerito.quedan_piezas(Bando::Team_Rocket) == false)
		resultado = ResultadoJuego::GANADORENTRENADOR;
	else if (Mitablerito.quedan_piezas(Bando::Entrenador) == false)
		resultado = ResultadoJuego::GANADORROCKET;

	// ganar por conseguir los puntos de poder
	else if (Mitablerito.controla_puntos_poder(Bando::Entrenador) == true)
		resultado = ResultadoJuego::GANADORENTRENADOR;
	else if (Mitablerito.controla_puntos_poder(Bando::Team_Rocket) == true)
		resultado = ResultadoJuego::GANADORROCKET;

	// si gana uno cambiamos a pantalla fin
	if (resultado != ResultadoJuego::NOGANADOR)
		pantallaActual = EstadoPantalla::FIN;
}

void  Juego::animar()
{
	if (pantallaActual == EstadoPantalla::ARENA) Arena.animaciones_arena();
}

void  Juego::actualizar_juego(double dt)
{
	if (pantallaActual == EstadoPantalla::ARENA) Arena.actualizar_arena(dt);
}