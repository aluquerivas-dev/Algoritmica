/*!

	\file principal.cpp
	\brief Programa principal creado por el estudiante los datos de cada algoritmo se generan en la carpeta datos, los ficheros .sh de gnuplot hay 2, uno para cada algoritmo los graficos se generan en la propia carpeta. Para poder compilar hacemos uso de CMake para ellos nos dirijimos a la carpeta "build" y ejecutamos "cmake ../"
	\author Ismael Abu-jadur García
	\date
	\version 1.0
*/


// Para los flujos de entrada y salida y para usar locale
#include <iostream>


#include <string>

#include "funcionesAuxiliares.hpp"
#include "macros.hpp"

#include <stdlib.h>
#include <time.h>
#include <vector>

/*!
	\brief   Programa principal de la práctica 1
	\return  int
*/
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
			std::cout << "Mochila" << std::endl;
			std::cout << RESET;
			mochila();
			break;
		case 2:
			std::cout << INVERSE;
			std::cout << "Sistema Monetario" << std::endl;
			std::cout << RESET;
			cambio();
			break;
		case 3:
			std::cout << INVERSE;
			std::cout << "Tiempo Mochila" << std::endl;
			std::cout << RESET;
			tiempo_mochila();
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

