#ifndef BIGNUM_HPP
#define BIGNUM_HPP
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <string>
#include <iostream>
#include "funcionesExtras.hpp"
using namespace std;
string sumarNumero(string &numero1, string &numero2);

/**
 * @brief      Realiza la multiplicación de dos números enteros grandes
 *
 * @param      numero1  El numero 1
 * @param      numero2  El numero 2
 * @param[in]  limite   El limite
 *
 * @return     Devuelve una cadena con el resultado
 */
string multiplicaNumeros(string &numero1, string &numero2, int limite);
class bignum
{
private:
	std::string numero_;
public:
	bignum() {numero_ = "";}

	/**
	 * @brief      Establece el numero.
	 *
	 * @param[in]  numero  el numero
	 */
	void setNumero(std::string numero) {numero_ = numero;};

	/**
	 * @brief      Devuelve el numero.
	 *
	 * @return     El numero.
	 */
	std::string getNumero() {return numero_;}

	/**
	 * @brief      Realiza la suma de dos números enteros grandes
	 *
	 * @param      numero1  El numero 1
	 * @param      numero2  El numero 2
	 *
	 * @return     Devuelve una cadena con el resultado
	 */
	int size() {return numero_.size();}


	string operator+(bignum &num)
	{
		std::string aux;
		string num1 = this->getNumero();
		string num2 = num.getNumero();
		aux = sumarNumero (num1, num2);
		return aux ;
	}
	string operator*(bignum &num)
	{
		std::string aux;
		int limite = 0;
		string num1 = this->getNumero();
		string num2 = num.getNumero();
		cout << "Introduce el limite: ";
		cin >> limite;
		aux = multiplicaNumeros(num1, num2, limite);
		return aux ;
	}
};


#endif // ENTERO_HPP
