#include "IA.h"
#include "ArenaCombate.h"

extern bool atk2_ini;
extern double cd2;

void IA::decidir_movimiento_Arena(ArenaCombate &arena)
{
	srand(time(NULL));

	int decision = rand() % (8 - 1 + 1) + 1;
	static int frame{100};

	switch (decision)
	{
		case 1:
			if(frame%10 == 0) arena.equipo2.mover_arena({ 0, 1 });
			break;

		case 2:
			if(frame%10 == 0) arena.equipo2.mover_arena({ 0, -1 });
			break;

		case 3:
			if(frame%10 == 0) arena.equipo2.mover_arena({ 1, 0 });
			break;

		case 4:
			if(frame%10 == 0) arena.equipo2.mover_arena({ -1, 0 });
			break;

		case 5:
			if (frame % 10 == 0) arena.equipo2.mover_arena({ sqrt(2) / 2, sqrt(2) / 2 });
			break;

		case 6:
			if (frame % 10 == 0) arena.equipo2.mover_arena({ -sqrt(2) / 2, sqrt(2) / 2 });
			break;

		case 7:
			if (frame % 10 == 0) arena.equipo2.mover_arena({ sqrt(2) / 2, -sqrt(2) / 2 });
			break;

		case 8:
			if (frame % 10 == 0) arena.equipo2.mover_arena({ -sqrt(2) / 2, -sqrt(2) / 2 });
			break;
	}

	frame--;
	if (frame <= 0) frame = 100;
}


void IA::decidir_ataque_Arena(ArenaCombate &arena)
{
	if (cd2 <= 0)
	{
		atk2_ini = true;
	}
}