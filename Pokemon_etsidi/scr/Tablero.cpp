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

	cursor.inicializarcursor(4, 4);

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
	if (flagmenu == true) dibujar_menu_hechizos();
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

<<<<<<< Updated upstream
bool Tablero::movimientoTerrestre(Pokemon* p, int fi, int ci, int ff, int cf) {

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
}

=======
>>>>>>> Stashed changes
void Tablero::conteoturno() {
	if (Turnoactual == TURNO::JUGADOR2)
		numeroturno++;
}
<<<<<<< Updated upstream
void Tablero::cambiarturno(){
	// Cambiar turno
	if (Turnoactual == TURNO::JUGADOR1)
=======
void Tablero::cambiarturno() {
	if (Turnoactual == TURNO::JUGADOR1) {
>>>>>>> Stashed changes
		Turnoactual = TURNO::JUGADOR2;
		hechizousadoturno = false;
	}
	else {
		Turnoactual = TURNO::JUGADOR1;
		hechizousadoturno = false;
	}

}


void Tablero::turnofinalizadoexito()
{
	cambiarturno();
	conteoturno();   // numeroturno++
}


<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
//TABLERO MUEVE 

void Tablero::tableromueve(bool key[]) {
	if(flagmenu == false) cursor.Cursormover(key, matriz, hechizoseleccionado);
	cogerpieza(key);
	soltarpieza(key); 
	dibujarmenu(key);
	seleccionarhechizo(key);
	hechizocuracion(key);
	hechizobloquear(key);
	if (key['x'] == true) cout<< matriz[cursor.fila][cursor.columna]->consultar_vida() <<modohechizo << hechizoseleccionado;
}



//COGER PIEZA

void Tablero::cogerpieza(bool key[]) {

	int f = cursor.fila;
	int c = cursor.columna;

	if ((key['e'] && modohechizo == false) || (key['e'] && hechizoseleccionado == 1)) {

		if (f == filaBloqueada && c == colBloqueada && turnosBloqueo > 0) //BLOQUEADA POR EL HECHIZO
			return;

		if (cursor.cursorllevaficha() == false) {
			//NO TIENE FICHA EL CURSOR
			if (matriz[f][c] != nullptr && ((int)matriz[f][c]->equipo) == int(Turnoactual)) { //MISMO TURNO EN EL QUE MUEVES
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

<<<<<<< Updated upstream
	if (key['z']) {
	

		if (cursor.cursorllevaficha() == true) {
			if (cursor.actualdistancia == 0) { //SI SE HA MOVIDO DE SU CASILLA PERO VUELVE GASTA EL TURNO
=======
	if ((key['q'] && modohechizo == false) || (key['q'] && hechizoseleccionado == 1)) {
		if (cursor.cursorllevaficha()) {

			//VOLVER A LA DE PARTIDA SIN GASTAR MOV
			if (cursor.actualdistancia == 0) {
>>>>>>> Stashed changes
				matriz[cursor.fi][cursor.ci] = cursor.obtenerfichacursor();
				cursor.cursorsueltaficha();
				ETSIDI::play("bin/sonidos/sonidopoke.wav");
				return;
			}
			

			if (casillaocupada(f, c) && !casillaaliado(f, c, cursor.obtenerfichacursor())) { //CASILLA OCUPADA ESTA AL REVES, ACTUA ASI

				if (casillaenemigo(f, c, cursor.obtenerfichacursor())) {
					// ENEMIGO → lógica de combate/arena
					return;
				}

				// Casilla libre
				matriz[f][c] = cursor.obtenerfichacursor(); //COLOCA EN VACIA
				cursor.cursorsueltaficha();
				ETSIDI::play("bin/sonidos/sonidopoke.wav");
				turnofinalizadoexito();
<<<<<<< Updated upstream
=======
				reseteohechizos();

				imprimir();

				return;
			}

	//VACIA
			if (!casillaocupada(f, c)) {

				matriz[f][c] = cursor.obtenerfichacursor();
				cursor.cursorsueltaficha();
				ETSIDI::play("sonidos/impacto.wav");
				turnofinalizadoexito();
				reseteohechizos();
				imprimir();

				return;
			}

		//ALIADA
			if (casillaaliado(f, c, cursor.obtenerfichacursor())) {
				return;
>>>>>>> Stashed changes
			}
			//ALIADO NO LO PONGO POR QUE NO ME HACE FALTA DE MOMENTO
		}
	}
<<<<<<< Updated upstream
=======
	
}



void Tablero::turnofinalizadoexito()
{
	cambiarturno();
	conteoturno();   // numeroturno++

	//RESETAR LA FUNCION DE BLOQUEO
	if (turnosBloqueo > 0)
	{
		turnosBloqueo--;

		if (turnosBloqueo == 0)
		{
			filaBloqueada = -1;
			colBloqueada = -1;
		}
	}

}

bool Tablero::controla_puntos_poder(Bando b) {
	int poder[5][2] = { {0,4},{4,0},{4,4},{4,8},{8,4} };
	for (auto p : poder)
		if (matriz[p[0]][p[1]] == nullptr ||
			matriz[p[0]][p[1]]->obtener_bando() != b)
			return false;
	return true;
}
>>>>>>> Stashed changes
	
}
<<<<<<< Updated upstream
=======
			
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

//	static ETSIDI::Sprite ico1("bin/sprites/Iconos/teleport.png", 9.0f, 35.0f, 3.5f, 3.5f); ico1.draw();
	//static ETSIDI::Sprite ico2("bin/sprites/Iconos/curar.png", 9.0f, 30.0f, 3.5f, 3.5f); ico2.draw();
	//static ETSIDI::Sprite ico3("bin/sprites/Iconos/shiftime.png", 9.0f, 25.0f, 3.5f, 3.5f); ico3.draw();
	//static ETSIDI::Sprite ico4("bin/sprites/Iconos/exchange.png", 9.0f, 20.0f, 3.5f, 3.5f); ico4.draw();
	//static ETSIDI::Sprite ico5("bin/sprites/Iconos/elemental.png", 9.0f, 15.0f, 3.5f, 3.5f); ico5.draw();
	//static ETSIDI::Sprite ico6("bin/sprites/Iconos/revivir.png", 9.0f, 10.0f, 3.5f, 3.5f); ico6.draw();
	//static ETSIDI::Sprite ico7("bin/sprites/Iconos/imprison.png", 9.0f, 5.0f, 3.5f, 3.5f); ico7.draw();

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
Textos::escribirCadena2D(34.0f, 3.0f, "[G] Volver");

glEnable(GL_DEPTH_TEST);

}

void Tablero::dibujarmenu(bool key[]) {
	if (matriz[cursor.fila][cursor.columna] != nullptr) { //POR SEGURIDAD
		if (key['h'] == true && matriz[cursor.fila][cursor.columna]->obtener_simbolo() == 'H' && (int)matriz[cursor.fila][cursor.columna]->obtener_bando() == (int)Turnoactual) {
			flagmenu = true;
		}
	}
	if (key['g'] == true && flagmenu == true) flagmenu = false;

}

void Tablero::reseteohechizos() {

	hechizousadoturno = true; 
	modohechizo = false;       
	hechizoseleccionado = 0;
}

void Tablero::seleccionarhechizo(bool key[]) {

	if (flagmenu == false || hechizousadoturno == true)
		return;

	//HACER EL DOWNCAST PARA VER LAS FUNCIONES INTERNAS DE LOS HECHIZOS
	Pokemon* p = matriz[cursor.fila][cursor.columna];
	if (!p) return; //ESTA VACIO

	Hechicero* h = dynamic_cast<Hechicero*>(p);
	if (!h) return; //NO ES HECHICERO

	//SELECCION
	if (key['2'])  // CURAR
	{
		if (h->verHechizos().puedecurar())
		{
			hechizoseleccionado = 2;
			modohechizo = true;
			flagmenu = false;
			h->modificarHechizos().gastacurar();
		}
	}
	else if (key['1']) // TELETRANSPORTE
	{
		if (h->verHechizos().puedeteletransportar())
		{
			hechizoseleccionado = 1;
			modohechizo = true;
			flagmenu = false;
			h->modificarHechizos().gastacurar();
		}
	}
	else if (key['7']) // BLOQUEAR
	{
		if (h->verHechizos().puedebloquear())
		{
			hechizoseleccionado = 7;
			modohechizo = true;
			flagmenu = false;
			h->modificarHechizos().gastacurar();
		}
	}
	else if (key['6']) // REVIVIR
	{
		if (h->verHechizos().puederevivir())
		{
			hechizoseleccionado = 7;
			modohechizo = true;
			flagmenu = false;
			h->modificarHechizos().gastacurar();
		}
	}
}


void Tablero::hechizocuracion(bool key[]) {

	if (modohechizo == false || hechizoseleccionado != 2)
		return;
	if (matriz[cursor.fila][cursor.columna] != nullptr) {
		if (((int)matriz[cursor.fila][cursor.columna]->obtener_bando() == (int)Turnoactual) && key['z'] == true){
			matriz[cursor.fila][cursor.columna]->vida_actual = matriz[cursor.fila][cursor.columna]->vida_actual + 20;
			if (matriz[cursor.fila][cursor.columna]->vida_actual > matriz[cursor.fila][cursor.columna]->vida_max)
				matriz[cursor.fila][cursor.columna]->vida_actual = matriz[cursor.fila][cursor.columna]->vida_max;

			reseteohechizos();
		}
	}
}

void Tablero::hechizoteletransporte(bool key[]) {
//NO HACE NADA ,SE HACE DESDE LAS FUNCIONES DE MOVIMIENTO
}


void Tablero::hechizobloquear(bool key[]) {

	if (modohechizo == false || hechizoseleccionado != 7)
		return;

	if (key['z']) {
		int f = cursor.fila;
		int c = cursor.columna;
		if (matriz[cursor.fila][cursor.columna] != nullptr) {
			if ((int)matriz[cursor.fila][cursor.columna]->obtener_bando() != (int)Turnoactual) {
				filaBloqueada = f;
				colBloqueada = c;
				turnosBloqueo = 2;

				reseteohechizos();
				return;
			}
		}
	}
}
>>>>>>> Stashed changes
