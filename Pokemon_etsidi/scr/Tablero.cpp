#include "Tablero.h"
#include <iostream>
#include "Pokemon.h"
#include "tiposp/Hechicero.h"    
#include "tiposp/Volador.h"
#include "tiposp/Tanque.h"
#include "tiposp/Distancia.h"
#include "tiposp/Basico.h"
#include "tiposp/Fenix.h"
#include "tiposp/CambiaFormas.h"
#include "ArenaCombate.h"
#include <cmath>

using namespace std;

void Tablero::imprimir() {
	cout << "\nTABLERO POKEMON\n";

	for (int f = 0; f < 9; f++) {
		for (int c = 0; c < 9; c++) {

			if (matriz[f][c] == nullptr) {
				cout << "|  .  |";
			}
			else {
				cout << "| " << matriz[f][c]->obtener_simbolo() << " |";
			}
		}
		cout << "\n";
	}
}

void Tablero::inicializar_tablero()
{
	for (int f = 0; f < 9; f++) {
		for (int c = 0; c < 9; c++) {
			casillas[f][c] = new Casilla();         // creamos la casilla en memoria
			casillas[f][c]->inicializar(f, c);      // la inicializamos
		}
	}

	Turnoactual = TURNO::JUGADOR1;

	//Hechiceros

	Pokemon* Alakazam = new Hechicero("Alakazam", Bando::Entrenador, Tipo::Psiquico, Tipo::Ninguno, { 4,0 }, "bin/sprites/Blanca/alakazam.png");
	Pokemon* Gengar = new Hechicero("Gengar", Bando::Team_Rocket, Tipo::Fantasma, Tipo::Veneno, { 4,8 }, "bin/sprites/Negra/gengar.png");

	

	//VOLADORES
	Pokemon* Charizard[2]{
		new Volador("Charizard",Bando::Entrenador,Tipo::Fuego, Tipo::Volador,{2,0}, "bin/sprites/Blanca/charizard.png"),
		new Volador("Charizard",Bando::Entrenador,Tipo::Fuego, Tipo::Volador,{6,0}, "bin/sprites/Blanca/charizard.png")
	};

	Pokemon* Crobat[2]{
		new Volador("Crobat",Bando::Team_Rocket,Tipo::Volador, Tipo::Veneno,{2,8}, "bin/sprites/Negra/crobat.png"),
		new Volador("Crobat",Bando::Team_Rocket,Tipo::Volador, Tipo::Veneno,{6,8}, "bin/sprites/Negra/crobat.png")
	};

	//Tanques 
	Pokemon* Snorlax[2]{
		new Tanque("Snorlax",Bando::Entrenador,Tipo::Normal,Tipo::Ninguno,{0,0}, "bin/sprites/Blanca/snorlax.png"),
		new Tanque("Snorlax",Bando::Entrenador,Tipo::Normal,Tipo::Ninguno,{8,0},"bin/sprites/Blanca/snorlax.png"),
	};
	Pokemon* Tyranitar[2]{
		new Tanque("Tyranitar",Bando::Team_Rocket,Tipo::Tierra,Tipo::Siniestro,{0,8}, "bin/sprites/Negra/tyranitar.png"),
		new Tanque("Tyranitar",Bando::Team_Rocket,Tipo::Tierra,Tipo::Siniestro,{8,8}, "bin/sprites/Negra/tyranitar.png"),
	};

	//Distancia
	Pokemon* Grovile[4] = {
		new Distancia("Grovile",Bando::Entrenador,Tipo::Planta,Tipo::Ninguno,{0,1}, "bin/sprites/Blanca/leafeon.png"),
		new Distancia("Grovile",Bando::Entrenador,Tipo::Planta,Tipo::Ninguno,{1,0}, "bin/sprites/Blanca/leafeon.png"),
		new Distancia("Grovile",Bando::Entrenador,Tipo::Planta,Tipo::Ninguno,{7,0}, "bin/sprites/Blanca/leafeon.png"),
		new Distancia("Grovile",Bando::Entrenador,Tipo::Planta,Tipo::Ninguno,{8,1}, "bin/sprites/Blanca/leafeon.png")

	};

	Pokemon* Umbreon[4] = {
		new Distancia("Umbreon",Bando::Team_Rocket,Tipo::Siniestro,Tipo::Ninguno,{0,7}, "bin/sprites/Negra/umbreon.png"),
		new Distancia("Umbreon",Bando::Team_Rocket,Tipo::Siniestro,Tipo::Ninguno,{1,8}, "bin/sprites/Negra/umbreon.png"),
		new Distancia("Umbreon",Bando::Team_Rocket,Tipo::Siniestro,Tipo::Ninguno,{7,8}, "bin/sprites/Negra/umbreon.png"),
		new Distancia("Umbreon",Bando::Team_Rocket,Tipo::Siniestro,Tipo::Ninguno,{8,7}, "bin/sprites/Negra/umbreon.png")

	};

	//Basico
	Pokemon* Machomp[7] = {
		new Basico("Machomp", Bando::Entrenador, Tipo::Lucha, Tipo::Ninguno,{1,1}, "bin/sprites/Blanca/machop.png"),
		new Basico("Machomp", Bando::Entrenador, Tipo::Lucha, Tipo::Ninguno,{2,1}, "bin/sprites/Blanca/machop.png"),
		new Basico("Machomp", Bando::Entrenador, Tipo::Lucha, Tipo::Ninguno,{3,1}, "bin/sprites/Blanca/machop.png"),
		new Basico("Machomp", Bando::Entrenador, Tipo::Lucha, Tipo::Ninguno,{4,1}, "bin/sprites/Blanca/machop.png"),
		new Basico("Machomp", Bando::Entrenador, Tipo::Lucha, Tipo::Ninguno,{5,1}, "bin/sprites/Blanca/machop.png"),
		new Basico("Machomp", Bando::Entrenador, Tipo::Lucha, Tipo::Ninguno,{6,1}, "bin/sprites/Blanca/machop.png"),
		new Basico("Machomp", Bando::Entrenador, Tipo::Lucha, Tipo::Ninguno,{7,1},"bin/sprites/Blanca/machop.png")
	};

	Pokemon* Scraggy[7] = {
	new	Basico("Scraggy", Bando::Team_Rocket, Tipo::Lucha, Tipo::Siniestro,{1,7},"bin/sprites/Negra/scraggy.png"),
		new Basico("Scraggy", Bando::Team_Rocket, Tipo::Lucha, Tipo::Siniestro,{2,7},"bin/sprites/Negra/scraggy.png"),
		new Basico("Scraggy", Bando::Team_Rocket, Tipo::Lucha, Tipo::Siniestro,{3,7}, "bin/sprites/Negra/scraggy.png"),
		new Basico("Scraggy", Bando::Team_Rocket, Tipo::Lucha, Tipo::Siniestro,{4,7}, "bin/sprites/Negra/scraggy.png"),
		new Basico("Scraggy", Bando::Team_Rocket, Tipo::Lucha, Tipo::Siniestro,{5,7},"bin/sprites/Negra/scraggy.png"),
	new	Basico("Scraggy", Bando::Team_Rocket, Tipo::Lucha, Tipo::Siniestro,{6,7},"bin/sprites/Negra/scraggy.png"),
	new Basico("Scraggy", Bando::Team_Rocket, Tipo::Lucha, Tipo::Siniestro,{7,7},"bin/sprites/Negra/scraggy.png")
	};

	//Cambiaforma
	Pokemon* Ditto[2]{ 
	new CambiaFormas("Ditto",Bando::Team_Rocket,Tipo::Normal,Tipo::Ninguno,{3,8},"bin/sprites/Negra/ditto.png"),
	new CambiaFormas("Ditto",Bando::Team_Rocket,Tipo::Normal,Tipo::Ninguno,{5,8},"bin/sprites/Negra/ditto.png")};

	//Fenix
	Pokemon* Moltres[2] = { 
		new Fenix("Moltres", Bando::Entrenador, Tipo::Fuego, Tipo::Volador,{5,0},"bin/sprites/Blanca/moltres.png"),
		new Fenix("Moltres", Bando::Entrenador, Tipo::Fuego, Tipo::Volador,{3,0},"bin/sprites/Blanca/moltres.png")};



	//Colocacion en tablero

	//Posicion Hechicero
	colocar_pokemon(Alakazam->pos_tab.x, Alakazam->pos_tab.y, Alakazam);
	colocar_pokemon(Gengar->pos_tab.x, Gengar->pos_tab.y, Gengar);

	//Posicion Volador
	colocar_pokemon(Charizard[0]->pos_tab.x, Charizard[0]->pos_tab.y, Charizard[0]);
	colocar_pokemon(Charizard[1]->pos_tab.x, Charizard[1]->pos_tab.y, Charizard[1]);
	colocar_pokemon(Crobat[0]->pos_tab.x, Crobat[0]->pos_tab.y, Crobat[0]);
	colocar_pokemon(Crobat[1]->pos_tab.x, Crobat[1]->pos_tab.y, Crobat[1]);

	//Posicion Tanque
	colocar_pokemon(Snorlax[0]->pos_tab.x, Snorlax[0]->pos_tab.y, Snorlax[0]);
	colocar_pokemon(Snorlax[1]->pos_tab.x, Snorlax[1]->pos_tab.y, Snorlax[1]);
	colocar_pokemon(Tyranitar[0]->pos_tab.x, Tyranitar[0]->pos_tab.y, Tyranitar[0]);
	colocar_pokemon(Tyranitar[1]->pos_tab.x, Tyranitar[1]->pos_tab.y, Tyranitar[1]);


	//Posicion Distancia
	for (int i = 0; i < 4; i++) colocar_pokemon(Grovile[i]->pos_tab.x, Grovile[i]->pos_tab.y, Grovile[i]);
	for (int i = 0; i < 4; i++) colocar_pokemon(Umbreon[i]->pos_tab.x, Umbreon[i]->pos_tab.y, Umbreon[i]);

	//Posicion Basico
	for (int i = 0; i < 7; i++) colocar_pokemon(Machomp[i]->pos_tab.x, Machomp[i]->pos_tab.y, Machomp[i]);
	for (int i = 0; i < 7; i++) colocar_pokemon(Scraggy[i]->pos_tab.x, Scraggy[i]->pos_tab.y, Scraggy[i]);

	//Posicion Cambiaforma
	colocar_pokemon(Ditto[0]->pos_tab.x, Ditto[0]->pos_tab.y, Ditto[0]);
	colocar_pokemon(Ditto[1]->pos_tab.x, Ditto[1]->pos_tab.y, Ditto[1]);

	//Posicion Fenix
	colocar_pokemon(Moltres[0]->pos_tab.x, Moltres[0]->pos_tab.y, Moltres[0]);
	colocar_pokemon(Moltres[1]->pos_tab.x, Moltres[1]->pos_tab.y, Moltres[1]);
}

void Tablero::tablerodibuja() {

	for (int f = 0; f < 9; f++)
	{
		for (int c = 0; c < 9; c++)
		{
			Pokemon* p = matriz[f][c];

			if (p != nullptr)
			{
				p->pokemondibuja(f, c);   //EL POKEMONCITO SE DIBUJA A SI MISMO QUE MONO
			}
		}
	}
}

int Tablero::distancia(int fi, int ci, int ff, int cf) {

	return abs(fi - ff) + abs(ci - cf); //COMPRUEBA EL NUMERO MÁXIMO DE CASILLAS QUE RECORRE LA FICHILLA
}

bool Tablero::casillaocupada(int ff, int cf) {
	if (matriz[ff][cf] != nullptr)
			return true;
	}

bool Tablero::casillaaliado(int ff, int cf, Pokemon* p) {

		if (ff < 0 || ff >= 9 || cf < 0 || cf >= 9)
			return false;

		//CASILLA VACIA
		if (matriz[ff][cf] == nullptr)
			return false;

		//COMPROBAR SI ES ALIADO
		return matriz[ff][cf]->obtener_bando() == p->obtener_bando();

}

bool Tablero::casillaenemigo(int ff, int cf, Pokemon* p) {

	if (ff < 0 || ff >= 9 || cf < 0 || cf >= 9)
		return false;

	//CASILLA VACIA
	if (matriz[ff][cf] == nullptr)
		return false;

	//COMPROBAR SI ES ALIADO
	return matriz[ff][cf]->obtener_bando() != p->obtener_bando();

}

bool Tablero::movimientoTerrestre(Pokemon* p, int fi, int ci, int ff, int cf) {

		int distanciafilas = ff - fi; //VER SI SE MUEVE DE IZQ A DERECHA
		int distanciacolumnas = cf - ci; //LO MISMO

		int pasos = std::max(abs(distanciafilas), abs(distanciacolumnas)); //TE DA EL MAYOR DE LOS DOS PARA VER CUANTAS CUADRICULAS VAS A PASAR

		return true;
	}

bool Tablero::movimientoVolador(Pokemon* p, int fi, int ci, int ff, int cf) {
	return true; //SIEMPRE PUEDE EJECUTAR EL MOVIMIENTO, por lo menos por ahora

}
bool Tablero::movimientoPsiquico(Pokemon* p, int fi, int ci, int ff, int cf) {
	return true; //LO MISMO QUE VOLADOR

}

bool Tablero::movimientoTipoValido(Pokemon* p, int fi, int ci, int ff, int cf) {

	switch (p->obtenertipomovimiento())
	{
	case TipoMovimiento::Tierra:
		return movimientoTerrestre(p, fi, ci, ff, cf);

	case TipoMovimiento::Vuelo:
		return movimientoVolador(p, fi, ci, ff, cf);

	case TipoMovimiento::Teletransporte:
		return movimientoPsiquico(p, fi, ci, ff, cf);

	default:
		return false;
	}
}

int Tablero::movimientovalido(Pokemon* p, int nx, int ny) {

	return nx; 
}

void Tablero::seleccionficha(int f, int c){
	Pokemon* p = matriz[f][c]; //PILLA EL POKEMON DE LA FILA Y COLUMNA

	//NO FICHA NO TRABAJO
	if (p == nullptr)
		return;

	//FICHA NO ES DEL TURNO ACTUAL A TOMAR POR SACO (ES LA CONVERSIÓN DE LAS LISTAS A ENTEROS COMO HICE ANTERIORMENTE EN MOVER FICHA)
	if (static_cast<int>(p->equipo) != static_cast<int>(Turnoactual))
		return;

	//SE SELECCIONA LA FICHA
	fichaSeleccionada = p;
	fichaYaSeleccionada = true;
}

bool Tablero::moverficha(Pokemon* p, int ff, int cf)
{

	if (p == nullptr || static_cast<int>(Turnoactual) != static_cast<int>(p->equipo)) //VER SI LA PIEZA PERTENCE AL TURNO o NO
		return false; 
	//COMO ENTRENADOR y JUGADOR 1 VALEN 1 y ROCKET Y JUGADOR 2 valen 2 se pueden pasar a enteros para programar, es bastante improvisado, pero funciona de momento

	int movimiento = movimientovalido(p, ff, cf); //COMPROBAR MOVIMIENTO
	//0  INvalido
	//1  VACIO
	//2  ENEMIGO

	if (movimiento == 0)
		return false;

	if (movimiento == 1) //CASILLA VACIA Y MOVIMIENTO VALIDO
	{
		//QUITARLO DE LA MATRIZ DE PUNTEROS POR QUE SE HA PODIDO MOVER
		matriz[(int)p->pos_tab.x][(int)p->pos_tab.y] = nullptr; //PONGO EL INT POR QUE EL MALDITO VECTOR 2D ES DE DOUBLES Y MATRIZ SOLO ADMITE ENTEROS COMO POSICIONES

		//COLOCARLO EN LA NUEVA CASILLA
		matriz[ff][cf] = p;

		//ACTUALIZAR POSICION EN TABLERO LOGICO
		p->pos_tab.x = ff;
		p->pos_tab.y = cf;

		//CAMBIO DE TURNO
		conteoturno(); 
		cambiarturno();

		return true; // SE HA MOVIDO CORRECTAMENTE
	}

	//if (movimiento == 2)
	//{
		//Pokemon* enemigo = matriz[ff][cf];

		//Arena.inicializa_Arena(p, enemigo, false);  

		//Pokemon* ganador = Arena.devolver_ganador();

		//matriz[p->pos_tab.x][p->pos_tab.y] = nullptr;

		//if (ganador == p)
		//{
	
		//	matriz[ff][cf] = p;
		//	p->pos_tab.x = ff;
		//	p->pos_tab.y = cf;
	//	}
	//	else
	//	{
		//EL QUE ESTABA EN LA CASILLA SE QUEDA EL OTRO DE MOMENTO DESAPARECE HASTA QUE CREE UN VECTOR DE MUERTOS O ALGO ASI 
	//	}

	//	conteoturno();
	//	cambiarturno();

	//	return true;
	//}

	//return false;
}

void Tablero::conteoturno() {
	if (Turnoactual == TURNO::JUGADOR2)
		numeroturno++;
}
void Tablero::cambiarturno(){
	// Cambiar turno
	if (Turnoactual == TURNO::JUGADOR1)
		Turnoactual = TURNO::JUGADOR2;
	else
		Turnoactual = TURNO::JUGADOR1;

}





void Tablero::dibujar_casillas() {

	for (int f = 0; f < 9; f++) {
		for (int c = 0; c < 9; c++) {
			(*casillas[f][c]).dibujar(matriz[f][c]);
		}
	}

	// dibujamos el cursor
	float lado = 5.0f;
	float x = cursor_c * lado;
	float y = cursor_f * lado;

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

}
bool Tablero::turnofinalizadoexito()
{
	cambiarturno();
	conteoturno();   // numeroturno++
	fichaSeleccionada = nullptr;
	fichaYaSeleccionada = false;
	return true;
}