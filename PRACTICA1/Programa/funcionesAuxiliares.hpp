#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "ordenacion.hpp"
#include "ClaseTiempo.cpp"
#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_
struct datos {
	double n;
	double t;
	double e;
};
	int menu();
	void ordenacionInsercionBinaria();
	void ordenacionInsercionShell();
	double sumatorio(std::vector<datos> &v,int a,int b);
	void rellenarVector(std::vector<int> &v, int max);
	void exportarDatos(std::vector<datos> &v, int opt,std::vector < std::vector < double > > &X);
	double coeficienteCorrelacion(std::vector<datos> &v);
	void calculoTiempo(int opt, std::vector < std::vector < double > > &X);
#endif

