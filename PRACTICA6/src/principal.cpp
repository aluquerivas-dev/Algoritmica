#include <iostream>
#include <string>
#include "funcionesAuxiliares.hpp"
#include "macros.hpp"
#include <stdlib.h>
#include <time.h>
#include <vector>
int main()
{
	srand(time(0));
	int opcion;
	do
	{
		// Se elige la opción del menún
		opcion = menu();
		std::cout << CLEAR_SCREEN;
		PLACE(3, 1);
		// Se ejecuta la opción del menú elegida
		switch (opcion)
		{
		case 1:
			std::cout << INVERSE;
			std::cout << "N Reinas Backtracking" << std::endl;
			std::cout << RESET;
			reinasBacktracking();
			break;
		case 2:
			std::cout << INVERSE;
			std::cout << "Sistema Monetario" << std::endl;
			std::cout << RESET;
			reinasVegas();
			break;
		case 3:
			std::cout << INVERSE;
			std::cout << "Dictar Directorio N Reinas con algoritmo  de Backtracking" << std::endl;
			std::cout << RESET;
			listar_dir(1);
			break;
		case 4:
			std::cout << INVERSE;
			std::cout << "Dictar Directorio N Reinas con algoritmo de Las Vegas" << std::endl;
			std::cout << RESET;
			listar_dir(2);
			break;
		case 5:
			std::cout << INVERSE;
			std::cout << "Laboratorio de prueba - Algoritmo de Las Vegas" << std::endl;
			std::cout << RESET;
			laboratorio_vegas();
			break;
		case 6:
			std::cout << INVERSE;
			std::cout << "Laboratorio de prueba - Algoritmo de Backtracking" << std::endl;
			std::cout << RESET;
			laboratorio_backtracking();
			break;
		case 7:
			std::cout << INVERSE;
			std::cout << "Comparación de Algoritmos" << std::endl;
			std::cout << RESET;
			laboratorio_comparacion();
			break;


		case 0:
			std::cout << INVERSE;
			std::cout << "Fin del programa" << std::endl;
			std::cout << RESET;
			break;
		//////////////////////////////////////////////////////////////////////////////
		default:
			std::cout << BIRED;
			std::cout << "Opción incorrecta ";
			std::cout << RESET;
			std::cout << "--> ";
			std::cout << ONIRED;
			std::cout << opcion << std::endl;
			std::cout << RESET;
		}
		if (opcion != 0)
		{
			PLACE(25, 1);
			std::cout << "Pulse ";
			std::cout << BIGREEN;
			std::cout << "ENTER";
			std::cout << RESET;
			std::cout << " para mostrar el ";
			std::cout << INVERSE;
			std::cout << "menú";
			std::cout << RESET;
			// Pausa
			std::cin.ignore();
			std::cout << CLEAR_SCREEN;
		}
	}
	while (opcion != 0);
	return 0;
}

