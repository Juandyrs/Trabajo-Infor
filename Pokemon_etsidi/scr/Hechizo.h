#pragma once
#include "Pokemon.h"

class Hechizo
{
	bool Teletransporte = true;
	bool Curar = true;
	bool Bloquear = true; 
	bool Revivir = true; 

public: 

    bool puedeteletransportar() const { return Teletransporte; }
    bool puedecurar() const { return Curar; }
    bool puedevloquear() const { return Bloquear; }
    bool puedeRevivir() const { return Revivir; }

    //metodos que realizan los hechizos
    bool llamar_curar(Pokemon* objetivo);


    void gastarteletransporte() { Teletransporte = false; }
    void gastracurar() { Curar = false; }
    void gastarbloquear() { Bloquear = false; }
    void gastarrevivir() { Revivir = false; }

};

