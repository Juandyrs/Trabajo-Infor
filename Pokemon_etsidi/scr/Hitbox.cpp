#include "Hitbox.h"
#include <freeglut.h>

void HitboxRectangular::dibujar()
{
	glVertex3d(-rectangulo.x, rectangulo.y, 0);
	glVertex3d(rectangulo.x, rectangulo.y, 0);
	glVertex3d(rectangulo.x, -rectangulo.y, 0);
	glVertex3d(-rectangulo.x, -rectangulo.y, 0);
	glEnd();
}
