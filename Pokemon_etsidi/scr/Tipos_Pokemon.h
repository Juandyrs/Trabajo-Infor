#pragma once
#include "Pokemon.h"

class Hechicero : public Pokemon {
public:
    
    void preparar(string n, char s, Bando b, Tipo t1, Tipo t2) {

        
        inicializa_datos(n, s, b, t1, t2); //Paso los datos recibidos del main
        inicializa_stats(200.0, 200.0, 50.0, 20.0, 40.0, 15.0); //Paso las estadísticas
        inicializa_mov(TipoMovimiento::Teletransporte, 9);//Paso el tipo de transporte
    }
};

class Volador : public Pokemon {
public:

    void preparar(string n, char s, Bando b, Tipo t1, Tipo t2) {


        inicializa_datos(n, s, b, t1, t2); //Paso los datos recibidos del main
        inicializa_stats(200.0, 200.0, 50.0, 20.0, 40.0, 15.0); //Paso las estadísticas
        inicializa_mov(TipoMovimiento::Vuelo, 5);//Paso el tipo de transporte
    }
};

class Tanque : public Pokemon {
public:

    void preparar(string n, char s, Bando b, Tipo t1, Tipo t2) {


        inicializa_datos(n, s, b, t1, t2); //Paso los datos recibidos del main
        inicializa_stats(200.0, 200.0, 50.0, 20.0, 40.0, 15.0); //Paso las estadísticas
        inicializa_mov(TipoMovimiento::Tierra, 5);//Paso el tipo de transporte
    }
};

class Distancia : public Pokemon {
public:

    void preparar(string n, char s, Bando b, Tipo t1, Tipo t2) {


        inicializa_datos(n, s, b, t1, t2); //Paso los datos recibidos del main
        inicializa_stats(200.0, 200.0, 50.0, 20.0, 40.0, 15.0); //Paso las estadísticas
        inicializa_mov(TipoMovimiento::Tierra, 5);//Paso el tipo de transporte
    }
};

class Basico : public Pokemon {
public:

    void preparar(string n, char s, Bando b, Tipo t1, Tipo t2) {


        inicializa_datos(n, s, b, t1, t2); //Paso los datos recibidos del main
        inicializa_stats(200.0, 200.0, 50.0, 20.0, 40.0, 15.0); //Paso las estadísticas
        inicializa_mov(TipoMovimiento::Tierra, 5);//Paso el tipo de transporte
    }
};



