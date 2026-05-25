#include "Colisiones.h"
#include <cmath>
#include <vector>

using std::max;
using std::min;
using std::abs;
using std::vector;

bool Colisiones::colision(Vector2D rect1, Vector2D pos1, Vector2D rect2, Vector2D pos2)
{
    Vector2D distancia = { abs(pos1.x - pos2.x), abs(pos1.y - pos2.y) };

	return distancia.x < (rect1.x + rect2.x) && distancia.y < (rect1.y + rect2.y);
}

bool Colisiones::colision(double radio, Vector2D pos_r, Vector2D rect2, Vector2D pos2)
{
    Vector2D distancia = { abs(pos_r.x - pos2.x), abs(pos_r.y - pos2.y) };

    return (distancia.x < (radio + rect2.x) && distancia.y < (radio + rect2.y));

}

bool Colisiones::colision(Vector2D rect, Vector2D pos, Vector2D dir, Vector2D origen, int a)
{
   double A{}, B{}, C{}; //Coeficientes de una recta generica

    A = dir.y;
    B = -dir.x;
    C = dir.x * origen.y - dir.y * origen.x;

    vector <Vector2D> esquinas(4);
    bool posi{ false }; //Resultado positivo
	bool nega{ false }; //Resultado negativo
	bool linea{ false }; //true si la recta direccion coincide con una de las esquinas del rectangulo

    double proy_min = 999999999.0;
	double proy_max = -999999999.0;

    esquinas[0] = pos + rect;
    esquinas[1] = pos + Vector2D(-rect.x, rect.y);
    esquinas[2] = pos - rect;
    esquinas[3] = pos + Vector2D(rect.x, -rect.y);

    for (int i = 0; i < 4; i++)
    {
        if (A * esquinas[i].x + B * esquinas[i].y + C > 0) posi = true;
        else if (A * esquinas[i].x + B * esquinas[i].y + C < 0) nega = true;
        else linea = true; // La esquina coincide con la recta direccion

		Vector2D esquina = esquinas[i] - origen; // Proyeccion de la esquina sobre la direccion
		double proyeccion = esquina.proyeccion(dir); // Proyeccion escalar

		if (proyeccion < proy_min) proy_min = proyeccion;
		if (proyeccion > proy_max) proy_max = proyeccion;
    }
    
	bool cruza = (posi && nega) || linea;

    bool adelante = proy_max >= 0.0;

	return cruza && adelante;
    
}
