#include "Colisiones.h"
#include <cmath>

using std::abs;

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