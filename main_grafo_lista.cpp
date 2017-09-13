#include "iostream"
#include "Arco.h"
#include "Grafo.h"
#include "list"
#include "vector"

using namespace std;


void imprimir_lista_arcos(list<Arco> una_lista){
	cout << " D  C" << endl;
	list<Arco>::iterator iterador= una_lista.begin();
	while (iterador != una_lista.end()) {
		Arco un_arco= *iterador;
		cout << "(" << un_arco.Devolver_destino() << ", " << un_arco.Devolver_costo() << ")" << endl;
		iterador++;
	}
	cout << endl;
}


void imprimir_lista_vertices(list<int> una_lista){
    cout << endl;
    list<int>::iterator iterador= una_lista.begin();
    while (iterador != una_lista.end()) {
        int vertice= *iterador;
        cout << *iterador << "  ";
        iterador++;
    }
    cout << endl;
}

void imprimir_menu(){
	cout << "                         que desea hacer?" << endl;
	cout << "o-----------------------------------------------------------------------o" << endl;
	cout << "| 0- Salir                      |  7- ver Arcos Adyacentes              |" << endl;
    cout << "| 1- Agregar un Arco            |  8- Agregar Vertice                   |" << endl;
    cout << "| 2- Eliminar un Arco           |  9- Eliminar Vertice                  |" << endl;
    cout << "| 3- Ver el Costo de un Arco    | 10- ver Cantidad de Vertices          |" << endl;
    cout << "| 4- Existe Arco?               | 11- el Grafo es vacio (vertices=0)?   |" << endl;
    cout << "| 5- Modificar el Costo Arco    | 12- existe vertice?                   |" << endl;
    cout << "| 6- ver Arcos Entrantes        | 13- Listar Vertices                   |" << endl;
    cout << "|                               |                                       |" << endl;
    cout << "------------------------------------------------------------------------o" << endl;
    cout << "| 14- DFS                                                               |" << endl;
    cout << "| 15- BFS                                                               |" << endl;
    cout << "o-----------------------------------------------------------------------o" << endl;
}

void DFS(Grafo un_grafo){
    // para todos los vertices: 
    // arma vector colores: B.lanco -> sin visitar, G.ris -> visitado, N.egro-> completo
    // arma vector tiempo visita
    // arma vector tiempo fin
    std::vector<char> colores;
    std::vector<int> tiempo_inicial; 
    std::vector<int> tiempo_final;

    list<int> lista_vertices;
    un_grafo.devolver_vertices(lista_vertices);
    
    list<int>::iterator iterador= lista_vertices.begin();

    while(iterador != lista_vertices.end()){
        colores.push_back('B');
    }

    cout << colores.size();
    for(int i=0; i<colores.size(); i++)
        cout << i << " -> " << colores.at(i) << endl;


}

int main(){
    int vertices, opcion, vertice, origen, destino, costo;
    list<int> listado_vertices;
    list<Arco> lista_arcos;

    cout << endl << "Ingrese cantidad de vertices: ";
    cin >> vertices;
    Grafo un_grafo(vertices);
    cout << endl << "Grafo de " << un_grafo.devolver_longitud() << " vertices creado" << endl << endl;

    imprimir_menu();
    cin >> opcion;

    while (opcion != 0){
        switch (opcion){
            case 1:{
                cout << "Ingrese Origen del arco: ";
                cin >> origen;
                cout << "Ingrese Destino del arco: ";
                cin >> destino;
                cout << "Ingrese Costo del arco: ";
                cin >> costo;
                un_grafo.agregar_arco(origen, destino, costo);
                cout << endl << "Se agregó el arco (" << origen << ", " << destino << ", " << costo << ")" << endl;
            }
                break;
            
            case 2:{
                cout << "Ingrese Origen del arco: ";
                cin >> origen;
                cout << "Ingrese Destino del arco: ";
                cin >> destino;
                un_grafo.eliminar_arco(origen, destino);
                cout << endl <<  "Se Eliminó el arco (" << origen << ", " << destino << ")" << endl;    
            }
                break;
            
            case 3:{
                cout << "Ingrese Origen del arco: ";
                cin >> origen;
                cout << "Ingrese Destino del arco: ";
                cin >> destino;
                cout <<  endl << "el costo del arco (" << origen << ", " << destino << ") es " << un_grafo.costo_arco(origen, destino) << endl;
            }
                break;
            
            case 4:{
                cout << "Ingrese Origen del arco: ";
                cin >> origen;
                cout << "Ingrese Destino del arco: ";
                cin >> destino;
                if (un_grafo.existe_arco(origen, destino))
                    cout << endl <<  "(" << origen << ", " << destino << ") Existe" << endl;
                else
                    cout << endl <<  "(" << origen << ", " << destino << ") NO Existe" << endl;

            }
                break;
            
            case 5:{
                cout << "Ingrese Origen del arco: ";
                cin >> origen;
                cout << "Ingrese Destino del arco: ";
                cin >> destino;
                cout << "Ingrese el Nuevo Costo del arco: ";
                cin >> costo;
                un_grafo.modificar_costo_arco(origen, destino, costo);
                cout <<  endl << "el costo del arco (" << origen << ", " << destino << ") es " << un_grafo.costo_arco(origen, destino) << endl;
            }
            /*
            case 6:{
                cout << "Ingrese el Vertice para ver Arcos Entrantes: ";
                cin >> vert;
                un_grafo.Devolver_entrantes(vert, lista_arcos);
                imprimir_lista(lista_arcos);
            }
                break;
            */
            case 7:{
                cout << "Ingrese el Vertice para ver Arcos Salientes: ";
                cin >> vertice;
                un_grafo.devolver_adyacentes(vertice, lista_arcos);
                imprimir_lista_arcos(lista_arcos);
            }
                break;
            
            case 8:{
                // si quisiera algun nombre en especial deberia
                // llevar aparte otro arreglo con los nombres y listo
                // por defecto se agrega un vertice al final:
                
                un_grafo.agregar_vertice(0);
                cout << endl <<  "1 Vertice Agregado! " << endl;
                cout << "nueva Cantidad de vertices: " << un_grafo.devolver_longitud() << endl;
            }
                break;
            
            case 9:{
                // cout << "Ingrese el N° de Vertice a Eliminar: ";
                // cin >> vert;
                // un_grafo.Eliminar_vertice(vert);
                cout << endl << "metodo aun no implementado! " << endl;
                // cout << endl << "Vertice Eliminado! " << endl;
                cout << "Cantidad de vertices: " << un_grafo.devolver_longitud() << endl;
            }
                break;
            
            case 10:{
                cout << endl <<  "Cantidad de vertices: " << un_grafo.devolver_longitud() << endl;
            }
                break;
            case 11:{
                if (un_grafo.esta_vacio())
                    cout << "NO existen vertices. Grafo VACIO" << endl;
                else
                    cout << "Existen vertices. Grafo NO vacio" << endl;
            }
                break;
            case 12:{
                cout << "ingrese en vertice a verificar (0...n): ";
                cin >> vertice;
                cout << endl;
                if (un_grafo.existe_vertice(vertice))
                    cout << "El vertice " << vertice << " Existe!" << endl;
                else
                    cout << "El vertice " << vertice << " NO Existe!" << endl;
            }
                break;
            case 13:{
                un_grafo.devolver_vertices(listado_vertices);
                imprimir_lista_vertices(listado_vertices);
            }
            case 14:{
                DFS(un_grafo);
            }
                break;
            default:{
                cout <<  endl << "Opción invalida\n" << "Ingrese una nueva opción\n";
            }
            break;

        }

        cout << endl << "Presione <ENTER> para continuar.." << endl;
        cin.ignore();
        cin.ignore();

        imprimir_menu();
        cin >> opcion;
    }



	return 0;
}
