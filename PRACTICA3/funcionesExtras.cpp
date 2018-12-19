#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <string>
#include "funcionesExtras.hpp"
#include <iostream>
using namespace std;
/*char * reservarCadena(int n)
{
	return new char [n];
}*/

void partirCadena(string c, string &c1, string &c2)
{
	int n;
	int n1, n2;
	int i;
	n = c.length();
	if (n % 2 == 0) //n es par
	{
		n1 = n / 2;
		n2 = n1;
	}
	else
	{
		n1 = (n + 1) / 2;
		n2 = n1 - 1;
	}
	c1 = c.substr(0, n1);
	c2 = c.substr(n1, n);

	if (c2.size() % 2 != 0 && c2.size() > 2)
	{
		agregarCerosDelante(c2, 1);
	}
	if (c1.size() % 2 != 0 && c1.size() > 2)
	{
		agregarCerosDelante(c1, 1);
	}
}

void agregarCerosFinal(string &c, int nCeros)
{
	c.append(nCeros, '0');
}

void agregarCerosDelante(string &c, int nCeros)
{
	string aux = "";
	aux.append(nCeros, '0');
	aux.append(c);
	c = aux;
}

void quitarCerosNoSignificativos(string &c)
{

	std::size_t found = c.find_first_not_of("0");

	if (found > 0 && found < 100)
	{
		c = c.substr(found, c.length());
	}

}
string multiplicarPotencia10(string c, int potencia)
{
	string aux = c;
	agregarCerosFinal(aux, potencia);
	return aux;
}
