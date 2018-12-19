#ifndef _GRAFO_HPP
#define _GRAFO_HPP
#include <vector>
#include<bits/stdc++.h>
using namespace std;
class Grafo
{
private:
	vector < vector <int> > _matriz;
	std::vector<string> _vertices;
	std::vector<int> _completados;
	int _coste = 0;
public:
	Grafo() {};
	inline void setAdyacencia(vector < vector <int> > &m)
	{
		_matriz = m;
	}
	inline void setCompletados(int value)
	{
		_completados.push_back(value);
	}
	inline void addVertex(string &n)
	{
		_vertices.push_back(n);
	}
	inline void printAdyacencia()
	{
		for (int i = 0; i < _matriz.size(); ++i)
		{
			for (int j = 0; j < _matriz.size(); ++j)
			{
				cout << " " << _matriz[i][j] << " ";
			}
			cout << "\n";
		}
	}
	inline void printVertex()
	{
		for (int i = 0; i < _vertices.size(); ++i)
		{
			cout << _vertices[i] << endl;
		}
	}

	inline void TSP(int X)
	{
		int i, nx;
		_completados[X] = 1;

		cout << _vertices[X] << "--->";
		//Encontramos el menor elemento y devolvemos la posición en su matriz.
		int nc = INT_MAX;
		int min = INT_MAX, kmin;

		for (i = 0; i < _vertices.size(); i++)
		{
			if ((_matriz[X][i] != 0) && (_completados[i] == 0))
				//Buscamos en la columna el valor minimo de coste y que cumpla la condición que no haya sido seleccionado en el vector de completados, se retorna en NC el valor de la columna.
				if (_matriz[X][i] + _matriz[i][X] < min)
				{
					min = _matriz[i][0] + _matriz[X][i];
					kmin = _matriz[X][i];
					//Guardamos la columna con el menor coste, y ponemos a completado el array de completados
					nc = i;
				}
		}

		if (min != INT_MAX)
			_coste += kmin;

		//
		nx = nc;

		if (nx == INT_MAX)
		{
			nx = 0;
			cout << _vertices[nx];
			_coste += _matriz[X][nx];
			cout << "\n\nCoste minimo: " << _coste << endl;
			return;
		}
		TSP(nx);

	}

};

inline Grafo &operator<<(Grafo &graf, const std::string &fichero)
{
	std::ifstream f(fichero, std::ios::in);
	int count = 1;
	int tam;
	int cero;
	string nombre;
	vector < vector <int> > m;
	if (f.good())
	{
		if (fichero.find("matriz") != std::string::npos)
		{
			f >> tam;
			f >> cero;
			m = vector< vector< int > >(tam, vector< int >(tam));
			for (int i = 0; i < tam; ++i)
			{
				for (int j = 0; j < tam; ++j)
				{
					f >> m[i][j];
				}
			}
			graf.setAdyacencia(m);
		}
		else if (fichero.find("vertices") != std::string::npos)
		{
			while (f >> nombre)
			{
				graf.addVertex(nombre);
			}
		}
		for (int i = 0; i < tam; ++i)
		{
			graf.setCompletados(0);
		}
	}
	else
	{
		std::cout << "Error al abrir fichero\n";
	}
	return graf;
}
#endif