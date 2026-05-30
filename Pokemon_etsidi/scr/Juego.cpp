#include "Juego.h"
#include "Pokemon.h"
#include "IA.h"
#include <freeglut.h>
#include "tiposp/CambiaFormas.h"
#include "tiposp/Fenix.h"
#include "tiposp/Hechicero.h"
#include <ETSIDI.h>

using namespace std; 

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
		Textos::escribirCadena2D(2.5f, 4.5f, "Pulsa [1] -> Jugador vs Jugador");
		Textos::escribirCadena2D(2.5f, 3.5f, "Pulsa [2] -> Jugador vs IA");

		glColor3f(0.5f, 0.7f, 1.0f);
		Textos::escribirCadena2D(2.1f, 1.5f, "Selecciona una opcion en el teclado");


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
		Textos::escribirCadena2D(1.8f, 8.6f, "Pulsa [R] para volver al menu");

		break;


	


}

}

void Juego::mover_Juego(bool key[])
{
	

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
		TableroArena();

		break;

	case ARENA:

		ArenaTablero();
		break;
	}

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

void Juego::TableroArena() {
	if (Mitablerito.arenabandera == true) {
		pantallaActual = ARENA;
		Arena.inicializa_Arena(Mitablerito.ataque, Mitablerito.defensa, false, Mitablerito.casillaarena);
	}

}

void Juego::ArenaTablero() {

	Pokemon* ganador = Arena.devolver_ganador();

	Arena.arena_combate();
	Arena.interaccion_obstaculos();
	Arena.limita_movimiento();

	if (IA_activa) IA::IA_Combate_Arena(Arena);

	if (ganador == nullptr)
		return; 

//RECUPERAR LA POSICION POR QUE CURSOR DESAPARECE Y APARECE
	int f = Mitablerito.filaCombate;
	int c = Mitablerito.columnaCombate;

//COLOCAR AL CANADOR
	Mitablerito.matriz[f][c] = ganador;

//BORRAR EL RESTO DE COSAS				//SI ESTAS COSAS VAN BIEN LAS ENCAPSULARE DENTRO DE TABLERO
	Mitablerito.ataque = nullptr;
	Mitablerito.defensa = nullptr;
	Mitablerito.arenabandera = false;

	Arena.resetear_Arena();

	//VOLVER AL TABLERO
	pantallaActual = TABLERO;

	Mitablerito.turnofinalizadoexito();

}