#pragma once
#include "Pokemon.h"

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


    void gastarteletransporte() { Teletransporte = false; }
    void gastracurar() { Curar = false; }
    void gastarbloquear() { Bloquear = false; }
    void gastarrevivir() { Revivir = false; }

};

