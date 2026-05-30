#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "tiposp/Basico.h"
#include "tiposp/Hechicero.h"
#include "tiposp/Distancia.h"
#include "tiposp/CambiaFormas.h"
#include "tiposp/Tanque.h"
#include "tiposp/Volador.h"
#include "tiposp/Fenix.h"
#include "Vector2D.h"

using std::string;

class Inicializador
{

public:

    static Pokemon* CrearPokemon(
        const std::string &rol,
        const std::string &nombre,
        const std::string &bandoStr,
        const std::string &tipo1Str,
        const std::string &tipo2Str,
        int xt, int yt,
        const std::string &spriteRuta,
        double xs, double ys,
        double xc, double yc,
        double xh, double yh
    )
    {
        Bando bando = (bandoStr == "Entrenador") ? Bando::Entrenador : Bando::Team_Rocket;

        Tipo tipo1 = (tipo1Str == "Tierra") ? Tipo::Tierra :
            (tipo1Str == "Planta") ? Tipo::Agua :
            (tipo1Str == "Fuego") ? Tipo::Fuego :
            (tipo1Str == "Planta") ? Tipo::Planta :
            (tipo1Str == "Siniestro") ? Tipo::Siniestro :
            (tipo1Str == "Bicho") ? Tipo::Bicho :
            (tipo1Str == "Dragon") ? Tipo::Dragon :
            (tipo1Str == "Electrico") ? Tipo::Electrico :
            (tipo1Str == "Hada") ? Tipo::Hada :
            (tipo1Str == "Lucha") ? Tipo::Lucha :
            (tipo1Str == "Volador") ? Tipo::Volador :
            (tipo1Str == "Fantasma") ? Tipo::Fantasma :
            (tipo1Str == "Normal") ? Tipo::Normal :
            (tipo1Str == "Acero") ? Tipo::Acero :
            (tipo1Str == "Veneno") ? Tipo::Veneno :
            (tipo1Str == "Psiquico") ? Tipo::Psiquico :
            (tipo1Str == "Hielo") ? Tipo::Hielo : Tipo::Ninguno;

        Tipo tipo2 = (tipo2Str == "Tierra") ? Tipo::Tierra :
            (tipo2Str == "Planta") ? Tipo::Agua :
            (tipo2Str == "Fuego") ? Tipo::Fuego :
            (tipo2Str == "Planta") ? Tipo::Planta :
            (tipo2Str == "Siniestro") ? Tipo::Siniestro :
            (tipo2Str == "Bicho") ? Tipo::Bicho :
            (tipo2Str == "Dragon") ? Tipo::Dragon :
            (tipo2Str == "Electrico") ? Tipo::Electrico :
            (tipo2Str == "Hada") ? Tipo::Hada :
            (tipo2Str == "Lucha") ? Tipo::Lucha :
            (tipo2Str == "Volador") ? Tipo::Volador :
            (tipo2Str == "Fantasma") ? Tipo::Fantasma :
            (tipo2Str == "Normal") ? Tipo::Normal :
            (tipo2Str == "Acero") ? Tipo::Acero :
            (tipo2Str == "Veneno") ? Tipo::Veneno :
            (tipo2Str == "Psiquico") ? Tipo::Psiquico :
            (tipo2Str == "Hielo") ? Tipo::Hielo : Tipo::Ninguno;

        if (rol == "Basico") return new Basico(nombre, bando, tipo1, tipo2, Vector2D(xt,yt),spriteRuta, Vector2D(xc,yc), Vector2D(xs,ys), Vector2D(xh,yh));
        else if (rol == "CambiaFormas") return new CambiaFormas(nombre, bando, tipo1, tipo2, Vector2D(xt, yt), spriteRuta, Vector2D(xc, yc), Vector2D(xs, ys), Vector2D(xh, yh));
        else if (rol == "Distancia") return new Distancia(nombre, bando, tipo1, tipo2, Vector2D(xt, yt), spriteRuta, Vector2D(xc, yc), Vector2D(xs, ys), Vector2D(xh, yh));
        else if (rol == "Fenix") return new Fenix(nombre, bando, tipo1, tipo2, Vector2D(xt, yt), spriteRuta, Vector2D(xc, yc), Vector2D(xs, ys), Vector2D(xh, yh));
        else if (rol == "Hechicero") return new Hechicero(nombre, bando, tipo1, tipo2, Vector2D(xt, yt), spriteRuta, Vector2D(xc, yc), Vector2D(xs, ys), Vector2D(xh, yh));
        else if (rol == "Tanque") return new Tanque(nombre, bando, tipo1, tipo2, Vector2D(xt, yt), spriteRuta, Vector2D(xc, yc), Vector2D(xs, ys), Vector2D(xh, yh));
        else if (rol == "Volador") return new Volador(nombre, bando, tipo1, tipo2, Vector2D(xt, yt), spriteRuta, Vector2D(xc, yc), Vector2D(xs, ys), Vector2D(xh, yh));

        return nullptr;
    }

};

