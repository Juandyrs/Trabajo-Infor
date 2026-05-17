#pragma once

#include "Obstaculo.h"
#include <vector>
#include "Pokemon.h"

using std::vector;

class ListaObstaculos
{

    vector<Obstaculo*> lista;

public:
    


    void agregar_Obstaculo(Obstaculo *obstaculo);
    void eliminar_Obstaculo(int index);
    void dibujar_Obstaculos() { for (auto obstaculo : lista) obstaculo->dibujar(); }
    bool interrumpir_Obstaculos(Pokemon &personaje);
	void eliminar_Contenido();
	Obstaculo& obtener_Obstaculo(int index) { return *lista[index]; }
	int obtener_Tamano() { return lista.size(); }

};
