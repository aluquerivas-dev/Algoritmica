#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "ClaseTiempo.cpp"
#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_
struct datos {
	double n;
	double t;
	double e;
	double nmod;
};
int menu();
void CombinatorioRecursividadTabla();
void CombinatorioRecursividad();
void CombinatorioIterativo();
void TorresHanoi();
void mainHanoiVisual();
double sumatorio(std::vector<datos> &v, int a, int b);
void rellenarVector(std::vector<int> &v, int max);
void exportarDatos(std::vector<datos> &v, int opt, std::vector < std::vector < double > > &X);
double coeficienteCorrelacion(std::vector<datos> &v);
double media(std::vector<datos> &v);
void calculoTiempo(int opt, std::vector < std::vector < double > > &X);
std::string porcentaje(float x);
void imprime( int *tab, int fil, int col, int ultNum );
void mueveDisco( int *tab, int fil, int col, int ultNum, int filOrig, int filDest );
void hanoi_visual( int *tab, int fil, int col, int disc, int ultNum, int O, int A, int D );
void formato_fecha(double dias);
#endif

