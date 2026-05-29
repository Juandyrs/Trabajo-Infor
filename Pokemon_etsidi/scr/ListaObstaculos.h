#pragma once

#include "Obstaculo.h"
#include <vector>
#include "Pokemon.h"

using std::vector;

class ListaObstaculos
{

    vector<Obstaculo*> lista;

public:
    
    friend InteraccionArena;

    void agregar_Obstaculo(Obstaculo *obstaculo);
    void eliminar_Obstaculo(int index);
    void dibujar_Obstaculos() { for (auto obstaculo : lista) obstaculo->dibujar(); }
    double distancia_obstaculo_cercano(Pokemon &personaje);
    bool interrumpir_Obstaculos(Pokemon &personaje);
	void eliminar_Contenido();
	Obstaculo& obtener_Obstaculo(int index) { return *lista[index]; }
    void animar() { for (auto obstaculo : lista) obstaculo->animar(); }

	int size() const { return static_cast<int>(lista.size()); }
    auto begin() const { return lista.begin(); }
    auto end() const { return lista.end(); }
};
