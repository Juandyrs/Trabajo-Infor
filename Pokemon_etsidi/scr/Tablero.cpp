#include "Tablero.h"
#include <iostream>
#include "Pokemon.h"
#include "Hechicero.h"
#include "Volador.h"
#include "Tanque.h"
#include "Distancia.h"
#include "Basico.h"
#include "Fenix.h"
#include "CambiaFormas.h"
#include "ArenaCombate.h"
#include "cmath"

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

int Tablero::distancia(int x1, int y1, int x2, int y2) {

	return abs(x1 - x2) + abs(y1 - y2);
}


bool Tablero::casillaocupada(int f, int c) {
	if (matriz[f][c] != nullptr) {
		return true;
	}
	return false;

}


bool Tablero::casillaaliado(int f, int c, Pokemon* p)
{

	if (!p) return false;
	Bando MiEquipo = p->obtener_bando();
//DENTRO DE MARGENES
	if (f < 0 || f >= 9 || c < 0 || c >= 9)
		return false;

//CASILLA VACIA
	if (matriz[f][c] == nullptr)
		return false;

//COMPROBAR SI ES ALIADO
return matriz[f][c]->obtener_bando() == MiEquipo;
}


bool Tablero::casillaenemigo(int f, int c, Pokemon* p)
{

	if (!p) return false;
	Bando MiEquipo = p->obtener_bando();
// MARGENES
	if (f < 0 || f >= 9 || c < 0 || c >= 9)
		return false;

//VACIA DE NUEVO
	if (matriz[f][c] == nullptr)
		return false;

//BANDO ENEMIGO
	return matriz[f][c]->obtener_bando() != MiEquipo;
}

int Tablero::movimientovalido(Pokemon* p, int nx, int ny)
{
//COMPROBACIÓN DE QUE SE HA SELECCIONADO ALGUNA PIEZA
	if (p == nullptr)
		return 0;

	int fx = p->pos_tab.x;
	int fy = p->pos_tab.y;

//MOVIMIENTO DENTRO DE MARGENES
	if (nx < 0 || nx >= 9 || ny < 0 || ny >= 9)
		return 0;

//COMPROBAR DISTANCIA MAXIMA
	int dist = distancia(fx, fy, nx, ny);
	if (dist > p->numero_casillas)   // ← atributo del Pokémon
		return 0;

	//CASILLA VACIA DEVUELVE 1
	if (matriz[nx][ny] == nullptr)
		return 1;

//VER EL BANDO SI NO ESTA VACIA


	//ALIADA 3
	if (casillaaliado(nx, ny, p))
		return 3;

//ENEMIGO 2
	if (casillaenemigo(nx, ny, p))
		return 2;

	return 0;
}