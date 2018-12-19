#ifndef _MATERIAL_HPP
#define _MATERIAL_HPP
#include <string>
class Material
{
private:
	int id_;
	int volumen_;
	int precio_;
	std::string estado_="No Usado";//Usado,No usado,Parcialmente Usado
public:
	Material(){};
	Material(int id,int volumen,int precio){
		setId(id);
		setVolumen(volumen);
		setPrecio(precio);
	};
	inline void setId(int n){id_=n;}
	inline void setVolumen(int n){volumen_=n;}
	inline void setPrecio(int n){precio_=n;}
	inline void setEstado(std::string n){estado_=n;}

	inline int getId()const{return id_;}
	inline int getVolumen()const{return volumen_;}
	inline int getPrecio()const{return precio_;}
	inline std::string getEstado()const{return estado_;}
	
	
};

#endif