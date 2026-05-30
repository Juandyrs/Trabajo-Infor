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
#include "Casilla.h"	
#include <cmath>
#include <ETSIDI.h>
#include <fstream>
#include <string>
#include "Inicializador.h"

using namespace std;
using std::ifstream;
using std::getline;
using std::stod;
using std::stoi;

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
	srand(time(NULL));

	for (int f = 0; f < 9; f++) {
		for (int c = 0; c < 9; c++) {
			casillas[f][c] = new Casilla();         // creamos la casilla en memoria
			casillas[f][c]->inicializar(f, c);      // la inicializamos
		}
	}

	cursor.inicializarcursor(4, 4);

	Turnoactual = TURNO::JUGADOR1;

	//Inicializacion de las piezas

	ifstream inicializa("piezas.txt");

	if (!inicializa.is_open())	return; // Avisa si no se puede abrir el fichero

	string linea;

	while (std::getline(inicializa, linea)) {
		// Ignorar líneas vacías
		if (linea.empty()) continue;

		std::stringstream ss(linea);
		std::string rol, nombre, bando, tipo1, tipo2, xStr, yStr, spriteRuta, xsStr, ysStr, xcStr, ycStr, xhStr, yhStr;

		// Leer cada campo separado por comas
		getline(ss, rol, ',');
		getline(ss, nombre, ',');
		getline(ss, bando, ',');
		getline(ss, tipo1, ',');
		getline(ss, tipo2, ',');
		getline(ss, xStr, ',');
		getline(ss, yStr, ',');
		getline(ss, spriteRuta, ',');
		getline(ss, xsStr, ',');
		getline(ss, ysStr, ',');
		getline(ss, xcStr, ',');
		getline(ss, ycStr, ',');
		getline(ss, xhStr, ',');
		getline(ss, yhStr, ',');

		// Convertir coordenadas de string a entero
		int x = stoi(xStr);
		int y = stoi(yStr);
		double xs = stod(xsStr);
		double ys = stod(ysStr);
		double xc = stod(xcStr);
		double yc = stod(ycStr);
		double xh = stod(xhStr);
		double yh = stod(yhStr);

		auto nuevoPokemon = Inicializador::CrearPokemon(rol, nombre, bando, tipo1, tipo2, x, y, spriteRuta, xs, ys, xc, yc, xh, yh);

		// Si se creó correctamente, lo añadimos a nuestro vector del tablero
		if (nuevoPokemon != nullptr && nuevoPokemon->obtener_bando() == Bando::Entrenador) equipo_entrenador.push_back(nuevoPokemon);
		else if (nuevoPokemon != nullptr && nuevoPokemon->obtener_bando() == Bando::Team_Rocket) equipo_rocket.push_back(nuevoPokemon);
	}

	for (auto e : equipo_entrenador) colocar_pokemon(e->pos_tab.x, e->pos_tab.y, e);
	for (auto e : equipo_rocket) colocar_pokemon(e->pos_tab.x, e->pos_tab.y, e);
	
	inicializa.close();
	imprimir();
}

void Tablero::dibujar_tableroyfichas() {
	for (int f = 0; f < 9; f++) {
		for (int c = 0; c < 9; c++) {

			casillas[f][c]->dibujarcasilla(matriz[f][c]);
		}
	}
}


void Tablero::tablerodibuja() { 
	dibujar_tableroyfichas();
	cursor.dibujarcursor();

}

int Tablero::distanciarecorrida(int fi, int ci, int ff, int cf) {

	return abs(fi - ff) + abs(ci - cf); //COMPRUEBA EL NUMERO DE CASILLAS QUE RECORRE LA FICHILLA
}

bool Tablero::casillaocupada(int ff, int cf) {
	if (matriz[ff][cf] != nullptr)
			return true;
			return false;
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
		return true;
	}
}

int Tablero::movimientovalido(Pokemon* p, int ff, int cf)
{

//CASILLA VACIA
	if (!casillaocupada(ff, cf))
		return 1;

	else if (casillaocupada(ff, cf)) {
		//CASILLA ALIADO
		if (casillaaliado(ff, cf, p))
			return 3;

		//CASILLA ENEMIGO
		if (casillaenemigo(ff, cf, p))
			return 2;
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
void Tablero::cambiarturno() {
	if (Turnoactual == TURNO::JUGADOR1)
		Turnoactual = TURNO::JUGADOR2;
	else
		Turnoactual = TURNO::JUGADOR1;

	for (int f = 0; f < 9; f++)   
		for (int c = 0; c < 9; c++)
			casillas[f][c]->avanzar_ciclo();
}






	//cambio las casillas cambiantes de tipo 

	//for (int f = 0; f < 9; f++)
		//for (int c = 0; c < 9; c++)
		//	casillas[f][c]->avanzar_ciclo();
//TABLERO MUEVE 

void Tablero::tableromueve(bool key[]) {
	cursor.Cursormover(key, matriz);
	cogerpieza(key);
	soltarpieza(key); 
}


//COGER PIEZA

void Tablero::cogerpieza(bool key[]) {

	int f = cursor.fila;
	int c = cursor.columna;

	if (key['e']) {
		if (cursor.cursorllevaficha() == false) {
			//NO TIENE FICHA EL CURSOR
			if (matriz[f][c] != nullptr && ((int)matriz[f][c]->equipo) == int(Turnoactual)) {
				cursor.cursorpillaficha(matriz[f][c]);
				ETSIDI::play("bin/sonidos/sonidopoke.wav");
				matriz[f][c] = nullptr;       //VACIAR ESA CASILLA
			}
		}
	}
}
//SOLTAR PIEZA
void Tablero::soltarpieza(bool key[]) {

	int f = cursor.fila;
	int c = cursor.columna;

	if (key['z']) {

		if (cursor.cursorllevaficha()) {

			//VOLVER A LA DE PARTIDA SIN GASTAR MOV
			if (cursor.actualdistancia == 0) {
				matriz[cursor.fi][cursor.ci] = cursor.obtenerfichacursor();
				cursor.cursorsueltaficha();
				ETSIDI::play("sonidos/impacto.wav");
				imprimir();
				return;
			}

			///ENEMIGA y COMBATE
			if (casillaenemigo(f, c, cursor.obtenerfichacursor())) {

				ETSIDI::play("sonidos/impacto.wav");

				cargadatosarena();
				cursor.cursorsueltaficha();
				arenabandera = true;
				turnofinalizadoexito();
				imprimir();

				return;
			}

	//VACIA
			if (!casillaocupada(f, c)) {

				matriz[f][c] = cursor.obtenerfichacursor();
				cursor.cursorsueltaficha();
				ETSIDI::play("sonidos/impacto.wav");
				turnofinalizadoexito();
				imprimir();

				return;
			}

		//ALIADA
			if (casillaaliado(f, c, cursor.obtenerfichacursor())) {
				return;
			}
		}
	}

	if (key['q']) {
		cout << cursor.actualdistancia << "\n";
		cout << cursor.maxdistancia << "\n";
		cout << cursor.ci << cursor.fi << "\n";
		cout << cursor.columna << cursor.fila << "\n";
		cout << cursor.llevaficha;
		cout << arenabandera;
	}
}



void Tablero::turnofinalizadoexito()
{
	cambiarturno();
	conteoturno();   // numeroturno++
}

bool Tablero::controla_puntos_poder(Bando b) {
	int poder[5][2] = { {0,4},{4,0},{4,4},{4,8},{8,4} };
	for (auto p : poder)
		if (matriz[p[0]][p[1]] == nullptr ||
			matriz[p[0]][p[1]]->obtener_bando() != b)
			return false;
	return true;
}
	
void Tablero::cargar_pokemons(Pokemon* p) {
	if (p->obtener_bando() == Bando::Entrenador)
		equipo_entrenador.push_back(p);
	else
		equipo_rocket.push_back(p);
}
			
bool Tablero::quedan_piezas(Bando b) {
	if (b == Bando::Entrenador) {
		for (auto p : equipo_entrenador)
			if (p->consultar_estado() == Estado::Vivo)
				return true;
	}
	else {
		for (auto p : equipo_rocket)
			if (p->consultar_estado() == Estado::Vivo)
				return true;
	}
	return false;
}


void Tablero::cargadatosarena() {
	defensa = matriz[cursor.fila][cursor.columna];
	ataque = cursor.obtenerfichacursor();
	casillaarena = (casillas[cursor.fila][cursor.columna])->obtener_tipo();
	filaCombate = cursor.fila;
	columnaCombate = cursor.columna;
}

void Tablero::dibujar_menu_hechizos() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5.0, 50.0, -5.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();



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
	
	Textos::escribirCadena2D(10.0f, 40.0f, "LIBRO DE HECHIZOS (Selecciona 1-7)");


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
	Textos::escribirCadena2D(12.5f, 34.5f, "1. Teletransporte - Mover aliado");
	Textos::escribirCadena2D(12.5f, 29.5f, "2. Curar - Sanar vida completa");
	Textos::escribirCadena2D(12.5f, 24.5f, "3. Cambiar Tiempo - Altera casillas");
	Textos::escribirCadena2D(12.5f, 19.5f, "4. Intercambiar - Cambiar 2 piezas");
	Textos::escribirCadena2D(12.5f, 14.5f, "5. Invocar Elemental");
	Textos::escribirCadena2D(12.5f, 9.5f, "6. Resucitar - Revivir aliado");
	Textos::escribirCadena2D(12.5f, 4.5f, "7. Encarcelar - Bloquear enemigo");

	glColor3f(0.7f, 0.7f, 0.7f);
	Textos::escribirCadena2D(34.0f, 3.0f, "[H] Volver");

	glEnable(GL_DEPTH_TEST);

}