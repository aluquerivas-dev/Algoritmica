/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 1
  \author
  \date
*/

#include <iostream>
#include <string>

#include "funcionesAuxiliares.hpp"

#include "macros.hpp"
#include "ordenacion.hpp"
#include "sistemaEcuaciones.hpp"
Ordenacion ordena;
int menu()
{

	int opcion, posicion;

	// Se muestran las opciones del menú
	posicion = 2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(posicion++, 10);
	std::cout << BIBLUE;
	std::cout << "Programa principal | Opciones del menú | Alumno:31018546X   ";
	std::cout << RESET;

	posicion++;
	PLACE(posicion++, 10);
	std::cout << "[1] Método de inserción binaria." << std::endl;


	PLACE(posicion++, 10);
	std::cout << "[2] Método Shell. " << std::endl;

	posicion++;
	PLACE(posicion++, 10);
	std::cout << BIRED << "[0] Fin del programa" << RESET << std::endl;

	posicion++;
	PLACE(posicion++, 20);
	std::cout << BIYELLOW;
	std::cout << "Opción: ";
	std::cout << RESET;
	std::cin >> opcion;

	// Se elimina el salto de línea del flujo de entrada
	std::cin.ignore();

	return opcion;
}

void ordenacionInsercionBinaria() {

	int minimo, maximo, incremento, repeticion;
	std::cout << RESET;
	std::cout << "Introduce el valor minimo de elementos del vector.\n";
	std::cin >> minimo;
	std::cout << "Introduce el valor maximo de elementos del vector.\n";
	std::cin >> maximo;
	std::cout << "Introduce el valor del incremento del vector.\n";
	std::cin >> incremento;
	std::cout << "Introduce el valor de repetición.\n";
	std::cin >> repeticion;

	std::vector<int> vector;
	std::vector<datos> vector_tiempos;
	datos T;
	T.t=0;
	Clock time;
	double ms;

	for (int i = minimo; i <= maximo; i = i + incremento)
	{
		for (int j = 0; j < repeticion; ++j)//For de repeticiones
		{
			vector.clear();
			rellenarVector(vector, i);

			//Invocamos medir tiempo
			time.start();

			//Aqui ordenamos
			ordena.insercionBinaria(vector, i);
			//
			if (time.isStarted())
			{
				time.stop();
				ms = time.elapsed();
				T.t = T.t + ms;
			}
			//assert(ordena.estaOrdenado(vector));
			//std::cout<<"Elementos del vector:"<<i<<" \n -->Repeticion:"<<j<<" \n -->Tiempo:"<<ms<<"\n";

			//Terminamos medir tiempo

		}
		T.t = T.t /repeticion;
		T.n = i;
		vector_tiempos.push_back(T);
		T.t=0;

	}
	getchar();
	//MINIMOS CUADRADOS
	std::vector < std::vector < double > > _matrizCoeficientes;
	std::vector < std::vector < double > > _matrizIndependientes;
	std::vector < std::vector < double > > _matrizSoluciones;

	_matrizCoeficientes = std::vector< std::vector< double > >(3, std::vector< double >(3));
	_matrizIndependientes = std::vector< std::vector< double > >(3, std::vector< double >(1));
	_matrizSoluciones = std::vector< std::vector< double > >(3, std::vector< double >(1));

	//Reserva de memoria para las matrizes


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			_matrizCoeficientes[i][j] = sumatorio(vector_tiempos, i + j, 0);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		_matrizIndependientes[i][0] = sumatorio(vector_tiempos, i, 1);
	}
	
	resolverSistemaEcuaciones(_matrizCoeficientes, _matrizIndependientes, 3, _matrizSoluciones);
	
	exportarDatos(vector_tiempos, 0, _matrizSoluciones); //Exporta a fichero

	system("./ejemplo_gnuplot.sh");
	system("./grafico.eps");

}

void ordenacionInsercionShell() {

	int minimo, maximo, incremento, repeticion;
	std::cout << RESET;
	std::cout << "Introduce el valor minimo de elementos del vector.\n";
	std::cin >> minimo;
	std::cout << "Introduce el valor maximo de elementos del vector.\n";
	std::cin >> maximo;
	std::cout << "Introduce el valor del incremento del vector.\n";
	std::cin >> incremento;
	std::cout << "Introduce el valor de repetición.\n";
	std::cin >> repeticion;

	std::vector<int> vector;
	std::vector<datos> vector_tiempos;
	datos T;
	T.t=0;
	Clock time;
	double ms;
	for (int i = minimo; i <= maximo; i = i + incremento)
	{
		for (int j = 0; j < repeticion; ++j)//For de repeticiones
		{
			vector.clear();
			rellenarVector(vector, i);

			//Invocamos medir tiempo
			time.start();

			//Aqui ordenamos
			ordena.insercionShell(vector, i);
			//
			if (time.isStarted())
			{
				time.stop();
				ms = time.elapsed();
				T.t = T.t + ms;

			}


			assert(ordena.estaOrdenado(vector));

			//Terminamos medir tiempo

		}
		T.t = T.t / repeticion;
		T.n = i;
		vector_tiempos.push_back(T);
		T.t=0;
	}
	getchar();
	//MINIMOS CUADRADOS


	std::vector < std::vector < double > > _matrizCoeficientes;
	std::vector < std::vector < double > > _matrizIndependientes;
	std::vector < std::vector < double > > _matrizSoluciones;

	_matrizCoeficientes = std::vector< std::vector< double > >(2, std::vector< double >(2));
	_matrizIndependientes = std::vector< std::vector< double > >(2, std::vector< double >(1));
	_matrizSoluciones = std::vector< std::vector< double > >(2, std::vector< double >(1));

	//Reserva de memoria para las matrizes


	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			_matrizCoeficientes[i][j] = sumatorio(vector_tiempos, i + j, 0);
		}
	}

	for (int i = 0; i < 2; i++)
	{
		_matrizIndependientes[i][0] = sumatorio(vector_tiempos, i, 1);
	}
	
	resolverSistemaEcuaciones(_matrizCoeficientes, _matrizIndependientes, 2, _matrizSoluciones);

	exportarDatos(vector_tiempos, 1, _matrizSoluciones); //Exporta a fichero

	system("./ejemplo_gnuplot.sh");
	system("./grafico.eps");
}



double sumatorio(std::vector<datos> &v, int a, int b)
{
	double resultado = 0;

	for (int i = 0; i < (int)v.size(); i++)
	{
		resultado += (pow(v[i].n, a)) * (pow(v[i].t, b));
	}
	return resultado;
}

void rellenarVector(std::vector<int> &v, int max) {

	for (int i = 0; i < max; ++i)
	{

		v.push_back(1 + rand() % (10000 - 1));
	}

}

double coeficienteCorrelacion(std::vector<datos> &v) {
	double mt, me, st, se, ste, denom, r;

	/* Calcula la media de las dos series x[], y[] */

	mt = 0;
	me = 0;

	for (int i = 0; i < (int)v.size(); i++) {

		mt += v[i].t;
		me += v[i].e;

	}

	mt /= (int)v.size();
	me /= (int)v.size();

	/*Calcula el denominador */

	st = 0;
	se = 0;

	for (int i = 0; i < (int)v.size(); i++) {

		st += (v[i].t - mt) * (v[i].t - mt);
		se += (v[i].e - me) * (v[i].e - me);

	}

	denom = sqrt (st * se);

	/* Calcula la correlación de las series */


	ste = 0;

	for (int i = 0; i < (int)v.size(); i++) {

		ste += (v[i].t - mt) * (v[i].e - me);

	}

	r = ste / denom;

	return r;
}
void exportarDatos(std::vector<datos> &v, int opt, std::vector < std::vector < double > > &X) {

	//a0 X[0][0]
	//a1 X[1][0]
	//a2 X[2][0]
	string cadena;
	if (opt == 0)
	{
		cadena="Datos1.txt";
		cout << "La ecuacion del ajuste polinomico es: " << X[2][0] << "n^2 + " << X[1][0] << "n + " << X[0][0] << " \n";
	} else if (opt == 1) {
		cadena="Datos2.txt";
		cout << "La ecuacion del ajuste polinomico es: " << X[0][0] << "+" << X[1][0] << "*n*log(n)\n";
	}

	
	std::ofstream fs(cadena.c_str());

	for (int i = 0; i < (int)v.size(); i++)
	{
		if (opt == 0)
		{
			v[i].e = X[0][0] + X[1][0] * v[i].n + X[2][0] * pow(v[i].n, 2);
		}
		else if (opt == 1) {

			v[i].e = X[0][0] + X[1][0] * v[i].n;
		}



		fs << v[i].n << "\t" << v[i].t << "\t" << v[i].e << std::endl;
	}

	fs.close();

	cout<<"El coeficiente de correlacion es: "<<coeficienteCorrelacion(v)<<"\n";
	getchar();
	calculoTiempo(opt,X);

}
void calculoTiempo(int opt, std::vector < std::vector < double > > &X){
	double valor=1;
	double res=0.0;
	while(valor!=0){
		system("clear");
		if (opt == 0)
		{
			cout << "La ecuacion del ajuste polinomico es: " << X[2][0] << "n^2 + " << X[1][0] << "n + " << X[0][0] << " \n";
			cout<<"0-Para salir , Introduce un tamaño de elementos para calcular su tiempo estimado: ";
			cin>>valor;
			if (valor!=0)
			{
				cout<<"El tiempo estimado en microsegundos  seria de:";
				res = X[0][0] + X[1][0] * valor + X[2][0] * pow(valor, 2);
				cout<<res<<" , en dias seria: "<<(pow(10,-6)*res)/86400<<"\n";
				getchar();
				getchar();
			}
			
		}
		else if (opt == 1) {

			cout << "La ecuacion del ajuste polinomico es: " << X[0][0] << "+" << X[1][0] << "*n*log(n)\n";
			cout<<"0-Para salir , Introduce un tamaño de elementos para calcular su tiempo estimado: ";
			cin>>valor;
			if (valor!=0)
			{
				cout<<"El tiempo estimado en microsegundos  seria de:";
				res= X[0][0] + X[1][0] * valor * log(valor);
				cout<<res<<" , en dias seria: "<<(pow(10,-6)*res)/86400<<"\n";
				getchar();
				getchar();
			}
			
		}

	}
	

}