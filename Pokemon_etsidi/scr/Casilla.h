#pragma once
#include "Pokemon.h"
#include <freeglut.h>
#include <ETSIDI.h>

enum class TipoCasilla{clara,oscura,neutr,poder,aviso_neutro,aviso_claro,aviso_oscuro};

class Casilla
{
	friend class tablero; 
	friend class cursor; 

	int columna, fila;
	TipoCasilla tipo;
	Pokemon* personaje = nullptr;
	int cambio;

public:

	Casilla() :fila(0), columna(0), tipo(TipoCasilla::clara), personaje(nullptr), cambio(-1) {}

	void inicializar(int f, int c);
	Pokemon* obtener_pokemon() const { return personaje; }
	void colocar_pokemon(Pokemon* p) { personaje = p; }
	void vaciar() { personaje = nullptr; }
	bool ocupacion() { return personaje != nullptr; }

	int obtener_fila() const { return fila; }
	int obtener_columna() const { return columna; }
	TipoCasilla obtener_tipo() const { return tipo; }
	int obtener_cambio() const { return cambio; }
	void avanzar_ciclo();

	void dibujarcasilla(Pokemon* p); 

	
};

