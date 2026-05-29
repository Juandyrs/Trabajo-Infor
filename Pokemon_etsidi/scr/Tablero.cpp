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
	srand(time(NULL));

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
	cargar_pokemons(Alakazam);
	colocar_pokemon(Gengar->pos_tab.x, Gengar->pos_tab.y, Gengar);
	cargar_pokemons(Gengar);

	//Posicion Volador
	colocar_pokemon(Charizard[0]->pos_tab.x, Charizard[0]->pos_tab.y, Charizard[0]);
	colocar_pokemon(Charizard[1]->pos_tab.x, Charizard[1]->pos_tab.y, Charizard[1]);
	cargar_pokemons(Charizard[0]);
	cargar_pokemons(Charizard[1]);

	colocar_pokemon(Crobat[0]->pos_tab.x, Crobat[0]->pos_tab.y, Crobat[0]);
	colocar_pokemon(Crobat[1]->pos_tab.x, Crobat[1]->pos_tab.y, Crobat[1]);
	cargar_pokemons(Crobat[0]);
	cargar_pokemons(Crobat[1]);

	//Posicion Tanque
	colocar_pokemon(Snorlax[0]->pos_tab.x, Snorlax[0]->pos_tab.y, Snorlax[0]);
	colocar_pokemon(Snorlax[1]->pos_tab.x, Snorlax[1]->pos_tab.y, Snorlax[1]);
	cargar_pokemons(Snorlax[0]);
	cargar_pokemons(Snorlax[1]);
	colocar_pokemon(Tyranitar[0]->pos_tab.x, Tyranitar[0]->pos_tab.y, Tyranitar[0]);
	colocar_pokemon(Tyranitar[1]->pos_tab.x, Tyranitar[1]->pos_tab.y, Tyranitar[1]);
	cargar_pokemons(Tyranitar[0]);
	cargar_pokemons(Tyranitar[1]);


	//Posicion Distancia
	for (int i = 0; i < 4; i++) { colocar_pokemon(Grovile[i]->pos_tab.x, Grovile[i]->pos_tab.y, Grovile[i]); cargar_pokemons(Grovile[i]); }
	for (int i = 0; i < 4; i++) { colocar_pokemon(Umbreon[i]->pos_tab.x, Umbreon[i]->pos_tab.y, Umbreon[i]); cargar_pokemons(Umbreon[i]); }

	//Posicion Basico
	for (int i = 0; i < 7; i++) { colocar_pokemon(Machomp[i]->pos_tab.x, Machomp[i]->pos_tab.y, Machomp[i]); cargar_pokemons(Machomp[i]); }
	for (int i = 0; i < 7; i++) { colocar_pokemon(Scraggy[i]->pos_tab.x, Scraggy[i]->pos_tab.y, Scraggy[i]); cargar_pokemons(Scraggy[i]); }


	//Posicion Cambiaforma
	colocar_pokemon(Ditto[0]->pos_tab.x, Ditto[0]->pos_tab.y, Ditto[0]);
	colocar_pokemon(Ditto[1]->pos_tab.x, Ditto[1]->pos_tab.y, Ditto[1]);
	cargar_pokemons(Ditto[0]);
	cargar_pokemons(Ditto[1]);

	//Posicion Fenix
	colocar_pokemon(Moltres[0]->pos_tab.x, Moltres[0]->pos_tab.y, Moltres[0]);
	colocar_pokemon(Moltres[1]->pos_tab.x, Moltres[1]->pos_tab.y, Moltres[1]);
	cargar_pokemons(Moltres[0]);
	cargar_pokemons(Moltres[1]);

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


		if (cursor.cursorllevaficha() == true) {
			if (cursor.actualdistancia == 0) { //SI SE HA MOVIDO DE SU CASILLA PERO VUELVE GASTA EL TURNO
				matriz[cursor.fi][cursor.ci] = cursor.obtenerfichacursor();
				cursor.cursorsueltaficha();
				ETSIDI::play("sonidos/impacto.wav");
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
				ETSIDI::play("sonidos/impacto.wav");
				turnofinalizadoexito();
			}
			//ALIADO NO LO PONGO POR QUE NO ME HACE FALTA DE MOMENTO
		}
	}

	if (key['q']) {
		cout << cursor.actualdistancia << "\n";
		cout << cursor.maxdistancia << "\n";
		cout << cursor.ci<<cursor.fi << "\n";
		cout << cursor.columna << cursor.fila << "\n";
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