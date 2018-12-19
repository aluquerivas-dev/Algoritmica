#include "bignum.hpp"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string>
using namespace std;

string sumarNumero(string &numero1, string &numero2)
{
	int digitos; //esto es para la dimension
	int x, y, aux, aux2 = 0; //para sumar
	int n1 = numero1.length();
	int n2 = numero2.length();
	if (n1 > n2)
	{
		agregarCerosDelante(numero2, n1 - n2); // esta cadena es para el caso en que haya sobreflujo en la ultima suma
		digitos = n1;
	}
	else
	{
		agregarCerosDelante(numero1, n2 - n1);
		digitos = n2;
	}
	string total = "";
	string total2 = "";
	string totalAux = "";
	for (int i = digitos - 1; i >= 0; i--)
	{
		x = numero1[i] - '0'; //pasamos el numero digito a digito a entero para poder operar con el
		y = numero2[i] - '0';
		aux = x + y + aux2; //aux2 en la primera iteración vale 0 porque no nos llevamos ninguna. Si en algun momento desborda la suma se pondra a 1 y entonces así controlamos que el siguiente numero sume 1
		if (aux >= 10)
		{
			aux2 = 1;
			aux = aux % 10;
		}
		else
		{
			aux2 = 0;
		}
		totalAux = '0' + aux;
		total.insert(0, totalAux);  //convertimos el digito a caracter y lo introducimos en la cadena
		if (i == 0 and aux2 == 1)
		{
			total.insert(0, "1");
			quitarCerosNoSignificativos(total);
			return total;
		}
	}
	quitarCerosNoSignificativos(total);
	return total;
}

string multiplicaNumeros(string &numero1, string  &numero2, int limite)
{
	//declaración de los numeros con los que operaremos
	int n = numero1.size();
	//variables para multiplicar
	int s;
	string w, x, y, z; //almacena digitos que quedan
	//enteros finales
	string final1, final2, final3; //sirven para la hora de retornar ya que dividimos la operacion en 3 y la sumamos
	//operación de multiplicación
	if (n <= limite)
	{
		string total;
		int numeroInt1, numeroInt2, aux; //aux nos servira para pasar el numero a cadena
		numeroInt1 = stoi(numero1);
		numeroInt2 = stoi(numero2);

		aux = numeroInt1 * numeroInt2; //multiplicamos los numeros y los almacenamos en aux para ahora convertirlo en cadena con sprintf
		total = to_string(aux);
		quitarCerosNoSignificativos(total);
		return total;
	}
	else
	{

		s = n / 2;
		//Dividimos el numero
		partirCadena(numero1, w, x);
		partirCadena(numero2, y, z);
		//ahora dividimos la operación del algoritmo en tres partes, hay que tener cuidado de convertir a entero los numeros que retorna la llamada de la multiplicación
		//final1
		final1 = multiplicaNumeros(w, y, limite);
		final1 = multiplicarPotencia10(final1, 2 * s);
		//final2
		string wz = multiplicaNumeros(w, z, limite);
		string xy = multiplicaNumeros(x, y, limite);
		final2 = sumarNumero(wz , xy);
		final2 = multiplicarPotencia10(final2, s);
		//final3
		final3 = multiplicaNumeros(x, z, limite);
		string total = sumarNumero(final1, final2);
		return (sumarNumero(total, final3));
		//return total;
	}
}
