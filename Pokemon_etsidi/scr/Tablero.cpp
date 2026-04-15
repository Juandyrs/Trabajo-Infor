#include "Tablero.h"

using namespace std;

void Tablero:: imprimir() {
	cout << "\nTABLERO POKEMON\n";

	for (int f = 0; f < 9; f++) {
		for (int c = 0; c < 9; c++) {
			
			if (matriz[f][c] == nullptr) {
				cout << "|  .  |";
			}
			else {
				cout << "| " <<(*matriz[f][c]).obtener_simbolo()  << " |";
			}
		}
		cout << "\n";
	}
}