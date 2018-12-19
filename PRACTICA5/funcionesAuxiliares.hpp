/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 3
  \author
  \date
*/

#ifndef _FuncionesAuxiliares_HPP_
#define _FuncionesAuxiliares_HPP_
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include "funcionesAuxiliares.hpp"
#include "macros.hpp"
#include "mochila.hpp"
#include <time.h>
#include "ClaseTiempo.cpp"
struct datos
{
	double n;
	double t;
	double e;
	double nmod;
};
//#include "sistemaEcuaciones.hpp"

/**
 * @brief      Muestra el menu de usuario, para que pueda ejecutar una serie de opciones.
 *
 * @return     opcion La opcion elegida por el usuario.
 */
int menu();

void mochila();

void cambio();
void tiempo_mochila();
std::string porcentaje(float x);
double sumatorio(std::vector<datos> &v, int a, int b);
void exportarDatos(std::vector<datos> &v, int opt, std::vector < std::vector < double > > &X);
double coeficienteCorrelacion(std::vector<datos> &v);
void calculoTiempo(int opt, std::vector < std::vector < double > > &X);
void formato_fecha(double dias);
double media(std::vector<double> &v);
#endif