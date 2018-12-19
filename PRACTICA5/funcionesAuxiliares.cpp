/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 1
  \author
  \date
*/
#include "funcionesAuxiliares.hpp"
#include "mochila.hpp"
#include "grafo.hpp"
#include "sistemaMonetario.hpp"
#include "sistemaEcuaciones.hpp"
#include "estadistica.hpp"
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
	std::cout <<  "[1] Mochila";
	PLACE(posicion++, 10);
	std::cout <<  "[2] Sistema Monetario";
	PLACE(posicion++, 10);
	std::cout <<  "[3] Tiempo Mochila";
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

void mochila()
{
	int volumen = 0;
	std::string fichero = "datos.txt";
	std::cout << RED << "Mochila" << RESET << std::endl;
	std::cout << RED << "Introduce el volumen: " << RESET;
	std::cin >> volumen;

	Mochila m(volumen + 1);
	m << fichero;
	m.rellenarMatrizMochila();
	m.bagAlgorithm2();
	getchar();
	getchar();


}
void cambio()
{
	int cambio = 0;
	std::string fichero = "dinero.txt";
	std::cout << RED << "sistemaMonetario" << RESET << std::endl;
	std::cout << RED << "Introduce el cambio(Centimos): " << RESET;
	std::cin >> cambio;

	SistemaMonetario m(cambio);
	m << fichero;
	m.mostrarSistemaMonetario();
	m.start();
	getchar();
	getchar();

}

void tiempo_mochila()
{

	int nmin = 100, nmax = 200;
	int rep = 0;
	std::vector<datos> vector_tiempos;
	datos T;
	T.t = 0;
	Clock time;
	double ms;
	cout << " Mochilusman " << RESET << endl;
	cout << "Ingrese las Repeticiones:" << endl;
	cin >> rep;
	int x;
	float percent =  100.0 / (nmax - nmin);
	float aux = 0.0;
	int volumen = 0, precio = 0, contador_volumen = 0;

	for (int i = nmin; i <= nmax; i++)
	{
		for (x = 0; x <= rep; ++x)
		{
			Mochila m;

			for (int j = 0; j < i; ++j)
			{
				volumen = rand() % 100 + 1;
				precio = rand() % 100 + 1;
				Material mat(j, volumen, precio);
				m.addMatVector(mat);
				contador_volumen += volumen;


			}

			m.setVolumen((contador_volumen + 1) * 0.5);
			contador_volumen = 0;
			//Invocamos medir tiempo
			time.start();
			//Aqui Hacemos la mochila
			m.rellenarMatrizMochila();
			//

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
	exportarDatos(vector_tiempos, 2, _matrizSoluciones); //Exporta a fichero
	system("./ejemplo_gnuplot.sh");
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
		fs << v[i].n << "\t" << v[i].t << "\t" << v[i].e << std::endl;
	}
	fs.close();
	cout << "El coeficiente de correlacion es: " << coeficienteCorrelacion(v) << "\n";
	getchar();
	getchar();
	calculoTiempo(opt, X);
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
	double valor = 1;

	anio = (pow(10, -6) * ms) / (86400 * 365);
	aux = fmod(anio, 365); //Dias que sobran de los años
	dias = aux;
	aux = std::fmod(dias, 24); //Horas que sobran de los años
	horas = aux;//Dias que sobran de los años
	aux = std::fmod(dias, 60); //Minutos que sobran de los años
	minutos = aux;
	aux = std::fmod(dias, 60); //Segundos que sobran de los años
	segundos = aux;
	//////
	cout << "\n Años: " << (int)anio << endl <<  " Dias: " << (int)dias << endl <<  " Horas: " << (int)horas << endl <<  " Minutos:" << (int)minutos << endl <<  " Segundos: " << (int)segundos << endl << "\n";


}