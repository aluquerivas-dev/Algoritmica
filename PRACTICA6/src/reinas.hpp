#ifndef _REINAS_HPP
#define _REINAS_HPP
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string.h>
class Reinas
{

private:

	int _n;//Numero de reinas de la prueba
	int num_sol;
	std::vector<int> _v;

public:

	Reinas(int n)
	{
		setN(n);
		setNumSol(0);
	};

	void setN(int i) {_n = i;};

	int getN()const {return _n;};

	void setNumSol(int i) {num_sol = i;};

	int getNumSol()const {return num_sol;};


	int getV(int i) {return _v[i];};

	void setV(int i, int n) {_v[i] = n;};

	void startReinasBacktracking(bool first_solution = false)
	{
		_v = std::vector<int>(getN() + 1);
		algoritmoNreinasBacktracking(first_solution);
	};
	void startReinasVegas(int opt)
	{
		if (opt == 0)
		{
			_v = std::vector<int>(getN() + 1);
			int contador = 0;
			bool opt = false;
			while (opt != true)
			{
				contador++;
				opt = algoritmoNreinasVegas();
				system("clear");
				std::cout << "Intento: " << contador << std::endl;

			}
			std::cout << "\nSe encontro una solución en la iteración: " << contador << "\n";
			mostrar_m();

		}
		if (opt == 1)
		{
			double num_pru = 0, con = 0, media = 0, contador = 0;
			std::cout << "Numero de pruebas: \n";
			std::cin >> num_pru;			_v = std::vector<int>(getN() + 1);
			bool opt = false;

			for (int i = 1; i <= num_pru; ++i)
			{

				while (opt != true)
				{
					contador++;
					opt = algoritmoNreinasVegas();


				}
				system("clear");
				std::cout << "Prueba Nº: " << i << ", intentos: " << contador << "\n";
				media += contador;
				contador = 0;
				opt = false;
			}
			std::cout << "El valor medio: " << media / num_pru << "\n";




		}

	};
	bool comprobar_sitio(int k)
	{
		for (int i = 1; i <= k - 1; ++i)
		{
			if (getV(i) == getV(k) || abs( getV(i) - getV(k) ) == abs(i - k))
			{
				return false;
			}
		}
		return true;
	};

	void algoritmoNreinasBacktracking(bool first_solution = false)
	{
		std::string nombre;
		if (first_solution == true)
		{
			nombre =  "../exports/backtrackingQueen/FistSolution" + std::to_string(getN()) + "QueenBacktracking.txt";
		}
		else
		{
			nombre =  "../exports/backtrackingQueen/AllSolution" + std::to_string(getN()) + "QueenBacktracking.txt";
		}
		std::ofstream fs(nombre.c_str(), std::ios_base::app);
		//
		int k = 1; //Fila del vector
		setV(0, 0);
		while (k > 0)
		{
			setV(k, getV(k) + 1);
			while (getV(k) <= getN() && comprobar_sitio(k) == false)
			{
				setV(k, getV(k) + 1);
			}
			if (getV(k) <= getN())
			{
				if (k == getN())
				{
					setNumSol(getNumSol() + 1);
					//Guardo en el fichero
					for (int i = 1; i < getN() + 1; ++i)
					{
						fs << getV(i) << "\t";
					}
					fs << "\n";
					if (first_solution == true)
					{
						break;
					}
				}
				else
				{
					k = k + 1;
					setV(k, 0);
				}
			}
			else
			{
				k = k - 1;
			}
		}
		fs.close();
	};

	bool algoritmoNreinasVegas()
	{
		int i;
		int j;
		int contador = 0;
		int columna = 0;
		int ran;
		std::vector<int> _aux;
		_aux = std::vector<int>(getN() + 1);
		for (int i = 0; i < _v.size(); ++i)
		{
			_v[i] = 0;
		}
		for (i = 1; i <= getN(); ++i)
		{
			contador = 0;
			for (j = 1; j <= getN(); ++j)
			{
				setV(i, j);
				if (comprobar_sitio(i) == true)
				{
					contador++;
					_aux[contador] = j;
				}
			}
			if (contador == 0)
			{
				break;//SAlimos
			}
			ran = rand() % contador + 1;
			columna = _aux[ran];
			setV(i, columna);
		}
		if (contador == 0)
		{
			return false;
		}
		else
		{
			std::string nombre;
			nombre =  "../exports/vegasQueen/FistSolution" + std::to_string(getN()) + "Queenvegas.txt";
			std::ofstream fs(nombre.c_str());
			for (int i = 1; i < getN() + 1; ++i)
			{
				fs << getV(i) << "\t";
			}
			fs << "\n";
			return true;
		}
	}
	void mostrar_m()
	{
		for (int i = 1; i < getN() + 1; ++i)
		{
			std::cout << getV(i) << "\t";
		}
		std::cout << "\n";
		for ( int i = 1; i < getN() + 1; ++i )
		{
			for ( int j = 1; j < getN() + 1; ++j )
			{
				if ( getV(i) == j )
				{
					std::cout << BIYELLOW << "[1]" << RESET;
				}
				else
				{
					std::cout << "[0]";
				}
			}
			std::cout << std::endl;
		}
	}


};
#endif