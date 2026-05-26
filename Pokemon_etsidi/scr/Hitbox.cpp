#include "Hitbox.h"
#include <freeglut.h>

void HitboxRectangular::dibujar()
{
	glTranslated(pos.x, pos.y, 0);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glVertex3d(-rectangulo.x, rectangulo.y, 0);
	glVertex3d(rectangulo.x, rectangulo.y, 0);
	glVertex3d(rectangulo.x, -rectangulo.y, 0);
	glVertex3d(-rectangulo.x, -rectangulo.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glTranslated(-pos.x, -pos.y, 0);
	glEnd();
}

void HitboxCircular::dibujar()
{
	glTranslated(pos.x, pos.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslated(-pos.x, -pos.y, 0);
}
