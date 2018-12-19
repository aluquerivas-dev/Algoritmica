/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 1
  \author
  \date
*/

#include "funcionesAuxiliares.hpp"
#include "mochila.hpp"
#include "grafo.hpp"
int menu()
{
	srand(time(0));
	int opcion;
	int posicion;
	// Se muestran las opciones del menú
	posicion = 2;
	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;
	PLACE(1, 10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;
	//////////////////////////////////////////////////////////////////////////////
	posicion++;
	PLACE(posicion++, 10);
	std::cout <<  "[1] Mochila";
	PLACE(posicion++, 10);
	std::cout <<  "[2] Grafo";
	//////////////////////////////////////////////////////////////////////////////
	posicion++;
	posicion++;
	PLACE(posicion++, 10);
	std::cout << BIRED << "[0] Salir";
	//////////////////////////////////////////////////////////////////////////////
	posicion++;
	PLACE(posicion++, 10);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;
	// Se lee el número de opción
	std::cin >> opcion;
	// Se elimina el salto de línea del flujo de entrada
	std::cin.ignore();
	return opcion;
}

void mochila()
{
	int volumen = 0;
	std::string fichero="datos.txt";
	std::cout << RED << "Mochila" << RESET << std::endl;
	std::cout << RED << "Introduce el volumen: " << RESET;
	std::cin >> volumen;
	
	Mochila m(volumen);
	m << fichero;
	m.start();


}
void grafo()
{
	Grafo m;
	std::string fichero;
	int opt;
	std::cout << "Grafo\n";
	/*
	std::cout << RED << "Introduce el fichero de matriz: " << RESET;
	std::cin >> fichero;
	*/
	m << "matriz-data.txt";
	/*
	std::cout << RED << "Introduce el fichero de nombres: " << RESET;
	std::cin >> fichero;
	*/
	m << "vertices-data.txt";

	cout << "Introduce 0 para no mostrar Adyacencias ni Vertices, 1 para mostrar." << endl;
	cin >> opt;
	if (opt == 1)
	{
		m.printAdyacencia();
		m.printVertex();
	}
	cout << "\n\n\n";
	m.TSP(0);
	getchar();
	getchar();
}