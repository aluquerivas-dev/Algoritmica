#include <iostream>
#include <vector>
using namespace std;
struct data
{
	int n;
	int k;
	double valor;

};
/*
long long int comb_normal(int n, int k){

 if(k==0 || k==n){
  return 1;
 }else{

  return comb(n-1,k-1,data)+ comb(n-1,k,data);
 }

}
*/
long long int busqueda(int n, int k, vector<data> &v) {

	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].n == n && v[i].k == k)
		{
			return v[i].valor;
		}
	}
	return 0;

}
long long int comb_tabla(int n, int k, vector<data> &dat) {

	data dato;
	dato.n = n;
	dato.k = k;
	//Busco si en el vector de datos dat existe ya un valor guardado para una n y una k para asi evitar hacer el calculo.


	if (k == 0 || k == n) {
		return 1;
	}
	else
	{

		long long int valor = busqueda(n, k, dat);

		if (valor != 0) {
			return valor;

		} else
		{


			//Guardo el valor guardado de la llamada recursiva,para luego meterlo dentro de nuestro vector de datos dat.
			long long int valor = comb_tabla(n - 1, k - 1, dat) + comb_tabla(n - 1, k, dat);
			dato.valor = valor;
			dat.push_back(dato);
			return valor;
		}


	}

}

int main() {
	int n, k;
	std::vector<data> data;
	cout << " nCk " << endl;
	cout << "Ingrese el n: " << endl;
	cin >> n;
	cout << "Ingrese el k: " << endl;
	cin >> k;
	cout << "El combinatorio es: " << comb_tabla(n, k, data) << endl;


	return 0;
}