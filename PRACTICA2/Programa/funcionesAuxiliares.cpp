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
#include "combinatoria.hpp"
#include "sistemaEcuaciones.hpp"
std::string porcentaje(float x)
{
	std::string cadena = "";
	int r = round(x);
	for (int i = 0; i < r; ++i) {
		cadena += "#";
	}
	return cadena;
}
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
	std::cout << "[1] Numero Combinatorio Recursividad." << std::endl;
	PLACE(posicion++, 10);
	std::cout << "[2] Numero Combinatorio Recursividad - Tabla. " << std::endl;
	PLACE(posicion++, 10);
	std::cout << "[3] Numero Combinatorio Iterativo. " << std::endl;
	PLACE(posicion++, 10);
	std::cout << "[4] Torres de Hanoi. " << std::endl;
	PLACE(posicion++, 10);
	std::cout << "[5] Torres de Hanoi Visual. " << std::endl;
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
void CombinatorioRecursividad()
{
	int nmin, nmax;
	float rep;
	std::vector<datos> vector_tiempos;
	datos T;
	T.t = 0;
	Clock time;
	double ms;
	cout << " nCk " << RESET << endl;
	cout << "Ingrese el n(min): " << endl;
	cin >> nmin;
	cout << "Ingrese el n:(max)" << endl;
	cin >> nmax;
	cout << "Ingrese las Repeticiones:" << endl;
	cin >> rep;
	int x;
	float percent =  100.0 / (nmax - nmin);
	float aux = 0.0;
	for (int i = nmin; i <= nmax; ++i) {
		for (x = 0; x <= rep; ++x) {
			for (int j = 1; j <= i; ++j) {
				//Invocamos medir tiempo
				time.start();
				//Aqui Hacemos la combinatoria
				comb_normal(i, j);
				//
				if (time.isStarted()) {
					time.stop();
					ms = time.elapsed();
					T.t = T.t + ms;
				}
			}
		}
		system("clear");
		cout << "[" << porcentaje(aux) << "]  " << aux << "% Completado\n";
		aux = aux + percent;
		T.t = T.t / x;
		T.n = i;
		T.nmod = pow(2, i);
		vector_tiempos.push_back(T);
		T.t = 0;
	}
	//MINIMOS CUADRADOS
	std::vector < std::vector < double > > _matrizCoeficientes;
	std::vector < std::vector < double > > _matrizIndependientes;
	std::vector < std::vector < double > > _matrizSoluciones;
	_matrizCoeficientes = std::vector< std::vector< double > >(2, std::vector< double >(2));
	_matrizIndependientes = std::vector< std::vector< double > >(2, std::vector< double >(1));
	_matrizSoluciones = std::vector< std::vector< double > >(2, std::vector< double >(1));
	//Reserva de memoria para las matrizes
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			_matrizCoeficientes[i][j] = sumatorio(vector_tiempos, i + j, 0);
		}
	}
	for (int i = 0; i < 2; i++) {
		_matrizIndependientes[i][0] = sumatorio(vector_tiempos, i, 1);
	}
	resolverSistemaEcuaciones(_matrizCoeficientes, _matrizIndependientes, 2, _matrizSoluciones);
	exportarDatos(vector_tiempos, 1, _matrizSoluciones); //Exporta a fichero
	system("./ejemplo_gnuplot.sh");
	getchar();
}

void CombinatorioRecursividadTabla()
{
	int nmin, nmax;
	float rep;
	std::vector<datos> vector_tiempos;
	std::vector<data> data;
	datos T;
	T.t = 0;
	Clock time;
	double ms;
	cout << " nCk " << RESET << endl;
	cout << "Ingrese el n(min): " << endl;
	cin >> nmin;
	cout << "Ingrese el n:(max)" << endl;
	cin >> nmax;
	cout << "Ingrese las Repeticiones:" << endl;
	cin >> rep;
	int x;
	float percent =  100.0 / (nmax - nmin);
	float aux = 0.0;
	for (int i = nmin; i <= nmax; ++i) {
		for (x = 0; x <= rep; ++x) {
			for (int j = 1; j <= i; ++j) {
				//Invocamos medir tiempo
				time.start();
				//Aqui Hacemos la combinatoria
				comb_tabla(i, j, data);
				//
				if (time.isStarted()) {
					time.stop();
					ms = time.elapsed();
					T.t = T.t + ms;
				}
			}
			data.clear();
		}
		system("clear");
		cout << "[" << porcentaje(aux) << "]  " << aux << "% Completado\n";
		aux = aux + percent;
		T.t = T.t / x;
		T.n = i;
		T.nmod = i;
		vector_tiempos.push_back(T);
		T.t = 0;
	}
	//MINIMOS CUADRADOS
	std::vector < std::vector < double > > _matrizCoeficientes;
	std::vector < std::vector < double > > _matrizIndependientes;
	std::vector < std::vector < double > > _matrizSoluciones;
	_matrizCoeficientes = std::vector< std::vector< double > >(3, std::vector< double >(3));
	_matrizIndependientes = std::vector< std::vector< double > >(3, std::vector< double >(1));
	_matrizSoluciones = std::vector< std::vector< double > >(3, std::vector< double >(1));
	//Reserva de memoria para las matrizes
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			_matrizCoeficientes[i][j] = sumatorio(vector_tiempos, i + j, 0);
		}
	}
	for (int i = 0; i < 3; i++) {
		_matrizIndependientes[i][0] = sumatorio(vector_tiempos, i, 1);
	}
	resolverSistemaEcuaciones(_matrizCoeficientes, _matrizIndependientes, 3, _matrizSoluciones);
	exportarDatos(vector_tiempos, 2, _matrizSoluciones); //Exporta a fichero
	system("./ejemplo_gnuplot.sh");
	//system("./grafico.eps");
	getchar();
}

void CombinatorioIterativo()
{
	int nmin, nmax;
	float rep;
	std::vector<datos> vector_tiempos;
	datos T;
	T.t = 0;
	Clock time;
	double ms;
	cout << " nCk " << RESET << endl;
	cout << "Ingrese el n(min): " << endl;
	cin >> nmin;
	cout << "Ingrese el n:(max)" << endl;
	cin >> nmax;
	cout << "Ingrese las Repeticiones:" << endl;
	cin >> rep;
	int x = 0;
	float percent =  100.0 / (nmax - nmin);
	float aux = 0.0;
	for (int i = nmin; i <= nmax; ++i) {
		for (x = 0; x <= rep; ++x) {
			for (int j = 1; j <= i; ++j) {
				//Invocamos medir tiempo
				time.start();
				//Aqui Hacemos la combinatoria
				comb_iterativo(i, j);
				//
				if (time.isStarted()) {
					time.stop();
					ms = time.elapsed();
					T.t = T.t + ms;
				}
			}
		}
		system("clear");
		cout << "[" << porcentaje(aux) << "]  " << aux << "% Completado\n";
		aux = aux + percent;
		T.t = T.t / x;
		T.n = i;
		T.nmod = i;
		vector_tiempos.push_back(T);
		T.t = 0;
	}
	//MINIMOS CUADRADOS
	std::vector < std::vector < double > > _matrizCoeficientes;
	std::vector < std::vector < double > > _matrizIndependientes;
	std::vector < std::vector < double > > _matrizSoluciones;
	_matrizCoeficientes = std::vector< std::vector< double > >(3, std::vector< double >(3));
	_matrizIndependientes = std::vector< std::vector< double > >(3, std::vector< double >(1));
	_matrizSoluciones = std::vector< std::vector< double > >(3, std::vector< double >(1));
	//Reserva de memoria para las matrizes
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			_matrizCoeficientes[i][j] = sumatorio(vector_tiempos, i + j, 0);
		}
	}
	for (int i = 0; i < 3; i++) {
		_matrizIndependientes[i][0] = sumatorio(vector_tiempos, i, 1);
	}
	resolverSistemaEcuaciones(_matrizCoeficientes, _matrizIndependientes, 3, _matrizSoluciones);
	exportarDatos(vector_tiempos, 3, _matrizSoluciones); //Exporta a fichero
	system("./ejemplo_gnuplot.sh");
	getchar();
}

void TorresHanoi()
{
	int nmin, nmax;
	float rep;
	std::vector<datos> vector_tiempos;
	datos T;
	T.t = 0;
	Clock time;
	double ms;
	cout << " nCk " << RESET << endl;
	cout << "Ingrese el n(min): " << endl;
	cin >> nmin;
	cout << "Ingrese el n:(max)" << endl;
	cin >> nmax;
	cout << "Ingrese las Repeticiones:" << endl;
	cin >> rep;
	int x;
	float percent =  100.0 / (nmax - nmin);
	float aux = 0.0;
	for (int i = nmin; i <= nmax; ++i) {
		for (x = 0; x <= rep; ++x) {
			//Invocamos medir tiempo
			time.start();
			//Aqui Hacemos la combinatoria
			hanoi(i);
			//
			if (time.isStarted()) {
				time.stop();
				ms = time.elapsed();
				T.t = T.t + ms;
			}
		}
		system("clear");
		cout << "[" << porcentaje(aux) << "]  " << aux << "% Completado\n";
		aux = aux + percent;
		T.t = T.t / x;
		T.n = i;
		T.nmod = pow(2, i);
		vector_tiempos.push_back(T);
		T.t = 0;
	}
	//MINIMOS CUADRADOS
	std::vector < std::vector < double > > _matrizCoeficientes;
	std::vector < std::vector < double > > _matrizIndependientes;
	std::vector < std::vector < double > > _matrizSoluciones;
	_matrizCoeficientes = std::vector< std::vector< double > >(2, std::vector< double >(2));
	_matrizIndependientes = std::vector< std::vector< double > >(2, std::vector< double >(1));
	_matrizSoluciones = std::vector< std::vector< double > >(2, std::vector< double >(1));
	//Reserva de memoria para las matrizes
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			_matrizCoeficientes[i][j] = sumatorio(vector_tiempos, i + j, 0);
		}
	}
	for (int i = 0; i < 2; i++) {
		_matrizIndependientes[i][0] = sumatorio(vector_tiempos, i, 1);
	}
	resolverSistemaEcuaciones(_matrizCoeficientes, _matrizIndependientes, 2, _matrizSoluciones);
	exportarDatos(vector_tiempos, 4, _matrizSoluciones); //Exporta a fichero
	system("./ejemplo_gnuplot.sh");
	getchar();
}
void imprime( int *tab, int fil, int col, int ultNum )
{
	int f, c;
	int i, esp;
	for ( c = col - 1; c >= 0; c-- ) {
		for ( f = 0; f < fil; f++ ) {
			esp = ( ultNum - tab[col * f + c] ) / 2;
// Espacios a la izquierda
			for ( i = 0; i < esp; i++ )
				printf( " " );
// Imprime los comodines
			for ( i = 0; i < tab[col * f + c]; i++ )
				printf( "*" );
// Espacios a la derecha
			for ( i = 0; i < esp; i++ )
				printf( " " );
			printf( "\t" );
		};
		printf( "\n" );
	};
};


void mueveDisco( int *tab, int fil, int col, int ultNum, int filOrig, int filDest )
{
	int cO = col - 1, cD = col - 1;
// Se busca el disco que se encuentre mas arriba y por lo tanto el mas pequeño de la fila de origen.
	while ( cO >= 0  &&  tab[col * filOrig + cO] == 0 ) {
		cO--;
	};
	if ( cO < 0 )
		cO = 0;
// Ahora se calcula cual es la posición libre mas arriba de la fila de destino
	while ( cD >= 0  &&  tab[col * filDest + cD] == 0 ) {
		cD--;
	};
// Se mueve el disco de la fila de origen a la de destino:
	tab[col * filDest + cD + 1] = tab[col * filOrig + cO];
	tab[col * filOrig + cO] = 0;
// Se imprime el tablero:
	imprime( tab, fil, col, ultNum );
};


void hanoi_visual( int *tab, int fil, int col, int disc, int ultNum, int O, int A, int D )
{
	if ( disc == 1 ) {
// Se borra la pantalla, se imprime la tabla y se hace una pausa que varia dependiendo del numero de discos:
		system("clear");
		mueveDisco( tab, fil, col, ultNum, O, D );
		if (col <= 5) system("sleep 0.8"); else if (col <= 10) system("sleep 0.3"); else if (col <= 15) system("sleep 0.06"); else if (col > 15) system("sleep 0.02");
	} else {
		hanoi_visual( tab, fil, col, disc - 1, ultNum, O, D, A );
		system("clear");
		mueveDisco( tab, fil, col, ultNum, O, D );
		if (col <= 5) system("sleep 0.8"); else if (col <= 10) system("sleep 0.3"); else if (col <= 15) system("sleep 0.06"); else if (col > 15) system("sleep 0.02");
		hanoi_visual( tab, fil, col, disc - 1, ultNum, A, O, D );
	};
};
void mainHanoiVisual()
{
	int fil = 3, col, *tablero = NULL;
	int f, c, disc = 1, ultNum;
	cout << RESET << "Indique el numero de discos: ";
	cin >> col;
	tablero = (int *)malloc( sizeof(int) * fil * col );
// Resetea las torres poniendo "los discos" en una de ellas y 0 en el resto.
	for ( f = 0; f < fil; f++ )
		for ( c = col - 1; c >= 0; c-- )
			if ( f == 0 ) {
				tablero[col * f + c] = disc;
				disc += 2;
			} else
				tablero[col * f + c] = 0;
	ultNum = disc;
// Se imprime el tablero antes de iniciar ningún movimiento:
	system("clear");
	imprime( tablero, fil, col, ultNum );
	system("sleep 0.2");
// Se llama a hanoi para comenzar "la partida":
	hanoi_visual( tablero, fil, col, col, ultNum, 0, 1, 2 );
}


double sumatorio(std::vector<datos> &v, int a, int b)
{
	double resultado = 0;
	for (int i = 0; i < (int)v.size(); i++) {
		resultado += (pow(v[i].nmod, a)) * (pow(v[i].t, b));
	}
	return resultado;
}

void rellenarVector(std::vector<int> &v, int max)
{
	for (int i = 0; i < max; ++i) {
		v.push_back(1 + rand() % (10000 - 1));
	}
}

double media(std::vector<double> &v)
{
	double m = 0;
	for (int i = 0; i < (int)v.size(); i++) {
		m += v[i];
	}
	m /= (int)v.size();
	return m;
}

double coeficienteCorrelacion(std::vector<datos> &v)
{
	double mt, me, st, se, ste, denom, r;
	/* Calcula la media de las dos series x[], y[] */
	///Vectores para la media
	std::vector<double> v_t;
	std::vector<double> v_e;
	for (int i = 0; i < (int)v.size(); ++i) {
		v_t.push_back(v[i].t);
		v_e.push_back(v[i].e);
	}
	///
	mt = media(v_t);
	me = media(v_e);
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
void exportarDatos(std::vector<datos> &v, int opt, std::vector < std::vector < double > > &X)
{
	//a0 X[0][0]
	//a1 X[1][0]
	//a2 X[2][0]
	string cadena;
	if (opt == 1) { //RECURSIVIDADNORMAL
		cadena = "Datos1.txt";
		cout << "La ecuacion del ajuste exponencial es: " << X[1][0] << "*2^n + " << X[0][0] << " \n";
	} else if (opt == 2) {//RECURSIVIDADTABLA
		cadena = "Datos2.txt";
		cout << "La ecuacion del ajuste cuadratico es: " << X[2][0] << "*n^2 + " << X[1][0] << "n + " << X[0][0] << " \n";
	} else if (opt == 3) {
		cout << "La ecuacion del ajuste cuadratico es: " << X[1][0] << "*n + " << X[0][0] << " \n";
		cadena = "Datos3.txt";
	} else if (opt == 4) {
		cout << "La ecuacion del ajuste exponencial es: " << X[1][0] << "2*^n + " << X[0][0] << " \n";
		cadena = "Datos4.txt";
	}
	std::ofstream fs(cadena.c_str());
	for (int i = 0; i < (int)v.size(); i++) {
		if (opt == 1) {
			v[i].e = X[0][0] + X[1][0] * pow(2, v[i].n);
		} else if (opt == 2) {
			v[i].e = X[0][0] + X[1][0] * v[i].n + X[2][0] * pow(v[i].n, 2);
		} else if (opt == 3) {
			v[i].e = X[0][0] + X[1][0] * v[i].n + X[2][0] * pow(v[i].n, 2);
		} else if (opt == 4) {
			v[i].e = X[0][0] + X[1][0] * pow(2, v[i].n);
		}
		fs << v[i].n << "\t" << v[i].t << "\t" << v[i].e << std::endl;
	}
	fs.close();
	cout << "El coeficiente de correlacion es: " << coeficienteCorrelacion(v) << "\n";
	getchar();
	getchar();
	calculoTiempo(opt, X);
}

void formato_fecha(double ms){
	double anio=0;
	double dias=0;
	double horas=0;
	double aux=0;
	double minutos=0;
	double segundos=0;
	double valor = 1;

	anio = (pow(10,-6)*ms)/(86400*365);
	aux = fmod(anio,365);//Dias que sobran de los años
	dias=aux;
 	aux = std::fmod(dias,24);//Horas que sobran de los años
	horas = aux;//Dias que sobran de los años
	aux = std::fmod(dias,60);//Minutos que sobran de los años
	minutos=aux;
	aux = std::fmod(dias,60);//Segundos que sobran de los años
	segundos=aux;
				//////
	cout << "\n Años: " << (int)anio<<endl <<  " Dias: " << (int)dias<<endl <<  " Horas: " << (int)horas<<endl <<  " Minutos:" << (int)minutos<<endl <<  " Segundos: " << (int)segundos<<endl << "\n";


}
void calculoTiempo(int opt, std::vector < std::vector < double > > &X)
{	
	double valor = 1;
	double res = 0.0;
	while (valor != 0) {
		system("clear");
		if (opt == 1) {
			cout << "La ecuacion del ajuste exponencial es: " << X[1][0] << "*2^n + " << X[0][0] << " \n";
			cout << "0-Para salir , Introduce un tamaño de elementos para calcular su tiempo estimado: ";
			cin >> valor;
			if (valor != 0) {
				cout << "El tiempo estimado en microsegundos  seria de:";
				res = X[0][0] + X[1][0] * pow(2, valor) ;
				cout <<res<<endl;
				formato_fecha(res);
				getchar();
				getchar();
			}
		} else if (opt == 2) {
			cout << "La ecuacion del ajuste polinomico es: " << X[2][0] << "*n^2 + " << X[1][0] << "n + " << X[0][0] << " \n";
			cout << "0-Para salir , Introduce un tamaño de elementos para calcular su tiempo estimado: ";
			cin >> valor;
			if (valor != 0) {
				cout << "El tiempo estimado en microsegundos  seria de:";
				res = X[0][0] + X[1][0] * valor + X[2][0] * pow(valor, 2);
				cout <<res<<endl;
				formato_fecha(res);
				getchar();
				getchar();
			}
		} else if (opt == 3) {
			cout << "La ecuacion del ajuste polinomico es:" << X[1][0] << "*n + " << X[0][0] << " \n";
			cout << "0-Para salir , Introduce un tamaño de elementos para calcular su tiempo estimado: ";
			cin >> valor;
			if (valor != 0) {
				cout << "El tiempo estimado en microsegundos  seria de:";
				res = X[0][0] + X[1][0] * valor + X[2][0] * pow(valor, 2);
				cout<<res<<endl;
				formato_fecha(res);
				getchar();
				getchar();
			}
		} else if (opt == 4) {
			cout << "La ecuacion del ajuste exponencial es: " << X[1][0] << "*2^n + " << X[0][0] << " \n";
			cout << "0-Para salir , Introduce un tamaño de elementos para calcular su tiempo estimado: ";
			cin >> valor;
			if (valor != 0) {
				cout << "El tiempo estimado en microsegundos  seria de:";
				res = X[0][0] + X[1][0] * pow(2, valor) ;
				cout<<res<<endl;
				formato_fecha(res);
				getchar();
				getchar();
			}
		}
	}
}
