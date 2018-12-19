/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 1
  \author
  \date
*/

#include "funcionesAuxiliares.hpp"

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
	std::cout <<  "[1] Suma";
	PLACE(posicion++, 10);
	std::cout <<  "[2] Multiplicación";
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

void sumar()
{
	bignum numero1, numero2;
	string n1, n2;
	std::cout << "Introduce el primer número: " << std::endl;
	std::cin >> n1;
	std::cout << "Introduce el segundo número: " << std::endl;
	std::cin >> n2;
	std::cout << "Primer número: " << numero1.getNumero() << std::endl;
	std::cout << "Segundo número: " << numero2.getNumero() << std::endl;
	//

	numero1.setNumero(n1);
	numero2.setNumero(n2);
	//

	string resultado = numero1 + numero2;
	std::cout << "\nResultado: " << resultado << std::endl;
	getchar();
}

void multiplicar()
{
	bignum numero1, numero2;
	string n1, n2;
	std::cout << "Introduce el primer número: " << std::endl;
	std::cin >> n1;
	std::cout << "Introduce el segundo número: " << std::endl;
	std::cin >> n2;
	int tam, z;

	if (n1.size() > n2.size())
	{
		tam = n1.size();
	}
	else
	{
		tam = n2.size();
	}

	z = tam - n1.size();
	agregarCerosDelante(n1, z);
	z = tam - n2.size();
	agregarCerosDelante(n2, z);

	if (n1.size() % 2 != 0 || n2.size() % 2 != 0)
	{
		agregarCerosDelante(n1, 1);
		agregarCerosDelante(n2, 1);
	}
	numero1.setNumero(n1);
	numero2.setNumero(n2);
	string resultado = numero1 * numero2;
	std::cout << "\nResultado: " << resultado << std::endl;
	getchar();
}