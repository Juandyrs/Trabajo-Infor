#include "ListaObstaculos.h"
#include <algorithm>

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

double ListaObstaculos::distancia_obstaculo_cercano(Pokemon &personaje)
{
	auto size = lista.size();
	vector<double> distancias(size);
	Vector2D DistanciaC{};
	double dx{}, dy{};

	int i{0};

	for (auto e : lista)
	{
		DistanciaC = personaje.consultar_posicion() - (*e).consultar_posicion();

		dx = max(0.0, abs(DistanciaC.x) - (personaje.consultar_hitbox().x + (*e).consultar_hitbox().x));
		dy = max(0.0, abs(DistanciaC.y) - (personaje.consultar_hitbox().y + (*e).consultar_hitbox().y));
		distancias[i] = sqrt(dx * dx + dy * dy);
		i++;
	}

	auto min_ele = min_element(distancias.begin(), distancias.end());
	//cout << *min_ele << endl;
	if (*min_ele > 0) return *min_ele;
	else return 0.0;
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



