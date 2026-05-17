#include "ListaObstaculos.h"

void ListaObstaculos::agregar_Obstaculo(Obstaculo *obstaculo)
{
	bool existe = false;

	for (auto existente : lista)
	{
		if (obstaculo == existente)
		{
			existe = true;
			break;
		}
	}

	if (!existe) lista.push_back(obstaculo);
}

void ListaObstaculos::eliminar_Obstaculo(int index)
{
	if ((index < 0) || (index >= lista.size()))return;
	delete lista[index];
	lista.erase(lista.begin() + index);
}

bool ListaObstaculos::interrumpir_Obstaculos(Pokemon& personaje)
{
	bool aux{ false };

	for (auto obstaculo : lista)
	{
		if(obstaculo->interrumpir(personaje)) aux = true;
	}

	return aux;
}

void ListaObstaculos::eliminar_Contenido()
{
	for (auto e : lista) delete e;
	lista.clear();
}



