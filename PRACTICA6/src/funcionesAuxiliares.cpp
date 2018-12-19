#include "funcionesAuxiliares.hpp"
#include "sistemaEcuaciones.hpp"
#include "estadistica.hpp"
#include <dirent.h>
int menu()
{
	srand(time(0));
	int opcion;
	int posicion;
	// Se muestran las opciones del menú
	posicion = 2;
	// Se borra la pantallainicializarInversa
	std::cout << CLEAR_SCREEN;
	PLACE(1, 10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;
	//////////////////////////////////////////////////////////////////////////////
	posicion++;
	PLACE(posicion++, 10);
	std::cout <<  "[1] N Reinas Backtracking";
	PLACE(posicion++, 10);
	std::cout <<  "[2] N Reinas Las Vegas";
	PLACE(posicion++, 10);
	std::cout <<  "[3] Dictar Directorio N Reinas con algoritmo de Backtracking";
	PLACE(posicion++, 10);
	std::cout <<  "[4] Dictar Directorio N Reinas con algoritmo de Las Vegas";
	PLACE(posicion++, 10);
	std::cout <<  "[5] Laboratorio de prueba - Algoritmo de Las Vegas";
	PLACE(posicion++, 10);
	std::cout <<  "[6] Laboratorio de prueba - Algoritmo de Backtracking";
	PLACE(posicion++, 10);
	std::cout <<  "[7] Comparacion de Algoritmos";
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

void reinasBacktracking()
{
	int reinas_n;
	int opt;
	std::cout << "Numero de reinas: \n";
	std::cin >> reinas_n;
	Reinas r(reinas_n);
	std::cout << "Cuantas soluciones: \n";
	std::cout << "  (1) Todas las soluciones: \n";
	std::cout << "  (2) Solo una: \n";
	std::cin >> opt;
	switch (opt)
	{
	case 1:
		r.startReinasBacktracking(false);//Solucion completa.
		break;
	case 2:
		opt = 2;
		r.startReinasBacktracking(true);//Solucion unica.
		break;
	default:
		std::cout << "No es valido \n";
		break;
	}
	std::cout << "TERMINE CON " << r.getNumSol() << " SOLUCIONES.\n";
	getchar();
}

void reinasVegas()
{
	int reinas_n;
	int opt;
	std::cout << "Numero de reinas: \n";
	std::cin >> reinas_n;
	Reinas r(reinas_n);
	r.startReinasVegas(0);
	getchar();
}
void listar_dir(int opcion)
{
	std::vector<string> _dir_;
	DIR * directorio;
	struct dirent * elemento;
	string elem, dir;
	int c = 1;
	if (opcion == 1)   //Backtracking
	{
		dir = "../exports/backtrackingQueen/";
	}
	else if (opcion == 2)     //Las vegas
	{
		dir = "../exports/vegasQueen/";
	}
	std::cout << BRED << "Directorio leido: " << BYELLOW << dir << RESET << "\n\n";
	if (directorio = opendir(dir.c_str()))
	{
		while (elemento = readdir(directorio))
		{
			elem = elemento->d_name;
			if (elem != "." && elem != "..")
			{
				if (c % 2 == 0)
				{
					cout << BGREEN << "(" << c << ") " << elem << RESET << endl;
				}
				else
				{
					cout << BWHITE << "(" << c << ") " << elem << RESET << endl;
				}
				_dir_.push_back(elem);
				c++;
			}
		}
	}
	closedir(directorio);
	int op = 0;
	std::cout << "Introduce el fichero a abrir(0-Salir): ";
	std::cin >> op;
	if (op != 0 && op > 0 && op <= _dir_.size())
	{
		string fichero = _dir_[op - 1];
		std::string cad;
		if (opcion == 1)   //Backtracking
		{
			cad = "gedit ../exports/backtrackingQueen/" + fichero + " &";
		}
		else if (opcion == 2)     //Las vegas
		{
			cad = "gedit ../exports/vegasQueen/" + fichero + " &";
		}
		std::cout << cad << "\n";
		system(cad.c_str());
		getchar();

	}

}
void laboratorio_vegas()
{
	int reinas_n;
	std::cout << "Numero de reinas: \n";
	std::cin >> reinas_n;
	Reinas r(reinas_n);
	r.startReinasVegas(1);
	getchar();

}
void laboratorio_backtracking()
{

	int nmin = 100, nmax = 200;
	int rep = 0;
	std::vector<datos> vector_tiempos;
	datos T;
	T.t = 0;
	Clock time;
	double ms;
	cout << " Ajuste Backtracking " << RESET << endl;
	cout << "Ingrese las Repeticiones:" << endl;
	cin >> rep;
	cout << "Reinas Mínimas:" << endl;
	cin >> nmin;
	cout << "Reinas Máximas:" << endl;
	cin >> nmax;
	int x;
	float percent =  100.0 / (nmax - nmin);
	float aux = 0.0;
	int volumen = 0, precio = 0, contador_volumen = 0;

	for (int i = nmin; i <= nmax; i++)
	{
		for (x = 0; x <= rep; ++x)
		{
			Reinas r(i);
			time.start();
			r.startReinasBacktracking(false);
			if (time.isStarted())
			{
				time.stop();
				ms = time.elapsed();
				T.t = T.t + ms;
			}

		}
		system("clear");
		cout << "[" << porcentaje(aux) << "]" << aux << "% Completado\n";
		aux = aux + percent;
		T.t = T.t / rep;
		T.n = i;
		T.nmod = factorial(i);
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
	exportarDatos(vector_tiempos, 5, _matrizSoluciones); //Exporta a fichero
	system("cd ../exports/gnu_plots/ && ./ejemplo_gnuplot.sh");
	getchar();

}
void laboratorio_comparacion()
{
	int reinas_n;
	std::cout << "Numero de reinas: \n";
	std::cin >> reinas_n;
	Reinas r1(reinas_n);
	Reinas r2(reinas_n);
	Clock time;
	double ms1;
	double ms2;

	time.start();
	r1.startReinasBacktracking(true);
	if (time.isStarted())
	{
		time.stop();
		ms1 = time.elapsed();
	}

	time.start();
	r2.startReinasVegas(0);
	if (time.isStarted())
	{
		time.stop();
		ms2 = time.elapsed();
	}
	system("reset");
	std::cout << "Tiempo Backtracking\n";
	formato_fecha(ms1);
	std::cout << "Tiempo Las Vegas\n";
	formato_fecha(ms2);
	double percent = 0;
	if (ms1 > ms2)
	{
		percent = abs((ms2 / ms1) * 100 - 100);
		std::cout << "Las vegas es mejor con un % de: " << percent << "%\n";

	}
	else
	{
		percent = abs((ms1 / ms2) * 100 - 100);
		std::cout << "Backtracking es mejor con un % de: " << percent << "%\n";
	}

	getchar();
}
double sumatorio(std::vector<datos> &v, int a, int b)
{
	double resultado = 0;
	for (int i = 0; i < (int)v.size(); i++)
	{
		resultado += (pow(v[i].nmod, a)) * (pow(v[i].t, b));
	}
	return resultado;
}
std::string porcentaje(float x)
{
	std::string cadena = "";
	int r = round(x);
	for (int i = 0; i < r; ++i)
	{
		cadena += "#";
	}
	return cadena;
}
void exportarDatos(std::vector<datos> &v, int opt, std::vector < std::vector < double > > &X)
{
	//a0 X[0][0]
	//a1 X[1][0]
	//a2 X[2][0]
	string cadena;
	if (opt == 1)
	{
		cadena = "Datos1.txt";
		cout << "La ecuacion del ajuste exponencial es: " << X[1][0] << "*2^n + " << X[0][0] << " \n";
	}
	else if (opt == 2)
	{
		cadena = "Datos2.txt";
		cout << "La ecuacion del ajuste cuadratico es: " << X[2][0] << "*n^2 + " << X[1][0] << "n + " << X[0][0] << " \n";
	}
	else if (opt == 3)
	{
		cout << "La ecuacion del ajuste cuadratico es: " << X[1][0] << "*n + " << X[0][0] << " \n";
		cadena = "Datos3.txt";
	}
	else if (opt == 4)
	{
		cout << "La ecuacion del ajuste exponencial es: " << X[1][0] << "2*^n + " << X[0][0] << " \n";
		cadena = "Datos4.txt";
	}
	else if (opt == 5)
	{
		cout << "La ecuacion factorial del ajuste exponencial es: n!*" << X[1][0] << " + " << X[0][0] << " \n";
		cadena = "../exports/gnu_plots/Datos5.txt";
	}
	std::ofstream fs(cadena.c_str());
	for (int i = 0; i < (int)v.size(); i++)
	{
		if (opt == 1)
		{
			v[i].e = X[0][0] + X[1][0] * pow(2, v[i].n);
		}
		else if (opt == 2)
		{
			v[i].e = X[0][0] + X[1][0] * v[i].n + X[2][0] * pow(v[i].n, 2);
		}
		else if (opt == 3)
		{
			v[i].e = X[0][0] + X[1][0] * v[i].n + X[2][0] * pow(v[i].n, 2);
		}
		else if (opt == 4)
		{
			v[i].e = X[0][0] + X[1][0] * pow(2, v[i].n);
		}
		else if (opt == 5)
		{
			v[i].e = X[0][0] + X[1][0] * v[i].nmod;
		}
		fs << v[i].n << "\t" << v[i].t << "\t" << v[i].e << std::endl;
	}
	fs.close();
	cout << "El coeficiente de correlacion es: " << coeficienteCorrelacion(v) << "\n";
	getchar();
	getchar();
	calculoTiempo(opt, X);
}
double factorial(int n)
{
	double con = 1;

	for (int i = 1; i <= n; ++i)
	{
		con = con * i;
	}
	return con;
}
double coeficienteCorrelacion(std::vector<datos> &v)
{
	double mt, me, st, se, ste, denom, r;
	/* Calcula la media de las dos series x[], y[] */
	///Vectores para la media
	std::vector<double> v_t;
	std::vector<double> v_e;
	for (int i = 0; i < (int)v.size(); ++i)
	{
		v_t.push_back(v[i].t);
		v_e.push_back(v[i].e);
	}
	///
	return getCoeficienteDeterminacion(v_t, v_e);
}
double media(std::vector<double> &v)
{
	double m = 0;
	for (int i = 0; i < (int)v.size(); i++)
	{
		m += v[i];
	}
	m /= (int)v.size();
	return m;
}
void calculoTiempo(int opt, std::vector < std::vector < double > > &X)
{
	double valor = 1;
	double res = 0.0;
	while (valor != 0)
	{
		system("clear");
		if (opt == 1)
		{
			cout << "La ecuacion del ajuste exponencial es: " << X[1][0] << "*2^n + " << X[0][0] << " \n";
			cout << "0-Para salir , Introduce un tamaño de elementos para calcular su tiempo estimado: ";
			cin >> valor;
			if (valor != 0)
			{
				cout << "El tiempo estimado en microsegundos  seria de:";
				res = X[0][0] + X[1][0] * pow(2, valor) ;
				cout << res << endl;
				formato_fecha(res);
				getchar();
				getchar();
			}
		}
		else if (opt == 2)
		{
			cout << "La ecuacion del ajuste polinomico es: " << X[2][0] << "*n^2 + " << X[1][0] << "n + " << X[0][0] << " \n";
			cout << "0-Para salir , Introduce un tamaño de elementos para calcular su tiempo estimado: ";
			cin >> valor;
			if (valor != 0)
			{
				cout << "El tiempo estimado en microsegundos  seria de:";
				res = X[0][0] + X[1][0] * valor + X[2][0] * pow(valor, 2);
				cout << res << endl;
				formato_fecha(res);
				getchar();
				getchar();
			}
		}
		else if (opt == 3)
		{
			cout << "La ecuacion del ajuste polinomico es:" << X[1][0] << "*n + " << X[0][0] << " \n";
			cout << "0-Para salir , Introduce un tamaño de elementos para calcular su tiempo estimado: ";
			cin >> valor;
			if (valor != 0)
			{
				cout << "El tiempo estimado en microsegundos  seria de:";
				res = X[0][0] + X[1][0] * valor + X[2][0] * pow(valor, 2);
				cout << res << endl;
				formato_fecha(res);
				getchar();
				getchar();
			}
		}
		else if (opt == 4)
		{
			cout << "La ecuacion del ajuste exponencial es: " << X[1][0] << "*2^n + " << X[0][0] << " \n";
			cout << "0-Para salir , Introduce un tamaño de elementos para calcular su tiempo estimado: ";
			cin >> valor;
			if (valor != 0)
			{
				cout << "El tiempo estimado en microsegundos  seria de:";
				res = X[0][0] + X[1][0] * pow(2, valor) ;
				cout << res << endl;
				formato_fecha(res);
				getchar();
				getchar();
			}
		}
		else if (opt == 5)
		{
			cout << "La ecuacion del ajuste factorial es: n!*" << X[1][0] << "+ " << X[0][0] << " \n";
			cout << "0-Para salir , Introduce un tamaño de elementos para calcular su tiempo estimado: ";
			cin >> valor;
			if (valor != 0)
			{
				cout << "El tiempo estimado en microsegundos  seria de:";
				res = X[0][0] + X[1][0] * factorial(valor);
				cout << res << endl;
				formato_fecha(res);
				getchar();
				getchar();
			}
		}
	}
}
void formato_fecha(double ms)
{
	double anio = 0;
	double dias = 0;
	double horas = 0;
	double aux = 0;
	double minutos = 0;
	double segundos = 0;

	aux = ms / 1e+6;
	segundos = fmod(aux, 60);
	aux = (aux - segundos) / 60;
	minutos = fmod(aux, 60);
	aux = (aux - minutos) / 60;
	horas = fmod(aux, 24);
	aux = (aux - horas) / 24;
	dias = fmod(aux, 365);
	anio = (aux - dias) / 365;
	//////
	cout << "\n Años: " << anio << endl <<  " Dias: " << dias << endl <<  " Horas: " << horas << endl <<  " Minutos:" << minutos << endl <<  " Segundos: " << segundos << endl << "\n";
}