#include "iostream"
#include "Grafo.h"

	Grafo::Grafo(int v){
		
		// list< Arco <int> > lista_arcos();

		// vector< list < Arco <int> > > vertices(v, list< Arco <int> > ());
		vector< list < Arco <int> > > vertices(v);
		/*for (int i=0; i<v; i++)
			vector< list < Arco <int> > > vertices.push_back();
		*/
		cout << "longitud " << vertices.size() << endl;
	}


	Grafo::Grafo(const Grafo & otroGrafo){

	}


	Grafo::~Grafo(){

	}



	Grafo & Grafo::operator = (const Grafo & otroGrafo){


	}

	// Devuelve true si la cantidad de vértices es cero
	bool Grafo::esta_vacio() const{


	}
	// Indica la cantidad de vértices del grafo
	int Grafo::devolver_longitud() const{
			
		cout << "longitud " << vertices.size() << endl;

		return vertices.size();

	}

	bool Grafo::existe_vertice(int vertice) const{


	}

	bool Grafo::existe_arco(int origen, int destino) const{


	}

/*
	// PRE CONDICION: existe_arco(origen, destino)
	const C & Grafo::costo_arco(int origen, int destino) const{


	}
*/
	void Grafo::devolver_vertices(list<int> & vertices) const{


	}

/*	void Grafo::devolver_adyacentes(int origen, list<Arco> & adyacentes) const{


	}
*/
	void Grafo::agregar_vertice(int vertice){


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