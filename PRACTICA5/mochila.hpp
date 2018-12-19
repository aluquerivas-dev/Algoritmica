#ifndef _MOCHILA_HPP
#define _MOCHILA_HPP
#include <vector>
#include <string>
#include "material.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <algorithm>
class Mochila
{
private:
	std::vector<Material> Vmats;
	int volumen_;
	std::vector<std::vector<int>> MaMochila_;

public:
	Mochila()
	{

	}
	Mochila(int v)
	{
		setVolumen(v);
	}
	inline void start()
	{

	}
	inline int getVolumen() const {return volumen_;}
	inline void setVolumen(int v) {volumen_ = v;}
	inline void addMatVector(Material &mat) {Vmats.push_back(mat);}
	inline Material & getMatVector(int i) {return Vmats[i];}
	inline void rellenarMatrizMochila()
	{
		MaMochila_ = std::vector< std::vector< int > >(Vmats.size() + 1, std::vector< int >(getVolumen() + 1));
		int i = 0, j = 0;
		for (int i = 0; i < getVolumen(); ++i)
		{
			MaMochila_[0][i] = 0;
		}
		for (int i = 0; i < Vmats.size(); ++i)
		{
			MaMochila_[i][0] = 0;
		}
		for ( i = 1; i < Vmats.size(); ++i)
		{
			for ( j = 1; j < getVolumen(); ++j)
			{
				if (j < getMatVector(i).getVolumen())
				{
					MaMochila_[i][j] = MaMochila_[i - 1][j];
				}
				else
				{
					MaMochila_[i][j] = std::max(
					                       MaMochila_[i - 1][j],
					                       getMatVector(i).getPrecio() *
					                       getMatVector(i).getVolumen() +
					                       MaMochila_[i - 1][j - getMatVector(i).getVolumen()]);
				}
			}
		}
	}
	inline void bagAlgorithm2()
	{
		int coste = 0;
		int volumen = 0 ;
		int i = Vmats.size() - 1; //Para empezar en el ultimo elemento de la matriz.
		int j = getVolumen() - 1; //Para empezar en el ultimo elemento de la Matriz.
		do
		{
			if (MaMochila_[i][j] != MaMochila_[i - 1][j] && getMatVector(i).getEstado() != "Usado")
			{
				getMatVector(i).setEstado("Usado");
				std::cout << "El material: " << i + 1 << " entra en la mochila.\n";
				std::cout << "   Coste: " << getMatVector(i).getPrecio() << "\n";
				std::cout << "   Volumen:" << getMatVector(i).getVolumen() << "\n";
				coste = coste + getMatVector(i).getVolumen() * getMatVector(i).getPrecio();
				j -= getMatVector(i).getVolumen();
			}
			else
			{
				i--;
			}

		}
		while (i > 0 && j > 0);
		std::cout << "El coste: " << MaMochila_[Vmats.size() - 1][getVolumen() - 1] << "\n";
	}
};
inline Mochila &operator<<(Mochila &bag, const std::string &fichero)
{
	std::ifstream f(fichero, std::ios::in);
	int id, volumen, precio;
	if (f.good())
	{
		while (f >> id >> volumen >> precio)
		{
			Material mat(id, volumen, precio);
			bag.addMatVector(mat);
		}
	}
	else
	{
		std::cout << "Error al abrir fichero\n";
	}
	return bag;
}

#endif
