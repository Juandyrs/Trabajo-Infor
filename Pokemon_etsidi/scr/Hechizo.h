#pragma once
#include "Pokemon.h"
#include "Textos.h"

class Hechizo
{
	bool Teletransporte = true;
	bool Curar = true;
	bool Bloquear = true; 
	bool Revivir = true; 
    bool Intercambio = true;
    Pokemon* pieza_bloqueada = nullptr;
    TipoMovimiento movoriginal;
    int casillasoriginal;
    int mensaje_error{ 0 };     // donde 0 es ninguno, 1 es ya usado, y 2 es no anadido
    float t_error{ 0.0f };


public: 

    bool puedeteletransportar() const { return Teletransporte; }
    bool puedecurar() const { return Curar; }
    bool puedevloquear() const { return Bloquear; }
    bool puedeRevivir() const { return Revivir; }

    //metodos que realizan los hechizos
    bool llamar_curar(Pokemon* objetivo);
    bool llamar_teletransporte(Pokemon* objetivo);
    void restaurarmovimiento(Pokemon* p) { p->restablecermovimiento(movoriginal, casillasoriginal);}
    void restaurarbloqueo(Pokemon* p) { p->restablecermovimiento(movoriginal, casillasoriginal); }
    bool llamar_intercambio(Pokemon* p);
    bool llamar_bloqueo(Pokemon* p);
    bool llamar_revivir();



    void actualiza_t(float t); 
    void dibuja_errores();
};

