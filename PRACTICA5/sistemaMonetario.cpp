#include "sistemaMonetario.hpp"
void SistemaMonetario::mostrarSistemaMonetario()
{
	cout << BLUE << "\n Sistema Monetario: " << CYAN << endl;

	for (int i = 0; i < _d.size(); i++)
	{
		cout << PURPLE << "Unidad: " << BIBLUE << (double)_d[i].getValor() / 100 << "\t" << PURPLE <<
		     " Tipo: "
		     <<
		     BIBLUE << _d[i].getTipo() << RESET << endl;
	}
}

void SistemaMonetario::setTablaDinero()
{
	int filas = _d.size();
	int columnas = getCambio();
	_tabla = std::vector<std::vector<int> >(filas + 1, std::vector< int >(columnas + 1));
	for (int i = 0; i < filas; i++)
	{
		_tabla[i][0] = 0;
	}
	for (int i = 0; i < columnas; i++)
	{
		_tabla[0][1] = 0;
	}

	for (int i = 1; i <= filas; i++)
	{
		for (int j = 1; j <= columnas; j++)
		{
			if (i == 1 && j < _d[i - 1].getValor())
			{
				_tabla[i][j] = INT_MAX;
			}
			else
			{
				if (i == 1)
				{
					_tabla[i][j] = 1 + _tabla[i][j - _d[0].getValor()];
				}
				else if (j < _d[i - 1].getValor())
				{
					_tabla[i][j] = _tabla[i - 1][j];
				}
				else
				{
					_tabla[i][j] = min(_tabla[i - 1][j], 1 + _tabla[i][j - _d[i - 1].getValor()]);
				}
			}
		}
	}

}
void SistemaMonetario::obtenerSolucion()
{
	int i = _d.size();
	int j = _cambio;
	int c = _cambio;
	cout << BLUE << "\n Cambio Usado: " << RESET << endl;

	do
	{
		if (_tabla[i][j] != _tabla[i - 1][j])
		{
			_d[i - 1].setCantidadUsada(_d[i - 1].getCantidadUsada() + 1);
			c = c - _d[i - 1].getValor();
			j -= j - c;
		}
		else
		{
			i--;
		}
	}
	while (i > 0 && j > 0);

	for (int i = 0; i < _d.size(); i++)
	{
		if (_d[i].getCantidadUsada() > 0)
		{
			cout << RED << "Cantidad: " << BIBLUE << _d[i].getCantidadUsada() << RESET << endl;
			cout << RED << "VALOR: " << BIBLUE << (float)_d[i].getValor() / 100 << "\t" << RED <<
			     " TIPO: "
			     <<
			     BIBLUE << _d[i].getTipo() << RESET << endl;

			cout << endl;
		}
	}
}

