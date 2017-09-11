#ifndef GRAFO_H
#define GRAFO_H
#include <list>
#include <vector>
#include "Arco.h"

// using namespace std;

class Grafo{
	
	public:

// NOTA: Dependiendo de la implementación puede ser necesario incluir otras funciones constructuras
	Grafo(const int & v);
	
	Grafo(const Grafo & otroGrafo);

	~Grafo();

	Grafo & operator = (const Grafo & otroGrafo);

	// Devuelve true si la cantidad de vértices es cero
	bool esta_vacio() const;
	// Indica la cantidad de vértices del grafo
	int devolver_longitud() const;

	bool existe_vertice(int vertice) const;

	bool existe_arco(int origen, int destino) const;

	// PRE CONDICION: existe_arco(origen, destino)
//	const un_tipo & costo_arco(int origen, int destino) const;

	void devolver_vertices(std::list<int> & vertices) const;

//	void devolver_adyacentes(int origen, list<Arco<un_tipo>> & adyacentes) const;

	void agregar_vertice(int vertice);

	// POST CONDICION: Para todo vértice v != vertice: !existeArco(v, vertice) && !existeArco(vertice, v)
	void eliminar_vertice(int vertice);

	// PRE CONDICION: existeArco(origen, destino)
//	void modificar_costo_arco(int origen, int destino, const un_tipo & costo);

	// PRE CONDICION: existeVertice(origen) && existeVertice(destino)
	// POST CONDICION: existeArco(origen, destino)
//	void agregar_arco(int origen, int destino, const un_tipo & costo);

	// POST CONDICION: !existeArco(origen, destino)
	void eliminar_arco(int origen, int destino);

	void vaciar();

	private:

		std::list<int> lista_arcos;
		std::vector< std::list<int> > vertices;

};

#endif