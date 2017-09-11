#include <vector>
#include "iostream"
#include "Grafo.h"

using namespace std;

	Grafo::Grafo(const int & v){
		
		for (int i=0; i<v; i++)
			vertices.push_back(lista_arcos);

	}


	Grafo::Grafo(const Grafo & otroGrafo){

	}


	Grafo::~Grafo(){

	}



	Grafo & Grafo::operator = (const Grafo & otroGrafo){


	}

	// Devuelve true si la cantidad de vértices es cero
	bool Grafo::esta_vacio() const{
		if (vertices.size() == 0)
			return true;
		else
			return false;

	}

	// Indica la cantidad de vértices del grafo
	int Grafo::devolver_longitud() const{
		return vertices.size();
	}



	bool Grafo::existe_vertice(int vertice) const{
		if ((vertices.size() - 1) >= vertice)
			return true;
		else
			return false;

	}

	bool Grafo::existe_arco(int origen, int destino) const{


	}

/*
	// PRE CONDICION: existe_arco(origen, destino)
	const C & Grafo::costo_arco(int origen, int destino) const{


	}
*/
	void Grafo::devolver_vertices(list<int> & listado_vertices) const{
		listado_vertices.empty();
		int longitud= vertices.size();
		for (int i=0; i<longitud; i++)
			listado_vertices.push_back(i);

	}

/*	void Grafo::devolver_adyacentes(int origen, list<Arco> & adyacentes) const{


	}
*/
	void Grafo::agregar_vertice(int vertice){
		// si quisiera algun nombre en especia deberia
		// llevar aparte un arreglito con los nombres y listo
		// por defecto se agrega un vertice al final:
		lista_arcos.empty();
		vertices.push_back(lista_arcos);

	}

	// POST CONDICION: Para todo vértice v != vertice: !existeArco(v, vertice) && !existeArco(vertice, v)
	void Grafo::eliminar_vertice(int vertice){


	}

/*
	// PRE CONDICION: existeArco(origen, destino)
	void Grafo::modificar_costo_arco(int origen, int destino, const C & costo){


	}

	// PRE CONDICION: existeVertice(origen) && existeVertice(destino)
	// POST CONDICION: existeArco(origen, destino)
	void Grafo::agregar_arco(int origen, int destino, const C & costo){


	}
*/

	// POST CONDICION: !existeArco(origen, destino)
	void Grafo::eliminar_arco(int origen, int destino){


	}

	void Grafo::vaciar(){


	}