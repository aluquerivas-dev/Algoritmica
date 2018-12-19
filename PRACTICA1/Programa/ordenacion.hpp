#include <vector>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <fstream>
#include <math.h>
#ifndef _ORDENACION_HPP_
#define _ORDENACION_HPP_

class Ordenacion
{
public:
	Ordenacion(){};
	


	void insercionBinaria(std::vector<int> &v, int max)
	{
		int i, j, aux, izq, der, m;
		for (i = 1; i < max; i++)
		{
			aux = v[i];
			izq = 0;
			der = i - 1;
			while (izq <= der)
			{
				m = ((izq + der) / 2);
				if (aux < v[m])
					der = m - 1;
				else
					izq = m + 1;
			}
			j = i - 1;
			while (j >= izq)
			{
				v[j + 1] = v[j];
				j = j - 1;
			}
			v[izq] = aux;
		}
	}

	void insercionShell(std::vector<int> &v, int max)
	{
		int i, j, inc, temp;

		for (inc = 1 ; inc < max; inc = inc * 3 + 1);

		while (inc > 0)
		{
			for (i = inc; i < max; i++)
			{
				j = i;
				temp = v[i];
				while ((j >= inc) && (v[j - inc] > temp))
				{
					v[j] = v[j - inc];
					j = j - inc;
				}

				v[j] = temp;
			}

			inc /= 2;
		}
	}
	bool estaOrdenado(const std::vector<int> &v) {



		for (int i = 1; i < (int)v.size(); ++i)
		{
			if (v[i] < v[i - 1])
			{
				return 0;
			}
		}
		return 1;
	}

	

};



#endif
