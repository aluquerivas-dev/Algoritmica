#include <iostream>
#include "funcionesAuxiliares.hpp"
#include "macros.hpp"
int main()
{

	srand(time(NULL));
	int opcion;
	do{

		// Se elige la opción del menún
		opcion = menu();		

		std::cout << CLEAR_SCREEN;
		PLACE(3,1);

		// Se ejecuta la opción del menú elegida
		switch(opcion)
		{
			case 0: 
				PLACE(25,1);
				std::cout << BRED;
				std::cout << "[0] Fin del programa" << std::endl << std::endl;
				std::cout << RESET;
			break;

			case 1: 
			   	std::cout << BIBLUE;
				std::cout << "[1] Método de inserción binaria." << std::endl;
				ordenacionInsercionBinaria();
				std::cout << RESET;

				break;

			case 2: 
			   	std::cout << BIBLUE;
				std::cout << "[2] Método Shell. " << std::endl;
				ordenacionInsercionShell();
				std::cout << RESET;

				break;

			default:
				std::cout << BIRED;
				std::cout << "Opción incorrecta ";
				std::cout << RESET;
				std::cout << "--> ";
			  	std::cout << ONIRED;
				std::cout << opcion << std::endl;
				std::cout << RESET;
     }
  
    if (opcion !=0)
    {
		PLACE(25,1);
		std::cout << "Pulse ";
		std::cout << INVERSE ;
		std::cout << "ENTER";
		std::cout << RESET;
		std::cout << " para mostrar el ";
		std::cout << BIGREEN ;
		std::cout << "menú: "; 
		std::cout << RESET;
		// Pausa
		std::cin.ignore();

		std::cout << CLEAR_SCREEN;
    }
	  }while(opcion!=0);

	return 0;
}


