#include "Obstaculo.h"
#include <freeglut.h>
#include "Colisiones.h"

Vector2D Obstaculo::consultar_dim_hitbox() const
{
	HitboxRectangular* h = dynamic_cast<HitboxRectangular*>(hitbox);

	return h->rectangulo;
}

// Metodos del obstaculo de piedra

bool Obs_Piedra::interrumpir(Pokemon &personaje, double dt)
{

	if (Colisiones::colision(hitbox, personaje.consultar_hitbox()))
	{
		//Se agrega un pequeno empuje para evitar adherirse a la piedra

		Vector2D dir_empuje = personaje.consultar_posicion() - hitbox->pos;
	
		double paso_atras = personaje.consultar_vel() * dt * 1.2; // Se coloca un factor por la misma razon
		Vector2D nueva_pos = personaje.consultar_posicion() + (dir_empuje.unitario() * paso_atras);;

		personaje.modificar_posicion(nueva_pos);

		personaje.modificar_mult_vel(0.0);

		return true;
	}

	return false;
} 

void Obs_Piedra::dibujar()
{
	HitboxRectangular *aux = dynamic_cast<HitboxRectangular*>(hitbox);

	glTranslated(hitbox->pos.x, hitbox->pos.y, 0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/sprites/Obstaculos/ObsPiedra.png").id);
	glDisable(GL_LIGHTING);
	glColor3f(1.0f, 1.0f, 1.0f);
	glEnable(GL_ALPHA_TEST);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex2d(aux->rectangulo.x, aux->rectangulo.y);
	glTexCoord2d(1, 0); glVertex2d(-aux->rectangulo.x, aux->rectangulo.y);
	glTexCoord2d(1, 1); glVertex2d(-aux->rectangulo.x, -aux->rectangulo.y);
	glTexCoord2d(0, 1); glVertex2d(aux->rectangulo.x, -aux->rectangulo.y);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
	glTranslated(-hitbox->pos.x, -hitbox->pos.y, 0);
	glPopMatrix();
}

// Metodos del obstaculo de fuego

bool Obs_Fuego::interrumpir(Pokemon &personaje, double dt)
{

	if (Colisiones::colision(hitbox,personaje.consultar_hitbox()) 
		&& personaje.consultar_efecto_estado() != EfectoEstado::Invulnerable)
	{
		personaje.modificar_estado(EfectoEstado::Quemadura, frames_fuego);
		return true;
	}
	return false;
}

void Obs_Fuego::dibujar()
{
	glPushMatrix();
	glTranslated(hitbox->pos.x + 0.18, hitbox->pos.y - 0.30, 0.0);
	sprite.draw();
	glPopMatrix();
}

//Metodos del obstaculo arbusto

bool Obs_Arbusto::interrumpir(Pokemon &personaje, double dt)
{
	if (Colisiones::colision(hitbox, personaje.consultar_hitbox())
		&& personaje.consultar_efecto_estado() != EfectoEstado::Invulnerable)
	{
		personaje.modificar_mult_vel(0.5);

		return true;
	}

	return false;
}

void Obs_Arbusto::dibujar()
{
	HitboxRectangular* aux = dynamic_cast<HitboxRectangular*>(hitbox);

	glTranslated(hitbox->pos.x, hitbox->pos.y, 0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/sprites/Obstaculos/ObsArbusto.png").id);
	glDisable(GL_LIGHTING);
	glColor3f(1.0f, 1.0f, 1.0f);
	glEnable(GL_ALPHA_TEST);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0); glVertex2d(aux->rectangulo.x, aux->rectangulo.y);
	glTexCoord2d(1, 0); glVertex2d(-aux->rectangulo.x, aux->rectangulo.y);
	glTexCoord2d(1, 1); glVertex2d(-aux->rectangulo.x, -aux->rectangulo.y);
	glTexCoord2d(0, 1); glVertex2d(aux->rectangulo.x, -aux->rectangulo.y);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
	glTranslated(-hitbox->pos.x, -hitbox->pos.y, 0);
	glPopMatrix();
}

