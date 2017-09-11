#include "iostream"
#include "Arco.h"
#include "Grafo.h"
#include "list"

using namespace std;

/*
void imprimir_lista(list<Arco> una_lista){
	cout << " O  D  C" << endl;
	list<Arco>::iterator iterador= una_lista.begin();
	while (iterador != una_lista.end()) {
		Arco un_arco= *iterador;
		cout << "(" << un_arco.Origen() << ", " << un_arco.Destino() << ", " << un_arco.Costo() << ")" << endl;
		iterador++;
	}
	cout << endl;
}
*/

void imprimir_menu(){
	
	cout << "****************************************" << endl;
	cout << endl << "que desea hacer?" << endl << endl;
    cout << " 1- Agregar un Arco" << endl;
    cout << " 2- Eliminar un Arco" << endl;
    cout << " 3- Ver el Costo de un Arco" << endl;
    cout << " 4- Existe Arco?" << endl;
    cout << " 5- Modificar el Costo de un Arco" << endl;
    cout << " 6- ver Arcos Entrantes" << endl;
    cout << " 7- ver Arcos Salientes (adyacentes)" << endl;
    cout << endl;
    cout << " 8- Agregar Vertice" << endl;
    cout << " 9- Eliminar Vertice" << endl;
    cout << "10- ver Cantidad de Vertices" << endl;
    cout << "11- ver Matriz de Adyacencia" << endl;
    cout << endl;
    cout << "0- Salir" << endl;
	cout << "****************************************" << endl;
}


int main(){
    int vertices, opcion;
    cout << "Ingrese cantidad de vertices: ";
    cin >> vertices;
    Grafo un_grafo(vertices);
    cout << "Grafo de " << vertices << " vertices creado" << endl << endl;

    imprimir_menu();
    cin >> opcion;

    while (opcion != 0){
        switch (opcion){
            /*
            case 1:{
                cout << "Ingrese Origen del arco: ";
                cin >> origen;
                cout << "Ingrese Destino del arco: ";
                cin >> destino;
                cout << "Ingrese Costo del arco: ";
                cin >> costo;
                un_grafo.Agregar_arco(origen, destino, costo);
                cout << endl << "Se agregó el arco (" << origen << ", " << destino << ", " << costo << ")" << endl;
            }
                break;
            case 2:{
                cout << "Ingrese Origen del arco: ";
                cin >> origen;
                cout << "Ingrese Destino del arco: ";
                cin >> destino;
                un_grafo.Eliminar_arco(origen, destino);
                cout << endl <<  "Se Eliminó el arco (" << origen << ", " << destino << ")" << endl;    
            }
                break;
            case 3:{
                cout << "Ingrese Origen del arco: ";
                cin >> origen;
                cout << "Ingrese Destino del arco: ";
                cin >> destino;
                cout <<  endl << "el costo del arco (" << origen << ", " << destino << ") es " << un_grafo.Ver_costo_arco(origen, destino) << endl;
            }
                break;
            case 4:{
                cout << "Ingrese Origen del arco: ";
                cin >> origen;
                cout << "Ingrese Destino del arco: ";
                cin >> destino;
                if (un_grafo.Existe_arco(origen, destino))
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
                un_grafo.Modificar_costo_arco(origen, destino, costo);
                cout <<  endl << "el costo del arco (" << origen << ", " << destino << ") es " << un_grafo.Ver_costo_arco(origen, destino) << endl;
            }
            case 6:{
                cout << "Ingrese el Vertice para ver Arcos Entrantes: ";
                cin >> vert;
                un_grafo.Devolver_entrantes(vert, lista_arcos);
                imprimir_lista(lista_arcos);
            }
                break;
            case 7:{
                cout << "Ingrese el Vertice para ver Arcos Salientes: ";
                cin >> vert;
                un_grafo.Devolver_adyacentes(vert, lista_arcos);
                imprimir_lista(lista_arcos);
            }
                break;
            case 8:{
                un_grafo.Agregar_vertice();
                cout << endl <<  "Vertice Agregado! " << endl;
                cout << "Cantidad de vertices: " << un_grafo.Cantidad_vertices() << endl;
            }
                break;
            case 9:{
                cout << "Ingrese el N° de Vertice a Eliminar: ";
                cin >> vert;
                un_grafo.Eliminar_vertice(vert);
                cout << endl << "Vertice Eliminado! " << endl;
                cout << "Cantidad de vertices: " << un_grafo.Cantidad_vertices() << endl;
            }
                break;
            */
            case 10:{
                cout << endl <<  "Cantidad de vertices: " << un_grafo.devolver_longitud() << endl;
            }
                break;
            case 11:{
                // imprimir_matriz(un_grafo, vertices);
            }
                break;
            default:{
                cout <<  endl << "Opción invalida\n" << "Ingrese una nueva opción\n";
            }
            break;

        }

        imprimir_menu();
        cin >> opcion;
    }



	return 0;
}
