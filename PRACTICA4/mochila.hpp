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

public:
	Mochila(int v)
	{
		setVolumen(v);
	};
	inline void start()
	{
		//showMatVector();
		ordination();//Ordenamos de mayor a menor
		//showMatVector();
		bagAlgorithm();//FIN
	};
	inline int getVolumen() const {return volumen_;}
	inline void setVolumen(int &v) {volumen_ = v;}
	inline void addMatVector(Material &mat) {Vmats.push_back(mat);}
	inline Material & getMatVector(int i) {return Vmats[i];}
	inline std::vector<Material> & getVector() {return Vmats;}
	inline void showMatVector()
	{
		for (auto value : Vmats) {
			std::cout << "ID--> " << value.getId() << " VOLUMEN--> " << value.getVolumen() << " PRECIO--> " << value.getPrecio() << " ESTADO--> " << value.getEstado() << "\n";
		}
	}

	inline static bool comparacion(const Material& m1, const Material& m2)
	{
		return m1.getPrecio() > m2.getPrecio();
	}
	inline void ordination()
	{
		std::sort(getVector().begin(), getVector().end(), comparacion);
	}
	inline void bagAlgorithm()
	{
		//Seleccionamos el indice del objeto de mayor coste, puesto que hemos ordenado la estructura de dantes anteriormente de mayor a menor el elemento de mayor coste siempre sera i=0
		int maximoCoste = 0;
		int resto = getVolumen();
		int cuenta = 0;
		do {
			if (Vmats[maximoCoste].getEstado() == "No Usado") {
				if (resto >= Vmats[maximoCoste].getVolumen()) {
					cuenta = cuenta + (Vmats[maximoCoste].getVolumen() * Vmats[maximoCoste].getPrecio());
					resto = resto - Vmats[maximoCoste].getVolumen();
					std::cout<<RED<<"Material Usado: "<<BLUE<<Vmats[maximoCoste].getId()<<YELLOW<<"\n -->Unidades Empleadas: "<<CYAN<<Vmats[maximoCoste].getVolumen()<<YELLOW<<"\n -->Precio por unidad: "<<CYAN<<Vmats[maximoCoste].getPrecio()<<YELLOW<<"\n -->Coste: "<<Vmats[maximoCoste].getVolumen() * Vmats[maximoCoste].getPrecio()<<CYAN<<"\n [Total en mochila: "<<cuenta<<" ]"<<RESET<<std::endl;
					maximoCoste++;
				} else {
					cuenta = cuenta + (resto * Vmats[maximoCoste].getPrecio());
					Vmats[maximoCoste].setEstado("Parcialmente Usado");
					resto = 0;
					std::cout<<RED<<"Material Usado: "<<BLUE<<Vmats[maximoCoste].getId()<<YELLOW<<"\n -->Unidades Empleadas: "<<CYAN<<Vmats[maximoCoste].getVolumen()<<YELLOW<<"\n -->Precio por unidad: "<<CYAN<<Vmats[maximoCoste].getPrecio()<<YELLOW<<"\n -->Coste: "<<Vmats[maximoCoste].getVolumen() * Vmats[maximoCoste].getPrecio()<<CYAN<<"\n [Total en mochila: "<<cuenta<<" ]"<<RESET<<std::endl;
					
				}
			}
		} while (resto != 0);
		std::cout << "\n\n Con un volumen en la Mochila de " << getVolumen() << " Unidades/Volumen el coste maximo de los materiales son " << cuenta << " Unidades/Precio" << std::endl;
		getchar();
	}

};

inline Mochila &operator<<(Mochila &bag, const std::string &fichero)
{
	std::ifstream f(fichero, std::ios::in);
	int id, volumen, precio;
	if (f.good()) {
		while (f >> id >> volumen >> precio) {
			Material mat(id, volumen, precio);
			bag.addMatVector(mat);
		}
	} else {
		std::cout << "Error al abrir fichero\n";
	}
	return bag;
}

#endif