#include "Arco.h"

	template <typename un_tipo> 
		Arco<un_tipo>::Arco(const int o, const int d, const un_tipo c){
			origen= o;
			destino= d;
			costo= c;

	}
/*
	template <typename un_tipo> 
		Arco<un_tipo>::~Arco(){
	}
*/
	template <typename un_tipo> 
		int Arco<un_tipo>::Devolver_origen() const{
			return origen;
	}

	template <typename un_tipo> 
		int Arco<un_tipo>::Devolver_destino() const{
			return destino;
	}

	template <typename un_tipo> 
		un_tipo Arco<un_tipo>::Devolver_costo() const{
			return costo;
	}
