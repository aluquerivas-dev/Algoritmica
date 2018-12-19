#ifndef _SISTEMAMONETARIO_HPP_
#define _SISTEMAMONETARIO_HPP_
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <vector>
#include <unistd.h>
#include <limits.h>
#include <algorithm>
#include "macros.hpp"
#include "dinero.hpp"
using namespace std;
class SistemaMonetario
{
private:
	vector<Dinero> _d;
	vector<vector<int> > _tabla;
	int _cambio;
public:
	SistemaMonetario(int x) {_cambio = x;};
	void mostrarSistemaMonetario();
	void obtenerSolucion();
	inline int getCambio() const {return _cambio;};
	inline void setDinero();
	void setTablaDinero();
	inline void addMonedaVector(Dinero &dinero) {_d.push_back(dinero);}
	inline void start()
	{
		setTablaDinero();
		obtenerSolucion();
		getchar();
		getchar();
	}
};
inline SistemaMonetario &operator<<(SistemaMonetario &sistema, const string &fichero)
{
	ifstream f(fichero, ios::in);
	int valor;
	string tipo;
	if (f.good())
	{
		while (f >> valor >> tipo)
		{
			Dinero aux;

			aux.setValor(valor);
			aux.setTipo(tipo);

			sistema.addMonedaVector(aux);
		}
	}
	else
	{
		cout << "Error al abrir fichero\n";
	}
	return sistema;
}
#endif