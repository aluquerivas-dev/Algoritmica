#ifndef _DINERO_HPP_
#define _DINERO_HPP_
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <vector>
#include <unistd.h>
#include "macros.hpp"
using namespace std;
class Dinero
{
private:
	int _valor;
	string _tipo;
	int _cantidadUsada = 0;
public:
	inline int getValor() {return _valor;};
	inline string getTipo() {return _tipo;};
	inline int getCantidadUsada() {return _cantidadUsada;};
	inline void setCantidadUsada(int x) {_cantidadUsada = x;};
	inline void setValor(int x) {_valor = x;};
	inline void setTipo(string x) {_tipo = x;};

};
#endif