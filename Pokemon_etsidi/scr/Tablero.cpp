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

void Tablero::reiniciar_tablero()
{
	numeroturno = 1;
	Turnoactual = TURNO::JUGADOR1;

	for (auto e : equipo_entrenador) delete e;
	for (auto e : equipo_rocket) delete e;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++) matriz[i][j] = nullptr;
	}

	equipo_entrenador.clear();
	equipo_rocket.clear();
	estado_hechizo = 1;

	cursor.resetear_cursor();
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
	
	dibujar_fondo_tablero();
	dibujar_tableroyfichas();
	movimientopiezassprite();
	cursor.dibujarcursor();
	
	if (cursor.cursorllevaficha()) dibujar_mov_posibles();

	dibujarestadisticas();
	imprimir_turno();


	Pokemon* poke_lanzador = matriz[f_hechicero][c_hechicero];
	if (poke_lanzador != nullptr && poke_lanzador->obtener_simbolo() == 'H') {
		Hechicero* mago = static_cast<Hechicero*>(poke_lanzador);
		mago->libro_hechizos().dibuja_errores();
	}

	//llamo al menu de hechizos si se ha pulsado la H
	if (menu_hechizos_abierto) {
		dibujar_menu_hechizos(); 
	}


	if (hechizo_cargado > 0 && (menu_hechizos_abierto==0)) {
		glDisable(GL_TEXTURE_2D);
		glColor3f(1.0f, 0.5f, 0.0f);

		if (hechizo_cargado == 6 && estado_hechizo == 1) {
			Textos::escribirCadena2DPequena(2.0f, 50.5f, "REVIVIR (Paso 1): Elige a quien revivir con [1, 2...]");

			vector<Pokemon*> muertos_temp = obtener_pokemons_muertos_detu_bando();

			if (muertos_temp.empty()) {
				glColor3f(1.0f, 0.0f, 0.0f); 
				Textos::escribirCadena2DPequena(2.0f, 48.0f, "¡No hay ningun pokemon muerto en tu equipo! Pulsa [H] para cancelar.");
			}
			else {
				glColor3f(1.0f, 1.0f, 1.0f); 
				for (int i = 0; i < muertos_temp.size(); i++) {
					string texto = to_string(i + 1) + ". " + muertos_temp[i]->consultar_nombre();
					Textos::escribirCadena2DPequena(2.0f, 45.0f - (i * 2.0f), texto.c_str());
				}
			}
		}
		else if (hechizo_cargado == 6 && estado_hechizo == 2) {
			Textos::escribirCadena2DPequena(2.0f, 50.5f, "REVIVIR (Paso 2): Mueve el cursor a una CASILLA VACIA y pulsa [E]");
		}
		else {
			Textos::escribirCadena2DPequena(2.0f, 50.5f, "MODO APUNTAR: Pulsa [E] para lanzar o [H] para cancelar");
		}
	}



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

void Tablero::conteoturno() {
	if (Turnoactual == TURNO::JUGADOR2) {
		numeroturno++;

	}
}

void Tablero::cambiarturno() {
	if (Turnoactual == TURNO::JUGADOR1)
		Turnoactual = TURNO::JUGADOR2;
	else {
		Turnoactual = TURNO::JUGADOR1;
		for (int f = 0; f < 9; f++)
			for (int c = 0; c < 9; c++)
				casillas[f][c]->avanzar_ciclo();
	}
}

void Tablero::hechizosmueve(bool key[]) {

	//si tenemos el menu abierto, bloqueamos el resto de acciones para no poder mover el cursor de mientras
	if (menu_hechizos_abierto) {
		if (key['h'] || key['H']) {
			menu_hechizos_abierto = false;
			key['h'] = key['H'] = false;
			return;
		}

		//con el menu de hechizos abierto, recogemos el numero del hechizo que el usuario quiere utilizar
		for (char c = '1'; c <= '7'; c++) {
			if (key[c]) {
				hechizo_cargado = c - '0'; // con esto convertimos del numero en ascii a numeros del 1 al 7, porque obtenemos distancias  a traves de la resta
				menu_hechizos_abierto = false; //cerramos el menu
				estado_hechizo = 1;
				key[c] = false;

				if (hechizo_cargado == 6) {
					p_revivir = nullptr;
				}

				return;
			}
		}
		return;
	}

	//una vez tenemos el hechizo seleccionado
	if (hechizo_cargado > 0) {


		//si nos encontramos con el hechizo 6 cargado y estamos en el estado de hechizo 1
		if (hechizo_cargado == 6 && estado_hechizo == 1) {

			vector<Pokemon*> muertos_temp = obtener_pokemons_muertos_detu_bando();

			if (muertos_temp.empty()) {
				if (key['h'] || key['H']) { hechizo_cargado = 0; key['h'] = key['H'] = false; }
			}
			else {
				for (int i = 0; i < muertos_temp.size(); i++) {
					char tecla = '1' + i;
					if (key[tecla]) {
						p_revivir = muertos_temp[i];
						estado_hechizo = 2; 
						key[tecla] = false;
					}
				}
			}
			if (key['h'] || key['H']) { hechizo_cargado = 0; estado_hechizo = 1; key['h'] = key['H'] = false; }
			return; 
		}



		cursor.Cursormover(key, matriz); //ahora ya si se puede mover el cursor

		if (key['e'] || key['E']) { //comprobamos si va todo bien y el hechizo se ha podido ejecutar bien.
			bool ok_hechizo = lanzar_hechizo(hechizo_cargado, cursor.fila, cursor.columna);
			if (ok_hechizo) {
				hechizo_cargado = 0; //resetamos el hechizo cargado 

			}
			key['e'] = key['E'] = false;
		}

		if (key['h'] || key['H']) { // para cancelar el hechizo
			hechizo_cargado = 0;
			key['h'] = key['H'] = false;
		}
		return; //bloqueamos el mover las piezas
	}

	//ahora vemos si tenemos el cursor sobre el hechicero y es nuetro turno
	if (key['h'] || key['H']) {
		Pokemon* p = matriz[cursor.fila][cursor.columna];
		if (p != nullptr && p->obtener_simbolo() == 'H') {
			bool turnito =
				(Turnoactual == TURNO::JUGADOR1 && p->obtener_bando() == Bando::Entrenador) ||
				(Turnoactual == TURNO::JUGADOR2 && p->obtener_bando() == Bando::Team_Rocket);

			if (turnito) {
				menu_hechizos_abierto = true; //se abre el menu desde tablero dibuja
				f_hechicero = cursor.fila;
				c_hechicero = cursor.columna;
			}
		}
		key['h'] = key['H'] = false;
	}
}

//TABLERO MUEVE 

void Tablero::tableromueve(bool key[]) 
{
	if (IA_activa && Turnoactual == TURNO::JUGADOR2) return;

	
	if (hechizo_cargado > 0 || menu_hechizos_abierto) {
		hechizosmueve(key);
	}
	else {
		hechizosmueve(key); 
		cursor.Cursormover(key, matriz);
		cogerpieza(key);
		soltarpieza(key);
	}

}

//COGER PIEZA

void Tablero::cogerpieza(bool key[]) {

	int f = cursor.fila;
	int c = cursor.columna;

	if (key['e'] || key['E']) {
		if (cursor.cursorllevaficha() == false) {
			//NO TIENE FICHA EL CURSOR


			if (matriz[f][c] != nullptr &&  matriz[f][c]->obtenerncasillas() == 0) { //LAS BLOQUEADAS
				std::cout << "La pieza esta bloqueada y no puede moverse." << std::endl;
				return;
			}

			if (matriz[f][c] != nullptr && ((int)matriz[f][c]->equipo) == int(Turnoactual)) { //RESTO DE PIEZAS DEL TURNO
				cursor.cursorpillaficha(matriz[f][c]);
				ETSIDI::play("bin/sonidos/sonidopoke.wav");
				f_seleccionada = f;
				c_seleccionada = c;
				matriz[f][c] = nullptr;       //VACIAR ESA CASILLA
			}
		}
	}


}
//SOLTAR PIEZA

void Tablero::soltarpieza(bool key[]) {

	int f = cursor.fila;
	int c = cursor.columna;
	Pokemon* p = cursor.obtenerfichacursor();

	if (key['z'] || key['Z']) {

		if (cursor.cursorllevaficha()) {
			p->sprites->setState(0, false);
			
			if (p->obtenertipomovimiento() == TipoMovimiento::Cambio) {

				Pokemon* poke_lanzador = matriz[f_hechicero][c_hechicero];
				Hechicero* mago = static_cast<Hechicero*>(poke_lanzador);
				Hechizo& magia = mago->libro_hechizos();

				//VACIA NO PERMITIDO
				if (!casillaocupada(f, c)) {
					std::cout << "No se puede intercambiar con una casilla vacía." << std::endl;
					return;
				}

				//INTERCAMBIO
				Pokemon* objetivo = matriz[f][c];

				//RESTAURAR EL MOVIMIENTO AL QUE TENIA ANTES, QUITAR LO DE TELETRANSPORTE
				magia.restaurarmovimiento(p);

				// Intercambio real
				matriz[f][c] = p;                      //CAMBIO
				matriz[cursor.fi][cursor.ci] = objetivo; //CAMBIADA

				cursor.cursorsueltaficha();
				turnofinalizadoexito();
				imprimir();
				return;
			}

			if (cursor.actualdistancia == 0) {
				if (p->obtenertipomovimiento() == TipoMovimiento::Hechizo) {
					Pokemon* poke_lanzador = matriz[f_hechicero][c_hechicero];
					Hechicero* mago = static_cast<Hechicero*>(poke_lanzador);
					Hechizo& magia = mago->libro_hechizos();
					magia.restaurarmovimiento(p);
				}
				matriz[f][c] = p;
				cursor.cursorsueltaficha();
				imprimir();
				return;
			}

			
			if (casillaenemigo(f, c, p)) {
				if (p->obtenertipomovimiento() == TipoMovimiento::Hechizo) {
					Pokemon* poke_lanzador = matriz[f_hechicero][c_hechicero];
					Hechicero* mago = static_cast<Hechicero*>(poke_lanzador);
					Hechizo& magia = mago->libro_hechizos();
					magia.restaurarmovimiento(p); 
				}

				cargadatosarena();
				cursor.cursorsueltaficha();
				arenabandera = true;
				turnofinalizadoexito();
				imprimir();
				return;
			}

			
			if (!casillaocupada(f, c)) {
				if (p->obtenertipomovimiento() == TipoMovimiento::Hechizo) {
					Pokemon* poke_lanzador = matriz[f_hechicero][c_hechicero];
					Hechicero* mago = static_cast<Hechicero*>(poke_lanzador);
					Hechizo& magia = mago->libro_hechizos();
					magia.restaurarmovimiento(p); 
				}

				matriz[f][c] = p;
				cursor.cursorsueltaficha();
				turnofinalizadoexito(); 
				imprimir();
				return;
			}

			
			if (casillaaliado(f, c, p)) {
				return;
			}
		}
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
		for (auto const& p : equipo_entrenador)
		{
			if (p->consultar_estado() == Estado::Vivo) return true;
		}
		return false;
	}
	else {
		for (auto const& p : equipo_rocket) 
		{
			if (p->consultar_estado() == Estado::Vivo) return true;
		}
		return false;
	}

}

void Tablero::cargadatosarena() {
	defensa = matriz[cursor.fila][cursor.columna];
	ataque = cursor.obtenerfichacursor();
	casillaarena = (casillas[cursor.fila][cursor.columna])->obtener_tipo();
	filaCombate = cursor.fila;
	columnaCombate = cursor.columna;
}

void Tablero::dibujar_menu_hechizos() {

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

//ponemos el titulo
	glDisable(GL_TEXTURE_2D);
	glColor3f(1.0f, 0.8f, 0.0f);
	Textos::escribirCadena2D(8.0f, 40.0f, "LIBRO DE HECHIZOS (Selecciona 1-7)");

	//dibujamos los sprites
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glColor3f(1.0f, 1.0f, 1.0f);
	static ETSIDI::Sprite ico1("bin/sprites/Iconos/low_teleport.png", 7.0f, 35.0f, 3.5f, 3.5f); ico1.draw();
	static ETSIDI::Sprite ico2("bin/sprites/Iconos/low_curar.png", 7.0f, 30.0f, 3.5f, 3.5f); ico2.draw();
	static ETSIDI::Sprite ico3("bin/sprites/Iconos/low_shiftime.png", 7.0f, 25.0f, 3.5f, 3.5f); ico3.draw();
	static ETSIDI::Sprite ico4("bin/sprites/Iconos/low_exchange.png", 7.0f, 20.0f, 3.5f, 3.5f); ico4.draw();
	static ETSIDI::Sprite ico5("bin/sprites/Iconos/low_elemental.png", 7.0f, 15.0f, 3.5f, 3.5f); ico5.draw();
	static ETSIDI::Sprite ico6("bin/sprites/Iconos/low_revivir.png", 7.0f, 10.0f, 3.5f, 3.5f); ico6.draw();
	static ETSIDI::Sprite ico7("bin/sprites/Iconos/cadena.png", 7.0f, 5.0f, 3.5f, 3.5f); ico7.draw();

	//leyendas de los hechizos
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glColor3f(1.0f, 1.0f, 1.0f);
	Textos::escribirCadena2D(9.5f, 34.5f, "1. Teletransporte - Mover aliado");
	Textos::escribirCadena2D(9.5f, 29.5f, "2. Curar - Curar vida completa");
	Textos::escribirCadena2D(9.5f, 24.5f, "3. Cambiar Tiempo - Altera casillas");
	Textos::escribirCadena2D(9.5f, 19.5f, "4. Intercambiar - Cambiar 2 piezas");
	Textos::escribirCadena2D(9.5f, 14.5f, "5. Invocar Elemental (Proximamente)");
	Textos::escribirCadena2D(9.5f, 9.5f, "6. Revivir - Revivir aliado");
	Textos::escribirCadena2D(9.5f, 4.5f, "7. Encarcelar - Bloquear enemigo");

	glColor3f(0.7f, 0.7f, 0.7f);
	Textos::escribirCadena2D(32.0f, 3.0f, "[H] Volver");

	glEnable(GL_DEPTH_TEST);
}

bool Tablero::lanzar_hechizo(int no_hechizo, int f, int c) {

	Pokemon* objetivo = matriz[f][c]; // al que tenemos en el objetivo para curar

	//necesitamos guardarnos las coordenadas del hechicero para saber quien lo lannza
	Pokemon* poke_lanzador = matriz[f_hechicero][c_hechicero];

	//comprobamos que el lanzador sea un hechicero
	if (poke_lanzador == nullptr || poke_lanzador->obtener_simbolo() != 'H') {
		return false;
	}

	//habiendo comprobado que es un hechicero, ahora podemos tratar el pokemon como un hechicero y usar su libro de chizos
	Hechicero* mago = static_cast<Hechicero*>(poke_lanzador);

	//miramos en su libro de hechizos
	Hechizo& magia = mago->libro_hechizos();


	switch (no_hechizo) {
	case 2: //cura
		if (casillaaliado(f, c, mago)) { //comprobamos que cure a un aliado
			if (magia.llamar_curar(objetivo)) { // como es un bool nos sirve para saber si se ha ejectuado bien, y dentro de ese bool que esta en hechizos, llamamos a la verdadera funcion de curar
				return true;
			}
		}
		
		return false;

	case 3: //cambio tiempo del tablero
		if (magia.puedecambiartiempo()) { 
			for (int i = 0; i < 9; i++)
				for (int j = 0; j < 9; j++)
					casillas[i][j]->avanzar_ciclo();
			magia.gastar_cambiartiempo(); 
			return true;
		}
		return false;

	case 1: //teletransporte

		if (casillaaliado(f, c, mago) && objetivo->obtenertipomovimiento() != TipoMovimiento::Teletransporte) {
			if (magia.llamar_teletransporte(objetivo)) {
				cursor.cursorpillaficha(objetivo); 
				matriz[f][c] = nullptr;            
				return true;                       
			}
		}
		cout << "No se puede aplicar teletransporte o el hechizo esta gastado." << endl;
		return false;


		case 4: //CAMBIO PIEZAS
		if (casillaaliado(f, c, mago) && objetivo->obtenertipomovimiento() != TipoMovimiento::Teletransporte) {
			if (magia.llamar_intercambio(objetivo)) {
				return true;
			}
		}

		cout << "No se puede intercambiar o el hechizo esta gastado." << endl;
		return false;

	case 6: // revivir
		if (matriz[f][c] == nullptr && p_revivir != nullptr) {
			if (magia.llamar_revivir()) { 

				matriz[f][c] = p_revivir; // nos colocamos al pokemon

				p_revivir->cura_max(); // vida al maximo
				p_revivir->cambiar_estado(Estado::Vivo); // cambiamos el estado a vivo

				p_revivir->modificar_posicion(Vector2D(c, f)); //tenemos que modificarle la posicion al pokemon
				return true;
			}
		}
		else {
			cout << "Fallo: ¡Debes revivirlo en una casilla vacía!" << endl;
		}
		return false;

		case 7: //BLOQUEO
			if (casillaenemigo(f, c, mago)) {
				if (magia.llamar_bloqueo(objetivo)) {
					return true; 
				}
			}

			cout << "No se puede bloquear o el hechizo está gastado." << endl;
			return false;

	}

	return false;
}

vector<Pokemon*> Tablero::obtener_pokemons_muertos_detu_bando() {
	vector<Pokemon*> muertos;
	Pokemon* mago = matriz[f_hechicero][c_hechicero];

	if (mago != nullptr) {
		std::vector<Pokemon*>& mi_equipo = (mago->obtener_bando() == Bando::Entrenador) ? equipo_entrenador : equipo_rocket;
		for (Pokemon* p : mi_equipo) {
			if (p->consultar_estado() == Estado::Muerto) {
				muertos.push_back(p);
			}
		}
	}
	return muertos;
}

void Tablero::dibujar_fondo_tablero() {
	
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor3f(1.0f, 1.0f, 1.0f);
	glDisable(GL_LIGHTING);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/fondos/fondo_tablero.png").id);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(-5.0f, -5.0f);
	glTexCoord2f(1, 0); glVertex2f(50.0f, -5.0f);
	glTexCoord2f(1, 1); glVertex2f(50.0f, 50.0f);
	glTexCoord2f(0, 1); glVertex2f(-5.0f, 50.0f);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);

}

void Tablero::dibujar_mov_posibles()
{
	auto movimientos = cursor.fichaencursor->movimiento_valido(this);

	for (auto e : movimientos)
	{
		float lado = 5.0f;
		float x = e.y * lado; //ESTAN AL REVES POR QUE SI NO EL MOVIMIENTO SALE INVERTIDO :p
		float y = (8 - e.x) * lado;

		glDisable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4ub(0, 0, 255, 100);
		glBegin(GL_QUADS);
		glVertex2f(x, y);
		glVertex2f(x + lado, y);
		glVertex2f(x + lado, y + lado);
		glVertex2f(x, y + lado);
		glEnd();
		glDisable(GL_BLEND);
		glEnable(GL_DEPTH_TEST);
	}
}

void Tablero::imprimir_turno() {
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);

	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
	glBegin(GL_QUADS);
	glVertex2f(-5.0f, 46.0f);
	glVertex2f(50.0f, 46.0f);
	glVertex2f(50.0f, 52.0f);
	glVertex2f(-5.0f, 52.0f);
	glEnd();
	glDisable(GL_BLEND);



	if (hechizo_cargado == 0) { 
		if (Turnoactual == TURNO::JUGADOR1) {
			glColor3f(1.0f, 1.0f, 1.0f); 
			Textos::escribirCadena2DPequena(12.5f, -2.5f, "TURNO: Entrenador (Jugador Claro)");
		}
		else {
			glColor3f(1.0f, 0.3f, 0.3f); 
			Textos::escribirCadena2DPequena(12.5f, -2.5f, "TURNO: Team Rocket (Jugador Oscuro)");
		}
	}

	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
	glBegin(GL_QUADS);
	glVertex2f(-5.0f, -10.0f);
	glVertex2f(50.0f, -10.0f);
	glVertex2f(50.0f, -4.0f);
	glVertex2f(-5.0f, -4.0f);
	glEnd();
	glDisable(GL_BLEND);

	
	glColor3f(1.0f, 1.0f, 0.8f);
	
	Textos::escribirCadena2DPequena(-4.0f, -7.5f, "[E] Coger/Lanzar  [Z] Soltar  [H] Hechizos (Cursor encima del Hechicero)");

	glEnable(GL_DEPTH_TEST);
}

void Tablero::dibujarestadisticas() {
	if (matriz[cursor.fila][cursor.columna] != nullptr) {

		Pokemon* p = matriz[cursor.fila][cursor.columna];
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_LIGHTING);

		glDisable(GL_BLEND);
		glDisable(GL_TEXTURE_2D);
		glColor3f(1.0f, 1.0f, 1.0f);
		char buffer[128];

		ETSIDI::setTextColor(1, 1, 1);

		string tipo;
		switch (p->obtenertipomovimiento()) {
		case TipoMovimiento::Tierra:        tipo = "Tierra";   break;
		case TipoMovimiento::Vuelo:         tipo = "Aire";     break;
		case TipoMovimiento::Teletransporte: tipo = "Teletransporte";   break;
		default:                            tipo = "Hechizo";  break;
		}

		float yy = 40.0f;
		yy -= 3.5f;
		Textos::escribirCadena2D(53.0f, yy, ("NOMBRE: " + p->consultar_nombre()).c_str());
		static ETSIDI::Sprite ico1("bin/sprites/Iconos/pokeball.png", 51.5f, yy + 0.5, 2.0f, 2.0f); ico1.draw(); yy -= 3.5f;
		Textos::escribirCadena2D(53.0f, yy, ("VIDA: " + to_string((int)p->consultar_vida()) + " / " + to_string((int)p->consultar_vidamax())).c_str());
		static ETSIDI::Sprite ico2("bin/sprites/Iconos/corazon.png", 51.5f, yy + 0.5, 2.0f, 2.0f); ico2.draw(); yy -= 3.5f;
		Textos::escribirCadena2D(53.0f, yy, ("ATAQUE: " + to_string((int)p->consultar_dano())).c_str());
		static ETSIDI::Sprite ico3("bin/sprites/Iconos/espada.png", 51.5f, yy + 0.5, 2.0f, 2.0f); ico3.draw(); yy -= 3.5f;
		Textos::escribirCadena2D(53.0f, yy, ("CASILLAS: " + to_string(p->obtenerncasillas())).c_str());
		static ETSIDI::Sprite ico4("bin/sprites/Iconos/botas.png", 51.5f, yy + 1, 3.0f, 3.0f); ico4.draw(); yy -= 3.5f;
		Textos::escribirCadena2D(53.0f, yy, ("TIPO: " + tipo).c_str());
		static ETSIDI::Sprite ico5("bin/sprites/Iconos/tipo.png", 51.5f, yy + 0.5, 4.5f, 4.5f); ico5.draw(); yy -= 3.5f;



		//std::string nombre = "Nombre: " + p->consultar_nombre();
		//ETSIDI::printxy(nombre.c_str(), 0, 8, 2);
		//std::string vida = "Vida: " + std::to_string((int)p->consultar_vida()) + " / " + std::to_string((int)p->consultar_vidamax());
		//ETSIDI::printxy(vida.c_str(), 0, 7);
		//std::string ataque = "Ataque: " + std::to_string((int)p->consultar_ataque());
		//ETSIDI::printxy(ataque.c_str(), 0, 6);
		//std::string mov = "Movimiento: " + std::to_string(p->obtenerncasillas()) + " casillas";
		//ETSIDI::printxy(mov.c_str(), 0, 5);
		//std::string lineaTipo = "Tipo: " + tipo;
		//ETSIDI::printxy(lineaTipo.c_str(), 0, 4);

		glEnable(GL_LIGHTING);
		glEnable(GL_DEPTH_TEST);

		if (p != pokemon_anterior)
		{

//BORRAR EL AUXILIAR
			if (sprite_aux != nullptr)
			{
				delete sprite_aux;
				sprite_aux = nullptr;
			}

//CREAR EL AUXILIAR NUEVO 
			if (p != nullptr)
			{
				sprite_aux = new ETSIDI::SpriteSequence(
					p->sprite.c_str(),3,5);

				sprite_aux->setSize(8.0f, 8.0f);
				sprite_aux->setCenter(0.5f, 0.5f);

				total_frames_aux = 15;
				frame_aux = 0;
				sprite_aux->setState(0, false);
			}

			// Actualizar referencia
			pokemon_anterior = p;
		}
		if (sprite_aux != nullptr)
		{
			glPushMatrix();
			glTranslated(53.5f, 13.0f, 1.0f);
			sprite_aux->draw();
			glPopMatrix();
		}
	}

}

void Tablero::actualiza(double dt) {

	if (sprite_aux != nullptr)
	{
		tiempo_aux += dt;

		if (tiempo_aux >= intervalo_aux)
		{
			tiempo_aux = 0.0f;

			frame_aux++;
			if (frame_aux >= total_frames_aux)
				frame_aux = 0;

			sprite_aux->setState(frame_aux);
		}
	}

}


void Tablero::movimientopiezassprite() {

	if (cursor.llevaficha && cursor.fichaencursor != nullptr)
	{
		Pokemon* p = cursor.fichaencursor;

		switch (cursor.direccion_actual)
		{
		case Direccion::Abajo:
			p->sprites->flip(false, false);
			p->sprites->setState(1, false);
			break;

		case Direccion::Derecha:
			p->sprites->flip(true, false);    //INVERTIR EL SPRITE 
			p->sprites->setState(6, false);
			break;

		case Direccion::Izquierda:
			p->sprites->flip(false, false);
			p->sprites->setState(6, false);
			break;

		case Direccion::Arriba:
			p->sprites->flip(false, false);
			p->sprites->setState(5, false); 
			break;
		}
	}
}